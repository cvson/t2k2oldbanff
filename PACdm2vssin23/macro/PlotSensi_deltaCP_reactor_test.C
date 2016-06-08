#include <TFile.h>
#include <TCanvas.h>
#include <TH1D.h>
#include <TH1D.h>
#include <TGraph.h>
#include <TString.h>
#include <TStyle.h>
#include <TColor.h>
#include <TChain.h>
#include <TMath.h>
#include <TROOT.h>
#include <TGaxis.h>
#include <TList.h>
#include <TObjArray.h>
#include <TLegend.h>

#include <stdlib.h>
#include <iostream>
#include <vector>

//Subfunctions
void PrintHisto(TCanvas *canvas, TString name, TString filename);
std::vector<TGraph*> GetContourGraphs(TObjArray *contours, TString color, int twotheta, int graphNum);
void PreparePlot(TH1D* plot);
void PrepareBestPoint(TGraph* gr);
void SetStyleVariables(TStyle *t2kStyle);


//Main Macro
void PlotSensi_deltaCP_reactor_test(TString SensiFile, TString filename){


  //**** Set Style for Plots ****
  TStyle *t2kstyle = new TStyle("T2K","T2K approved plots style");
  SetStyleVariables(t2kstyle);
  gROOT->SetStyle("T2K");

  TChain *Sensi = new TChain("SensiTree");
  Sensi->Add("/disk2/usr5/jeimber/Ptheta_MultiSample/outputs/Sensi_Results/"+SensiFile);
  std::cout << "Sensi Tree: " << Sensi->GetEntries() << std::endl;

  TString gr_names[4] = {"nue", "numu", "nuebar", "numubar"};
  TString gr_numbers[10] = {"0","1","2","3","4","5","6","7","8","9"};

  TH1D *SA_dcp = new TH1D("SA_dcp", "Asimov Sensitivity", 51, -3.2028, 3.2028);

  TH1D *SA_norm[4];
  SA_norm[0] = new TH1D("SA_dcp_norm_nue", "Asimov Sensitivity", 51, -3.2028, 3.2028);
  SA_norm[1] = new TH1D("SA_dcp_norm_numu", "Asimov Sensitivity", 51, -3.2028, 3.2028);
  SA_norm[2] = new TH1D("SA_dcp_norm_nuebar", "Asimov Sensitivity", 51, -3.2028, 3.2028);
  SA_norm[3] = new TH1D("SA_dcp_norm_numubar", "Asimov Sensitivity", 51, -3.2028, 3.2028);

  TH1D *SA_like[4];
  SA_like[0] = new TH1D("SA_dcp_Like_nue", "Asimov Sensitivity", 51, -3.2028, 3.2028);
  SA_like[1] = new TH1D("SA_dcp_Like_numu", "Asimov Sensitivity", 51, -3.2028, 3.2028);
  SA_like[2] = new TH1D("SA_dcp_Like_nuebar", "Asimov Sensitivity", 51, -3.2028, 3.2028);
  SA_like[3] = new TH1D("SA_dcp_Like_numubar", "Asimov Sensitivity", 51, -3.2028, 3.2028);

  double AvNLLtot = 0.;
  double AvNLL_norm[4] = {0.};
  double AvNLL_like[4] = {0.};

  double globalmin = 999999.;
  int globalmin_bin = 0.;

  double norm_min[4] = {999999.,999999.,999999.,999999.};
  int norm_min_bin[4] = {0};
  double like_min[4] = {999999.,999999.,999999.,999999.};
  int like_min_bin[4] = {0};

  Sensi->SetBranchAddress("AvNLLtot", &AvNLLtot);
  Sensi->SetBranchAddress("AvNLL_norm", &AvNLL_norm);
  Sensi->SetBranchAddress("AvNLL_shape", &AvNLL_like);

  TFile *outFile = new TFile("../Sensiplots/"+filename+".root", "RECREATE");
  outFile->cd();

  for(int i=0; i<Sensi->GetEntries(); i++){
    Sensi->GetEntry(i);

    if(2*AvNLLtot < globalmin){
      globalmin = 2*AvNLLtot;
      globalmin_bin = i;
    }

    for(int k=0; k<4; k++){
      if(2*AvNLL_norm[k] < norm_min[k]){
        norm_min[k] = 2*AvNLL_norm[k];
	norm_min_bin[k] = i;
      }
      if(2*AvNLL_like[k] < like_min[k]){
        like_min[k] = 2*AvNLL_like[k];
        like_min_bin[k] = i;
      }
    }
  }

  for(int k=0; k<4; k++){
    printf("%f  %i \n", like_min[k], like_min_bin[k]);
  }

  for(int i=0; i<Sensi->GetEntries(); i++){
    Sensi->GetEntry(i);

    SA_dcp->SetBinContent(i+1, 2*AvNLLtot - globalmin);
    for(int k=0; k<4; k++){
      //single sample shape only for Sensitivity, Poisson likelihood for Asimov
      SA_like[k]->SetBinContent(i+1, 2*AvNLL_like[k] - like_min[k]);
      //single sample norm only
      SA_norm[k]->SetBinContent(i+1, 2*AvNLL_norm[k] - norm_min[k]);
    }

  }


  //***** Best Fit Points ****

  TGraph *best_all = new TGraph(1);
  TGraph *best_all_conv = new TGraph(1);
  best_all->SetPoint(0, SA_dcp->GetXaxis()->GetBinCenter(globalmin_bin+1), 0.);
  PrepareBestPoint(best_all);
  best_all->Write("BestFit_Point_All");

  TGraph *best_norm[4];
  TGraph *best_like[4];

  for(int k=0; k<4; k++){
    best_norm[k] = new TGraph(1);
    best_norm[k]->SetPoint(0, SA_norm[k]->GetXaxis()->GetBinCenter(norm_min_bin[k]+1), 0.);
    PrepareBestPoint(best_norm[k]);
    best_norm[k]->Write("BestFit_Point_norm_"+gr_names[k]);

    best_like[k] = new TGraph(1);
    best_like[k]->SetPoint(0, SA_like[k]->GetXaxis()->GetBinCenter(like_min_bin[k]+1), 0.);
    PrepareBestPoint(best_like[k]);
    best_like[k]->Write("BestFit_Point_like_"+gr_names[k]);
  }    


  //**** 90% CL contour ****
  int nlevels = 2;
  double levels[2] = {0.9889, 2.706};
  //  double levels[2] = {0.4945, 1.3528};
  double xVals[2] = {-3.2028, 3.2028};

  TGraph *gr68 = new TGraph(2);
  gr68->SetPoint(0, xVals[0], levels[0]);
  gr68->SetPoint(1, xVals[1], levels[0]);
  gr68->SetLineColor(kOrange);
  gr68->SetLineWidth(2);
  gr68->SetLineStyle(7);

  TGraph *gr90 = new TGraph(2);
  gr90->SetPoint(0, xVals[0], levels[1]);
  gr90->SetPoint(1, xVals[1], levels[1]);
  gr90->SetLineColor(kOrange+2);
  gr90->SetLineWidth(2);
  gr90->SetLineStyle(7);



  TCanvas *c2 = new TCanvas();
  c2->cd();
  SA_dcp->Draw("C");
  PreparePlot(SA_dcp);
  gr68->Draw("Lsame");
  gr90->Draw("Lsame");
  SA_dcp->Draw("Csame");
  SA_dcp->Write();
  //  best_all->Draw("Psame");
  printf("got here\n");

  PrintHisto(c2, "Sensi_test_all", filename);

  printf("made first plot\n");

  TCanvas *c3 = new TCanvas();
  c3->Divide(2,2);
  for(int i=0; i<4; i++){
    c3->cd(i+1);
    SA_norm[i]->Draw("C");
    PreparePlot(SA_norm[i]);
    gr68->Draw("Lsame");
    gr90->Draw("Lsame");
    SA_norm[i]->Draw("Csame");
    SA_norm[i]->Write();
    //    best_norm[i]->Draw("Psame");
  }
  PrintHisto(c3, "Sensi_test_norm", filename);

  TCanvas *c4 = new TCanvas();
  c4->Divide(2,2);
  TH1D* SA_like_cont[4];
  for(int i=0; i<4; i++){
    c4->cd(i+1);
    SA_like[i]->Draw("C");
    PreparePlot(SA_like[i]);
    gr68->Draw("Lsame");
    gr90->Draw("Lsame");
    SA_like[i]->Draw("Csame");
    SA_like[i]->Write();
    //    best_like[i]->Draw("Psame");
  }
  PrintHisto(c4, "Sensi_test_likelihood", filename);

  //  printf("globalmin: %f, t23: %f, dM32: %f \n", globalmin, globalmin_t13, globalmin_dcp);


}
//#############################################################################
void PrintHisto(TCanvas *canvas, TString name, TString filename){
  canvas->Print("../Sensiplots/"+filename+"/"+name+".eps");
  canvas->Print("../Sensiplots/"+filename+"/"+name+".pdf");
  canvas->Print("../Sensiplots/"+filename+"/"+name+".png");
  canvas->Print("../Sensiplots/"+filename+"/"+name+".C");
}
//#############################################################################
std::vector<TGraph*> GetContourGraphs(TObjArray *contours, TString color, int twotheta, int graphNum){
  std::vector<TGraph*> gVect;
  double x,y;
  int ncontours = contours->GetEntries();
  std::cout << ncontours << std::endl;
  TList *list = (TList*)contours->At(graphNum);
  std::cout << list->GetEntries() << std::endl;
  
  for(int j=0; j<list->GetEntries(); j++){
    TGraph *gc = new TGraph();
    TGraph *gc_temp = (TGraph*)list->At(j);
    int count=0;
    std::cout << "points" << gc_temp->GetN() << std::endl;
    for(int i=0; i<gc_temp->GetN(); i++){
      gc_temp->GetPoint(i, x, y);
      if(twotheta==1){
	gc->SetPoint(i, x, y);
      }
      else{ //switch to sin^2(t13)
	//	gc->SetPoint(count, 1-TMath::Power(1-2*x, 2), y);
	gc->SetPoint(count, 0.5*(1-TMath::Sqrt(1-x)), y);
	count++;
      }
    }
    gc->SetLineWidth(2);
    gc->SetFillColor(0);
    gc->SetMarkerSize(0);

    if(graphNum==0){ gc->SetLineStyle(7); }
    
    if(twotheta==0){
      gc->GetXaxis()->SetLimits(0.015, 0.036);
      gc->GetXaxis()->SetTitle("sin^{2}#theta_{13}");
    }
    else{
      gc->GetXaxis()->SetLimits(0.0595, 0.1405);
      gc->GetXaxis()->SetTitle("sin^{2}2#theta_{13}");
    }
    gc->GetYaxis()->SetRangeUser(-3.2028, 3.2028);
    
    gc->GetYaxis()->SetTitle("#delta_{cp}");
    
    if(color.Contains("lue")){
      gc->SetLineColor(kBlue);
      gc->SetMarkerColor(kBlue);
    }
    else if(color.Contains("ed")){
      gc->SetLineColor(kRed);
      gc->SetMarkerColor(kRed);
    }
    else if(color.Contains("ack")){
      gc->SetLineColor(kBlack);
      gc->SetMarkerColor(kBlack);
    }
    else if(color.Contains("ite")){
      gc->SetLineColor(kWhite);
      gc->SetMarkerColor(kWhite);
    }
    
    gVect.push_back(gc);
  }
  return gVect;
}

//#############################################################################
void PreparePlot(TH1D* plot){
  plot->GetXaxis()->SetTitle("#delta_{CP}");
  plot->GetYaxis()->SetTitle("#Delta #chi^{2}");
  TGaxis* gx = (TGaxis*)plot->GetXaxis();
  gx->SetMaxDigits(3);
  TGaxis* gy = (TGaxis*)plot->GetYaxis();
  gy->SetMaxDigits(3);
  plot->SetLineWidth(2);
  plot->SetLineColor(kBlue);
}
//#############################################################################
void PrepareBestPoint(TGraph* gr){
  gr->SetMarkerStyle(34);
  gr->SetMarkerColor(kRed);
  gr->SetMarkerSize(0.5);
}
//#############################################################################
void SetStyleVariables(TStyle *t2kStyle){

  // use plain black on white colors
  t2kStyle->SetFrameBorderMode(0);
  t2kStyle->SetCanvasBorderMode(0);
  t2kStyle->SetPadBorderMode(0);
  t2kStyle->SetPadColor(0);
  t2kStyle->SetCanvasColor(0);
  t2kStyle->SetStatColor(0);
  t2kStyle->SetFillColor(0);
  t2kStyle->SetLegendBorderSize(1);

  // set the paper & margin sizes
  t2kStyle->SetPaperSize(20,26);
  t2kStyle->SetPadTopMargin(0.05);
  t2kStyle->SetPadRightMargin(0.15); //0.05 
  t2kStyle->SetPadBottomMargin(0.16);
  t2kStyle->SetPadLeftMargin(0.13);

  // use large Times-Roman fonts
  t2kStyle->SetTextFont(132);
  t2kStyle->SetTextSize(0.08);
  t2kStyle->SetLabelFont(132,"x");
  t2kStyle->SetLabelFont(132,"y");
  t2kStyle->SetLabelFont(132,"z");
  t2kStyle->SetLabelSize(0.05,"x");
  t2kStyle->SetTitleSize(0.06,"x");
  t2kStyle->SetLabelSize(0.05,"y");
  t2kStyle->SetTitleSize(0.06,"y");
  t2kStyle->SetLabelSize(0.05,"z");
  t2kStyle->SetTitleSize(0.06,"z");
  t2kStyle->SetLabelFont(132,"t");
  t2kStyle->SetTitleFont(132,"x");
  t2kStyle->SetTitleFont(132,"y");
  t2kStyle->SetTitleFont(132,"z");
  t2kStyle->SetTitleFont(132,"t");
  t2kStyle->SetTitleFillColor(0);
  t2kStyle->SetTitleX(0.25);
  t2kStyle->SetTitleFontSize(0.08);
  t2kStyle->SetTitleFont(132,"pad");

  t2kStyle->SetPadGridX(true);
  t2kStyle->SetPadGridY(true);

  // use bold lines and markers
  //  t2kStyle->SetMarkerStyle(20);
  t2kStyle->SetHistLineWidth(1.85);
  t2kStyle->SetLineStyleString(2,"[12 12]"); // postscript dashes

  // get rid of X error bars and y error bar caps
  //  t2kStyle->SetErrorX(0.001);

  // do not display any of the standard histogram decorations
  t2kStyle->SetOptTitle(0);
  t2kStyle->SetOptStat(0);
  t2kStyle->SetOptFit(0);

  // put tick marks on top and RHS of plots
  t2kStyle->SetPadTickX(1);
  t2kStyle->SetPadTickY(1);

  t2kStyle->SetPalette(1,0);  // use the nice red->blue palette
  const Int_t NRGBs = 5;
  const Int_t NCont = 255;

  Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
  Double_t red[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
  Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
  Double_t blue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
  TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue,
                                   NCont);
  t2kStyle->SetNumberContours(NCont);

  // End of definition of t2kStyle
}
