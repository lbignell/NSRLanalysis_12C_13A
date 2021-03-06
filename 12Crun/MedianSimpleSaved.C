#include "TROOT.h"
#include "TH1.h"
#include "TMath.h"
#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"
#include <iostream>
#include "TString.h"
#include <fstream>

using namespace std;

Double_t median1(TH1 *h1) { 
   //compute the median for 1-d histogram h1 
   Int_t nbins = h1->GetXaxis()->GetNbins(); 
   Double_t *x = new Double_t[nbins]; 
   Double_t *y = new Double_t[nbins]; 
   for (Int_t i=0;i<nbins;i++) {
      x[i] = h1->GetXaxis()->GetBinCenter(i+1); 
      y[i] = h1->GetBinContent(i+1); 
   } 
   Double_t median = TMath::Median(nbins,x,y); 
   delete [] x; 
   delete [] y; 
   return median; 
} 

void MedianSimpleSaved(const char* filename, int Energy) { 

  //cout << "Opening File... ";

  //Open the file
  TFile* f = new TFile(filename);

  //cout << "Done!" << endl << "Getting Tree... "; 

  TTree* ResultsTree = (TTree*)f->Get("Results");

  //cout << "Done!" << endl;

  //Check whether energy is 210/475/2000 MeV or LED run.
  const char* CutA;
  const char* CutB;

  if(Energy == 2000){
    CutA = "(1310<TimeSimple[2])&&(TimeSimple[2]<1380)&&(1310<TimeSimple[3])&&(TimeSimple[3]<1380)&&(18000<QDCsimple[2])&&(130000<QDCsimple[3])&&(1265<TimeSimple[0])&&(TimeSimple[0]<1330)";
    CutB = "(1310<TimeSimple[2])&&(TimeSimple[2]<1380)&&(1310<TimeSimple[3])&&(TimeSimple[3]<1380)&&(18000<QDCsimple[2])&&(130000<QDCsimple[3])&&(1265<TimeSimple[1])&&(TimeSimple[1]<1330)";
  }
  else if(Energy == 475){
    CutA = "(1310<TimeSimple[2])&&(TimeSimple[2]<1380)&&(1310<TimeSimple[3])&&(TimeSimple[3]<1380)&&(30000<QDCsimple[2])&&(300000<QDCsimple[3])&&(1265<TimeSimple[0])&&(TimeSimple[0]<1330)";
    CutB = "(1310<TimeSimple[2])&&(TimeSimple[2]<1380)&&(1310<TimeSimple[3])&&(TimeSimple[3]<1380)&&(30000<QDCsimple[2])&&(300000<QDCsimple[3])&&(1265<TimeSimple[1])&&(TimeSimple[1]<1330)";
  }
  else if(Energy == 210){
    CutA = "(1310<TimeSimple[2])&&(TimeSimple[2]<1380)&&(1310<TimeSimple[3])&&(TimeSimple[3]<1380)&&(35000<QDCsimple[2])&&(QDCsimple[2]<160000)&&(560000<QDCsimple[3])&&(1265<TimeSimple[0])&&(TimeSimple[0]<1330)";
    CutB = "(1310<TimeSimple[2])&&(TimeSimple[2]<1380)&&(1310<TimeSimple[3])&&(TimeSimple[3]<1380)&&(35000<QDCsimple[2])&&(QDCsimple[2]<160000)&&(560000<QDCsimple[3])&&(1265<TimeSimple[1])&&(TimeSimple[1]<1330)";
  }
  else if(Energy == 0){
    //LED measurements.
  }
  else{
    cout << "Warning, attempted to call MedianSimpleSaved with invalid energy"
	 << "Energy = " << Energy
	 << endl;
    return;
  }

  //cout << "Getting histos, etc... ";    

  TH1D* hnewBeamA;
  TCanvas* c4 = new TCanvas("LED ON, Beam A", filename, 4);
  //Get BeamON events for PMT A
  Long64_t nentriesBeamA = ResultsTree->Draw("QDCsimple[0]>>hnewBeamA(100000, 0., 0.)", CutA);
  hnewBeamA = (TH1D*)gDirectory->Get("hnewBeamA");
  Double_t medianBeamA = median1(hnewBeamA); 
  Double_t meanBeamA = hnewBeamA->GetMean();

  TH1D* hnewBeamB;
  TCanvas* c5 = new TCanvas("LED ON, Beam B", filename, 5);
  //Get BeamON events for PMT B
  Long64_t nentriesBeamB = ResultsTree->Draw("QDCsimple[1]>>hnewBeamB(100000, 0., 0.)", CutB);
  hnewBeamB = (TH1D*)gDirectory->Get("hnewBeamB");
  Double_t medianBeamB = median1(hnewBeamB); 
  Double_t meanBeamB = hnewBeamB->GetMean();

  //cout << "Done!" << endl;

  cout<<"---------------------------------------------------------------"<<endl
      << "Median Data for file: \t" << filename << endl
      <<"\tPMTA, Beam  \tPMTB, Beam" << endl
      << "Median \t" << medianBeamA << "\t" << medianBeamB << endl
      << "Mean \t" << meanBeamA << "\t" << meanBeamB << endl
      << "# events \t" << nentriesBeamA << "\t" << nentriesBeamB << endl
      <<"---------------------------------------------------------------"<<endl;

  //Also save as a root file.
  TString prefix = "Median";
  TString ROOTfname = prefix + filename;
  TFile* theROOTfile = new TFile(ROOTfname, "RECREATE");
  TTree* MedianTree = new TTree("MedianResults",
				"The median, mean, and # events");
  //MedianTree->Branch("MedianLEDA", &medianLEDA, "MedianLEDA/D");
  //MedianTree->Branch("MedianLEDB", &medianLEDB, "MedianLEDB/D");
  MedianTree->Branch("MedianBeamA", &medianBeamA, "MedianBeamA/D");
  MedianTree->Branch("MedianBeamB", &medianBeamB, "MedianBeamB/D");
  //MedianTree->Branch("MeanLEDA", &meanLEDA, "MeanLEDA/D");
  //MedianTree->Branch("MeanLEDB", &meanLEDB, "MeanLEDB/D");
  MedianTree->Branch("MeanBeamA", &meanBeamA, "MeanBeamA/D");
  MedianTree->Branch("MeanBeamB", &meanBeamB, "MeanBeamB/D");
  //MedianTree->Branch("NentriesLEDA", &nentriesLEDA, "NentriesLEDA/L");
  //MedianTree->Branch("NentriesLEDB", &nentriesLEDB, "NentriesLEDB/L");
  MedianTree->Branch("NentriesBeamA", &nentriesBeamA, "NentriesBeamA/L");
  MedianTree->Branch("NentriesBeamB", &nentriesBeamB, "NentriesBeamB/L");

  //Get the current parameter values from the parameter value file.
  //The nominal default values are commented.
  double avg_baseline[4];// = {8133, 8166, 8165, 8000};
  double max_amplitude[4];// = {13, 17, 50, 100};
  int avg_pre_samples[4];// = {4, 4, 4, 4};
  int avg_post_samples[4];// = {4, 4, 4, 4};
  int trig_pre_samples[4];// = {10, 10, 10, 10};
  int trig_post_samples[4];// = {10, 10, 10, 60};
  int UnTrigSettleLength[4];// = {21, 21, 21, 71};

  fstream file;
  file.open("params.txt", ios_base::in | ios_base::out | ios_base::app);
  
  //Fill the algorithm parameter arrays
  for(int i = 0; i<4; i++){
    //Read the next line in to the variables.       
    file >> avg_baseline[i] >> max_amplitude[i] >> avg_pre_samples[i]
	 >> avg_post_samples[i] >> trig_pre_samples[i]
	 >> trig_post_samples[i] >> UnTrigSettleLength[i];
  }

  MedianTree->Branch("avg_baseline", &avg_baseline, "avg_baseline[4]/D");
  MedianTree->Branch("max_amplitude", &max_amplitude, "max_amplitude[4]/D");
  MedianTree->Branch("avg_pre_samples", &avg_pre_samples,
		     "avg_pre_samples[4]/I");
  MedianTree->Branch("avg_post_samples", &avg_post_samples,
		     "avg_post_samples[4]/I");
  MedianTree->Branch("trig_pre_samples", &trig_pre_samples,
		     "trig_pre_samples[4]/I");
  MedianTree->Branch("trig_post_samples", &trig_post_samples,
		     "trig_post_samples[4]/I");
  MedianTree->Branch("UnTrigSettleLength", &UnTrigSettleLength,
		     "UnTrigSettleLength[4]/I");

  MedianTree->Fill();
  MedianTree->Write();
  theROOTfile->Close();
  //c2->Close();
  //c3->Close();
  c4->Close();
  c5->Close();
  f->Close();
  
} 
