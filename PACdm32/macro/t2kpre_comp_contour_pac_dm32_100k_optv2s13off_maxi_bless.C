   {
    gROOT->ProcessLine(".x /home/t2k/cvson/rootlogon.C");
    gROOT->ProcessLine(".L /home/t2k/cvson/basicPlotUtil.C");
    gStyle->SetLineWidth(2);
    const Int_t NSAMPLE = 3;
    const char *m_name[NSAMPLE] = {"current","pac7d8e21","pac30e21"};
    const char *m_name_long[NSAMPLE] = {"POT by 2014","7.8x10^{21} POT","20x10^{21} POT w/improvement"};
    TFile *pfile[NSAMPLE];
    TFile *pfilesyst[NSAMPLE];
    TH1D *hisdcp[NSAMPLE];
    TH1D *hisdcpsyst[NSAMPLE];

    TGraph *graphdcp[NSAMPLE];
    TGraph *graphdcpsyst[NSAMPLE];

    const char *m_color4merge[NSAMPLE] = {"#000000",
        "#0072B2",
        "#D55E00"};
    Int_t ci;
    TChain *pchain = new TChain("MinimaTree");
    TChain *pchainsys = new TChain("MinimaTree");
    for (Int_t isam=0; isam<NSAMPLE; ++isam) {
        if(isam==0){pfile[isam] = new TFile(Form("../plots/%s_s13off_wreactorthrow_StatOnly_sensiAsimov_100k_dm32.root",m_name[isam]));
        pfilesyst[isam] = new TFile(Form("../plots/%s_s13off_wreactorthrow_sensiAsimov_100k_dm32.root",m_name[isam]));
        }
        else {
        pfile[isam] = new TFile(Form("../plots/%s_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_100k_dm32.root",m_name[isam]));
        pfilesyst[isam] = new TFile(Form("../plots/%s_optv2s13off_wreactorthrow_sensiAsimov_100k_dm32.root",m_name[isam]));
        }
        hisdcp[isam] = (TH1D*) pfile[isam]->Get("SA_dm32");
        hisdcpsyst[isam] = (TH1D*) pfilesyst[isam]->Get("SA_dm32");
        ci = TColor::GetColor(m_color4merge[isam]);
        hisdcp[isam]->SetLineColor(ci);
        hisdcp[isam]->SetLineWidth(3);
        hisdcpsyst[isam]->SetLineStyle(7);
        hisdcpsyst[isam]->SetLineColor(ci);
        hisdcpsyst[isam]->SetLineWidth(3);
        pchain->Add(Form("../plots/%s_wreactorthrow_StatOnly_sensiAsimov_100k_dm32.root",m_name[isam]));
        pchainsys->Add(Form("../plots/%s_wreactorthrow_sensiAsimov_100k_dm32.root",m_name[isam]));
    }
 
    //TString subname = "pac_dcp_point1_wreactorthrow";
    TString subname = "t2kpre_dm32_point1_wreactorthrow_all_100k_optv2s13off_maxi_bless";
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
    
    for (Int_t isam=0; isam<NSAMPLE; isam++) {
        graphdcp[isam] = new TGraph(hisdcp[isam]);
        graphdcpsyst[isam] = new TGraph(hisdcpsyst[isam]);
        //cout<<"Eval at dcp=0 "<<graphdcp[isam]->Eval(0)<<" syst "<<graphdcpsyst[isam]->Eval(0)<<endl;
    }
    
    new TCanvas;
    /*titleStyle(hisdcpsyst[4]);
    hisdcpsyst[4]->Draw("C");
    for (Int_t isam=0; isam<(NSAMPLE-1); isam++) {
        hisdcpsyst[isam]->Draw("C same");
    }
    for (Int_t isam=0; isam<(NSAMPLE); isam++) {
        hisdcp[isam]->Draw("C same");
    }*/
    titleStyle(hisdcpsyst[2]);
    hisdcpsyst[2]->GetXaxis()->SetTitle("#Delta m^{2}_{32} (eV^{2})");
    //hisdcp[2]->SetMinimum(0);
    //hisdcp[4]->GetXaxis()->SetRangeUser(0.44,0.58);
    hisdcpsyst[2]->GetXaxis()->SetRangeUser(2.1e-3,2.9e-3);
   //hisdcp[2]->SetMaximum(100);
   //hisdcpsyst[2]->SetMaximum(50);
    //hisdcp[2]->GetYaxis()->SetRangeUser(0,30);
    hisdcpsyst[2]->Draw("L");
    for (Int_t isam=0; isam<(NSAMPLE); isam++) {
        hisdcp[isam]->Draw("C same");
    }
    for (Int_t isam=0; isam<NSAMPLE-1; isam++) {
        hisdcpsyst[isam]->Draw("C same");
    }
    
    const int nlevels = 3;
    //double levels[nlevels] = {0.9889, 2.706,4.0};
    double levels[nlevels] = {2.71, 6.63,9.0};//90%, 99%, 3 sigma
    double xVals[2] = {2.1e-3,2.9e-3};
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

    //TLegend* leg0 = new TLegend(.35, .65, 0.6, .89);
    TLegend* leg0 = new TLegend(.2, .65, 0.45, .89);
    leg0->SetFillStyle(0);
    leg0->SetBorderSize(0);
    leg0->SetTextSize(18);
    leg0->SetTextFont(43);
    for (Int_t isam=0; isam<NSAMPLE; ++isam) {
        leg0->AddEntry(hisdcp[isam],Form("%s",m_name_long[isam]),"l");
    }
    leg0->SetFillStyle(0);
    leg0->Draw();
    
    //TLegend* leg1 = new TLegend(.6, .6, 0.8, .85);
    TLegend* leg1 = new TLegend(.5, .75, 0.65, .9);
    leg1->SetFillStyle(0);
    leg1->SetBorderSize(0);
    leg1->SetTextSize(18);
    leg1->SetTextFont(43);
    leg1->AddEntry(hisdcp[0],"Stat. only","l");
    leg1->AddEntry(hisdcpsyst[0],"Systematics","l");
    leg1->SetFillStyle(0);
    leg1->Draw();
    double ypos = 0.96;
    double xpos =0.75;
    TLatex *   text2kpre = new TLatex(xpos,ypos,"T2K Preliminary");//remove PRELIMINARY
    text2kpre->SetTextAlign(22);//change from 22
    text2kpre->SetNDC(kTRUE);
    ci = TColor::GetColor("#000000");
    text2kpre->SetTextColor(ci);
    text2kpre->SetTextFont(43);
    text2kpre->SetTextSize(24);
    text2kpre->SetLineWidth(3);
    text2kpre->Draw();
    hisdcpsyst[2]->GetYaxis()->SetRangeUser(0,50);
    gPad->Modified();
    //gPad->Print("plots/"+subname+"comp.eps");
    //gPad->Print("plots/"+subname+"comp.png");
    gPad->Print("plots/"+subname+"comp_zoom.eps");
    gPad->Print("plots/"+subname+"comp_zoom.png");
    gPad->Print("plots/"+subname+"comp_zoom.pdf");
    gPad->Print("plots/"+subname+"comp_zoom.C");

}
