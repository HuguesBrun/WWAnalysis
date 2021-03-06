import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        'file:../SkimStep/latinosYieldSkim.root'
    )
)

process.chargedMetPrinter = cms.EDAnalyzer('ChargedMetPrinter')
process.p = cms.Path(process.chargedMetPrinter)
