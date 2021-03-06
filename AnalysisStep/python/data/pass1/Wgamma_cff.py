import FWCore.ParameterSet.Config as cms

maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
source = cms.Source ("PoolSource",fileNames = readFiles, secondaryFileNames = secFiles)
readFiles.extend( [
    'file:/nfs/bluearc/group/skims/hww/Wgamma/hwwSkim_1_1_EUC.root',
    'file:/nfs/bluearc/group/skims/hww/Wgamma/hwwSkim_2_1_Tgk.root',
    'file:/nfs/bluearc/group/skims/hww/Wgamma/hwwSkim_3_1_v2f.root',
] );


secFiles.extend( [
               ] )

