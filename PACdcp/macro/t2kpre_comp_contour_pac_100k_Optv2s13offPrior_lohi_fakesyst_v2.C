{
    gROOT->ProcessLine(".x /home/t2k/cvson/rootlogon.C");
    gROOT->ProcessLine(".L /home/t2k/cvson/basicPlotUtil.C");
    gStyle->SetLineWidth(2);
    const Int_t NSAMPLE = 5;
    const char *m_name[NSAMPLE] = {"current","pac7d8e21","pac15e21","pac20e21","pac30e21"};
    const char *m_name_long[NSAMPLE] = {"current","7.8e21","15e21","20e21","30e21"};
    TFile *pfile[NSAMPLE];
    TFile *pfileB[NSAMPLE];
    TFile *pfileC[NSAMPLE];
    TFile *pfilesyst[NSAMPLE];
    TFile *pfilesystB[NSAMPLE];
    TFile *pfilesystC[NSAMPLE];

    TH1D *hisdcp[NSAMPLE];
    TH1D *hisdcpB[NSAMPLE];
    TH1D *hisdcpC[NSAMPLE];
    TH1D *hisdcpsyst[NSAMPLE];
    TH1D *hisdcpsystB[NSAMPLE];
    TH1D *hisdcpsystC[NSAMPLE];
    
    TGraph *graphdcp[NSAMPLE];
    TGraph *graphdcpB[NSAMPLE];
    TGraph *graphdcpC[NSAMPLE];
    TGraph *graphdcpsyst[NSAMPLE];
    TGraph *graphdcpsystB[NSAMPLE];
    TGraph *graphdcpsystC[NSAMPLE];
    const char *m_color4merge[NSAMPLE] = {"#9E62B5",
        "#90CB5F",
        "#83A0A3",
        "#A6444B",
        "#92783C"};
    Int_t ci;
    TChain *pchain = new TChain("MinimaTree");
    TChain *pchainsys = new TChain("MinimaTree");
    for (Int_t isam=0; isam<NSAMPLE; ++isam) {
        if(isam==0){
        pfile[isam] = new TFile(Form("../plots/%s_dcp_point1_s13off_100ksensi_wreactorthrow_StatOnly.root",m_name[isam]));
        pfileB[isam] = new TFile(Form("../plots/%s_dcp_point1_s13off_100ksensi_wreactorthrow_StatOnly.root",m_name[isam]));
        pfileC[isam] = new TFile(Form("../plots/%s_dcp_point1_s13off_100ksensi_wreactorthrow_StatOnly.root",m_name[isam]));
        pfilesyst[isam] = new TFile(Form("../plots/%s_dcp_point1_100k4check_s13off_100ksensi_wreactorthrow.root",m_name[isam]));
        pfilesystB[isam] = new TFile(Form("../plots/%s_dcp_point1_100k4checkAlt_s13off_100ksensi_wreactorthrow.root",m_name[isam]));
        pfilesystC[isam] = new TFile(Form("../plots/%s_dcp_point1_100k4checkAltx2_s13off_100ksensi_wreactorthrow.root",m_name[isam]));
        } 
        else{
        pfilesyst[isam] = new TFile(Form("../../PACdcpsyst/plots/%s_dcp_point1_100k4check_optv2s13off_fakesyst_100ksensi_wreactorthrow.root",m_name[isam]));
        pfilesystB[isam] = new TFile(Form("../../PACdcpsyst/plots/%s_dcp_point1_100k4check_optv2s13off_fakesyst_sin23hi_100ksensi_wreactorthrow.root",m_name[isam]));
        pfilesystC[isam] = new TFile(Form("../../PACdcpsyst/plots/%s_dcp_point1_100k4check_optv2s13off_fakesyst_sin23lo_100ksensi_wreactorthrow.root",m_name[isam]));
        pfile[isam] = new TFile(Form("../plots/%s_dcp_point1_optv2s13off_100ksensi_wreactorthrow_StatOnly.root",m_name[isam]));
        pfileB[isam] = new TFile(Form("../plots/%s_dcp_point1_optv2s13off_sin23hi_100ksensi_wreactorthrow_StatOnly.root",m_name[isam]));
        pfileC[isam] = new TFile(Form("../plots/%s_dcp_point1_optv2s13off_sin23lo_100ksensi_wreactorthrow_StatOnly.root",m_name[isam]));
        }
        hisdcp[isam] = (TH1D*) pfile[isam]->Get("SA_dcp");
        hisdcpB[isam] = (TH1D*) pfileB[isam]->Get("SA_dcp");
        hisdcpC[isam] = (TH1D*) pfileC[isam]->Get("SA_dcp");
        hisdcpsyst[isam] = (TH1D*) pfilesyst[isam]->Get("SA_dcp");
        hisdcpsystB[isam] = (TH1D*) pfilesystB[isam]->Get("SA_dcp");
        hisdcpsystC[isam] = (TH1D*) pfilesystC[isam]->Get("SA_dcp");
    }
    
    TString subname = "t2kpre_dcp_point1_100k_wreactorthrow_all_optv2s13off_statvssyst_lohi_fakesyst_v2";
    cout<<"Number of entries "<<pchain->GetEntries()<<" should equal "<<NSAMPLE<<endl;
    //make graph
   Double_t xpot[NSAMPLE]={0,5.2,10,13.33,20};
   Double_t yval[NSAMPLE];
   Double_t yvalB[NSAMPLE];
   Double_t yvalC[NSAMPLE];
   Double_t yvalsyst[NSAMPLE];
   Double_t yvalsystB[NSAMPLE];
   Double_t yvalsystC[NSAMPLE]; 
    for (Int_t isam=0; isam<NSAMPLE; isam++) {
        graphdcp[isam] = new TGraph(hisdcp[isam]);
        graphdcpB[isam] = new TGraph(hisdcpB[isam]);
        graphdcpC[isam] = new TGraph(hisdcpC[isam]);
        graphdcpsyst[isam] = new TGraph(hisdcpsyst[isam]);
        graphdcpsystB[isam] = new TGraph(hisdcpsystB[isam]);
        graphdcpsystC[isam] = new TGraph(hisdcpsystC[isam]);
        cout<<"Eval at dcp=0 "<<graphdcp[isam]->Eval(0)<<" syst "<<graphdcpsyst[isam]->Eval(0)<<endl;
   yval[isam] = TMath::Min(graphdcp[isam]->Eval(0),TMath::Min(graphdcp[isam]->Eval(-1*TMath::Pi()),graphdcp[isam]->Eval(TMath::Pi())));
   yvalB[isam] = TMath::Min(graphdcpB[isam]->Eval(0),TMath::Min(graphdcpB[isam]->Eval(-1*TMath::Pi()),graphdcpB[isam]->Eval(TMath::Pi())));
   yvalC[isam] = TMath::Min(graphdcpC[isam]->Eval(0),TMath::Min(graphdcpC[isam]->Eval(-1*TMath::Pi()),graphdcpC[isam]->Eval(TMath::Pi())));
   yvalsyst[isam] = TMath::Min(graphdcpsyst[isam]->Eval(0),TMath::Min(graphdcpsyst[isam]->Eval(-1*TMath::Pi()),graphdcpsyst[isam]->Eval(TMath::Pi())));
   yvalsystB[isam] = TMath::Min(graphdcpsystB[isam]->Eval(0),TMath::Min(graphdcpsystB[isam]->Eval(-1*TMath::Pi()),graphdcpsystB[isam]->Eval(TMath::Pi())));
   yvalsystC[isam] = TMath::Min(graphdcpsystC[isam]->Eval(0),TMath::Min(graphdcpsystC[isam]->Eval(-1*TMath::Pi()),graphdcpsystC[isam]->Eval(TMath::Pi())));
  cout<<"Eval at sindcp=0 "<<yval[isam]<<" syst "<<yvalsyst[isam]<<endl;
  if(isam==0){
  yval[isam] = 0;
  yvalB[isam] = 0;
  yvalC[isam] = 0;
  yvalsyst[isam] = 0;
  yvalsystB[isam] = 0;
  yvalsystC[isam] = 0;
   }
     }
    
    new TCanvas;
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
    double xVals[2] = {-3.2028, 3.2028};
    double xValsPOT[2] = {0, 20};
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
    ci = TColor::GetColor("#000000");
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
    ci = TColor::GetColor("#000000");
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

    TLegend* leg0 = new TLegend(.22, .6, 0.5, .85);
    leg0->SetFillStyle(0);
    leg0->SetBorderSize(0);
    leg0->SetTextSize(18);
    leg0->SetTextFont(43);
    for (Int_t isam=0; isam<NSAMPLE; ++isam) {
        leg0->AddEntry(hisdcpsyst[isam],Form("%s POT",m_name_long[isam]),"l");
    }
    leg0->SetFillStyle(0);
    leg0->Draw();
    
    
    gPad->Print("plots/"+subname+"comp.eps");
    gPad->Print("plots/"+subname+"comp.png");
//plot exclusive dcp=0
TGraph *pzerodcpExclusive = new TGraph(NSAMPLE,xpot,yval);
TGraph *pzerodcpExclusiveB = new TGraph(NSAMPLE,xpot,yvalB);
TGraph *pzerodcpExclusiveC = new TGraph(NSAMPLE,xpot,yvalC);
TGraph *pzerodcpExclusivesyst = new TGraph(NSAMPLE,xpot,yvalsyst);
TGraph *pzerodcpExclusivesystB = new TGraph(NSAMPLE,xpot,yvalsystB);
TGraph *pzerodcpExclusivesystC = new TGraph(NSAMPLE,xpot,yvalsystC);

new TCanvas;
pzerodcpExclusive->GetXaxis()->SetTitle("Protons-on-Target (x10^{21})");
pzerodcpExclusive->GetYaxis()->SetTitle("#Delta #chi^{2} to exclude sin#delta_{CP}=0");
titleStyle(pzerodcpExclusive);
pzerodcpExclusive->SetLineWidth(3);
pzerodcpExclusiveB->SetLineWidth(3);
pzerodcpExclusiveC->SetLineWidth(3);
pzerodcpExclusivesyst->SetLineWidth(3);
pzerodcpExclusivesystB->SetLineWidth(3);
pzerodcpExclusivesystC->SetLineWidth(3);

pzerodcpExclusive->SetLineStyle(7);
pzerodcpExclusiveB->SetLineStyle(7);
pzerodcpExclusiveC->SetLineStyle(7);

ci =TColor::GetColor("#000000");
pzerodcpExclusive->SetLineColor(ci);
TSpline3 *s3 = new TSpline3("s3",pzerodcpExclusive->GetX(),pzerodcpExclusive->GetY(),pzerodcpExclusive->GetN());
s3->SetLineColor(ci);

ci =TColor::GetColor("#000000");
pzerodcpExclusivesyst->SetLineColor(ci);
TSpline3 *s3syst = new TSpline3("s3syst",pzerodcpExclusivesyst->GetX(),pzerodcpExclusivesyst->GetY(),pzerodcpExclusivesyst->GetN());
s3syst->SetLineColor(ci);
s3syst->SetLineStyle(7);
s3syst->SetLineWidth(3);

ci =TColor::GetColor("#D55E00");
    pzerodcpExclusivesystB->SetLineColor(ci);
    TSpline3 *s3systB = new TSpline3("s3systB",pzerodcpExclusivesystB->GetX(),pzerodcpExclusivesystB->GetY(),pzerodcpExclusivesystB->GetN());
    s3systB->SetLineColor(ci);
    s3systB->SetLineStyle(7);
    s3systB->SetLineWidth(3);
pzerodcpExclusiveB->SetLineColor(ci);
    TSpline3 *s3B = new TSpline3("s3B",pzerodcpExclusiveB->GetX(),pzerodcpExclusiveB->GetY(),pzerodcpExclusiveB->GetN());
    s3B->SetLineColor(ci);

ci =TColor::GetColor("#0072B2");
    pzerodcpExclusivesystC->SetLineColor(ci);
    TSpline3 *s3systC = new TSpline3("s3systC",pzerodcpExclusivesystC->GetX(),pzerodcpExclusivesystC->GetY(),pzerodcpExclusivesystC->GetN());
    s3systC->SetLineColor(ci);
    s3systC->SetLineStyle(7);
    s3systC->SetLineWidth(3);
pzerodcpExclusiveC->SetLineColor(ci);
    TSpline3 *s3C = new TSpline3("s3C",pzerodcpExclusiveC->GetX(),pzerodcpExclusiveC->GetY(),pzerodcpExclusiveC->GetN());
    s3C->SetLineColor(ci);


s3->SetLineWidth(3);
s3B->SetLineWidth(3);
s3C->SetLineWidth(3);
pzerodcpExclusive->SetMaximum(16);
pzerodcpExclusive->Draw("AL");
pzerodcpExclusive->GetXaxis()->SetRangeUser(0,20);
gPad->Modified();
//pzerodcpExclusivesyst->Draw("P same");
//pzerodcpExclusivesystB->Draw("P same");
//pzerodcpExclusivesystC->Draw("P same");
s3->Draw("L same");
s3B->Draw("L same");
s3C->Draw("L same");
s3syst->Draw("L same");
s3systB->Draw("L same");
s3systC->Draw("L same");
TLegend* leg0 = new TLegend(.17, .65, 0.5, .89);
    leg0->SetMargin(0.1);
    leg0->SetFillStyle(0);
    leg0->SetBorderSize(0);
    leg0->SetTextSize(18);
    leg0->SetTextFont(43);
leg0->AddEntry(s3C,"True sin^{2}#theta_{23}=0.43","l");
leg0->AddEntry(s3,"True sin^{2}#theta_{23}=0.50","l");
leg0->AddEntry(s3B,"True sin^{2}#theta_{23}=0.60","l");
leg0->Draw();
   ci = TColor::GetColor("#000000");

    tex = new TLatex(.4,levels[0]+0.2,"  90% C.L.");
    tex->SetTextAlign(11);
    tex->SetTextFont(43);
    tex->SetTextColor(ci);
    tex->SetTextSize(15);
    tex->SetLineWidth(2);
    tex->Draw();

 ci = TColor::GetColor("#000000");
    tex = new TLatex(.4,levels[1]+0.2,"  99% C.L.");
    tex->SetTextAlign(11);
    tex->SetTextFont(43);
    tex->SetTextColor(ci);
    tex->SetTextSize(15);
    tex->SetLineWidth(2);
    tex->Draw();

    ci = TColor::GetColor("#000000");
    tex = new TLatex(.4,levels[2]+0.2,"  3#sigma C.L.");
    tex->SetTextAlign(11);
    tex->SetTextFont(43);
    tex->SetTextColor(ci);
    tex->SetTextSize(15);
    tex->SetLineWidth(2);
    tex->Draw();

    TLegend* leg1 = new TLegend(.4, .7, .85, .85);
    leg1->SetMargin(0.1);
    leg1->SetFillStyle(0);
    leg1->SetBorderSize(0);
    leg1->SetTextSize(18);
    leg1->SetTextFont(43);
leg1->AddEntry(s3,"w/ eff. stat. improvements (no sys. errors)","l");
leg1->AddEntry(s3syst,"w/ eff. stat. & sys. improvements","l");
leg1->Draw();

TGraph *gr68pot = new TGraph(2);
    gr68pot->SetPoint(0, xValsPOT[0], levels[0]);
    gr68pot->SetPoint(1, xValsPOT[1], levels[0]);
    ci = TColor::GetColor("#000000");
    gr68pot->SetLineColor(ci);
    gr68pot->SetLineWidth(2);
    gr68pot->SetLineStyle(7);
    
    TGraph *gr90pot = new TGraph(2);
    gr90pot->SetPoint(0, xValsPOT[0], levels[1]);
    gr90pot->SetPoint(1, xValsPOT[1], levels[1]);
    ci = TColor::GetColor("#000000");
    gr90pot->SetLineColor(ci);
    gr90pot->SetLineWidth(2);
    gr90pot->SetLineStyle(7);
    
    TGraph *gr95pot = new TGraph(2);
    gr95pot->SetPoint(0, xValsPOT[0], levels[2]);
    gr95pot->SetPoint(1, xValsPOT[1], levels[2]);
    ci = TColor::GetColor("#000000");
    gr95pot->SetLineColor(ci);
    gr95pot->SetLineWidth(2);
    gr95pot->SetLineStyle(7);
gr68pot->Draw("Lsame");
    gr90pot->Draw("Lsame");
    gr95pot->Draw("Lsame");
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
gPad->Print("plots/"+subname+"dcpExclusive.png");
gPad->Print("plots/"+subname+"dcpExclusive.pdf");
gPad->Print("plots/"+subname+"dcpExclusive.C");
}
