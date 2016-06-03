{
    gROOT->ProcessLine(".x /home/t2k/cvson/rootlogon.C");
    gROOT->ProcessLine(".L /home/t2k/cvson/basicPlotUtil.C");
    gStyle->SetLineWidth(2);
    const Int_t NSAMPLE = 7;
    const char *m_name[NSAMPLE] = {"sin23lo04_","sin23lo_","sin23lo047_","","sin23hi528_","sin23hi57_","sin23hi_"};
    const char *m_name_long[NSAMPLE] = {"sin^{2}_{23}=0.4","sin^{2}_{23}=0.43","sin^{2}_{23}=0.47","sin^{2}_{23}=0.50","sin^{2}_{23}=0.528","sin^{2}_{23}=0.57","sin^{2}_{23}=0.60"};
    const Int_t NTHROW = 5;
    const char *m_throw[NTHROW] = {"pac30e21c2","pac30e21c3","pac30e21","pac30e21c5","pac30e21c4"};
    const char *m_throw1[NTHROW] = {"pac7d8e21c2","pac7d8e21c3","pac7d8e21","pac7d8e21c5","pac7d8e21c4"};
    const char *m_throw2[NTHROW] = {"pac2d5e21c2","pac2d5e21c3","pac2d5e21","pac2d5e21c5","pac2d5e21c4"};
    //const char *m_throw_long[NTHROW] = {"#nu:#bar{#nu} = 50:50","#nu:#bar{#nu} = 84:16","#nu:#bar{#nu} = 60:40","#nu:#bar{#nu} = 28:72","#nu:#bar{#nu} = 40:60"};
    const char *m_throw_long[NTHROW] = {"#nu:#bar{#nu} = 84:16","#nu:#bar{#nu} = 60:40","#nu:#bar{#nu} = 50:50","#nu:#bar{#nu} = 40:60","#nu:#bar{#nu} = 28:72"};
    Int_t lineStyle[NTHROW]={1,3,5,7,10};
    TFile *pfile[NSAMPLE][NTHROW];
    TH1D *hisdcp[NSAMPLE][NTHROW];
   TGraph *graphdcp[NSAMPLE][NTHROW]; 

   TFile *pfile1[NSAMPLE][NTHROW];
    TH1D *hisdcp1[NSAMPLE][NTHROW];
    TGraph *graphdcp1[NSAMPLE][NTHROW];

   TFile *pfile2[NSAMPLE][NTHROW];
    TH1D *hisdcp2[NSAMPLE][NTHROW];
    TGraph *graphdcp2[NSAMPLE][NTHROW];

     TGraph *graphdcpExclu[NSAMPLE][NTHROW];
     //Double_t xval[3]={2.5,7.8,30};
     Double_t xval[3]={1.67,5.2,20};
     Double_t yval[3]={0,0,0};
    
    const char *m_color4merge[NSAMPLE] = {
"#CA6545",
"#807DC1",
"#9CCE56",
"#9AC2B4",
"#5E3C4B",
"#686F3C",
"#C754AE"
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
        pfile[isam][ithrow] = new TFile(Form("../plots/%s_dcp_point1_%s100ksensi_wreactorthrow_StatOnly.root",m_throw[ithrow],m_name[isam]));
        hisdcp[isam][ithrow] = (TH1D*) pfile[isam][ithrow]->Get("SA_dcp");
      
        pfile1[isam][ithrow] = new TFile(Form("../plots/%s_dcp_point1_%s100ksensi_wreactorthrow_StatOnly.root",m_throw1[ithrow],m_name[isam]));
    hisdcp1[isam][ithrow] = (TH1D*) pfile1[isam][ithrow]->Get("SA_dcp");

       pfile2[isam][ithrow] = new TFile(Form("../plots/%s_dcp_point1_%s100ksensi_wreactorthrow_StatOnly.root",m_throw2[ithrow],m_name[isam]));
    hisdcp2[isam][ithrow] = (TH1D*) pfile2[isam][ithrow]->Get("SA_dcp");
        //ci = TColor::GetColor(m_color4merge[isam]);
        ci = TColor::GetColor(m_colorthrow[ithrow]);
        hisdcp[isam][ithrow]->SetLineColor(ci);
        hisdcp[isam][ithrow]->SetLineWidth(3);
        graphdcp[isam][ithrow] = new TGraph(hisdcp[isam][ithrow]);

        hisdcp1[isam][ithrow]->SetLineColor(ci);
    hisdcp1[isam][ithrow]->SetLineWidth(3);
    graphdcp1[isam][ithrow] = new TGraph(hisdcp1[isam][ithrow]);
       
       hisdcp2[isam][ithrow]->SetLineColor(ci);
    hisdcp2[isam][ithrow]->SetLineWidth(3);
    graphdcp2[isam][ithrow] = new TGraph(hisdcp2[isam][ithrow]);
 
        double minsq = TMath::Min(graphdcp[isam][ithrow]->Eval(0),TMath::Min(graphdcp[isam][ithrow]->Eval(-1*TMath::Pi()),graphdcp[isam][ithrow]->Eval(TMath::Pi())));
       double minsq1 = TMath::Min(graphdcp1[isam][ithrow]->Eval(0),TMath::Min(graphdcp1[isam][ithrow]->Eval(-1*TMath::Pi()),graphdcp1[isam][ithrow]->Eval(TMath::Pi())));
       double minsq2 = TMath::Min(graphdcp2[isam][ithrow]->Eval(0),TMath::Min(graphdcp2[isam][ithrow]->Eval(-1*TMath::Pi()),graphdcp2[isam][ithrow]->Eval(TMath::Pi())));
         cout<<"sam "<<isam<<" throw "<<ithrow<<" chisq "<<minsq<<endl;
       yval[0] = minsq2;
       yval[1] = minsq1;
       yval[2] = minsq;
       graphdcpExclu[isam][ithrow] = new TGraph(3,xval,yval);
      graphdcpExclu[isam][ithrow]->SetLineColor(ci);
        graphdcpExclu[isam][ithrow]->SetLineWidth(3); 
      }
    }
    
    TString subname = "t2kpre_dcp_point1_wreactorthrow_StatOnly_allExclusive_mod2_scale1d5";
    
    
    
    const int nlevels = 3;
    //double levels[nlevels] = {0.9889, 2.706,4.0};
    double levels[nlevels] = {2.71, 6.63,9.0};//90%, 99%, 3 sigma
    //double xVals[2] = {0, 30};
    double xVals[2] = {0, 20};
    TLatex *   tex[3];
    TGraph *gr68 = new TGraph(2);
    gr68->SetPoint(0, xVals[0], levels[0]);
    gr68->SetPoint(1, xVals[1], levels[0]);
    ci = TColor::GetColor("#000000");
    gr68->SetLineColor(ci);
    gr68->SetLineWidth(2);
    gr68->SetLineStyle(7);
    
    tex[0] = new TLatex(.1,levels[0]+0.2,"  90% C.L.");
    tex[0]->SetTextAlign(11);
    tex[0]->SetTextFont(43);
    tex[0]->SetTextColor(ci);
    tex[0]->SetTextSize(15);
    tex[0]->SetLineWidth(2);
    
    
    TGraph *gr90 = new TGraph(2);
    gr90->SetPoint(0, xVals[0], levels[1]);
    gr90->SetPoint(1, xVals[1], levels[1]);
    ci = TColor::GetColor("#000000");
    gr90->SetLineColor(ci);
    gr90->SetLineWidth(2);
    gr90->SetLineStyle(7);
    tex[1] = new TLatex(.1,levels[1]+0.2,"  99% C.L.");
    tex[1]->SetTextAlign(11);
    tex[1]->SetTextFont(43);
    tex[1]->SetTextColor(ci);
    tex[1]->SetTextSize(15);
    tex[1]->SetLineWidth(2);
    
    TGraph *gr95 = new TGraph(2);
    gr95->SetPoint(0, xVals[0], levels[2]);
    gr95->SetPoint(1, xVals[1], levels[2]);
    ci = TColor::GetColor("#000000");
    gr95->SetLineColor(ci);
    gr95->SetLineWidth(2);
    gr95->SetLineStyle(7);
    tex[2] = new TLatex(.1,levels[2]+0.2,"  3#sigma C.L.");
    tex[2]->SetTextAlign(11);
    tex[2]->SetTextFont(43);
    tex[2]->SetTextColor(ci);
    tex[2]->SetTextSize(15);
    tex[2]->SetLineWidth(2);
    
    //gr68->Draw("Lsame");
    //gr90->Draw("Lsame");
    //gr95->Draw("Lsame");

    TLegend* leg0[NSAMPLE];
    
    for (Int_t isam=0; isam<NSAMPLE; ++isam) {
    leg0[isam] = new TLegend(.17, .6, 0.5, .90);
    leg0[isam]->SetFillStyle(0);
    leg0[isam]->SetBorderSize(0);
    leg0[isam]->SetTextSize(24);
    leg0[isam]->SetTextFont(43);
    for (Int_t ithrow=0; ithrow<NTHROW; ++ithrow) {
        leg0[isam]->AddEntry(hisdcp[isam][ithrow],Form("%s",m_throw_long[ithrow]),"l");
    }
    leg0[isam]->SetFillStyle(0);
    }
    

    for (Int_t isam=0; isam<NSAMPLE; ++isam) {
    new TCanvas;
    graphdcpExclu[isam][4]->GetXaxis()->SetTitle("Protons-on-target (x10^{21})");
    graphdcpExclu[isam][4]->GetYaxis()->SetTitle("#Delta #chi^{2} to exclude sin#delta_{CP}=0");
    titleStyle(graphdcpExclu[isam][4]);
    graphdcpExclu[isam][4]->SetMinimum(0);
    graphdcpExclu[isam][4]->SetMaximum(25);
    graphdcpExclu[isam][4]->GetXaxis()->SetRangeUser(0,20);
    graphdcpExclu[isam][4]->Draw("AL");
    graphdcpExclu[isam][3]->Draw("L same");
    graphdcpExclu[isam][2]->Draw("L same");
    graphdcpExclu[isam][1]->Draw("L same");
    graphdcpExclu[isam][0]->Draw("L same");
    gr68->Draw("Lsame");
    gr90->Draw("Lsame");
    gr95->Draw("Lsame");
    tex[0]->Draw();
    tex[1]->Draw();
    tex[2]->Draw();
    leg0[isam]->Draw();
    TLatex *texsn = new TLatex(11,18,m_name_long[isam]);
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
    gPad->Print("plots/"+subname+Form("sam%d_",isam)+"comp.pdf");
    gPad->Print("plots/"+subname+Form("sam%d_",isam)+"comp.C");
 }
    
}
