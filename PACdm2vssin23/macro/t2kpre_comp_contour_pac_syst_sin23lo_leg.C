{
    gROOT->ProcessLine(".x /home/t2k/cvson/rootlogon.C");
    gROOT->ProcessLine(".L /home/t2k/cvson/basicPlotUtil.C");
    
    
    TString subname = "current_t23dm32_point1_sin23lo_wreactorthrow_StatOnly";
    TFile *pfile1 = new TFile("../plots/"+subname+".root");
    
    TString subnamesys = "current_setB_t23dm32_point1_sin23lo_wreactorthrow";
    TFile *pfile1sys = new TFile("../plots/"+subnamesys+".root");
    
    TString subname2 = "pac7d8e21_t23dm32_point1_sin23lo_wreactorthrow_StatOnly";
    TFile *pfile2 = new TFile("../plots/"+subname2+".root");
    TString subname2sys = "pac7d8e21_setB_t23dm32_point1_sin23lo_wreactorthrow";
    TFile *pfile2sys = new TFile("../plots/"+subname2sys+".root");
    
    TString subname3 = "pac30e21_t23dm32_point1_sin23lo_wreactorthrow_StatOnly";
    TFile *pfile3 = new TFile("../plots/"+subname3+".root");
    TString subname3sys = "pac30e21_setB_t23dm32_point1_sin23lo_wreactorthrow";
    TFile *pfile3sys = new TFile("../plots/"+subname3sys+".root");
    
    TString plotsubname = "t2kpre_t23dm32_point1_sin23lo_wreactorthrow";
    
    //TH2 for axis
    TH2D *hcont = (TH2D*)pfile1->Get("SA_t23_dM32");
    Int_t ci;
    TGraph *pcont1_cl90 = (TGraph*)pfile1->Get("cont_like_all_90_0");
    ci = TColor::GetColor("#000000");
    pcont1_cl90->SetLineColor(ci);
    pcont1_cl90->SetLineWidth(3);
    //pcont1_cl90->SetLineStyle(7);
    
    TGraph *pcont1_cl90_sys = (TGraph*)pfile1sys->Get("cont_like_all_90_0");
    pcont1_cl90_sys->SetLineColor(ci);
    pcont1_cl90_sys->SetLineWidth(3);
    pcont1_cl90_sys->SetLineStyle(7);

    
    
    
    TGraph *pcont2_cl90 = (TGraph*)pfile2->Get("cont_like_all_90_0");
    ci = TColor::GetColor("#0072B2");
    pcont2_cl90->SetLineColor(ci);
    pcont2_cl90->SetLineWidth(3);
    //pcont2_cl90->SetLineStyle(7);
    
    TGraph *pcont2_cl90_sys = (TGraph*)pfile2sys->Get("cont_like_all_90_0");
    pcont2_cl90_sys->SetLineColor(ci);
    pcont2_cl90_sys->SetLineWidth(3);
    pcont2_cl90_sys->SetLineStyle(7);

    TGraph *pcont3_cl90 = (TGraph*)pfile3->Get("cont_like_all_90_0");
    ci = TColor::GetColor("#D55E00");
    pcont3_cl90->SetLineColor(ci);
    pcont3_cl90->SetLineWidth(3);
    //pcont3_cl90->SetLineStyle(7);
    
    TGraph *pcont3_cl90_sys = (TGraph*)pfile3sys->Get("cont_like_all_90_0");
    pcont3_cl90_sys->SetLineColor(ci);
    pcont3_cl90_sys->SetLineWidth(3);
    pcont3_cl90_sys->SetLineStyle(7);
    new TCanvas();
   gStyle->SetLineWidth(2);
    TGaxis::SetMaxDigits(4);
    titleStyle(hcont);
    
    hcont->Draw("AXIS");
    hcont->GetYaxis()->SetLimits(0.0022,0.0030);
    hcont->GetXaxis()->SetLimits(0.35,0.67);
    gPad->Modified();
    pcont1_cl90->Draw("Lsame");
    //pcont1_cl68->Draw("Lsame");
    pcont2_cl90->Draw("Lsame");
    //pcont2_cl68->Draw("Lsame");
    pcont3_cl90->Draw("Lsame");
    //pcont3_cl68->Draw("Lsame");
    
    pcont1_cl90_sys->Draw("Lsame");
    //pcont1_cl68->Draw("Lsame");
    pcont2_cl90_sys->Draw("Lsame");
    //pcont2_cl68->Draw("Lsame");
    pcont3_cl90_sys->Draw("Lsame");
    
    double sn2true = 0.43;
    double dm2true = 0.002509;
    TMarker *mTrue = new TMarker(sn2true, dm2true, 8);
    ci = TColor::GetColor("#000000");
    mTrue->SetMarkerColor(ci);
    mTrue->SetMarkerSize(1.1);
    mTrue->Draw("same");
    
    TLegend* leg0 = new TLegend(.22, .67, 0.5, .89);
    leg0->SetFillStyle(0);
    leg0->SetBorderSize(0);
    leg0->SetTextSize(18);
    leg0->SetTextFont(43);
    /*leg0->AddEntry(mTrue, "Asimov true", "p");
    leg0->AddEntry(pcont2_cl90, "Stat. 90%", "l");
    leg0->AddEntry(pcont2_cl68, "Stat. 68%", "l");
    leg0->AddEntry(pcont1_cl90, "Syst. 90%", "l");
    leg0->AddEntry(pcont1_cl68, "Syst. 68%", "l");*/
    
    leg0->AddEntry(pcont1_cl90, "POT by 2014 , 90% C.L", "l");
    //leg0->AddEntry(pcont1_cl90_sys, "Current POT Syst., 90% C.L", "l");
    
    leg0->AddEntry(pcont2_cl90, "7.8x10^{21} POT, 90% C.L", "l");
    //leg0->AddEntry(pcont2_cl90_sys, "7.8x10^{20} POT Syst., 90% C.L", "l");
    
    leg0->AddEntry(pcont3_cl90, "20x10^{21} POT w/improvement, 90% C.L", "l");
    //leg0->AddEntry(pcont3_cl90_sys, "30x10^{20} POT Syst., 90% C.L", "l");
    leg0->SetFillStyle(0);
    leg0->Draw();

     TLegend* leg1 = new TLegend(.6, .77, 0.8, .89);
    leg1->SetFillStyle(0);
    leg1->SetBorderSize(0);
    leg1->SetTextSize(18);
    leg1->SetTextFont(43);
    leg1->AddEntry(pcont1_cl90,"Stat. only","l");
    leg1->AddEntry(pcont1_cl90_sys,"Systematics","l");
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
    
   
    
    gPad->Print("plots/"+plotsubname+".eps");
    gPad->Print("plots/"+plotsubname+".png");
    gPad->Print("plots/"+plotsubname+".pdf");
    gPad->Print("plots/"+plotsubname+".C"); 
}
