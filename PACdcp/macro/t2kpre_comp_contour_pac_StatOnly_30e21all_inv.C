{
    gROOT->ProcessLine(".x /home/t2k/cvson/rootlogon.C");
    gROOT->ProcessLine(".L /home/t2k/cvson/basicPlotUtil.C");
    gStyle->SetLineWidth(2);
    const Int_t NSAMPLE = 3;
    const char *m_name[NSAMPLE] = {"sin23lo_","","sin23hi_"};
    const char *m_name_long[NSAMPLE] = {"sin^{2}_{23}=0.43","sin^{2}_{23}=0.50","sin^{2}_{23}=0.60"};
    const Int_t NTHROW = 5;
    
    //const char *m_throw[NTHROW] = {"pac30e21","pac30e21c2","pac30e21c3","pac30e21c4","pac30e21c5"};
    //const char *m_throw_long[NTHROW] = {"1.25e21 #nu + 1.25e21 #bar{#nu}","2.1e21 #nu + 0.4e21 #bar{#nu}","1.5e21 #nu + 1.0e21 #bar{#nu}","0.7e21 #nu + 1.8e21 #bar{#nu}","1.0e21 #nu + 1.5e21 #bar{#nu}"};
    const char *m_throw[NTHROW] = {"pac30e21c2","pac30e21c3","pac30e21","pac30e21c5","pac30e21c4"};
    const char *m_throw_long[NTHROW] = {"#nu:#bar{#nu} = 84:16","#nu:#bar{#nu} = 60:40","#nu:#bar{#nu} = 50:50","#nu:#bar{#nu} = 40:60","#nu:#bar{#nu} = 28:72"};
    Int_t lineStyle[NTHROW]={1,3,5,7,10};
    TFile *pfile[NSAMPLE][NTHROW];
    TH1D *hisdcp[NSAMPLE][NTHROW];
   TGraph *graphdcp[NSAMPLE][NTHROW]; 
    
    const char *m_color4merge[NSAMPLE] = {
"#D55E00",
"#000000",
"#0072B2"
};
const char *m_colorthrow[NTHROW]={
"#D55E00",
        "#CC79A7",
        "#000000",
        "#009E73",
        "#0072B2"
}
    Int_t ci;
    for (Int_t isam=0; isam<NSAMPLE; ++isam) {
        for (Int_t ithrow=0; ithrow<NTHROW; ++ithrow) {
        pfile[isam][ithrow] = new TFile(Form("../plots/%s_dcp_point1_optv2s13off_%sposcpinv_inv_100ksensi_wreactorthrow_StatOnly.root",m_throw[ithrow],m_name[isam]));
        hisdcp[isam][ithrow] = (TH1D*) pfile[isam][ithrow]->Get("SA_dcp");
        //ci = TColor::GetColor(m_color4merge[isam]);
        ci = TColor::GetColor(m_colorthrow[ithrow]);
        hisdcp[isam][ithrow]->SetLineColor(ci);
        hisdcp[isam][ithrow]->SetLineWidth(3);
       // hisdcp[isam][ithrow]->SetLineStyle(lineStyle[ithrow]);
        graphdcp[isam][ithrow] = new TGraph(hisdcp[isam][ithrow]);
        double minsq = TMath::Min(graphdcp[isam][ithrow]->Eval(0),TMath::Min(graphdcp[isam][ithrow]->Eval(-1*TMath::Pi()),graphdcp[isam][ithrow]->Eval(TMath::Pi())));
       cout<<"sam "<<isam<<" throw "<<ithrow<<" chisq "<<minsq<<endl;
        }
    }
    
    TString subname = "t2kpre_dcp_point1_wreactorthrow_StatOnly_30e21_poscpinv";
    
    
    
    const int nlevels = 3;
    //double levels[nlevels] = {0.9889, 2.706,4.0};
    double levels[nlevels] = {2.71, 6.63,9.0};//90%, 99%, 3 sigma
    double xVals[2] = {-3.2028, 3.2028};
    TLatex *   tex[3];
    TGraph *gr68 = new TGraph(2);
    gr68->SetPoint(0, xVals[0], levels[0]);
    gr68->SetPoint(1, xVals[1], levels[0]);
    ci = TColor::GetColor("#000000");
    gr68->SetLineColor(ci);
    gr68->SetLineWidth(2);
    gr68->SetLineStyle(7);
    
    tex[0] = new TLatex(-2.0,levels[0]+0.2,"  90% C.L.");
    tex[0]->SetTextAlign(11);
    tex[0]->SetTextFont(43);
    tex[0]->SetTextColor(ci);
    tex[0]->SetTextSize(20);
    tex[0]->SetLineWidth(2);
    
    
    TGraph *gr90 = new TGraph(2);
    gr90->SetPoint(0, xVals[0], levels[1]);
    gr90->SetPoint(1, xVals[1], levels[1]);
    ci = TColor::GetColor("#000000");
    gr90->SetLineColor(ci);
    gr90->SetLineWidth(2);
    gr90->SetLineStyle(7);
    tex[1] = new TLatex(-2.0,levels[1]+0.2,"  99% C.L.");
    tex[1]->SetTextAlign(11);
    tex[1]->SetTextFont(43);
    tex[1]->SetTextColor(ci);
    tex[1]->SetTextSize(20);
    tex[1]->SetLineWidth(2);
    
    TGraph *gr95 = new TGraph(2);
    gr95->SetPoint(0, xVals[0], levels[2]);
    gr95->SetPoint(1, xVals[1], levels[2]);
    ci = TColor::GetColor("#000000");
    gr95->SetLineColor(ci);
    gr95->SetLineWidth(2);
    gr95->SetLineStyle(7);
    tex[2] = new TLatex(-2.0,levels[2]+0.5,"  3#sigma C.L.");
    tex[2]->SetTextAlign(11);
    tex[2]->SetTextFont(43);
    tex[2]->SetTextColor(ci);
    tex[2]->SetTextSize(20);
    tex[2]->SetLineWidth(2);
    
    //gr68->Draw("Lsame");
    //gr90->Draw("Lsame");
    //gr95->Draw("Lsame");

    TLegend* leg0[NSAMPLE];
    
    for (Int_t isam=0; isam<NSAMPLE; ++isam) {
    leg0[isam] = new TLegend(.57, .4, 0.85, .65);
    leg0[isam]->SetFillStyle(0);
    leg0[isam]->SetBorderSize(0);
    leg0[isam]->SetTextSize(24);
    leg0[isam]->SetTextFont(43);
    for (Int_t ithrow=0; ithrow<NTHROW; ++ithrow) {
        //leg0[isam]->AddEntry(hisdcp[isam][ithrow],Form("%s, %s",m_name_long[isam],m_throw_long[ithrow]),"l");
        leg0[isam]->AddEntry(hisdcp[isam][ithrow],Form("%s",m_throw_long[ithrow]),"l");
    }
    leg0[isam]->SetFillStyle(0);
    }
    
    for (Int_t isam=0; isam<NSAMPLE; ++isam) {
    new TCanvas;
    titleStyle(hisdcp[isam][4]);
    hisdcp[isam][4]->SetMinimum(0);
    hisdcp[isam][4]->SetMaximum(80);
    hisdcp[isam][4]->Draw("C");
    hisdcp[isam][3]->Draw("C same");
    hisdcp[isam][2]->Draw("C same");
    hisdcp[isam][1]->Draw("C same");
    hisdcp[isam][0]->Draw("C same");
    gr68->Draw("Lsame");
    gr90->Draw("Lsame");
    gr95->Draw("Lsame");
    //tex[0]->Draw();
    //tex[1]->Draw();
    tex[2]->Draw();
    leg0[isam]->Draw();
//sin label
TLatex *texsn = new TLatex(-0.5,65,m_name_long[isam]);
    texsn->SetTextAlign(11);
    texsn->SetTextFont(43);
    //texsn->SetTextColor(ci);
    texsn->SetTextSize(35);
    texsn->SetLineWidth(2);
    texsn->Draw();
        //T2K Preliminary
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
    gPad->Print("plots/"+subname+Form("sam%d_",isam)+"comp.eps");
    gPad->Print("plots/"+subname+Form("sam%d_",isam)+"comp.png");
    gPad->Print("plots/"+subname+Form("sam%d_",isam)+"comp.C");
    gPad->Print("plots/"+subname+Form("sam%d_",isam)+"comp.pdf");
     }
    
}
