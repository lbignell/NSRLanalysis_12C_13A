//This function will run though all of the BLsub_* files and apply cuts, saving
//histograms to an output .root file as it goes.
#include "TROOT.h"
#include "TH1.h"
#include "TMath.h"
#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"
#include <iostream>
#include "TString.h"
#include <fstream>
#include <vector>
#include "TObjArray.h"

using namespace std;

void AllManualHistogram(string outfilename){

  string theLine;

  TObjArray Hlist(0);

  //f->Close();

  //////////////////////////////////////////////////////////////////////////////
  //Water
  //T1, 2 GeV
  TH1D* w_T1_2000 =
    new TH1D("w_T1_2000", "Water, Tub 1, 2000 MeV;Charge (AU);Counts",
	     100000, 0., 10000.);
  theLine = ".x ManualHistogram.C+(\"BLsub_Water_2000MeV.root\",0,"
    "w_T1_2000,1310,1350,18000,1310,1350,130000,1265,1330,148,1)";
  gROOT->ProcessLine(theLine.c_str());
  //f->Open(outfilename.c_str(), "UPDATE");
  //w_T1_2000->Write("w_T1_2000");
  Hlist.Add(w_T1_2000);
  //f->Close();

  //T2, 2 GeV
  TH1D* w_T2_2000 =
    new TH1D("w_T2_2000", "Water, Tub 2, 2000 MeV;Charge (AU);Counts",
	     100000, 0., 10000.);
  theLine = ".x ManualHistogram.C+(\"BLsub_Water_2000MeV.root\",1,"
    "w_T2_2000,1310,1350,18000,1310,1350,130000,1265,1330,133,1)";
  gROOT->ProcessLine(theLine.c_str());
  //f->Open(outfilename.c_str(), "UPDATE");
  //w_T2_2000->Write("w_T2_2000");
  Hlist.Add(w_T2_2000);
  //f->Close();

  //T1, 475 MeV
  TH1D* w_T1_475 =
    new TH1D("w_T1_475", "Water, Tub 1, 475 MeV;Charge (AU);Counts",
	     100000, 0., 10000.);
  theLine = ".x ManualHistogram.C+(\"BLsub_Water_475MeV.root\",0,"
    "w_T1_475,1310,1350,30000,1310,1350,300000,1265,1330,148,1)";
  gROOT->ProcessLine(theLine.c_str());
  //f->Open(outfilename.c_str(), "UPDATE");
  //w_T1_475->Write("w_T1_475");
  Hlist.Add(w_T1_475);
  //f->Close();

  //T2, 475 MeV
  TH1D* w_T2_475 =
    new TH1D("w_T2_475", "Water, Tub 2, 475 MeV;Charge (AU);Counts",
	     100000, 0., 10000.);
  theLine = ".x ManualHistogram.C+(\"BLsub_Water_475MeV.root\",1,"
    "w_T2_475,1310,1350,30000,1310,1350,300000,1265,1330,133,1)";
  gROOT->ProcessLine(theLine.c_str());
  //f->Open(outfilename.c_str(), "UPDATE");
  //w_T2_475->Write("w_T2_475");
  Hlist.Add(w_T2_475);
  //f->Close();

  //T1, 210 MeV
  TH1D* w_T1_210 =
    new TH1D("w_T1_210", "Water, Tub 1, 210 MeV;Charge (AU);Counts",
	     100000, 0., 10000.);
  theLine = ".x ManualHistogram.C+(\"BLsub_Water_210MeV.root\",0,"
    "w_T1_210,1310,1350,50000,1310,1350,560000,1265,1330,148,1)";
  gROOT->ProcessLine(theLine.c_str());
  //f->Open(outfilename.c_str(), "UPDATE");
  //w_T1_210->Write("w_T1_210");
  Hlist.Add(w_T1_210);
  //f->Close();

  //T2, 210 MeV
  TH1D* w_T2_210 =
    new TH1D("w_T2_210", "Water, Tub 2, 210 MeV;Charge (AU);Counts",
	     100000, 0., 10000.);
  theLine = ".x ManualHistogram.C+(\"BLsub_Water_210MeV.root\",1,"
    "w_T2_210,1310,1350,50000,1310,1350,560000,1265,1330,133,1)";
  gROOT->ProcessLine(theLine.c_str());
  //f->Open(outfilename.c_str(), "UPDATE");
  //w_T2_210->Write("w_T2_210");
  Hlist.Add(w_T2_210);
  //f->Close();
  //////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////
  //WbLS, 1%
  //T1, 2 GeV
  TH1D* WbLS_1pc_T1_2000 =
    new TH1D("WbLS_1pc_T1_2000", "1% WbLS, Tub 1, 2000 MeV;Charge (AU);Counts",
	     100000, 0., 10000.);
  theLine = ".x ManualHistogram.C+(\"BLsub_WbLS1Pc_2000MeV.root\",0,"
    "WbLS_1pc_T1_2000,1310,1350,18000,1310,1350,130000,1265,1330,148,1)";
  gROOT->ProcessLine(theLine.c_str());
  //f->Open(outfilename.c_str(), "UPDATE");
  //WbLS_1pc_T1_2000->Write();
  Hlist.Add(WbLS_1pc_T1_2000);
  //f->Close();

  //T2, 2 GeV
  TH1D* WbLS_1pc_T2_2000 =
    new TH1D("WbLS_1pc_T2_2000", "1% WbLS, Tub 2, 2000 MeV;Charge (AU);Counts",
	     100000, 0., 10000.);
  theLine = ".x ManualHistogram.C+(\"BLsub_WbLS1Pc_2000MeV.root\",1,"
    "WbLS_1pc_T2_2000,1310,1350,18000,1310,1350,130000,1265,1330,133,1)";
  gROOT->ProcessLine(theLine.c_str());
  //f->Open(outfilename.c_str(), "UPDATE");
  //WbLS_1pc_T2_2000->Write("WbLS_1pc_T2_2000");
  Hlist.Add(WbLS_1pc_T2_2000);
  //f->Close();

  //T1, 475 MeV
  TH1D* WbLS_1pc_T1_475 =
    new TH1D("WbLS_1pc_T1_475", "1% WbLS, Tub 1, 475 MeV;Charge (AU);Counts",
	     100000, 0., 10000.);
  theLine = ".x ManualHistogram.C+(\"BLsub_WbLS1Pc_475MeV.root\",0,"
    "WbLS_1pc_T1_475,1310,1350,30000,1310,1350,300000,1265,1330,148,1)";
  gROOT->ProcessLine(theLine.c_str());
  //f->Open(outfilename.c_str(), "UPDATE");
  //WbLS_1pc_T1_475->Write("WbLS_1pc_T1_475");
  Hlist.Add(WbLS_1pc_T1_475);
  //f->Close();

  //T2, 475 MeV
  TH1D* WbLS_1pc_T2_475 =
    new TH1D("WbLS_1pc_T2_475", "1% WbLS, Tub 2, 475 MeV;Charge (AU);Counts",
	     100000, 0., 10000.);
  theLine = ".x ManualHistogram.C+(\"BLsub_WbLS1Pc_475MeV.root\",1,"
    "WbLS_1pc_T2_475,1310,1350,30000,1310,1350,300000,1265,1330,133,1)";
  gROOT->ProcessLine(theLine.c_str());
  //f->Open(outfilename.c_str(), "UPDATE");
  //WbLS_1pc_T2_475->Write("WbLS_1pc_T2_475");
  Hlist.Add(WbLS_1pc_T2_475);
  //f->Close();

  //T1, 210 MeV
  TH1D* WbLS_1pc_T1_210 =
    new TH1D("WbLS_1pc_T1_210", "1% WbLS, Tub 1, 210 MeV;Charge (AU);Counts",
	     100000, 0., 10000.);
  theLine = ".x ManualHistogram.C+(\"BLsub_WbLS1Pc_210MeV.root\",0,"
    "WbLS_1pc_T1_210,1310,1350,50000,1310,1350,560000,1265,1330,148,1)";
  gROOT->ProcessLine(theLine.c_str());
  //f->Open(outfilename.c_str(), "UPDATE");
  //WbLS_1pc_T1_210->Write("WbLS_1pc_T1_210");
  Hlist.Add(WbLS_1pc_T1_210);
  //f->Close();

  //T2, 210 MeV
  TH1D* WbLS_1pc_T2_210 =
    new TH1D("WbLS_1pc_T2_210", "1% WbLS, Tub 2, 210 MeV;Charge (AU);Counts",
	     100000, 0., 10000.);
  theLine = ".x ManualHistogram.C+(\"BLsub_WbLS1Pc_210MeV.root\",1,"
    "WbLS_1pc_T2_210,1310,1350,50000,1310,1350,560000,1265,1330,133,1)";
  gROOT->ProcessLine(theLine.c_str());
  //f->Open(outfilename.c_str(), "UPDATE");
  //WbLS_1pc_T2_210->Write("WbLS_1pc_T2_210");
  Hlist.Add(WbLS_1pc_T2_210);
  //f->Close();
  //////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////
  //0.4% WbLS
  //T1, 2 GeV
  TH1D* WbLS_0p4pc_T1_2000 =
    new TH1D("WbLS_0p4pc_T1_2000", "0.4% WbLS, Tub 1, 2000 MeV;Charge (AU);Counts",
	     100000, 0., 10000.);
  theLine = ".x ManualHistogram.C+(\"BLsub_WbLSp4Pc_2000MeV.root\",0,"
    "WbLS_0p4pc_T1_2000,1310,1350,18000,1310,1350,130000,1265,1330,148,1)";
  gROOT->ProcessLine(theLine.c_str());
  //f->Open(outfilename.c_str(), "UPDATE");
  //WbLS_0p4pc_T1_2000->Write("WbLS_0p4pc_T1_2000");
  Hlist.Add(WbLS_0p4pc_T1_2000);
  //f->Close();

  //T2, 2 GeV
  TH1D* WbLS_0p4pc_T2_2000 =
    new TH1D("WbLS_0p4pc_T2_2000", "0.4% WbLS, Tub 2, 2000 MeV;Charge (AU);Counts",
	     100000, 0., 10000.);
  theLine = ".x ManualHistogram.C+(\"BLsub_WbLSp4Pc_2000MeV.root\",1,"
    "WbLS_0p4pc_T2_2000,1310,1350,18000,1310,1350,130000,1265,1330,133,1)";
  gROOT->ProcessLine(theLine.c_str());
  //f->Open(outfilename.c_str(), "UPDATE");
  //WbLS_0p4pc_T2_2000->Write("WbLS_0p4pc_T2_2000");
  Hlist.Add(WbLS_0p4pc_T2_2000);
  //f->Close();

  //T1, 475 MeV
  TH1D* WbLS_0p4pc_T1_475 =
    new TH1D("WbLS_0p4pc_T1_475", "0.4% WbLS, Tub 1, 475 MeV;Charge (AU);Counts",
	     100000, 0., 10000.);
  theLine = ".x ManualHistogram.C+(\"BLsub_WbLSp4Pc_475MeV.root\",0,"
    "WbLS_0p4pc_T1_475,1310,1350,30000,1310,1350,300000,1265,1330,148,1)";
  gROOT->ProcessLine(theLine.c_str());
  //f->Open(outfilename.c_str(), "UPDATE");
  //WbLS_0p4pc_T1_475->Write("WbLS_0p4pc_T1_475");
  Hlist.Add(WbLS_0p4pc_T1_475);
  //f->Close();

  //T2, 475 MeV
  TH1D* WbLS_0p4pc_T2_475 =
    new TH1D("WbLS_0p4pc_T2_475", "0.4% WbLS, Tub 2, 475 MeV;Charge (AU);Counts",
	     100000, 0., 10000.);
  theLine = ".x ManualHistogram.C+(\"BLsub_WbLSp4Pc_475MeV.root\",1,"
    "WbLS_0p4pc_T2_475,1310,1350,30000,1310,1350,300000,1265,1330,133,1)";
  gROOT->ProcessLine(theLine.c_str());
  //f->Open(outfilename.c_str(), "UPDATE");
  //WbLS_0p4pc_T2_475->Write("WbLS_0p4pc_T2_475");
  Hlist.Add(WbLS_0p4pc_T2_475);
  //f->Close();

  //T1, 210 MeV
  TH1D* WbLS_0p4pc_T1_210 =
    new TH1D("WbLS_0p4pc_T1_210", "0.4% WbLS, Tub 1, 210 MeV;Charge (AU);Counts",
	     100000, 0., 10000.);
  theLine = ".x ManualHistogram.C+(\"BLsub_WbLSp4Pc_210MeV.root\",0,"
    "WbLS_0p4pc_T1_210,1310,1350,50000,1310,1350,560000,1265,1330,148,1)";
  gROOT->ProcessLine(theLine.c_str());
  //f->Open(outfilename.c_str(), "UPDATE");
  //WbLS_0p4pc_T1_210->Write("WbLS_0p4pc_T1_210");
  Hlist.Add(WbLS_0p4pc_T1_210);
  //f->Close();

  //T2, 210 MeV
  TH1D* WbLS_0p4pc_T2_210 =
    new TH1D("WbLS_0p4pc_T2_210", "0.4% WbLS, Tub 2, 210 MeV;Charge (AU);Counts",
	     100000, 0., 10000.);
  theLine = ".x ManualHistogram.C+(\"BLsub_WbLSp4Pc_210MeV.root\",1,"
    "WbLS_0p4pc_T2_210,1310,1350,50000,1310,1350,560000,1265,1330,133,1)";
  gROOT->ProcessLine(theLine.c_str());
  //f->Open(outfilename.c_str(), "UPDATE");
  //WbLS_0p4pc_T2_210->Write("WbLS_0p4pc_T2_210");
  Hlist.Add(WbLS_0p4pc_T2_210);
  //f->Close();
  //////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////
  //Pure LS
  //T1, 2 GeV
  TH1D* WbLS_PureLS_T1_2000 =
    new TH1D("WbLS_PureLS_T1_2000", "Pure LS, Tub 1, 2000 MeV;Charge (AU);Counts",
	     100000, 0., 10000.);
  theLine = ".x ManualHistogram.C+(\"BLsub_LS_2000MeV.root\",0,"
    "WbLS_PureLS_T1_2000,1310,1350,18000,1310,1350,130000,1265,1330,148,10)";
  gROOT->ProcessLine(theLine.c_str());
  //f->Open(outfilename.c_str(), "UPDATE");
  //WbLS_PureLS_T1_2000->Write("WbLS_PureLS_T1_2000");
  Hlist.Add(WbLS_PureLS_T1_2000);
  //f->Close();

  //T2, 2 GeV
  TH1D* WbLS_PureLS_T2_2000 =
    new TH1D("WbLS_PureLS_T2_2000", "Pure LS, Tub 2, 2000 MeV;Charge (AU);Counts",
	     100000, 0., 10000.);
  theLine = ".x ManualHistogram.C+(\"BLsub_LS_2000MeV.root\",1,"
    "WbLS_PureLS_T2_2000,1310,1350,18000,1310,1350,130000,1265,1330,133,5)";
  gROOT->ProcessLine(theLine.c_str());
  //f->Open(outfilename.c_str(), "UPDATE");
  //WbLS_PureLS_T2_2000->Write("WbLS_PureLS_T2_2000");
  Hlist.Add(WbLS_PureLS_T2_2000);
  //f->Close();

  //T1, 475 MeV
  TH1D* WbLS_PureLS_T1_475 =
    new TH1D("WbLS_PureLS_T1_475", "Pure LS, Tub 1, 475 MeV;Charge (AU);Counts",
	     100000, 0., 10000.);
  theLine = ".x ManualHistogram.C+(\"BLsub_LS_475MeV.root\",0,"
    "WbLS_PureLS_T1_475,1310,1350,30000,1310,1350,300000,1265,1330,148,10)";
  gROOT->ProcessLine(theLine.c_str());
  //f->Open(outfilename.c_str(), "UPDATE");
  //WbLS_PureLS_T1_475->Write("WbLS_PureLS_T1_475");
  Hlist.Add(WbLS_PureLS_T1_475);
  //f->Close();

  //T2, 475 MeV
  TH1D* WbLS_PureLS_T2_475 =
    new TH1D("WbLS_PureLS_T2_475", "Pure LS, Tub 2, 475 MeV;Charge (AU);Counts",
	     100000, 0., 10000.);
  theLine = ".x ManualHistogram.C+(\"BLsub_LS_475MeV.root\",1,"
    "WbLS_PureLS_T2_475,1310,1350,30000,1310,1350,300000,1265,1330,133,5)";
  gROOT->ProcessLine(theLine.c_str());
  //f->Open(outfilename.c_str(), "UPDATE");
  //WbLS_PureLS_T2_475->Write("WbLS_PureLS_T2_475");
  Hlist.Add(WbLS_PureLS_T2_475);
  //f->Close();

  //T1, 210 MeV
  TH1D* WbLS_PureLS_T1_210 =
    new TH1D("WbLS_PureLS_T1_210", "Pure LS, Tub 1, 210 MeV;Charge (AU);Counts",
	     100000, 0., 10000.);
  theLine = ".x ManualHistogram.C+(\"BLsub_LS_210MeV.root\",0,"
    "WbLS_PureLS_T1_210,1310,1350,50000,1310,1350,560000,1265,1330,148,10)";
  gROOT->ProcessLine(theLine.c_str());
  //f->Open(outfilename.c_str(), "UPDATE");
  //WbLS_PureLS_T1_210->Write("WbLS_PureLS_T1_210");
  Hlist.Add(WbLS_PureLS_T1_210);
  //f->Close();

  //T2, 210 MeV
  TH1D* WbLS_PureLS_T2_210 =
    new TH1D("WbLS_PureLS_T2_210", "Pure LS, Tub 2, 210 MeV;Charge (AU);Counts",
	     100000, 0., 10000.);
  theLine = ".x ManualHistogram.C+(\"BLsub_LS_210MeV.root\",1,"
    "WbLS_PureLS_T2_210,1310,1350,50000,1310,1350,560000,1265,1330,133,5)";
  gROOT->ProcessLine(theLine.c_str());
  //f->Open(outfilename.c_str(), "UPDATE");
  //WbLS_PureLS_T2_210->Write("WbLS_PureLS_T2_210");
  Hlist.Add(WbLS_PureLS_T2_210);
  //f->Close();
  //////////////////////////////////////////////////////////////////////////////
  cout << "Writing out file" << endl;
  TFile* f = new TFile(outfilename.c_str(), "RECREATE");
  Hlist.Write();
  f->Close();
}
