{
    gROOT->ProcessLine(".x /home/t2k/cvson/rootlogon.C");
    gROOT->ProcessLine(".L /home/t2k/cvson/basicPlotUtil.C");
    gStyle->SetLineWidth(2);
    const Int_t NSAMPLE = 39;
    TFile *pfile[NSAMPLE];
    TH1D *hisdcp[NSAMPLE];
    TGraph *graphdcp[NSAMPLE];
    
    TFile *pfile30[NSAMPLE];
    TH1D *hisdcp30[NSAMPLE];
    TGraph *graphdcp30[NSAMPLE];
//invert + syst
TFile *pfile_inv[NSAMPLE];
    TH1D *hisdcp_inv[NSAMPLE];
    TGraph *graphdcp_inv[NSAMPLE];
    
    TFile *pfile30_inv[NSAMPLE];
    TH1D *hisdcp30_inv[NSAMPLE];
    TGraph *graphdcp30_inv[NSAMPLE];    
//normal +stat
   TFile *pfile_stat[NSAMPLE];
    TH1D *hisdcp_stat[NSAMPLE];
    TGraph *graphdcp_stat[NSAMPLE];
    
    TFile *pfile30_stat[NSAMPLE];
    TH1D *hisdcp30_stat[NSAMPLE];
    TGraph *graphdcp30_stat[NSAMPLE];

//invert stat.
TFile *pfile_stat_inv[NSAMPLE];
    TH1D *hisdcp_stat_inv[NSAMPLE];
    TGraph *graphdcp_stat_inv[NSAMPLE];
    
    TFile *pfile30_stat_inv[NSAMPLE];
    TH1D *hisdcp30_stat_inv[NSAMPLE];
    TGraph *graphdcp30_stat_inv[NSAMPLE];

    for (Int_t isam=0; isam<NSAMPLE; ++isam) {
        pfile[isam] = new TFile(Form("../plots/pac7d8e21_dcp_point1_100k4check_optv2s13off_100ksensi_dcp%d_wreactorthrow.root",isam+1));
        hisdcp[isam] = (TH1D*) pfile[isam]->Get("SA_dcp");
 
        pfile30[isam] = new TFile(Form("../plots/pac30e21_dcp_point1_100k4check_optv2s13off_100ksensi_dcp%d_wreactorthrow.root",isam+1));
        hisdcp30[isam] = (TH1D*) pfile30[isam]->Get("SA_dcp");

      pfile_inv[isam] = new TFile(Form("../plots/pac7d8e21_dcp_point1_100k4check_optv2s13off_100ksensi_dcp%d_inv_wreactorthrow.root",isam+1));
    hisdcp_inv[isam] = (TH1D*) pfile_inv[isam]->Get("SA_dcp");
    
    pfile30_inv[isam] = new TFile(Form("../plots/pac30e21_dcp_point1_100k4check_optv2s13off_100ksensi_dcp%d_inv_wreactorthrow.root",isam+1));
    hisdcp30_inv[isam] = (TH1D*) pfile30_inv[isam]->Get("SA_dcp");

       pfile_stat[isam] = new TFile(Form("../plots/pac7d8e21_dcp_point1_optv2s13off_dcp%d_wreactorthrow_StatOnly.root",isam+1));
    hisdcp_stat[isam] = (TH1D*) pfile_stat[isam]->Get("SA_dcp");
    
    pfile30_stat[isam] = new TFile(Form("../plots/pac30e21_dcp_point1_optv2s13off_dcp%d_wreactorthrow_StatOnly.root",isam+1));
    hisdcp30_stat[isam] = (TH1D*) pfile30_stat[isam]->Get("SA_dcp");
   
pfile_stat_inv[isam] = new TFile(Form("../plots/pac7d8e21_dcp_point1_optv2s13off_dcp%d_inv_wreactorthrow_StatOnly.root",isam+1));
    hisdcp_stat_inv[isam] = (TH1D*) pfile_stat_inv[isam]->Get("SA_dcp");
    
    pfile30_stat_inv[isam] = new TFile(Form("../plots/pac30e21_dcp_point1_optv2s13off_dcp%d_inv_wreactorthrow_StatOnly.root",isam+1));
    hisdcp30_stat_inv[isam] = (TH1D*) pfile30_stat_inv[isam]->Get("SA_dcp");

 }
    
    TString subname = "t2kpre_dcp_point1_100k4check_100ksensi_wreactorthrow_optv2s13off_truedcp_unknownMH_corr2";
    //make graph
    Double_t dcptrue[NSAMPLE];
    Double_t yval[NSAMPLE];
    Double_t yval30[NSAMPLE];
    Double_t yval_inv[NSAMPLE];
    Double_t yval30_inv[NSAMPLE];
    
    Double_t yval_stat[NSAMPLE];
    Double_t yval30_stat[NSAMPLE];
Double_t yval_stat_inv[NSAMPLE];
    Double_t yval30_stat_inv[NSAMPLE];

   double mindcp = -3.2028;//-180;
    double maxdcp = 3.2028;//180;
    for (Int_t isam=0; isam<NSAMPLE; isam++) {
        graphdcp[isam] = new TGraph(hisdcp[isam]);
        //dcptrue[isam]=  mindcp +(maxdcp-mindcp)*(isam+1)/((double)40);
        dcptrue[isam]=  (mindcp +(maxdcp-mindcp)*(isam+1)/((double)40))*180/(TMath::Pi());
        yval[isam] = TMath::Min(graphdcp[isam]->Eval(0),TMath::Min(graphdcp[isam]->Eval(-1*TMath::Pi()),graphdcp[isam]->Eval(TMath::Pi())));
        graphdcp30[isam] = new TGraph(hisdcp30[isam]);
        yval30[isam] = TMath::Min(graphdcp30[isam]->Eval(0),TMath::Min(graphdcp30[isam]->Eval(-1*TMath::Pi()),graphdcp30[isam]->Eval(TMath::Pi()))); 

graphdcp_inv[isam] = new TGraph(hisdcp_inv[isam]);
    yval_inv[isam] = TMath::Min(graphdcp_inv[isam]->Eval(0),TMath::Min(graphdcp_inv[isam]->Eval(-1*TMath::Pi()),graphdcp_inv[isam]->Eval(TMath::Pi())));
    graphdcp30_inv[isam] = new TGraph(hisdcp30_inv[isam]);
    yval30_inv[isam] = TMath::Min(graphdcp30_inv[isam]->Eval(0),TMath::Min(graphdcp30_inv[isam]->Eval(-1*TMath::Pi()),graphdcp30_inv[isam]->Eval(TMath::Pi())));   

       graphdcp_stat[isam] = new TGraph(hisdcp_stat[isam]);
    yval_stat[isam] = TMath::Min(graphdcp_stat[isam]->Eval(0),TMath::Min(graphdcp_stat[isam]->Eval(-1*TMath::Pi()),graphdcp_stat[isam]->Eval(TMath::Pi())));
    graphdcp30_stat[isam] = new TGraph(hisdcp30_stat[isam]);
    yval30_stat[isam] = TMath::Min(graphdcp30_stat[isam]->Eval(0),TMath::Min(graphdcp30_stat[isam]->Eval(-1*TMath::Pi()),graphdcp30_stat[isam]->Eval(TMath::Pi())));


graphdcp_stat_inv[isam] = new TGraph(hisdcp_stat_inv[isam]);
    yval_stat_inv[isam] = TMath::Min(graphdcp_stat_inv[isam]->Eval(0),TMath::Min(graphdcp_stat_inv[isam]->Eval(-1*TMath::Pi()),graphdcp_stat_inv[isam]->Eval(TMath::Pi())));
    graphdcp30_stat_inv[isam] = new TGraph(hisdcp30_stat_inv[isam]);
    yval30_stat_inv[isam] = TMath::Min(graphdcp30_stat_inv[isam]->Eval(0),TMath::Min(graphdcp30_stat_inv[isam]->Eval(-1*TMath::Pi()),graphdcp30_stat_inv[isam]->Eval(TMath::Pi())));
cout<<"sam "<<isam<<" normal "<<yval_stat[isam]<<" invert "<<yval_stat_inv[isam]<<endl;
yval_stat[isam] = TMath::Min(yval_stat[isam],yval_stat_inv[isam]);
yval30_stat[isam] = TMath::Min(yval30_stat[isam],yval30_stat_inv[isam]);    

yval[isam] = TMath::Min(yval[isam],yval_inv[isam]);
    yval30[isam] = TMath::Min(yval30[isam],yval30_inv[isam]);

   }
    
    new TCanvas;
    titleStyle(hisdcp[0]);
    hisdcp[0]->SetMinimum(0);
    hisdcp[0]->SetMaximum(60);
    hisdcp[0]->Draw("C");
    for (Int_t isam=1; isam<(NSAMPLE); isam++) {
        hisdcp[isam]->Draw("C same");
    }
    int nlevels = 3;
    //double levels[nlevels] = {0.9889, 2.706,4.0};
    double levels[nlevels] = {2.71, 6.63,9.0};//90%, 99%, 3 sigma
    //double xVals[2] = {-3.2028, 3.2028};
    double xVals[2] = {-180, 180};
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


    
    gPad->Print("plots/"+subname+"comp.eps");
    gPad->Print("plots/"+subname+"comp.png");

    //plot as function of true dcp
   TGraph *pzerodcpExclusive = new TGraph(NSAMPLE,dcptrue,yval);
   TGraph *pzerodcpExclusive30 = new TGraph(NSAMPLE,dcptrue,yval30);
   TGraph *pzerodcpExclusive_stat = new TGraph(NSAMPLE,dcptrue,yval_stat);
   TGraph *pzerodcpExclusive30_stat = new TGraph(NSAMPLE,dcptrue,yval30_stat);   
new TCanvas;
pzerodcpExclusive30_stat->GetXaxis()->SetTitle("True #delta_{CP}(#circ)");
pzerodcpExclusive30_stat->GetYaxis()->SetTitle("#Delta #chi^{2} to exclude sin#delta_{CP}=0");
titleStyle(pzerodcpExclusive30_stat);

pzerodcpExclusive->SetLineWidth(3);
pzerodcpExclusive->SetLineStyle(7);
ci =TColor::GetColor("#D55E00");
pzerodcpExclusive->SetLineColor(ci);
TSpline3 *s3 = new TSpline3("s3",pzerodcpExclusive->GetX(),pzerodcpExclusive->GetY(),pzerodcpExclusive->GetN());
s3->SetLineColor(ci);
s3->SetLineWidth(3);

pzerodcpExclusive30->SetLineWidth(3);
    pzerodcpExclusive30->SetLineStyle(7);
    ci =TColor::GetColor("#0072B2");
    pzerodcpExclusive30->SetLineColor(ci);
    TSpline3 *s330 = new TSpline3("s330",pzerodcpExclusive30->GetX(),pzerodcpExclusive30->GetY(),pzerodcpExclusive30->GetN());
    s330->SetLineColor(ci);
    s330->SetLineWidth(3);
pzerodcpExclusive_stat->SetLineWidth(3);
    pzerodcpExclusive_stat->SetLineStyle(7);
    ci =TColor::GetColor("#D55E00");//red
    pzerodcpExclusive_stat->SetLineColor(ci);
    TSpline3 *s3_stat = new TSpline3("s3",pzerodcpExclusive_stat->GetX(),pzerodcpExclusive_stat->GetY(),pzerodcpExclusive_stat->GetN());
    s3_stat->SetLineColor(ci);
    s3_stat->SetLineWidth(3);
    s3->SetLineStyle(7);
    
    pzerodcpExclusive30_stat->SetLineWidth(3);
    pzerodcpExclusive30_stat->SetLineStyle(7);
    ci =TColor::GetColor("#0072B2");//blue
    pzerodcpExclusive30_stat->SetLineColor(kWhite);
    TSpline3 *s330_stat = new TSpline3("s330",pzerodcpExclusive30_stat->GetX(),pzerodcpExclusive30_stat->GetY(),pzerodcpExclusive30_stat->GetN());
    s330_stat->SetLineColor(ci);
    s330_stat->SetLineWidth(3);
    s330->SetLineStyle(7);

pzerodcpExclusive30_stat->SetMinimum(0);
pzerodcpExclusive30_stat->SetMaximum(20);
pzerodcpExclusive30_stat->Draw("AL");
s330_stat->Draw("L same");
//pzerodcpExclusive30->Draw("P same");
s330->Draw("L same");
//pzerodcpExclusive->Draw("P same");
s3->Draw("L same");
//pzerodcpExclusive_stat->Draw("P same");
s3_stat->Draw("L same");
gr68->Draw("Lsame");
    gr90->Draw("Lsame");
    gr95->Draw("Lsame");
TLegend* leg0 = new TLegend(.17, .69, 0.5, .89);

    leg0->SetFillStyle(0);
    leg0->SetBorderSize(0);
    leg0->SetTextSize(18);
    leg0->SetTextFont(43);
leg0->AddEntry(s330_stat,"20x10^{21} POT w/ eff. stat. improvements (no sys. errors)","l");
leg0->AddEntry(s330,"20x10^{21} POT w/ eff. stat. improvements & 2016 sys. errors","l");
leg0->AddEntry(s3_stat,"7.8x10^{21} POT (no sys. errors)","l");
leg0->AddEntry(s3,"7.8x10^{21} POT w/ 2016 sys. errors.","l");
leg0->Draw();
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
gPad->Print("plots/"+subname+"dcpExclusive.eps");
gPad->Print("plots/"+subname+"dcpExclusive.C");
gPad->Print("plots/"+subname+"dcpExclusive.png");
gPad->Print("plots/"+subname+"dcpExclusive.pdf");
}
