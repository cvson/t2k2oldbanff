#include <TFile.h>
#include <TCanvas.h>
#include <TH2D.h>
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
void PreparePlot(TH2D* plot);
void PrepareBestPoint(TGraph* gr);
void SetStyleVariables(TStyle *t2kStyle);


//Main Macro
void PlotSensiAsimov_zoom_test_new(TString SensiAsimovFile, TString filename){
    
    
    //**** Set Style for Plots ****
    TStyle *t2kstyle = new TStyle("T2K","T2K approved plots style");
    SetStyleVariables(t2kstyle);
    gROOT->SetStyle("T2K");
    
    TChain *Sensi = new TChain("SensiTree");
    //Sensi->Add("/disk2/usr5/jeimber/Ptheta_MultiSample/outputs/SensiAsimov_Results/"+SensiAsimovFile);
    Sensi->Add("/home/t2k/cvson/ptheta/pac2016/20151128/Ptheta_MultiSample/PACdm2vssin23/outputs/SensiAsimov/"+SensiAsimovFile);
    std::cout << "Sensi Tree: " << Sensi->GetEntries() << std::endl;
    
    TString gr_names[4] = {"nue", "numu", "nuebar", "numubar"};
    TString gr_numbers[10] = {"0","1","2","3","4","5","6","7","8","9"};
    
    TH2D *SA_t23_dM32 = new TH2D("SA_t23_dM32", "Asimov Sensitivity", 51, 0.39784, 0.61816, 101, 0.00239589, 0.00262011);
    
    TH2D *SA_norm[4];
    SA_norm[0] = new TH2D("SA_t23_dM32_norm_nue", "Asimov Sensitivity", 51, 0.39784, 0.61816, 101, 0.00239589, 0.00262011);
    SA_norm[1] = new TH2D("SA_t23_dM32_norm_numu", "Asimov Sensitivity", 51, 0.39784, 0.61816, 101, 0.00239589, 0.00262011);
    SA_norm[2] = new TH2D("SA_t23_dM32_norm_nuebar", "Asimov Sensitivity", 51, 0.39784, 0.61816, 101, 0.00239589, 0.00262011);
    SA_norm[3] = new TH2D("SA_t23_dM32_norm_numubar", "Asimov Sensitivity", 51, 0.39784, 0.61816, 101, 0.00239589, 0.00262011);
    
    TH2D *SA_like[4];
    SA_like[0] = new TH2D("SA_t23_dM32_Like_nue", "Asimov Sensitivity", 51, 0.39784, 0.61816, 101, 0.00239589, 0.00262011);
    SA_like[1] = new TH2D("SA_t23_dM32_Like_numu", "Asimov Sensitivity", 51, 0.39784, 0.61816, 101, 0.00239589, 0.00262011);
    SA_like[2] = new TH2D("SA_t23_dM32_Like_nuebar", "Asimov Sensitivity", 51, 0.39784, 0.61816, 101, 0.00239589, 0.00262011);
    SA_like[3] = new TH2D("SA_t23_dM32_Like_numubar", "Asimov Sensitivity", 51, 0.39784, 0.61816, 101, 0.00239589, 0.00262011);
    
    double AvNLLtot = 0.;
    double AvNLL_norm[4] = {0};
    double AvNLL_like[4] = {0};
    
    double globalmin = 999999.;
    int globalmin_bin = 0.;
    
    double norm_min[4] = {999999.,999999.,999999.,999999.};
    int norm_min_bin[4] = {0.};
    double like_min[4] = {999999.,999999.,999999.,999999.};
    int like_min_bin[4] = {0.};
    
    Sensi->SetBranchAddress("AvNLLtot", &AvNLLtot);
    Sensi->SetBranchAddress("AvNLL_norm", &AvNLL_norm);
    Sensi->SetBranchAddress("AvNLL_shape", &AvNLL_like);
    
    TFile *outFile = new TFile("../plots/"+filename+".root", "RECREATE");
    outFile->cd();
    
    for(int i=0; i<Sensi->GetEntries(); i++){
        Sensi->GetEntry(i);
        //cout<<"Entries "<<i<<" value "<< AvNLLtot<<endl;
        //to mask out inf and nan values
        if(!TMath::Finite(AvNLLtot) || TMath::IsNaN(AvNLLtot) ) continue;//newadd
        for(int k=0; k<4; k++){
            if(!TMath::Finite(AvNLL_norm[k]) || TMath::IsNaN(AvNLL_norm[k]) ) continue;//newadd
            if(!TMath::Finite(AvNLL_like[k]) || TMath::IsNaN(AvNLL_like[k]) ) continue;//newadd
        }
        if(AvNLLtot < globalmin){
            globalmin = AvNLLtot;
            globalmin_bin = i;
        }
        
        for(int k=0; k<4; k++){
            if(AvNLL_norm[k] < norm_min[k]){
                norm_min[k] = AvNLL_norm[k];
                norm_min_bin[k] = i;
            }
            if(AvNLL_like[k] < like_min[k]){
                like_min[k] = AvNLL_like[k];
                like_min_bin[k] = i;
            }
        }
    }
    //cout<<"FINISH CHECK MINIMUM"<<endl;
    for(int i=0; i<Sensi->GetEntries(); i++){
        Sensi->GetEntry(i);
        //resetup for inf and nan values
        if(!TMath::Finite(AvNLLtot) || TMath::IsNaN(AvNLLtot) ){//newadd
            SA_t23_dM32->SetBinContent((i%51)+1, TMath::FloorNint(i/51)+1, 1e4);
        }
        else SA_t23_dM32->SetBinContent((i%51)+1, TMath::FloorNint(i/51)+1, AvNLLtot - globalmin);
        
        for(int k=0; k<4; k++){
            //single sample shape only for Sensitivity, Poisson likelihood for Asimov
            if(!TMath::Finite(AvNLL_like[k]) || TMath::IsNaN(AvNLL_like[k]) ) SA_like[k]->SetBinContent((i%51)+1, TMath::FloorNint(i/51)+1, 1e4);
            else SA_like[k]->SetBinContent((i%51)+1, TMath::FloorNint(i/51)+1, AvNLL_like[k] - like_min[k]);
            //single sample norm only
            if(!TMath::Finite(AvNLL_norm[k]) || TMath::IsNaN(AvNLL_norm[k]) ) SA_norm[k]->SetBinContent((i%51)+1, TMath::FloorNint(i/51)+1, 1e4);
            else SA_norm[k]->SetBinContent((i%51)+1, TMath::FloorNint(i/51)+1, AvNLL_norm[k] - norm_min[k]);
        }
        
        /*else {
         SA_t23_dM32->SetBinContent((i%51)+1, TMath::FloorNint(i/51)+1, AvNLLtot - globalmin);
         for(int k=0; k<4; k++){
         //single sample shape only for Sensitivity, Poisson likelihood for Asimov
         if(TMath::Finite(AvNLL_like[k]) && !TMath::IsNaN(AvNLL_like[k]) ) SA_like[k]->SetBinContent((i%51)+1, TMath::FloorNint(i/51)+1, AvNLL_like[k] - like_min[k]);
         //single sample norm only
         if(TMath::Finite(AvNLL_norm[k]) && !TMath::IsNaN(AvNLL_norm[k]) )SA_norm[k]->SetBinContent((i%51)+1, TMath::FloorNint(i/51)+1, AvNLL_norm[k] - norm_min[k]);
         }*/
        
        //}
        
    }
    
    
    //***** Best Fit Points ****
    
    TGraph *best_all = new TGraph(1);
    best_all->SetPoint(0, SA_t23_dM32->GetXaxis()->GetBinCenter((globalmin_bin%51)+1),
                       SA_t23_dM32->GetYaxis()->GetBinCenter(TMath::FloorNint(globalmin_bin/51)+1));
    
    
    PrepareBestPoint(best_all);
    best_all->Write("BestFit_Point_All");
    
    TGraph *best_norm[4];
    TGraph *best_like[4];
    
    for(int k=0; k<4; k++){
        best_norm[k] = new TGraph(1);
        best_norm[k]->SetPoint(0, SA_norm[k]->GetXaxis()->GetBinCenter((norm_min_bin[k]%51)+1),
                               SA_norm[k]->GetYaxis()->GetBinCenter(TMath::FloorNint(norm_min_bin[k]/51)+1));
        PrepareBestPoint(best_norm[k]);
        best_norm[k]->Write("BestFit_Point_norm_"+gr_names[k]);
        
        best_like[k] = new TGraph(1);
        best_like[k]->SetPoint(0, SA_like[k]->GetXaxis()->GetBinCenter((like_min_bin[k]%51)+1),
                               SA_like[k]->GetYaxis()->GetBinCenter(TMath::FloorNint(like_min_bin[k]/51)+1));
        PrepareBestPoint(best_like[k]);
        best_like[k]->Write("BestFit_Point_like_"+gr_names[k]);
    }
    
    
    
    
    //**** 90% CL contour ****
    int nlevels = 2;
    //  double levels[2] = {2.279, 4.605};
    double levels[2] = {1.1395, 2.3025};
    
    TCanvas *c1 = new TCanvas();
    c1->cd();
    SA_t23_dM32->Draw("colz");
    TH2D* SA_t23_dM32_cont = (TH2D*)SA_t23_dM32->Clone();
    SA_t23_dM32_cont->SetContour(nlevels, levels);
    SA_t23_dM32_cont->Draw("cont list");
    c1->Update();
    TObjArray *contours_t23_dM32 = (TObjArray*)gROOT->GetListOfSpecials()->FindObject("contours");
    if(!contours_t23_dM32){ std::cerr << "quitting!" << std::endl; return; }
    std::vector<TGraph*> gVect_t23_dM32_90;
    std::vector<TGraph*> gVect_t23_dM32_68;
    std::vector<TGraph*> gVect_t23_dM32_conv_90;
    std::vector<TGraph*> gVect_t23_dM32_conv_68;
    gVect_t23_dM32_90 = GetContourGraphs(contours_t23_dM32, "white", 0, 1);
    gVect_t23_dM32_68 = GetContourGraphs(contours_t23_dM32, "white", 0, 0);
    gVect_t23_dM32_conv_90 = GetContourGraphs(contours_t23_dM32, "black", 0, 1);
    gVect_t23_dM32_conv_68 = GetContourGraphs(contours_t23_dM32, "black", 0, 0);
    PreparePlot(SA_t23_dM32);
    SA_t23_dM32->Draw("colz");
    SA_t23_dM32->Write();
    for(int j=0; j<gVect_t23_dM32_90.size(); j++){
        gVect_t23_dM32_90[j]->Draw("Lsame");
        gVect_t23_dM32_90[j]->Write("cont_like_all_90_"+gr_numbers[j]);
        gVect_t23_dM32_conv_90[j]->Write("cont_like_all_conv_90_"+gr_numbers[j]);
    }
    for(int j=0; j<gVect_t23_dM32_68.size(); j++){
        gVect_t23_dM32_68[j]->Draw("Lsame");
        gVect_t23_dM32_68[j]->Write("cont_like_all_68_"+gr_numbers[j]);
        gVect_t23_dM32_conv_68[j]->Write("cont_like_all_conv_68_"+gr_numbers[j]);
    }
    //  best_all->Draw("Psame");
    PrintHisto(c1, "SensiAsimov_test_all", filename);
    
    
    TCanvas *c3 = new TCanvas();
    c3->Divide(2,2);
    TH2D* SA_norm_cont[4];
    std::vector< std::vector<TGraph*> > gVect_norm_90;
    std::vector< std::vector<TGraph*> > gVect_norm_68;
    std::vector< std::vector<TGraph*> > gVect_norm_conv_90;
    std::vector< std::vector<TGraph*> > gVect_norm_conv_68;
    for(int i=0; i<4; i++){
        c3->cd(i+1);
        SA_norm[i]->Draw("colz");
        SA_norm_cont[i] = (TH2D*)SA_norm[i]->Clone();
        SA_norm_cont[i]->SetContour(nlevels, levels);
        SA_norm_cont[i]->Draw("cont list");
        c3->Update();
        TObjArray *contours_norm = (TObjArray*)gROOT->GetListOfSpecials()->FindObject("contours");
        if(!contours_norm){ std::cerr << "quitting!" << std::endl; return; }
        gVect_norm_90.push_back(GetContourGraphs(contours_norm, "white", 0, 1));
        gVect_norm_68.push_back(GetContourGraphs(contours_norm, "white", 0, 0));
        gVect_norm_conv_90.push_back(GetContourGraphs(contours_norm, "black", 0, 1));
        gVect_norm_conv_68.push_back(GetContourGraphs(contours_norm, "black", 0, 0));
        PreparePlot(SA_norm[i]);
        SA_norm[i]->Draw("colz");
        SA_norm[i]->Write();
        for(int j=0; j<gVect_norm_90[i].size(); j++){
            gVect_norm_90[i][j]->Draw("Lsame");
            gVect_norm_90[i][j]->Write("cont_norm_90_"+gr_names[i]+"_"+gr_numbers[j]);
            gVect_norm_90[i][j]->Write("cont_norm_conv_90_"+gr_names[i]+"_"+gr_numbers[j]);
        }
        for(int j=0; j<gVect_norm_68[i].size(); j++){
            gVect_norm_68[i][j]->Draw("Lsame");
            gVect_norm_68[i][j]->Write("cont_norm_68_"+gr_names[i]+"_"+gr_numbers[j]);
            gVect_norm_68[i][j]->Write("cont_norm_conv_68_"+gr_names[i]+"_"+gr_numbers[j]);
        }
        //    best_norm[i]->Draw("Psame");
    }
    PrintHisto(c3, "SensiAsimov_test_norm", filename);
    
    TCanvas *c4 = new TCanvas();
    c4->Divide(2,2);
    TH2D* SA_like_cont[4];
    std::vector< std::vector<TGraph*> > gVect_like_90;
    std::vector< std::vector<TGraph*> > gVect_like_68;
    std::vector< std::vector<TGraph*> > gVect_like_conv_90;
    std::vector< std::vector<TGraph*> > gVect_like_conv_68;
    for(int i=0; i<4; i++){
        c4->cd(i+1);
        SA_like[i]->Draw("colz");
        SA_like_cont[i] = (TH2D*)SA_like[i]->Clone();
        SA_like_cont[i]->SetContour(nlevels, levels);
        SA_like_cont[i]->Draw("cont list");
        c4->Update();
        TObjArray *contours_like = (TObjArray*)gROOT->GetListOfSpecials()->FindObject("contours");
        if(!contours_like){ std::cerr << "quitting!" << std::endl; return; }
        gVect_like_90.push_back(GetContourGraphs(contours_like, "white", 0, 1));
        gVect_like_68.push_back(GetContourGraphs(contours_like, "white", 0, 0));
        gVect_like_conv_90.push_back(GetContourGraphs(contours_like, "black", 0, 1));
        gVect_like_conv_68.push_back(GetContourGraphs(contours_like, "black", 0, 0));
        PreparePlot(SA_like[i]);
        SA_like[i]->Draw("colz");
        SA_like[i]->Write();
        for(int j=0; j<gVect_like_90[i].size(); j++){
            gVect_like_90[i][j]->Draw("Lsame");
            gVect_like_90[i][j]->Write("cont_like_90_"+gr_names[i]+"_"+gr_numbers[j]);
            gVect_like_conv_90[i][j]->Write("cont_like_conv_90_"+gr_names[i]+"_"+gr_numbers[j]);
        }
        for(int j=0; j<gVect_like_68[i].size(); j++){
            gVect_like_68[i][j]->Draw("Lsame");
            gVect_like_68[i][j]->Write("cont_like_68_"+gr_names[i]+"_"+gr_numbers[j]);
            gVect_like_conv_68[i][j]->Write("cont_like_conv_68_"+gr_names[i]+"_"+gr_numbers[j]);
        }
        //    best_like[i]->Draw("Psame");
    }
    PrintHisto(c4, "SensiAsimov_test_likelihood", filename);
    
    //  printf("globalmin: %f, t23: %f, dM32: %f \n", globalmin, globalmin_t23, globalmin_dM32);
    
    
}
//#############################################################################
void PrintHisto(TCanvas *canvas, TString name, TString filename){
    canvas->Print("../plots/"+filename+"/"+name+".eps");
    canvas->Print("../plots/"+filename+"/"+name+".pdf");
    canvas->Print("../plots/"+filename+"/"+name+".png");
    canvas->Print("../plots/"+filename+"/"+name+".C");
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
            if(twotheta==0){
                gc->SetPoint(i, x, y);
            }
            else{ //switch to sin^2(2 t23)
                //      if(x > 0.5){
                gc->SetPoint(count, 1-TMath::Power(1-2*x, 2), y);
                count++;
                //    }
            }
        }
        gc->SetLineWidth(2);
        gc->SetFillColor(0);
        gc->SetMarkerSize(0);
        
        if(graphNum==0){ gc->SetLineStyle(7); }
        
        if(twotheta==0){
            gc->GetXaxis()->SetLimits(0.3, 0.7);
            gc->GetXaxis()->SetTitle("sin^{2}#theta_{23}");
        }
        else{
            gc->GetXaxis()->SetLimits(0.8, 1.0);
            gc->GetXaxis()->SetTitle("sin^{2}2#theta_{23}");
        }
        gc->GetYaxis()->SetRangeUser(0.0015, 0.004);
        
        gc->GetYaxis()->SetTitle("#Delta m^{2}_{32}");
        
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
void PreparePlot(TH2D* plot){
    plot->GetXaxis()->SetTitle("sin^{2}#theta_{23}");
    plot->GetYaxis()->SetTitle("#Delta m^{2}_{32}");
    TGaxis* gx = (TGaxis*)plot->GetXaxis();
    gx->SetMaxDigits(3);
    TGaxis* gy = (TGaxis*)plot->GetYaxis();
    gy->SetMaxDigits(3);
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
