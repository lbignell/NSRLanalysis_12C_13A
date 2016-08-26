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

//Run over all files, getting LED events for SPE distribution.
void runManual(string outfilename, string fname){

  string theLine;

  TObjArray Hlist(0);
