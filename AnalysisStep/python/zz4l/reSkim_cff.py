import FWCore.ParameterSet.Config as cms

muons4skim = cms.EDFilter("PATMuonSelector",
    src = cms.InputTag("boostedMuons"),
    cut = cms.string("isTrackerMuon||isGlobalMuon"), #pt > 5 && abs(eta) < 2.4"),
)
electrons4skim = cms.EDFilter("PATElectronSelector",
    src = cms.InputTag("boostedElectrons"),
    cut = cms.string(""), #pt > 7 && abs(eta) < 2.5"),
)
leptons4skim = cms.EDProducer("CandViewMerger",
    src = cms.VInputTag( cms.InputTag("muons4skim"),  cms.InputTag("electrons4skim"), )
)
dileptons4skim = cms.EDProducer("CandViewShallowCloneCombiner",
    decay = cms.string('leptons4skim leptons4skim'),
    cut = cms.string('deltaR(daughter(0).eta,daughter(0).phi,daughter(1).eta,daughter(1).phi) > 0.01'),
    checkCharge = cms.bool(False)
)

skim2010 = cms.EDFilter("CandViewSelector",
    src = cms.InputTag("dileptons4skim"),
    cut = cms.string('min(daughter(0).pt,daughter(1).pt) > 10 && ' +
                     'max(daughter(0).pt,daughter(1).pt) > 20'),
    filter = cms.bool(True),
)

skim40 = cms.EDFilter("CandViewSelector",
    src = cms.InputTag("dileptons4skim"),
    cut = cms.string('mass > 40 && daughter(0).pdgId = -daughter(1).pdgId'), ## and SF/OS
    filter = cms.bool(True),
)

reskim = cms.Sequence(muons4skim + electrons4skim + leptons4skim + dileptons4skim + skim2010 + skim40)
