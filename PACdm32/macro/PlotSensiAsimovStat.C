//Subfunctions
void PrintHisto(TCanvas *canvas, TString name);
void SetStyleVariables(TStyle *t2kStyle);


//Main Macro
void PlotSensiAsimovStat(){


  //**** Set Style for Plots ****
  TStyle *t2kstyle = new TStyle("T2K","T2K approved plots style");
  SetStyleVariables(t2kstyle);
  gROOT->SetStyle("T2K");

  TChain *Sensi = new TChain("SensiTree");
  Sensi->Add("/disk2/usr5/jeimber/Ptheta_MultiSample/outputs/SensiAsimov_Results/SensiAsimov_Stat_Test/SensiAsimov_Results_0*.root");
  std::cout << "Sensi Tree: " << Sensi->GetEntries() << std::endl;
  TChain *Marg = new TChain("MargTree");
  Marg->Add("/disk2/usr5/jeimber/Ptheta_MultiSample/outputs/MargFit_Results/MargFit_ToyXp_Test/MargFit_Results_*.root");
  std::cout << "Marg Tree: " << Marg->GetEntries() << std::endl;
  Sensi->AddFriend(Marg);

  
  TH2D *SA_t23_dM32 = new TH2D("SA_t23_dM32", "Asimov Sensitivity", 51, -0.01, 1.01, 101, -0.01e-2, 2.01e-2);
  TH2D *SA_t13_dcp = new TH2D("SA_t13_dcp", "Asimov Sensitivity", 51, -3.2028, 3.2028, 81, -0.005, 0.805);

  TH2D *SA_norm[4];
  //  SA_norm[0] = new TH2D("SA_t13_dcp_norm_nue", "Asimov Sensitivity", 51, -3.2028, 3.2028, 81, -0.005, 0.805);
  SA_norm[0] = new TH2D("SA_t23_dM32_norm_nue", "Asimov Sensitivity", 51, -0.01, 1.01, 101, -0.01e-2, 2.01e-2);
  SA_norm[1] = new TH2D("SA_t23_dM32_norm_numu", "Asimov Sensitivity", 51, -0.01, 1.01, 101, -0.01e-2, 2.01e-2);
  //  SA_norm[2] = new TH2D("SA_t13_dcp_norm_nuebar", "Asimov Sensitivity", 51, -3.2028, 3.2028, 81, -0.005, 0.805);
  SA_norm[2] = new TH2D("SA_t23_dM32_norm_nuebar", "Asimov Sensitivity", 51, -0.01, 1.01, 101, -0.01e-2, 2.01e-2);
  SA_norm[3] = new TH2D("SA_t23_dM32_norm_numubar", "Asimov Sensitivity", 51, -0.01, 1.01, 101, -0.01e-2, 2.01e-2);

  TH2D *SA_like[4];
  //  SA_like[0] = new TH2D("SA_t13_dcp_Like_nue", "Asimov Sensitivity", 51, -3.2028, 3.2028, 81, -0.005, 0.805);
  SA_like[0] = new TH2D("SA_t23_dM32_Like_nue", "Asimov Sensitivity", 51, -0.01, 1.01, 101, -0.01e-2, 2.01e-2);
  SA_like[1] = new TH2D("SA_t23_dM32_Like_numu", "Asimov Sensitivity", 51, -0.01, 1.01, 101, -0.01e-2, 2.01e-2);
  //  SA_like[2] = new TH2D("SA_t13_dcp_Like_nuebar", "Asimov Sensitivity", 51, -3.2028, 3.2028, 81, -0.005, 0.805);
  SA_like[2] = new TH2D("SA_t23_dM32_Like_nuebar", "Asimov Sensitivity", 51, -0.01, 1.01, 101, -0.01e-2, 2.01e-2);
  SA_like[3] = new TH2D("SA_t23_dM32_Like_numubar", "Asimov Sensitivity", 51, -0.01, 1.01, 101, -0.01e-2, 2.01e-2);

  double OscParams[6] = {0.};
  int OscParBins[6] = {0};
  double AvNLLtot = 0.;
  double AvNLL_norm[4] = {0};
  double AvNLL_like[4] = {0};


  Sensi->SetBranchAddress("OscParams", &OscParams);
  Sensi->SetBranchAddress("OscParBins", &OscParBins);

  Sensi->SetBranchAddress("AvNLLtot", &AvNLLtot);
  Sensi->SetBranchAddress("AvNLL_norm", &AvNLL_norm);
  Sensi->SetBranchAddress("AvNLL_shape", &AvNLL_like);
  
  for(int i=0; i<Sensi->GetEntries(); i++){
    Sensi->GetEntry(i);

    if(SA_t23_dM32->GetBinContent(SA_t23_dM32->FindBin(OscParams[3], OscParams[2])) > AvNLLtot ||
       SA_t23_dM32->GetBinContent(SA_t23_dM32->FindBin(OscParams[3], OscParams[2])) == 0.){
      SA_t23_dM32->SetBinContent(SA_t23_dM32->FindBin(OscParams[3], OscParams[2]), AvNLLtot);
      //    SA_t23_dM32_t13->SetBinContent(ht23delM32_t13->FindBin(t23, delM32), t13);
      //    SA_t23_dM32_dcp->SetBinContent(ht23delM32_dcp->FindBin(t23, delM32), dcp);
    }

    if(SA_t13_dcp->GetBinContent(SA_t13_dcp->FindBin(OscParams[0], OscParams[1])) > AvNLLtot ||
       SA_t13_dcp->GetBinContent(SA_t13_dcp->FindBin(OscParams[0], OscParams[1])) == 0.){
      SA_t13_dcp->SetBinContent(SA_t13_dcp->FindBin(OscParams[0], OscParams[1]), AvNLLtot);
      //    SA_t13_dcp_t13->SetBinContent(ht13delcp_t13->FindBin(t13, delcp), t23);
      //    SA_t13_dcp_dcp->SetBinContent(ht13delcp_dcp->FindBin(t13, delcp), dM32);
    }

    //single sample norm only

    // if(SA_norm[0]->GetBinContent(SA_norm[0]->FindBin(OscParams[0], OscParams[1])) > AvNLL_norm[0] ||
    //    SA_norm[0]->GetBinContent(SA_norm[0]->FindBin(OscParams[0], OscParams[1])) == 0.){
    //   SA_norm[0]->SetBinContent(SA_norm[0]->FindBin(OscParams[0], OscParams[1]), AvNLL_norm[0]);
    // }

    // if(SA_norm[2]->GetBinContent(SA_norm[2]->FindBin(OscParams[0], OscParams[1])) > AvNLL_norm[2] ||
    //    SA_norm[2]->GetBinContent(SA_norm[2]->FindBin(OscParams[0], OscParams[1])) == 0.){
    //   SA_norm[2]->SetBinContent(SA_norm[2]->FindBin(OscParams[0], OscParams[1]), AvNLL_norm[2]);
    // }

    if(SA_norm[0]->GetBinContent(SA_norm[0]->FindBin(OscParams[3], OscParams[2])) > AvNLL_norm[0] ||
       SA_norm[0]->GetBinContent(SA_norm[0]->FindBin(OscParams[3], OscParams[2])) == 0.){
      SA_norm[0]->SetBinContent(SA_norm[0]->FindBin(OscParams[3], OscParams[2]), AvNLL_norm[0]);
    }

    if(SA_norm[2]->GetBinContent(SA_norm[2]->FindBin(OscParams[3], OscParams[2])) > AvNLL_norm[2] ||
       SA_norm[2]->GetBinContent(SA_norm[2]->FindBin(OscParams[3], OscParams[2])) == 0.){
      SA_norm[2]->SetBinContent(SA_norm[2]->FindBin(OscParams[3], OscParams[2]), AvNLL_norm[2]);
    }

    if(SA_norm[1]->GetBinContent(SA_norm[1]->FindBin(OscParams[3], OscParams[2])) > AvNLL_norm[1] ||
       SA_norm[1]->GetBinContent(SA_norm[1]->FindBin(OscParams[3], OscParams[2])) == 0.){
      SA_norm[1]->SetBinContent(SA_norm[1]->FindBin(OscParams[3], OscParams[2]), AvNLL_norm[1]);
    }

    if(SA_norm[3]->GetBinContent(SA_norm[3]->FindBin(OscParams[3], OscParams[2])) > AvNLL_norm[3] ||
       SA_norm[3]->GetBinContent(SA_norm[3]->FindBin(OscParams[3], OscParams[2])) == 0.){
      SA_norm[3]->SetBinContent(SA_norm[3]->FindBin(OscParams[3], OscParams[2]), AvNLL_norm[3]);
    }


    //single sample full likelihood

    // if(SA_like[0]->GetBinContent(SA_like[0]->FindBin(OscParams[0], OscParams[1])) > AvNLL_like[0] ||
    //    SA_like[0]->GetBinContent(SA_like[0]->FindBin(OscParams[0], OscParams[1])) == 0.){
    //   SA_like[0]->SetBinContent(SA_like[0]->FindBin(OscParams[0], OscParams[1]), AvNLL_like[0]);
    // }

    // if(SA_like[2]->GetBinContent(SA_like[2]->FindBin(OscParams[0], OscParams[1])) > AvNLL_like[2] ||
    //    SA_like[2]->GetBinContent(SA_like[2]->FindBin(OscParams[0], OscParams[1])) == 0.){
    //   SA_like[2]->SetBinContent(SA_like[2]->FindBin(OscParams[0], OscParams[1]), AvNLL_like[2]);
    // }

    if(SA_like[0]->GetBinContent(SA_like[0]->FindBin(OscParams[3], OscParams[2])) > AvNLL_like[0] ||
       SA_like[0]->GetBinContent(SA_like[0]->FindBin(OscParams[3], OscParams[2])) == 0.){
      SA_like[0]->SetBinContent(SA_like[0]->FindBin(OscParams[3], OscParams[2]), AvNLL_like[0]);
    }

    if(SA_like[2]->GetBinContent(SA_like[2]->FindBin(OscParams[3], OscParams[2])) > AvNLL_like[2] ||
       SA_like[2]->GetBinContent(SA_like[2]->FindBin(OscParams[3], OscParams[2])) == 0.){
      SA_like[2]->SetBinContent(SA_like[2]->FindBin(OscParams[3], OscParams[2]), AvNLL_like[2]);
    }

    if(SA_like[1]->GetBinContent(SA_like[1]->FindBin(OscParams[3], OscParams[2])) > AvNLL_like[1] ||
       SA_like[1]->GetBinContent(SA_like[1]->FindBin(OscParams[3], OscParams[2])) == 0.){
      SA_like[1]->SetBinContent(SA_like[1]->FindBin(OscParams[3], OscParams[2]), AvNLL_like[1]);
    }

    if(SA_like[3]->GetBinContent(SA_like[3]->FindBin(OscParams[3], OscParams[2])) > AvNLL_like[3] ||
       SA_like[3]->GetBinContent(SA_like[3]->FindBin(OscParams[3], OscParams[2])) == 0.){
      SA_like[3]->SetBinContent(SA_like[3]->FindBin(OscParams[3], OscParams[2]), AvNLL_like[3]);
    }


  }

  TCanvas *c1 = new TCanvas();
  c1->cd();
  SA_t23_dM32->Draw("colz");
  PrintHisto(c1, "SensiAsimovStat_test_all");

  TCanvas *c2 = new TCanvas();
  c2->cd();
  SA_t13_dcp->Draw("colz");

  TCanvas *c3 = new TCanvas();
  c3->Divide(2,2);
  for(int i=0; i<4; i++){
    c3->cd(i+1);
    SA_norm[i]->Draw("colz");
  }
  PrintHisto(c3, "SensiAsimovStat_test_norm");

  TCanvas *c4 = new TCanvas();
  c4->Divide(2,2);
  for(int i=0; i<4; i++){
    c4->cd(i+1);
    SA_like[i]->Draw("colz");
  }
  PrintHisto(c4, "SensiAsimovStat_test_likelihood");

}
//#############################################################################
void PrintHisto(TCanvas *canvas, TString name){
  canvas->Print("../plots/"+name+".eps");
  canvas->Print("../plots/"+name+".pdf");
  canvas->Print("../plots/"+name+".png");
  canvas->Print("../plots/"+name+".C");
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
