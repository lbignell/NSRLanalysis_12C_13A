//This function runs the algorithm, with the current parameter settings.
//Then it runs the median function. The AvgWfm and Median... results are saved.
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TSystem.h"
#include <sstream>
#include <iostream>

using namespace std;

void RunAlgorithm(string type, string en){
  TString s = TString::Format("echo Running %s data at %s",
			      type.c_str(), en.c_str());
  gSystem->Exec(s);
  gSystem->Exec("echo New Data set! The time is...");
  gSystem->Exec("date");

  TFile* f1 = new TFile(TString::Format("%s_%s.root",
					type.c_str(), en.c_str()));
  TTree* Results = (TTree*)f1->Get("Results");

  Results->Process("BaselineRemovalv5.C+");

  TString command = TString::Format("mv AvgWfms.root AvgWfms_%s_%s.root",
				    type.c_str(), en.c_str());
  gSystem->Exec(command);

  TString command1 = TString::Format("mv BLsubtractedv5.root BLsub_%s_%s.root",
				     type.c_str(), en.c_str());
  gSystem->Exec(command1);

  //truncate 'MeV' from the beam energy argument
  size_t pos = en.find("MeV");
  cout << "Beam Energy = " << en.substr(0,pos) << " MeV" << endl;
  TString command1a =
    TString::Format(".x MedianSimpleSaved.C+(\"BLsub_%s_%s.root\", %s)",
		    type.c_str(), en.c_str(), en.substr(0,pos).c_str());
  gROOT->ProcessLine(command1a);

  TString command2 =
    TString::Format("mv MedianBLsub* Median_%s_%s.root",
		    type.c_str(), en.c_str());
  gSystem->Exec(command2);

  f1->Close();

}
