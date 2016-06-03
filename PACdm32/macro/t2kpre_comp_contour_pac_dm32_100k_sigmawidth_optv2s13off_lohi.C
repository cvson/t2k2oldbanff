{
    gROOT->ProcessLine(".x /home/t2k/cvson/rootlogon.C");
    gROOT->ProcessLine(".L /home/t2k/cvson/basicPlotUtil.C");
    gStyle->SetLineWidth(2);
    const Int_t NSAMPLE = 5;
    const char *m_name[NSAMPLE] = {"current","pac7d8e21","pac15e21","pac20e21","pac30e21"};
    const char *m_name_long[NSAMPLE] = {"current","7.8e21","15e21","20e21","30e21"};
    TFile *pfile[NSAMPLE];
    TFile *pfilesyst[NSAMPLE];
   
    TH1D *hisdcp[NSAMPLE];
    TH1D *hisdcpsyst[NSAMPLE];
    
    TGraph *graphdcp[NSAMPLE];
    TGraph *graphdcpsyst[NSAMPLE];
   
   TFile *pfile_lo[NSAMPLE];
    TFile *pfilesyst_lo[NSAMPLE];
    
    TH1D *hisdcp_lo[NSAMPLE];
    TH1D *hisdcpsyst_lo[NSAMPLE];
    
    TGraph *graphdcp_lo[NSAMPLE];
    TGraph *graphdcpsyst_lo[NSAMPLE];

TFile *pfile_hi[NSAMPLE];
    TFile *pfilesyst_hi[NSAMPLE];
    
    TH1D *hisdcp_hi[NSAMPLE];
    TH1D *hisdcpsyst_hi[NSAMPLE];
    
    TGraph *graphdcp_hi[NSAMPLE];
    TGraph *graphdcpsyst_hi[NSAMPLE]; 
    const char *m_color4merge[NSAMPLE] = {"#9E62B5",
        "#90CB5F",
        "#83A0A3",
        "#A6444B",
        "#92783C"};
    Int_t ci;
    TChain *pchain = new TChain("MinimaTree");
    TChain *pchainsys = new TChain("MinimaTree");
    for (Int_t isam=0; isam<NSAMPLE; ++isam) {
        if(isam==0){pfile[isam] = new TFile(Form("../plots/%s_s13off_wreactorthrow_StatOnly_sensiAsimov_100k_dm32.root",m_name[isam]));
        pfilesyst[isam] = new TFile(Form("../plots/%s_s13off_wreactorthrow_sensiAsimov_100k_dm32.root",m_name[isam]));
       pfile_lo[isam] = new TFile(Form("../plots/%s_s13off_sin23lo_wreactorthrow_StatOnly_sensiAsimov_100k_dm32.root",m_name[isam]));
    pfilesyst_lo[isam] = new TFile(Form("../plots/%s_s13off_sin23lo_wreactorthrow_sensiAsimov_100k_dm32.root",m_name[isam]));
    pfile_hi[isam] = new TFile(Form("../plots/%s_s13off_sin23hi_wreactorthrow_StatOnly_sensiAsimov_100k_dm32.root",m_name[isam]));
    pfilesyst_hi[isam] = new TFile(Form("../plots/%s_s13off_sin23hi_wreactorthrow_sensiAsimov_100k_dm32.root",m_name[isam])); 
       
        }
        else {
        pfile[isam] = new TFile(Form("../plots/%s_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_100k_dm32.root",m_name[isam]));
        pfilesyst[isam] = new TFile(Form("../plots/%s_optv2s13off_wreactorthrow_sensiAsimov_100k_dm32.root",m_name[isam]));
        pfile_lo[isam] = new TFile(Form("../plots/%s_optv2s13off_sin23lo_wreactorthrow_StatOnly_sensiAsimov_100k_dm32.root",m_name[isam]));
    pfilesyst_lo[isam] = new TFile(Form("../plots/%s_optv2s13off_sin23lo_wreactorthrow_sensiAsimov_100k_dm32.root",m_name[isam]));
        pfile_hi[isam] = new TFile(Form("../plots/%s_optv2s13off_sin23hi_wreactorthrow_StatOnly_sensiAsimov_100k_dm32.root",m_name[isam]));
    pfilesyst_hi[isam] = new TFile(Form("../plots/%s_optv2s13off_sin23hi_wreactorthrow_sensiAsimov_100k_dm32.root",m_name[isam]));
        }
        hisdcp[isam] = (TH1D*) pfile[isam]->Get("SA_dm32");
        hisdcpsyst[isam] = (TH1D*) pfilesyst[isam]->Get("SA_dm32");
        ci = TColor::GetColor(m_color4merge[isam]);
        hisdcp[isam]->SetLineColor(ci);
        hisdcp[isam]->SetLineWidth(3);
        hisdcp[isam]->SetLineStyle(7);
        hisdcpsyst[isam]->SetLineColor(ci);
        hisdcpsyst[isam]->SetLineWidth(3);

        hisdcp_lo[isam] = (TH1D*) pfile_lo[isam]->Get("SA_dm32");
    hisdcpsyst_lo[isam] = (TH1D*) pfilesyst_lo[isam]->Get("SA_dm32");
    hisdcp_lo[isam]->SetLineColor(ci);
    hisdcp_lo[isam]->SetLineWidth(3);
    hisdcp_lo[isam]->SetLineStyle(7);
    hisdcpsyst_lo[isam]->SetLineColor(ci);
    hisdcpsyst_lo[isam]->SetLineWidth(3);

hisdcp_hi[isam] = (TH1D*) pfile_hi[isam]->Get("SA_dm32");
    hisdcpsyst_hi[isam] = (TH1D*) pfilesyst_hi[isam]->Get("SA_dm32");
    hisdcp_hi[isam]->SetLineColor(ci);
    hisdcp_hi[isam]->SetLineWidth(3);
    hisdcp_hi[isam]->SetLineStyle(7);
    hisdcpsyst_hi[isam]->SetLineColor(ci);
    hisdcpsyst_hi[isam]->SetLineWidth(3);

        if(isam==0){pchain->Add(Form("../plots/%s_s13off_wreactorthrow_StatOnly_sensiAsimov_100k_dm32.root",m_name[isam]));
        pchainsys->Add(Form("../plots/%s_s13off_wreactorthrow_sensiAsimov_100k_dm32.root",m_name[isam]));
        }
        else {
        pchain->Add(Form("../plots/%s_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_100k_dm32.root",m_name[isam]));
        pchainsys->Add(Form("../plots/%s_optv2s13off_wreactorthrow_sensiAsimov_100k_dm32.root",m_name[isam]));
        }  
  }
    
    //TString subname = "pac_dcp_point1_wreactorthrow";
    TString subname = "t2kpre_dm32_point1_wreactorthrow_100k_optv2s13off_lohi";
    //TString subname = "pac_dcp_point1_wreactorthrow_StatOnly";
    cout<<"Number of entries "<<pchain->GetEntries()<<" should equal "<<NSAMPLE<<endl;
    double global_min;
    double global_min_sys;
    pchain->SetBranchAddress("globalmin",&global_min);
    pchainsys->SetBranchAddress("globalmin",&global_min_sys);
    double chisqcorrect[NSAMPLE];
    for (Int_t isam=0; isam<NSAMPLE; isam++) {
        pchain->GetEntry(isam);
        pchainsys->GetEntry(isam);
        cout<<"Global min stat. "<<global_min<<" syst. "<<global_min_sys<<endl;
        chisqcorrect[isam] = global_min_sys - global_min;
        //cout<<"bin number "<<hisdcp[isam]->GetNbinsX()<<endl;
        //correct to different global point
        /*for (Int_t ibin=1; ibin<hisdcp[isam]->GetNbinsX()+1; ibin++) {
            hisdcp[isam]->SetBinContent(ibin,hisdcp[isam]->GetBinContent(ibin)+chisqcorrect[isam]);
        }*/
    }
    //make graph
   double deviation[NSAMPLE]={0.1e-6,0.1e-6,0.1e-6,0.1e-6,0.1e-6};
   Int_t Npointsearch[NSAMPLE]={5000,5000,5000,5000,5000}; 
   //Double_t xpot[NSAMPLE]={1,7.8,15,20,30};
  Double_t xpot[NSAMPLE]={0.67,5.2,10,13.33,20};
    Double_t yval[NSAMPLE];
   Double_t yvalsyst[NSAMPLE]; 
  Double_t yval_hi[NSAMPLE];
   Double_t yvalsyst_hi[NSAMPLE];
   Double_t yval_lo[NSAMPLE];
   Double_t yvalsyst_lo[NSAMPLE];
   for (Int_t isam=0; isam<NSAMPLE; isam++) {
        graphdcp[isam] = new TGraph(hisdcp[isam]);
        Int_t j = 0;
        yval[isam]=0;
        yvalsyst[isam]=0;
        yval_lo[isam]=0;
        yvalsyst_lo[isam]=0;
       yval_hi[isam]=0;
        yvalsyst_hi[isam]=0;
        double tempxlow =0;
        double tempxhigh =0;
        cout<<"SAM "<<isam<<endl;
        for (j=0;j<Npointsearch[isam];j++) {
         double tempx = 2.35e-3+deviation[isam]*j;
         if (TMath::AreEqualRel(1,graphdcp[isam]->Eval(tempx),0.6e-2)) {
           printf("found point %d with x=%g, y=%g\n",j,tempx,graphdcp[isam]->Eval(tempx));
           if(tempx<2.5e-3) tempxlow =tempx;//yval[isam] -=tempx;
           else tempxhigh=tempx;//yval[isam] +=tempx;
         }
        }
       cout<<"Temxhigh "<<tempxhigh<<" low "<<tempxlow<<endl;
        yval[isam] = tempxhigh - tempxlow;
       tempxlow =0;
       tempxhigh =0;
        graphdcpsyst[isam] = new TGraph(hisdcpsyst[isam]);
        for (j=0;j<Npointsearch[isam];j++) {
         double tempx = 2.35e-3+deviation[isam]*j;
         if (TMath::AreEqualRel(1,graphdcpsyst[isam]->Eval(tempx),0.6e-2)) {
           printf("found point %d with x=%g, y=%g\n",j,tempx,graphdcpsyst[isam]->Eval(tempx));
           if(tempx<2.5e-3) tempxlow =tempx;//yvalsyst[isam] -=tempx;
           else tempxhigh=tempx;//yvalsyst[isam] +=tempx;
         }
        }
        yvalsyst[isam] = tempxhigh - tempxlow;
      graphdcp_hi[isam] = new TGraph(hisdcp_hi[isam]);
    double tempxlow =0;
    double tempxhigh =0;
    cout<<"SAM "<<isam<<endl;
    for (j=0;j<Npointsearch[isam];j++) {
        double tempx = 2.35e-3+deviation[isam]*j;
        if (TMath::AreEqualRel(1,graphdcp_hi[isam]->Eval(tempx),0.6e-2)) {
            printf("found point %d with x=%g, y=%g\n",j,tempx,graphdcp_hi[isam]->Eval(tempx));
            if(tempx<2.5e-3) tempxlow =tempx;//yval_hi[isam] -=tempx;
            else tempxhigh=tempx;//yval_hi[isam] +=tempx;
        }
    }
    cout<<"Temxhigh "<<tempxhigh<<" low "<<tempxlow<<endl;
    yval_hi[isam] = tempxhigh - tempxlow;
    tempxlow =0;
    tempxhigh =0;
    graphdcpsyst_hi[isam] = new TGraph(hisdcpsyst_hi[isam]);
    for (j=0;j<Npointsearch[isam];j++) {
        double tempx = 2.35e-3+deviation[isam]*j;
        if (TMath::AreEqualRel(1,graphdcpsyst_hi[isam]->Eval(tempx),0.6e-2)) {
            printf("found point %d with x=%g, y=%g\n",j,tempx,graphdcpsyst_hi[isam]->Eval(tempx));
            if(tempx<2.5e-3) tempxlow =tempx;//yvalsyst_hi[isam] -=tempx;
            else tempxhigh=tempx;//yvalsyst_hi[isam] +=tempx;
        }
    }
    yvalsyst_hi[isam] = tempxhigh - tempxlow;
    graphdcp_lo[isam] = new TGraph(hisdcp_lo[isam]);
    double tempxlow =0;
    double tempxhigh =0;
    cout<<"SAM "<<isam<<endl;
    for (j=0;j<Npointsearch[isam];j++) {
        double tempx = 2.35e-3+deviation[isam]*j;
        if (TMath::AreEqualRel(1,graphdcp_lo[isam]->Eval(tempx),0.6e-2)) {
            printf("found point %d with x=%g, y=%g\n",j,tempx,graphdcp_lo[isam]->Eval(tempx));
            if(tempx<2.5e-3) tempxlow =tempx;//yval_lo[isam] -=tempx;
            else tempxhigh=tempx;//yval_lo[isam] +=tempx;
        }
    }
    cout<<"Temxhigh "<<tempxhigh<<" low "<<tempxlow<<endl;
    yval_lo[isam] = tempxhigh - tempxlow;
    tempxlow =0;
    tempxhigh =0;
    graphdcpsyst_lo[isam] = new TGraph(hisdcpsyst_lo[isam]);
    for (j=0;j<Npointsearch[isam];j++) {
        double tempx = 2.35e-3+deviation[isam]*j;
        if (TMath::AreEqualRel(1,graphdcpsyst_lo[isam]->Eval(tempx),0.6e-2)) {
            printf("found point %d with x=%g, y=%g\n",j,tempx,graphdcpsyst_lo[isam]->Eval(tempx));
            if(tempx<2.5e-3) tempxlow =tempx;//yvalsyst_lo[isam] -=tempx;
            else tempxhigh=tempx;//yvalsyst_lo[isam] +=tempx;
        }
    }
    yvalsyst_lo[isam] = tempxhigh - tempxlow;
   
      //percentage
        yval[isam] /=(5.02e-5);//2.51e-3 devide by 2
        yvalsyst[isam] /=(5.02e-5); 
        yval_hi[isam] /=(5.02e-5);//2.51e-3 devide by 2
        yvalsyst_hi[isam] /=(5.02e-5);
        yval_lo[isam] /=(5.02e-5);//2.51e-3 devide by 2
        yvalsyst_lo[isam] /=(5.02e-5);
        cout<<"SAM "<<isam<<" width stat.  "<<yval[isam]<<" syst. "<<yvalsyst[isam]<<endl;
       cout<<"SAM "<<isam<<" HI width stat.  "<<yval_hi[isam]<<" syst. "<<yvalsyst_hi[isam]<<endl;
       cout<<"SAM "<<isam<<" LO width stat.  "<<yval_lo[isam]<<" syst. "<<yvalsyst_lo[isam]<<endl; 
       //cout<<"Eval sam "<<isam<<" stat "<<graphdcp[isam]->Eval(Y,1,"S")<<" syst "<<graphdcpsyst[isam]->Eval(Y,1,"S")<<endl;
    }

   TGraph *dm32width = new TGraph(NSAMPLE,xpot,yval);
    TGraph *dm32widthsyst = new TGraph(NSAMPLE,xpot,yvalsyst);
    TGraph *dm32width_lo = new TGraph(NSAMPLE,xpot,yval_lo);
    TGraph *dm32widthsyst_lo = new TGraph(NSAMPLE,xpot,yvalsyst_lo);
TGraph *dm32width_hi = new TGraph(NSAMPLE,xpot,yval_hi);
    TGraph *dm32widthsyst_hi = new TGraph(NSAMPLE,xpot,yvalsyst_hi);
    new TCanvas;
    dm32width->GetXaxis()->SetTitle("Protons-on-Target (x10^{21})");
    //dm32width->GetYaxis()->SetTitle("1#sigma widthh");
    dm32width->GetYaxis()->SetTitle("Uncertainty on #Delta m^{2}_{32} (%)");
    titleStyle(dm32width);
    dm32width->SetLineWidth(3);
    dm32widthsyst->SetLineWidth(3);
    dm32widthsyst->SetLineStyle(7);
    ci =TColor::GetColor("#000000");
    dm32width->SetLineColor(ci);
    TSpline3 *s3 = new TSpline3("s3",dm32width->GetX(),dm32width->GetY(),dm32width->GetN());
    s3->SetLineColor(ci);
    ci =TColor::GetColor("#000000");
    dm32widthsyst->SetLineColor(ci);
    TSpline3 *s3syst = new TSpline3("s3syst",dm32widthsyst->GetX(),dm32widthsyst->GetY(),dm32widthsyst->GetN());
    s3syst->SetLineColor(ci);
    s3syst->SetLineStyle(7);
    s3syst->SetLineWidth(3);
    s3->SetLineWidth(3);

    dm32width_lo->SetLineWidth(3);
    dm32widthsyst_lo->SetLineWidth(3);
    dm32widthsyst_lo->SetLineStyle(7);
    ci =TColor::GetColor("#D55E00");
    dm32width_lo->SetLineColor(ci);
    dm32widthsyst_lo->SetLineColor(ci);
    dm32width_hi->SetLineWidth(3);
    dm32widthsyst_hi->SetLineWidth(3);
    dm32widthsyst_hi->SetLineStyle(7);
    ci =TColor::GetColor("#0072B2");
    dm32width_hi->SetLineColor(ci);
    dm32widthsyst_hi->SetLineColor(ci);
    dm32width->SetMaximum(5);
    dm32width->SetMinimum(0);
    dm32width->GetXaxis()->SetRangeUser(0,20);
    dm32width->Draw("APC");
    dm32widthsyst->Draw("PC same");
    dm32width_lo->Draw("PC same");
    dm32widthsyst_lo->Draw("PC same");
    dm32width_hi->Draw("PC same");
    dm32widthsyst_hi->Draw("PC same");
    //s3->Draw("L same");
    //s3syst->Draw("L same");
    TLegend* leg0 = new TLegend(.42, .6, 0.7, .85);
    leg0->SetFillStyle(0);
    leg0->SetBorderSize(0);
    leg0->SetTextSize(18);
    leg0->SetTextFont(43);
    leg0->AddEntry(dm32width_lo,"sin^{2}#theta_{23}=0.43","l");
    leg0->AddEntry(dm32width,"sin^{2}#theta_{23}=0.5","l");
    leg0->AddEntry(dm32width_hi,"sin^{2}#theta_{23}=0.6","l");
    leg0->Draw();
    TLegend* leg1 = new TLegend(.67, .6, 0.82, .85);
    leg1->SetFillStyle(0);
    leg1->SetBorderSize(0);
    leg1->SetTextSize(18);
    leg1->SetTextFont(43);
    leg1->AddEntry(dm32width,"Stat. only","l");
    leg1->AddEntry(dm32widthsyst,"Systematics","l");
    leg1->Draw();
    gPad->Print("plots/"+subname+"1sigmawidth_percentage.eps"); 
    gPad->Print("plots/"+subname+"1sigmawidth_percentage.png");
    gPad->Print("plots/"+subname+"1sigmawidth_percentage.pdf");
    gPad->Print("plots/"+subname+"1sigmawidth_percentage.C");   
 //gPad->Print("plots/"+subname+"1sigmawidth.eps");
 
    /*new TCanvas;
    titleStyle(hisdcp[4]);
    hisdcp[4]->GetXaxis()->SetTitle("#Delta m^{2}_{32} (GeV)");
    hisdcp[4]->SetMinimum(0);
    hisdcp[4]->GetXaxis()->SetRangeUser(2.4e-3,2.6e-3);
    hisdcp[4]->Draw("C");
    for (Int_t isam=0; isam<(NSAMPLE-1); isam++) {
        hisdcp[isam]->Draw("C same");
    }
    for (Int_t isam=0; isam<NSAMPLE; isam++) {
        hisdcpsyst[isam]->Draw("C same");
    }
    
    const int nlevels = 3;
    //double levels[nlevels] = {0.9889, 2.706,4.0};
    double levels[nlevels] = {2.71, 6.63,9.0};//90%, 99%, 3 sigma
    double xVals[2] = {2.0e-3, 3.0e-3};
    TLatex *   tex;
    TGraph *gr68 = new TGraph(2);
    gr68->SetPoint(0, xVals[0], levels[0]);
    gr68->SetPoint(1, xVals[1], levels[0]);
    ci = TColor::GetColor("#000000");
    gr68->SetLineColor(ci);
    gr68->SetLineWidth(2);
    gr68->SetLineStyle(7);
    
    tex = new TLatex(-2.0,levels[0]+0.2,"  90% C.L.");
    tex->SetTextAlign(11);
    tex->SetTextFont(43);
    tex->SetTextColor(ci);
    tex->SetTextSize(20);
    tex->SetLineWidth(2);
    tex->Draw();
    
    
    TGraph *gr90 = new TGraph(2);
    gr90->SetPoint(0, xVals[0], levels[1]);
    gr90->SetPoint(1, xVals[1], levels[1]);
    ci = TColor::GetColor("#8064A2");
    gr90->SetLineColor(ci);
    gr90->SetLineWidth(2);
    gr90->SetLineStyle(7);
    tex = new TLatex(-2.0,levels[1]+0.2,"  99% C.L.");
    tex->SetTextAlign(11);
    tex->SetTextFont(43);
    tex->SetTextColor(ci);
    tex->SetTextSize(20);
    tex->SetLineWidth(2);
    tex->Draw();
    
    TGraph *gr95 = new TGraph(2);
    gr95->SetPoint(0, xVals[0], levels[2]);
    gr95->SetPoint(1, xVals[1], levels[2]);
    ci = TColor::GetColor("#F79646");
    gr95->SetLineColor(ci);
    gr95->SetLineWidth(2);
    gr95->SetLineStyle(7);
    tex = new TLatex(-2.0,levels[2]+0.2,"  3#sigma C.L.");
    tex->SetTextAlign(11);
    tex->SetTextFont(43);
    tex->SetTextColor(ci);
    tex->SetTextSize(20);
    tex->SetLineWidth(2);
    tex->Draw();
    
    gr68->Draw("Lsame");
    gr90->Draw("Lsame");
    gr95->Draw("Lsame");

    TLegend* leg0 = new TLegend(.32, .6, 0.55, .85);
    leg0->SetFillStyle(0);
    leg0->SetBorderSize(0);
    leg0->SetTextSize(18);
    leg0->SetTextFont(43);
    for (Int_t isam=0; isam<NSAMPLE; ++isam) {
        leg0->AddEntry(hisdcpsyst[isam],Form("%s POT",m_name_long[isam]),"l");
    }
    leg0->SetFillStyle(0);
    leg0->Draw();

    TLegend* leg1 = new TLegend(.65, .6, 0.8, .85);
    leg1->SetFillStyle(0);
    leg1->SetBorderSize(0);
    leg1->SetTextSize(18);
    leg1->SetTextFont(43);
    leg1->AddEntry(hisdcp[0],"Stat. only","l");
    leg1->AddEntry(hisdcpsyst[0],"Systematics","l");
    leg1->SetFillStyle(0);
    leg1->Draw();
    
    
    //gPad->Print("plots/"+subname+"comp.eps");
    //gPad->Print("plots/"+subname+"comp.png");
    gPad->Print("plots/"+subname+"comp_zoom.eps");
    gPad->Print("plots/"+subname+"comp_zoom.png");*/
}
