
#include <TGraph.h>
#include <TGraphAsymmErrors.h>
#include <TAxis.h>
#include <TLine.h>
#include <TLegend.h>
#include <TText.h>
#include <TLatex.h>
#include <TCanvas.h>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "tdrstyle.C"

void PlotLimit ( string LimitFile , string filePrefix, string LimTitle , bool DoObsLim , bool DoExpLim ) {

    setTDRStyle();

    vector<float> vMass           ;
    vector<float> vObsLimit       ; 
    vector<float> vMedianExpLimit ; 
    vector<float> vExpLim68Down   ; 
    vector<float> vExpLim68Up     ; 
    vector<float> vExpLim95Down   ; 
    vector<float> vExpLim95Up     ;

    ifstream indata;
    indata.open(LimitFile.c_str());
    if(!indata) { // file couldn't be opened
        cerr << "Error: file could not be opened" << endl;
        return;
    }
    float Mass           ;
    float ObsLimit       ; 
    float MedianExpLimit ; 
    float ExpLim68Down   ; 
    float ExpLim68Up     ; 
    float ExpLim95Down   ; 
    float ExpLim95Up     ;

    while ( indata >> Mass >> ObsLimit >> MedianExpLimit >> ExpLim68Down >> ExpLim68Up >> ExpLim95Down >> ExpLim95Up )  {
        cout << Mass << " " << MedianExpLimit <<" "<< ExpLim68Down <<" "<< ExpLim68Up <<" "<< ExpLim95Down <<" "<< ExpLim95Up << endl;

        vMass           .push_back(Mass           );
        vObsLimit       .push_back(ObsLimit       ); 
        vMedianExpLimit .push_back(MedianExpLimit ); 
        vExpLim68Down   .push_back(ExpLim68Down   ); 
        vExpLim68Up     .push_back(ExpLim68Up     ); 
        vExpLim95Down   .push_back(ExpLim95Down   ); 
        vExpLim95Up     .push_back(ExpLim95Up     );
    }

    TCanvas* cLimit = new TCanvas("c1","c1",900,600);
    cLimit->cd();

    float x1 = vMass.at(0) - 5. ;
    float x2 = vMass.at(vMass.size()-1) + 5. ; 

    // Expected Limit
    TGraph* ExpLim = NULL ;
    TGraphAsymmErrors* ExpBand68 = NULL ;
    TGraphAsymmErrors* ExpBand95 = NULL ;
    float min = 999999., max = 0;
    float minZoom = 999999., maxZoom = 0;
    if ( DoExpLim ) {
        float x[100];
        float ex[100];
        float y[100];
        float yu68[100];
        float yd68[100];
        float yu95[100];
        float yd95[100]; 
        for ( int i = 0 ; i < (signed) vMass.size() ; ++i ) {
            x[i] = vMass.at(i) ; ex[i] = 0 ; 
            y[i] = vMedianExpLimit.at(i) ;   
	    if(y[i]    > max) max = y[i]   ; if(y[i]    < min) min = y[i]   ;
	    if(x[i]<=250){ if(y[i]    > maxZoom) maxZoom = y[i]   ; if(y[i]    < minZoom) minZoom = y[i]   ;}
            yu68[i] = vExpLim68Up.at(i)   -y[i];   if(yu68[i] > max) max = yu68[i]; if(yu68[i] < min) min = yu68[i];
            yd68[i] = y[i] - vExpLim68Down.at(i);  if(yd68[i] > max) max = yd68[i]; if(yd68[i] < min) min = yd68[i];
            yu95[i] = vExpLim95Up.at(i)   -y[i];   if(yu95[i] > max) max = yu95[i]; if(yu95[i] < min) min = yu95[i];
            yd95[i] = y[i] - vExpLim95Down.at(i);  if(yd95[i] > max) max = yd95[i]; if(yd95[i] < min) min = yd95[i];
        }
        ExpBand95 = new TGraphAsymmErrors((signed) vMass.size(),x,y,ex,ex,yd95,yu95);
        ExpBand95->SetFillColor(kYellow); 
        ExpBand95->SetFillColor(90); 
        ExpBand95->GetYaxis()->SetRangeUser(0.,50);
        ExpBand95->GetXaxis()->SetRangeUser(x1,x2);
        ExpBand95->GetXaxis()->SetTitle("Higgs mass [GeV/c^{2}]");
        ExpBand95->GetYaxis()->SetTitle("95% Limit on #sigma/#sigma_{SM} ");
        ExpBand95->Draw("A3");
        ExpBand95->GetYaxis()->SetRangeUser(0.,50);
        ExpBand95->Draw("A3");
        ExpBand68 = new TGraphAsymmErrors((signed) vMass.size(),x,y,ex,ex,yd68,yu68);
        ExpBand68->SetFillColor(kGreen); 
        ExpBand68->SetFillColor(211); 
        ExpBand68->Draw("3");

        ExpLim = new TGraph((signed) vMass.size(),x,y);    
        ExpLim->SetLineWidth(2);
        ExpLim->SetLineStyle(1);
        ExpLim->Draw("l");
    }

    // Observed Limit
    TGraph* ObsLim = NULL ;
    if ( DoObsLim ) {
        float x[100];
        float y[100];    
        for ( int i = 0 ; i < (signed) vMass.size() ; ++i ) { 
            x[i] = vMass.at(i) ; 
            y[i] = vObsLimit.at(i) ; 
	    if(y[i] > max) max = y[i]; if(y[i] < min) min = y[i];
	    if(x[i]<=250){ if(y[i]    > maxZoom) maxZoom = y[i]   ; if(y[i]    < minZoom) minZoom = y[i]   ;}
        }
        ObsLim = new TGraph((signed) vMass.size(),x,y);
        //ObsLim->SetMarkerColor(kBlue);
        ObsLim->SetMarkerColor(kRed+2);
        ObsLim->SetLineWidth(2);
        //ObsLim->SetLineColor(kBlue);
        ObsLim->SetLineColor(kRed+2);
        //ObsLim->SetLineStyle(2);
        ObsLim->SetMarkerStyle(kFullCircle);
        if   (DoExpLim) ObsLim->Draw("lp");
        else {
            ObsLim->GetYaxis()->SetRangeUser(0.,10); 
            ObsLim->GetXaxis()->SetRangeUser(x1,x2);
            ObsLim->GetXaxis()->SetTitle("Higgs mass [GeV/c^{2}]");
            ObsLim->GetYaxis()->SetTitle("95% CL Limit on #sigma/#sigma_{SM} ");
            ObsLim->Draw("alp");
        }
    }

    TLine *l = new TLine(x1,1,x2,1);
    l->SetLineWidth(2);
    l->SetLineColor(kBlack);
    l->Draw("same");

    TLatex* title = new TLatex(.19,.82,LimTitle.c_str());
    title->SetTextSize(.04);
    title->SetNDC(1);
    title->Draw("same");

    TText* CMS = new TText(.19,.88,"CMS Preliminary");
    CMS ->SetTextSize(.05);
    CMS ->SetNDC(1);
    CMS ->Draw("same");

    //TLatex* Lumi = new TLatex(.19,.84,"Lumi = 1.5 fb^{-1} ");
    //Lumi ->SetTextSize(.03);
    //Lumi ->SetNDC(1);
    //Lumi ->Draw("same");


    TLegend* leg = NULL ;  
    leg = new TLegend(0.60,0.75,0.9,0.88,"");
    if (DoExpLim) leg->AddEntry(ExpLim,   "95% CL: median","l");
    if (DoExpLim) leg->AddEntry(ExpBand68,"95% CL: 68% band","f");
    if (DoExpLim) leg->AddEntry(ExpBand95,"95% CL: 95% band","f");
    if (DoObsLim) leg->AddEntry(ObsLim,"Observed","lp");
    leg->SetTextSize(.03);
    leg->SetFillStyle(0);
    leg->SetBorderSize(0);
    leg->SetShadowColor(0);
    leg->SetFillColor(0);
    leg->Draw("same");


    vector<string> extensions;
    extensions.push_back(".png");
    extensions.push_back(".pdf");
    extensions.push_back(".eps");

    ExpBand95->GetXaxis()->SetRangeUser(x1,x2);
    ExpBand95->GetYaxis()->SetRangeUser(min-0.2,max+2);
    cLimit->Update();
    for(size_t i=0;i<extensions.size();++i) cLimit->Print( ("plots/"+filePrefix+"_lin"+extensions[i]).c_str() );

    ExpBand95->GetXaxis()->SetRangeUser(x1,250);
    ExpBand95->GetYaxis()->SetRangeUser(minZoom/3.,maxZoom+0.2*maxZoom);
    cLimit->Update();
    for(size_t i=0;i<extensions.size();++i) cLimit->Print( ("plots/"+filePrefix+"_zoom_lin"+extensions[i]).c_str() );

    cLimit->SetLogy();

    ExpBand95->GetXaxis()->SetRangeUser(x1,x2);
    ExpBand95->GetYaxis()->SetRangeUser(min/3.,max*10);
    cLimit->Update();
    for(size_t i=0;i<extensions.size();++i) cLimit->Print( ("plots/"+filePrefix+"_log"+extensions[i]).c_str() );

    ExpBand95->GetXaxis()->SetRangeUser(x1,250);
    ExpBand95->GetYaxis()->SetRangeUser(minZoom/3.,maxZoom*10);
    cLimit->Update();
    for(size_t i=0;i<extensions.size();++i) cLimit->Print( ("plots/"+filePrefix+"_zoom_log"+extensions[i]).c_str() );

    //  ExpBand95->GetXaxis()->SetRangeUser(x1,300.);
    //  gPad->WaitPrimitive();
    //  figName = "LimitPlots/" + LimTitle + "_zoom.gif" ;
    //  cLimit->SaveAs(figName.c_str()) ;


    return;
}
