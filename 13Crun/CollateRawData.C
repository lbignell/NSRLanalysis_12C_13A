// THIS IS A MACRO, DON'T TRY TO COMPILE!
{
  //gSystem->Exec("echo New Data set! The time is...");
  //gSystem->Exec("date");
  //TChain* TheChain1 = new TChain("FADCData");
  //for(int num = 5461; num<5562; num++){
    //TheChain1->Add(TString::Format("rootoutputfile%i.root",num));
  //}
  //Get files together and do some very elementary analysis.
  //TheChain1->Process("SimpleSumIntegralv2.C+");
  //gSystem->Exec("mv SimpleIntegral.root SimpleIntegral_5461_5561.root");
  //TFile* f1 = new TFile("SimpleIntegral_5461_5561.root");
  //Results->Process("DimaBaselineRemoval.C+");
  //gSystem->Exec("mv DimaBLsub.root DimaBLsub_5461_5561.root");
  //Results->Process("BaselineRemovalv3.C+");
  //gSystem->Exec("mv BLsubtractedv3.root BaselineSubtractedv3_5461_5561.root");
  
  gSystem->Exec("echo New Data set! The time is...");
  gSystem->Exec("date");
  //gSystem->Exec("rm SimpleIntegral.root");
  TChain* TheChain1 = new TChain("FADCData");
  for(int num = 5461; num<5562; num++){
    TheChain1->Add(TString::Format("../../../wblsdaq/beamrun2/rootoutputfile%i.root",num));
  }
  TheChain1->Process("SimpleSumIntegralv2.C+");
  gSystem->Exec("mv SimpleIntegral.root SimpleIntegral_5461_5561.root");
  
  //gSystem->Exec("echo New Data set! The time is...");
  //gSystem->Exec("date");
  //TChain* TheChain2 = new TChain("FADCData");
  //for(int num = 5562; num<5697; num++){
  //TheChain2->Add(TString::Format("../../../wblsdaq/beamrun2/rootoutputfile%i.root",num));
  //}
  //TheChain2->Process("SimpleSumIntegralv2.C+");
  //gSystem->Exec("mv SimpleIntegral.root SimpleIntegral_5562_5697.root");
 //TFile* f2 = new TFile("SimpleIntegral_5562_5697.root");
  //Results->Process("DimaBaselineRemoval.C+");
  //gSystem->Exec("mv DimaBLsub.root DimaBLsub_5562_5697.root");
  //Results->Process("BaselineRemovalv3.C+");
  //gSystem->Exec("mv BLsubtractedv3.root BaselineSubtractedv3_5562_5697.root");

  gSystem->Exec("echo New Data set! The time is...");
  gSystem->Exec("date");
  //gSystem->Exec("rm SimpleIntegral.root");
  TChain* TheChain2 = new TChain("FADCData");
  for(int num = 5562; num<5697; num++){
    TheChain2->Add(TString::Format("../../../wblsdaq/beamrun2/rootoutputfile%i.root",num));
  }
  TheChain2->Process("SimpleSumIntegralv2.C+");
  gSystem->Exec("mv SimpleIntegral.root SimpleIntegral_5562_5697.root");  

  //gSystem->Exec("echo New Data set! The time is...");
  //gSystem->Exec("date");
  //gSystem->Exec("rm SimpleIntegral.root");
  //TChain* TheChain3 = new TChain("FADCData");
  //for(int num = 5697; num<5803; num++){
  //TheChain3->Add(TString::Format("../../../wblsdaq/beamrun2/rootoutputfile%i.root",num));
  //}
  //TheChain3->Process("SimpleSumIntegralv2.C+");
  //gSystem->Exec("mv SimpleIntegral.root SimpleIntegral_5697_5803.root");
  //TFile* f3 = new TFile("SimpleIntegral_5697_5803.root");
  //Results->Process("DimaBaselineRemoval.C+");
  //gSystem->Exec("mv DimaBLsub.root DimaBLsub_5697_5803.root");
  //Results->Process("BaselineRemovalv3.C+");
  //gSystem->Exec("mv BLsubtractedv3.root BaselineSubtractedv3_5697_5803.root");

  gSystem->Exec("echo New Data set! The time is...");
  gSystem->Exec("date");
  //gSystem->Exec("rm SimpleIntegral.root");
  TChain* TheChain3 = new TChain("FADCData");
  for(int num = 5697; num<5803; num++){
    TheChain3->Add(TString::Format("../../../wblsdaq/beamrun2/rootoutputfile%i.root",num));
  }
  TheChain3->Process("SimpleSumIntegralv2.C+");
  gSystem->Exec("mv SimpleIntegral.root SimpleIntegral_5697_5803.root"); 

  //gSystem->Exec("echo New Data set! The time is...");
  //gSystem->Exec("date");
  //gSystem->Exec("rm SimpleIntegral.root");
  //TChain* TheChain4 = new TChain("FADCData");
  //for(int num = 5803; num<5927; num++){
  //TheChain4->Add(TString::Format("../../../wblsdaq/beamrun2/rootoutputfile%i.root",num));
  //}
  //TheChain4->Process("SimpleSumIntegralv2.C+");
  //gSystem->Exec("mv SimpleIntegral.root SimpleIntegral_5803_5926.root");
  //TFile* f4 = new TFile("SimpleIntegral.root");
  //Results->Process("DimaBaselineRemoval.C+");
  //gSystem->Exec("mv DimaBLsub.root DimaBLsub_5803_5926.root");
 //Results->Process("BaselineRemovalv3.C+");
 //gSystem->Exec("mv BLsubtractedv3.root BaselineSubtractedv3_5803_5926.root");

  gSystem->Exec("echo New Data set! The time is...");
  gSystem->Exec("date");
  //gSystem->Exec("rm SimpleIntegral.root");
  TChain* TheChain4 = new TChain("FADCData");
  for(int num = 5803; num<5927; num++){
    TheChain4->Add(TString::Format("../../../wblsdaq/beamrun2/rootoutputfile%i.root",num));
  }
  TheChain4->Process("SimpleSumIntegralv2.C+");
  gSystem->Exec("mv SimpleIntegral.root SimpleIntegral_5803_5926.root");

  //gSystem->Exec("echo New Data set! The time is...");
  //gSystem->Exec("date");
  //gSystem->Exec("rm SimpleIntegral.root");
  //TChain* TheChain5 = new TChain("FADCData");
  //for(int num = 5927; num<5938; num++){
  //TheChain5->Add(TString::Format("../../../wblsdaq/beamrun2/rootoutputfile%i.root",num));
  //}
  //TheChain5->Process("SimpleSumIntegralv2.C+");
  //gSystem->Exec("mv SimpleIntegral.root SimpleIntegral_5927_5937.root");
  //TFile* f5 = new TFile("SimpleIntegral.root");
  //Results->Process("DimaBaselineRemoval.C+");
  //gSystem->Exec("mv DimaBLsub.root DimaBLsub_5927_5937.root");
  //Results->Process("BaselineRemovalv3.C+");
  //gSystem->Exec("mv BLsubtractedv3.root BaselineSubtractedv3_5927_5937.root");
 
  gSystem->Exec("echo New Data set! The time is...");
  gSystem->Exec("date");
  //gSystem->Exec("rm SimpleIntegral.root");
  TChain* TheChain6 = new TChain("FADCData");
  for(int num = 5937; num<6068; num++){
    TheChain6->Add(TString::Format("../../../wblsdaq/beamrun2/rootoutputfile%i.root",num));
  }
  TheChain6->Process("SimpleSumIntegralv2.C+");
  gSystem->Exec("mv SimpleIntegral.root SimpleIntegral_5937_6067.root");
  //TFile* f6 = new TFile("SimpleIntegral.root");
  //Results->Process("DimaBaselineRemoval.C+");
  //gSystem->Exec("mv DimaBLsub.root DimaBLsub_5937_6067.root");
  //Results->Process("BaselineRemovalv3.C+");
  //gSystem->Exec("mv BLsubtractedv3.root BaselineSubtractedv3_5937_6067.root");
 
  gSystem->Exec("echo New Data set! The time is...");
  gSystem->Exec("date");
  //gSystem->Exec("rm SimpleIntegral.root");
  TChain* TheChain7 = new TChain("FADCData");
  for(int num = 6068; num<6174; num++){
    TheChain7->Add(TString::Format("../../../wblsdaq/beamrun2/rootoutputfile%i.root",num));
  }
  TheChain7->Process("SimpleSumIntegralv2.C+");
  gSystem->Exec("mv SimpleIntegral.root SimpleIntegral_6068_6173.root");
  //TFile* f7 = new TFile("SimpleIntegral.root");
  //Results->Process("DimaBaselineRemoval.C+");
  //gSystem->Exec("mv DimaBLsub.root DimaBLsub_6068_6173.root");
  //Results->Process("BaselineRemovalv3.C+");
  //gSystem->Exec("mv BLsubtractedv3.root BaselineSubtractedv3_6068_6173.root");
 
  gSystem->Exec("echo New Data set! The time is...");
  gSystem->Exec("date");
  //gSystem->Exec("rm SimpleIntegral.root");
  TChain* TheChain8 = new TChain("FADCData");
  for(int num = 6174; num<6302; num++){
    TheChain8->Add(TString::Format("../../../wblsdaq/beamrun2/rootoutputfile%i.root",num));
  }
  TheChain8->Process("SimpleSumIntegralv2.C+");
  gSystem->Exec("mv SimpleIntegral.root SimpleIntegral_6174_6301.root");
  //TFile* f8 = new TFile("SimpleIntegral.root");
  //Results->Process("DimaBaselineRemoval.C+");
  //gSystem->Exec("mv DimaBLsub.root DimaBLsub_6174_6301.root");
  //Results->Process("BaselineRemovalv3.C+");
  //gSystem->Exec("mv BLsubtractedv3.root BaselineSubtractedv3_6174_6301.root");
 
  gSystem->Exec("echo New Data set! The time is...");
  gSystem->Exec("date");
  //gSystem->Exec("rm SimpleIntegral.root");
  TChain* TheChain9 = new TChain("FADCData");
  for(int num = 6302; num<6423; num++){
    TheChain9->Add(TString::Format("../../../wblsdaq/beamrun2/rootoutputfile%i.root",num));
  }
  TheChain9->Process("SimpleSumIntegralv2.C+");
  gSystem->Exec("mv SimpleIntegral.root SimpleIntegral_6302_6422.root");
  //TFile* f9 = new TFile("SimpleIntegral.root");
  //Results->Process("DimaBaselineRemoval.C+");
  //gSystem->Exec("mv DimaBLsub.root DimaBLsub_6302_6422.root");
  //Results->Process("BaselineRemovalv3.C+");
  //gSystem->Exec("mv BLsubtractedv3.root BaselineSubtractedv3_6302_6422.root");
 
  gSystem->Exec("echo New Data set! The time is...");
  gSystem->Exec("date");
  //gSystem->Exec("rm SimpleIntegral.root");
  TChain* TheChain10 = new TChain("FADCData");
  for(int num = 6423; num<6424; num++){
    TheChain10->Add(TString::Format("../../../wblsdaq/beamrun2/rootoutputfile%i.root",num));
  }
  TheChain10->Process("SimpleSumIntegralv2.C+");
  gSystem->Exec("mv SimpleIntegral.root SimpleIntegral_6423.root");
  //TFile* f10 = new TFile("SimpleIntegral.root");
  //Results->Process("DimaBaselineRemoval.C+");
  //gSystem->Exec("mv DimaBLsub.root DimaBLsub_6423.root");
  //Results->Process("BaselineRemovalv3.C+");
  //gSystem->Exec("mv BLsubtractedv3.root BaselineSubtractedv3_6423.root");
 
  gSystem->Exec("echo New Data set! The time is...");
  gSystem->Exec("date");
  //gSystem->Exec("rm SimpleIntegral.root");
  TChain* TheChain11 = new TChain("FADCData");
  for(int num = 6424; num<6425; num++){
    TheChain11->Add(TString::Format("../../../wblsdaq/beamrun2/rootoutputfile%i.root",num));
  }
  TheChain11->Process("SimpleSumIntegralv2.C+");
  gSystem->Exec("mv SimpleIntegral.root SimpleIntegral_6424.root");
  //TFile* f11 = new TFile("SimpleIntegral.root");
  //Results->Process("DimaBaselineRemoval.C+");
  //gSystem->Exec("mv DimaBLsub.root DimaBLsub_6424.root");
  //Results->Process("BaselineRemovalv3.C+");
  //gSystem->Exec("mv BLsubtractedv3.root BaselineSubtractedv3_6424.root");
 
  gSystem->Exec("echo New Data set! The time is...");
  gSystem->Exec("date");
  //gSystem->Exec("rm SimpleIntegral.root");
  TChain* TheChain12 = new TChain("FADCData");
  for(int num = 6425; num<6426; num++){
    TheChain12->Add(TString::Format("../../../wblsdaq/beamrun2/rootoutputfile%i.root",num));
  }
  TheChain12->Process("SimpleSumIntegralv2.C+");
  gSystem->Exec("mv SimpleIntegral.root SimpleIntegral_6425.root");
  //TFile* f12 = new TFile("SimpleIntegral.root");
  //Results->Process("DimaBaselineRemoval.C+");
  //gSystem->Exec("mv DimaBLsub.root DimaBLsub_6425.root");
  //Results->Process("BaselineRemovalv3.C+");
  //gSystem->Exec("mv BLsubtractedv3.root BaselineSubtractedv3_6425.root");
 
  gSystem->Exec("echo New Data set! The time is...");
  gSystem->Exec("date");
  //gSystem->Exec("rm SimpleIntegral.root");
  TChain* TheChain13 = new TChain("FADCData");
  for(int num = 6426; num<6427; num++){
    TheChain13->Add(TString::Format("../../../wblsdaq/beamrun2/rootoutputfile%i.root",num));
  }
  TheChain13->Process("SimpleSumIntegralv2.C+");
  gSystem->Exec("mv SimpleIntegral.root SimpleIntegral_6426.root");
  // TFile* f13 = new TFile("SimpleIntegral.root");
  //Results->Process("DimaBaselineRemoval.C+");
  //gSystem->Exec("mv DimaBLsub.root DimaBLsub_6426.root");
  //Results->Process("BaselineRemovalv3.C+");
  //gSystem->Exec("mv BLsubtractedv3.root BaselineSubtractedv3_6426.root");
 
}
