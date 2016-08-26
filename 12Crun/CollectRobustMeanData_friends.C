#include "TROOT.h"
#include "TH1.h"
#include "TMath.h"
#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "tinydir.h"
#include "TChain.h"

using namespace std;

void CollectRobustMeanData_friends(){

  string path = "./AllData2_run0";//"/mnt/hgfs/share/beamrun2/RawData/Parameter\ Optimisation/trig_post/SecondRun/AllData2_run0";
  string theFile;
  tinydir_dir dir;
  tinydir_file file;
  //TFile* f;
  //  TTree* theTree;

  TFile* Collected = new TFile("CollectedRobustMeanData.root", "RECREATE");

  //TTree* theTree = new TTree("MedianResults", "Collated data");
  TChain* theChain = new TChain("MedianResults");

  for(int i = 0; i<59; i++){//loop on parameter changes
    tinydir_open(&dir, path.c_str());//expects const char* path as second arg.
    printf(path.c_str());
    printf("\n");
    while (dir.has_next)
      {
	tinydir_readfile(&dir, &file);
	
	printf("%s", file.name);

	if (file.is_dir)
	  {
	    printf("/");
	  }
	printf("\n");

	//Insert my code here:
	if(strstr(file.name, "Median_")){
	  printf("Processing in ROOT \n");
	  theFile = path + "/" + file.name;
	  cout << "theFile = " << theFile << endl;
	  //theTree->AddFriend("MedianResults", theFile.c_str());
	  //theTree->Fill();
	  theChain->Add(theFile.c_str());
	}  
	
	tinydir_next(&dir);
      	
      }

    tinydir_close(&dir);

    //path.pop_back();//only works for later c++ compilers :(
    if ((path.size() > 0)&&(i<10)){
      path.resize(path.size() - 1);
    }
    else if((path.size() > 0)&&(i<101)){
      path.resize(path.size() - 2);
    }
    else if((path.size() > 0)&&(i<1001)){
      path.resize(path.size() - 3);
    }
    else{printf("Too many files... need to edit CollectMedianData.C");}

    //remove the number from path
    stringstream strsm;
    strsm << i+1;
    path.append(strsm.str());
    
  }
  
  //outTree->Write();
  //theChain->Draw("MedianLEDA", "", "");
  //printf("Number of Entries in TTree = %i", theTree->GetEntries());
  //theChain->CloneTree(-1,"fast");
  //theTree->Write();
  theChain->Write();
  Collected->Close();

}
