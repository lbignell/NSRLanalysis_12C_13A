//This program will scan through a directory (passed as a parameter), check the
//header of every raw .root files saved by the FADC DAQ, put it in a TChain, and
//pass to another program for analysis (+saving?).
#include "TROOT.h"
#include "TChain.h"
#include "tinydir.h"
#include "TBranch.h"
#include "TLeaf.h"
#include <fstream>
#include "TFile.h"
#include <iostream>
#include "TString.h"
#include "TSystem.h"

using namespace std;

void* GetPointerToValue(TBranch* thisBranch, int entry,
				const char* name){
  thisBranch->GetEntry(entry);
  TLeaf* theLeaf = thisBranch->GetLeaf(name);
  return theLeaf->GetValuePointer();
}

//Needs to be run in the same directory as the BLsub files.
void GrabFilesForMedian(){

  string theFile;
  tinydir_dir dir;
  tinydir_file file;
  TTree* theTree;
  TBranch* theBranch;
  Int_t* dummy;

  //Need to sort this one out.
  TFile* Collected; //= new TFile("CollectedMedianData.root", "RECREATE");

  tinydir_open(&dir, ".");//path.c_str());//expects const char* path as second arg.
  while (dir.has_next)
    {
      //printf("Getting files in this directory... \n");
      
      tinydir_readfile(&dir, &file);
      
      //printf("%s \n", file.name);
      
      if (file.is_dir)
	{
	  //printf("/");
	}
      //printf("\n");
      
      //Insert my code here:
      if(strstr(file.name, "BLsub_")&&!(strstr(file.name, "Median"))){
	//This is where the file is opened, and checked to see if it's the run
	//I want...
	//printf("%s \n", file.name);
	TString Command;
	if(strstr(file.name, "2000MeV")){
	  //2 GeV protons
	  //printf("Processing file: %s \n", file.name);
	  Command = TString::Format(".x MedianSimpleSaved.C+(\"%s\", 2000)",
				    file.name);
	  gROOT->ProcessLine(Command);
	}
	else if(strstr(file.name, "475MeV")){
	  //475 MeV protons
	  //printf("Processing file: %s \n", file.name);
	  Command = TString::Format(".x MedianSimpleSaved.C+(\"%s\", 475)",
				    file.name);
	  gROOT->ProcessLine(Command);
	}
	else if(strstr(file.name, "210MeV")){
	  //210 MeV protons
	  //printf("Processing file: %s \n", file.name);
	  Command = TString::Format(".x MedianSimpleSaved.C+(\"%s\", 210)",
				    file.name);
	  gROOT->ProcessLine(Command);
	}
	else{
	  //LED measurements
	}
      }

       
      tinydir_next(&dir);
      
    }

  tinydir_close(&dir);
}
