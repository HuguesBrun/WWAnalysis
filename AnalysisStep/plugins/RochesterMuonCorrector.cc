//
// $Id: RochesterMuonCorrector.cc,v 1.2 2012/10/10 16:54:53 gpetrucc Exp $
//

/**
  \class    modules::RochesterMuonCorrectorT RochesterMuonCorrectorT.h "MuonAnalysis/MuonAssociators/interface/RochesterMuonCorrectorT.h"
  \brief    Applies Rochester corrections to muons            
  \author   Giovanni Petrucciani
  \version  $Id: RochesterMuonCorrector.cc,v 1.2 2012/10/10 16:54:53 gpetrucc Exp $
*/


#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"

#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Muon.h"

#include "WWAnalysis/AnalysisStep/src/rochcor.h"
#include "WWAnalysis/AnalysisStep/src/rochcor2012.h"
#include "DataFormats/MuonReco/interface/MuonCocktails.h"

namespace modules {

  template<typename T>
  class RochesterMuonCorrectorT : public edm::EDProducer {
    public:
      explicit RochesterMuonCorrectorT(const edm::ParameterSet & iConfig);
      virtual ~RochesterMuonCorrectorT() { }

      virtual void produce(edm::Event & iEvent, const edm::EventSetup & iSetup);

    private:
      /// Labels for input collections
      edm::InputTag src_;
    
      /// Rochester corrector
#if ROOT_VERSION_CODE <  ROOT_VERSION(5,30,00)
      rochcor corrector_;
#else
      rochcor2012 corrector_;
#endif

      bool doRochester_;
      bool doNewTuneP_;
  };

} // namespace

template<typename T>
modules::RochesterMuonCorrectorT<T>::RochesterMuonCorrectorT(const edm::ParameterSet & iConfig) :
    src_(iConfig.getParameter<edm::InputTag>("src")),
    doRochester_(iConfig.existsAs<bool>("doRochesterCorrection") ? iConfig.getParameter<bool>("doRochesterCorrection") : true),
    doNewTuneP_(iConfig.existsAs<bool>("doNewTuneP") ? iConfig.getParameter<bool>("doNewTuneP") : false)
{
    produces<std::vector<T> >(); 
#if ROOT_VERSION_CODE <  ROOT_VERSION(5,30,00)
    std::cout << "Compiling in CMSSW 4.X series or earlier: will use 2011 corrections." << std::endl;
#else
    std::cout << "Compiling in CMSSW 5.X series or later: will use 2012 corrections." << std::endl;
#endif
}

template<typename T>
void 
modules::RochesterMuonCorrectorT<T>::produce(edm::Event & iEvent, const edm::EventSetup & iSetup) {
    using namespace edm;
    using namespace std;

    Handle<View<T> > src;
    iEvent.getByLabel(src_, src);

    unsigned int nsrc = src->size();
    auto_ptr<vector<T> > out(new vector<T>());
    out->reserve(nsrc);

    unsigned int run = iEvent.id().run(); 

    TLorentzVector p4;
    for (unsigned int i = 0; i < nsrc; ++i) {
        const T &mu = (*src)[i];

        p4.SetPtEtaPhiM(mu.pt(), mu.eta(), mu.phi(), mu.mass());

        if (doNewTuneP_) {
            reco::TrackRef tk = (muon::tevOptimized(mu, 200, 17., 40., 0.25)).first; 
            p4.SetPtEtaPhiM(tk->pt(), tk->eta(), tk->phi(), mu.mass());
        } 

        if (doRochester_) {
            float qterr = 0; // not used yet, will try later
            if (run == 1) {
                corrector_.momcor_mc(p4, mu.charge(), 0.0, 0, qterr);
            } else {
                corrector_.momcor_data(p4, mu.charge(), 0.0, (run <= 173692 || run >= 190000) ? 0 : 1, qterr);
            }
        }

        out->push_back(mu);
        out->back().setP4(reco::Particle::PolarLorentzVector(p4.Pt(), p4.Eta(), p4.Phi(), mu.mass()));
    }

    iEvent.put(out);
}


namespace modules {
    //typedef modules::RochesterMuonCorrectorT<reco::Muon>  RochesterMuonCorrector;
    typedef modules::RochesterMuonCorrectorT<pat::Muon>   RochesterPATMuonCorrector;
}

#include "FWCore/Framework/interface/MakerMacros.h"
using namespace modules;
//DEFINE_FWK_MODULE(RochesterMuonCorrector);
DEFINE_FWK_MODULE(RochesterPATMuonCorrector);
