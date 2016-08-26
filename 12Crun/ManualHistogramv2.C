//This script will generate a histogram manually and will also generate zero
//PE counts in the histogram (at 0 + DBL_EPSILON).
//The function returns a pointer to the histogram.
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

using namespace std;

//Arguments: input file name, PMT channel number, a pointer to an instanciated
//histogram, H1 cuts: Low time, high time, low QDC, H2 cuts: low time, high
//time, low QDC, H1-H2 cut: low time diff, high time diff, single PE charge in
//units of counts, attenuation factor (1 for none).
void ManualHistogramv2(string fname, int ChNum, TH1D* QDCHisto,
		       double LowTimeH1, double HighTimeH1, double LowQDCH1,
		       double LowTimeH2, double HighTimeH2, double LowQDCH2,
		       double LowTimePMT, double HighTimePMT,
		       //		       double LowTimeDiff, double HighTimeDiff, 
		       double SinglePE, double Attenuation,
		       double LowTimeH3, double HighTimeH3, double LowQDCH3){

  cout<< "Processing file: " << fname << "..." << endl;

  TFile* f = TFile::Open(fname.c_str());
  TTree* ResultsTree = (TTree*)f->Get("Results");

  vector< vector<double> >* theQDCsimple = NULL;
  vector< vector<double> >* theTimeSimple = NULL;
  vector< vector<double> >* thePulseWidthSimple = NULL;
  vector< vector<double> >* theInterpDiff = NULL;
  vector< vector<double> >* thePulseHeight = NULL;

  ResultsTree->SetBranchAddress("QDCsimple", &theQDCsimple);
  ResultsTree->SetBranchAddress("TimeSimple", &theTimeSimple);
  ResultsTree->SetBranchAddress("PulseWidthSimple", &thePulseWidthSimple);
  ResultsTree->SetBranchAddress("InterpDiff", &theInterpDiff);
  ResultsTree->SetBranchAddress("PulseHeight", &thePulseHeight);

  Long64_t numEntries = ResultsTree->GetEntries();

  double ScaleFactor = (Attenuation/SinglePE);

  Long64_t NumPassedEvts = 0;

  //TH1D* QDCHisto =
  //new TH1D("QDCHisto", "QDC, with cuts applied;Charge (AU);Counts",
  //	     100000, 0., 10000.);

  for(Long64_t i = 0; i < numEntries; i++){
    //cout << "Getting entry " << i << "...";
    ResultsTree->GetEntry(i);
    //cout << "Done!" << endl;
    if(theTimeSimple->size()==4){
    //Loop number of pulses in H1
    for(size_t j = 0; j < theTimeSimple->at(2).size(); j++){
      //cout << "Getting pulse " << j << "..." << endl;
      //Apply H1 Time Cut
      if((LowTimeH1<theTimeSimple->at(2).at(j))&&
	 (theTimeSimple->at(2).at(j)<HighTimeH1)){
	//Passed H1 time cut.
	//cout << "Passed H1 time cut!" << endl;
	//Apply H1 charge cut.
	if(LowQDCH1<theQDCsimple->at(2).at(j)){
	  //Passed H1 charge cut.
	  //cout << "Passed H1 charge cut! Checking H3..." << endl;
	  //The next event should be a H3 event:
	  for(size_t j2 = j; j2<theTimeSimple->at(2).size(); j2++){
	    //Pass the H3 time cut:
	    if(j2<theTimeSimple->at(2).size()){
	    if((LowTimeH3<theTimeSimple->at(2).at(j2))&&
	       (theTimeSimple->at(2).at(j2)<HighTimeH3)){
	      // cout << "Passed H1 time cut!" << endl;
	      if(LowQDCH3<theQDCsimple->at(2).at(j2)){
	  //Loop number of pulses in H2
	  for(size_t k = 0; k < theTimeSimple->at(3).size(); k++){
	    //cout << "Getting pulse " << k << "..." << endl;
	    //Apply H2 time cut
	    if((LowTimeH2<theTimeSimple->at(3).at(k))
	       &&(theTimeSimple->at(3).at(k)<HighTimeH2)){
	      //Passed H2 time cut.
	      //cout << "Passed H2 time cut!" << endl;
	      //Apply H2 charge cut.
	      if(LowQDCH2<theQDCsimple->at(3).at(k)){
		//Passed H2 charge cut.
		//cout << "Passed H2 Charge cut! Checking time cut..." << endl;
		//Check whether there are any events in the channel.
		//if((LowTimeDiff<
		//  (theTimeSimple->at(2).at(j)-theTimeSimple->at(3).at(k)))&&
		// ((theTimeSimple->at(2).at(j)-theTimeSimple->at(3).at(k))<
		//  HighTimeDiff)){
		  //Passed H1-H2 time diff cut		  
		  //cout << "Passed time cut! Checking PMT cut..." << endl;
		  if(theQDCsimple->at(ChNum).size()!=0){
		    //There are events. Check whether any meet the cut.
		    bool MadeCut = false;
		    for(size_t l = 0; l<theTimeSimple->at(ChNum).size(); l++){
		      //Apply time cut on PMT.
		      //cout << "PMT pulse " << l << "..." << endl;
		      if((LowTimePMT<theTimeSimple->at(ChNum).at(l))
			 &&(theTimeSimple->at(ChNum).at(l)<HighTimePMT)){
			//cout << "Passed all cuts; fill val = "
			//   << theQDCsimple->at(ChNum).at(l)*ScaleFactor
			//   << endl;
			MadeCut = true;
			NumPassedEvts++;
			QDCHisto->Fill(theQDCsimple->at(ChNum).at(l)*ScaleFactor);
		      }//end of channel time cut
		    }//end loop on channel events
		    if(!MadeCut){QDCHisto->Fill(0.+DBL_EPSILON);}//Add 0 to histo.
		  }
		  else{
		    //Add a zero to the histogram.
		    QDCHisto->Fill(0. + DBL_EPSILON);
		  }//end if/else # evts in ChNum
		  //}//H1-H2 time diff cut end.
	      }//H2 charge cut end.
	    }//H2 time cut end
	  }//H2 vector loop
	      }//H3 charge cut
	    }//H3 time cut
	    }//H3 size check
	  }//H3 vector loop
	}//H1 charge cut end
      }//H1 time cut end
    }//H1 vector loop end
    }//Vector size check end
    else{
      cout << "ERROR: theTimeSimple->size()!=4 = " << theTimeSimple->size()
	   << endl;
      cout << "numEntries = " << numEntries << ", theQDCsimple->size() = "
	   << theQDCsimple->size() << endl;
      return;// QDCHisto;
    }
  }//tree loop end

  cout << "Number of non-zero events passing cut = " << NumPassedEvts << endl;
  return;// QDCHisto;
}
