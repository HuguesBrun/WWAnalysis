#include <vector>
#include <iostream>
#include <iomanip>
#include <utility>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>
#include <algorithm>

int getSignalCBNLValueInt(int ch, bool do7TeV) {
    if (do7TeV) {
        if      (ch == 0) return 3;
        else if (ch == 1) return 3;
        else              return 3;
    }

    else {
        if      (ch == 0) return 3;
        else if (ch == 1) return 3;
        else              return 3;
    }
}

int getSignalCBNRValueInt(int ch, bool do7TeV) {
    if (do7TeV) {
        if      (ch == 0) return 4;
        else if (ch == 1) return 3;
        else              return 4;
    }

    else {
        if      (ch == 0) return 4;
        else if (ch == 1) return 3;
        else              return 4;
    }
}

std::string getSignalACBMeanString(int ch, bool do7TeV) {

    stringstream fss;
    fss << "( ";

    if (do7TeV) {
      if (ch == 0) fss << "(-13930.1) + (539.231*@0) + (-8.32968*@0*@0) + (0.064182*@0*@0*@0) + (-0.000246672*@0*@0*@0*@0) + (3.78293e-07*@0*@0*@0*@0*@0)";
      if (ch == 1) fss << "(4.98953) + (-0.104704*@0) + (0.000692868*@0*@0) + (-1.55343e-06*@0*@0*@0)";
      if (ch == 2) fss << "(9961.38) + (-381.654*@0) + (5.83785*@0*@0) + (-0.0445624*@0*@0*@0) + (0.000169746*@0*@0*@0*@0) + (-2.58122e-07*@0*@0*@0*@0*@0)";
    }
    else {
      if (ch == 0) fss << "(-5610.63) + (212.57*@0) + (-3.2137*@0*@0) + (0.024235*@0*@0*@0) + (-9.11651e-05*@0*@0*@0*@0) + (1.36857e-07*@0*@0*@0*@0*@0)";
      if (ch == 1) fss << "(578.388) + (-19.2295*@0) + (0.249414*@0*@0) + (-0.00156402*@0*@0*@0) + (4.66922e-06*@0*@0*@0*@0) + (-5.15396e-09*@0*@0*@0*@0*@0)";
      if (ch == 2) fss << "(-2080.58) + (77.8248*@0) + (-1.1614*@0*@0) + (0.00864348*@0*@0*@0) + (-3.20828e-05*@0*@0*@0*@0) + (4.7516e-08*@0*@0*@0*@0*@0)";
    }

    fss << " ) +  @0*@1";

    return fss.str();

}

std::string getSignalACBSigmaString(int ch, bool do7TeV) {
    stringstream fss;
    fss << "( ";

    if (do7TeV) {
      if (ch == 0) fss << "(-1365.41) + (52.5832*@0) + (-0.808963*@0*@0) + (0.00621652*@0*@0*@0) + (-2.38528e-05*@0*@0*@0*@0) + (3.65518e-08*@0*@0*@0*@0*@0)";
      if (ch == 1) fss << "(28.2466) + (-0.620451*@0) + (0.00480095*@0*@0) + (-1.20793e-05*@0*@0*@0)";
      if (ch == 2) fss << "(301.006) + (-12.4853*@0) + (0.202481*@0*@0) + (-0.00160639*@0*@0*@0) + (6.25857e-06*@0*@0*@0*@0) + (-9.60019e-09*@0*@0*@0*@0*@0)";
    }
    else {
      if (ch == 0) fss << "(-262.457) + (7.19346*@0) + (-0.06682*@0*@0) + (0.000188319*@0*@0*@0) + (4.80395e-07*@0*@0*@0*@0) + (-2.50775e-09*@0*@0*@0*@0*@0)";
      if (ch == 1) fss << "(9463.43) + (-363.801*@0) + (5.58469*@0*@0) + (-0.042781*@0*@0*@0) + (0.000163529*@0*@0*@0*@0) + (-2.4951e-07*@0*@0*@0*@0*@0)";
      if (ch == 2) fss << "(2616.92) + (-96.7344*@0) + (1.42558*@0*@0) + (-0.0104643*@0*@0*@0) + (3.82629e-05*@0*@0*@0*@0) + (-5.57557e-08*@0*@0*@0*@0*@0)";
    }
    fss << " ) * (1+@1)";
    return fss.str();
}

std::string getSignalACBAlphaLString(int ch, bool do7TeV) {
    stringstream fss;

    if (do7TeV) {
      if (ch == 0) fss << "(11377.9) + (-434.904*@0) + (6.63511*@0*@0) + (-0.0504989*@0*@0*@0) + (0.000191727*@0*@0*@0*@0) + (-2.90491e-07*@0*@0*@0*@0*@0)";
      if (ch == 1) fss << "(6.35039) + (-0.1231*@0) + (0.000976223*@0*@0) + (-2.56707e-06*@0*@0*@0)";
      if (ch == 2) fss << "(687.274) + (-26.0742*@0) + (0.393449*@0*@0) + (-0.0029466*@0*@0*@0) + (1.09516e-05*@0*@0*@0*@0) + (-1.6159e-08*@0*@0*@0*@0*@0)";
    }
    else {
      if (ch == 0) fss << "(-1103.11) + (40.2738*@0) + (-0.585011*@0*@0) + (0.00423019*@0*@0*@0) + (-1.52245e-05*@0*@0*@0*@0) + (2.18134e-08*@0*@0*@0*@0*@0)";
      if (ch == 1) fss << "(-1112.99) + (39.1361*@0) + (-0.544*@0*@0) + (0.00373658*@0*@0*@0) + (-1.26639e-05*@0*@0*@0*@0) + (1.6908e-08*@0*@0*@0*@0*@0)";
      if (ch == 2) fss << "(-1263.91) + (52.3695*@0) + (-0.860155*@0*@0) + (0.00701184*@0*@0*@0) + (-2.83847e-05*@0*@0*@0*@0) + (4.5668e-08*@0*@0*@0*@0*@0)";
    }

    return fss.str();
}

std::string getSignalACBAlphaRString(int ch, bool do7TeV) {
    stringstream fss;

    if (do7TeV) {
      if (ch == 0) fss << "(4019.03) + (-157.485*@0) + (2.46088*@0*@0) + (-0.0191559*@0*@0*@0) + (7.42719e-05*@0*@0*@0*@0) + (-1.14739e-07*@0*@0*@0*@0*@0)";
      if (ch == 1) fss << "(-27.2451) + (0.689038*@0) + (-0.00541835*@0*@0) + (1.41309e-05*@0*@0*@0)";
      if (ch == 2) fss << "(14908.3) + (-573.045*@0) + (8.78832*@0*@0) + (-0.0672107*@0*@0*@0) + (0.000256324*@0*@0*@0*@0) + (-3.89989e-07*@0*@0*@0*@0*@0)";
    }
    else {
      if (ch == 0) fss << "(-5790.11) + (210.816*@0) + (-3.05796*@0*@0) + (0.0220949*@0*@0*@0) + (-7.95151e-05*@0*@0*@0*@0) + (1.14013e-07*@0*@0*@0*@0*@0)";
      if (ch == 1) fss << "(17713.6) + (-672.074*@0) + (10.1843*@0*@0) + (-0.0770338*@0*@0*@0) + (0.000290835*@0*@0*@0*@0) + (-4.38426e-07*@0*@0*@0*@0*@0)";
      if (ch == 2) fss << "(-3319.49) + (130.258*@0) + (-2.03779*@0*@0) + (0.015895*@0*@0*@0) + (-6.18147e-05*@0*@0*@0*@0) + (9.58797e-08*@0*@0*@0*@0*@0)";
    }

    return fss.str();
}


std::string getSignalCBMeanString(float m, int ch, bool do7TeV, bool doFFT) {
    stringstream fss;
    if (m<400.) fss << "( ";  

    if (!doFFT) fss << "@0 + ";

    if (m<400.) {
      if (do7TeV) {
        if (ch == 0) fss << "(-6.1079) + (0.167135*@0) + (-0.00173297*@0*@0) + (8.41436e-06*@0*@0*@0) + (-1.93623e-08*@0*@0*@0*@0) + (1.70215e-11*@0*@0*@0*@0*@0)";
        if (ch == 1) fss << "(-6.79743) + (0.205898*@0) + (-0.00234078*@0*@0) + (1.22413e-05*@0*@0*@0) + (-2.98971e-08*@0*@0*@0*@0) + (2.74991e-11*@0*@0*@0*@0*@0)";
        if (ch == 2) fss << "(-2.13163) + (0.06424*@0) + (-0.000719368*@0*@0) + (3.6258e-06*@0*@0*@0) + (-8.58607e-09*@0*@0*@0*@0) + (7.73984e-12*@0*@0*@0*@0*@0)";
      }
      else {
        if (ch == 0) fss << "(-15.2428) + (0.42122*@0) + (-0.00447937*@0*@0) + (2.26779e-05*@0*@0*@0) + (-5.482e-08*@0*@0*@0*@0) + (5.05978e-11*@0*@0*@0*@0*@0)";
        if (ch == 1) fss << "(-4.03873) + (0.142765*@0) + (-0.00182324*@0*@0) + (1.04662e-05*@0*@0*@0) + (-2.78456e-08*@0*@0*@0*@0) + (2.78107e-11*@0*@0*@0*@0*@0)";
        if (ch == 2) fss << "(-10.9222) + (0.303444*@0) + (-0.00323681*@0*@0) + (1.63907e-05*@0*@0*@0) + (-3.96643e-08*@0*@0*@0*@0) + (3.6718e-11*@0*@0*@0*@0*@0)";
      }
    }
    else {
      if (do7TeV) {
        if (ch == 0) fss << "(-37.3605) + (0.16104*@0) + (-0.000135637*@0*@0) + (-3.60719e-08*@0*@0*@0)";
        if (ch == 1) fss << "(74.9049) + (-0.422597*@0) + (0.000826695*@0*@0) + (-5.40726e-07*@0*@0*@0)";
        if (ch == 2) fss << "(48.1328) + (-0.281179*@0) + (0.000587659*@0*@0) + (-4.13174e-07*@0*@0*@0)";
      }
      else {
        if (ch == 0) fss << "(-6.41691) + (0.0280361*@0) + (8.63703e-06*@0*@0) + (-6.02868e-08*@0*@0*@0)";
        if (ch == 1) fss << "(-99.8383) + (0.485366*@0) + (-0.000667099*@0*@0) + (2.41678e-07*@0*@0*@0)";
        if (ch == 2) fss << "(46.2677) + (-0.23461*@0) + (0.000415771*@0*@0) + (-2.49403e-07*@0*@0*@0)";
      }
    }

    if (m<400.) {
        if (ch == 0 || ch == 1) fss << " ) +  @0*@1";
        else                    fss << " ) +  @0*@1";
    }
    return fss.str();
}

std::string getSignalCBSigmaString(float m, int ch, bool do7TeV) {
    stringstream fss;
    if (m<400.) fss << "( ";  

    if (m<400.) {
      if (do7TeV) {
        if (ch == 0) fss << "(-11.9644) + (0.322417*@0) + (-0.00316474*@0*@0) + (1.52947e-05*@0*@0*@0) + (-3.52316e-08*@0*@0*@0*@0) + (3.11258e-11*@0*@0*@0*@0*@0)";
        if (ch == 1) fss << "(7.60884) + (-0.136629*@0) + (0.00109711*@0*@0) + (-3.42615e-06*@0*@0*@0) + (4.2221e-09*@0*@0*@0*@0) + (-1.15089e-12*@0*@0*@0*@0*@0)";
        if (ch == 2) fss << "(-37.2709) + (1.04312*@0) + (-0.0109539*@0*@0) + (5.58378e-05*@0*@0*@0) + (-1.36553e-07*@0*@0*@0*@0) + (1.28701e-10*@0*@0*@0*@0*@0)";
      }
      else {
        if (ch == 0) fss << "(-7.90106) + (0.215914*@0) + (-0.00204471*@0*@0) + (9.51991e-06*@0*@0*@0) + (-2.05431e-08*@0*@0*@0*@0) + (1.67545e-11*@0*@0*@0*@0*@0)";
        if (ch == 1) fss << "(7.8429) + (-0.176575*@0) + (0.00186777*@0*@0) + (-8.96356e-06*@0*@0*@0) + (2.09583e-08*@0*@0*@0*@0) + (-1.91015e-11*@0*@0*@0*@0*@0)";
        if (ch == 2) fss << "(-19.3154) + (0.526495*@0) + (-0.00518631*@0*@0) + (2.47189e-05*@0*@0*@0) + (-5.56479e-08*@0*@0*@0*@0) + (4.76618e-11*@0*@0*@0*@0*@0)";
      }
    }
    else {
      if (do7TeV) {
        if (ch == 0) fss << "(-1466.27) + (13.999*@0) + (-0.0515713*@0*@0) + (9.14173e-05*@0*@0*@0) + (-7.77111e-08*@0*@0*@0*@0) + (2.55656e-11*@0*@0*@0*@0*@0)";
        if (ch == 1) fss << "(-308.2) + (3.86357*@0) + (-0.0170954*@0*@0) + (3.45735e-05*@0*@0*@0) + (-3.23298e-08*@0*@0*@0*@0) + (1.15216e-11*@0*@0*@0*@0*@0)";
        if (ch == 2) fss << "(1215.74) + (-9.92514*@0) + (0.0318114*@0*@0) + (-5.04198e-05*@0*@0*@0) + (4.00774e-08*@0*@0*@0*@0) + (-1.26592e-11*@0*@0*@0*@0*@0)";
      }
      else {
        if (ch == 0) fss << "TMath::Max((-432.572) + (3.29719*@0) + (-0.0101818*@0*@0) + (1.56988e-05*@0*@0*@0) + (-1.15531e-08*@0*@0*@0*@0) + (3.3178e-12*@0*@0*@0*@0*@0),1.)";
        if (ch == 1) fss << "TMath::Max((477.628) + (-2.99693*@0) + (0.0067043*@0*@0) + (-6.53915e-06*@0*@0*@0) + (3.02364e-09*@0*@0*@0*@0) + (-5.31362e-13*@0*@0*@0*@0*@0),1.);";
        if (ch == 2) fss << "TMath::Max((-1368.8) + (12.213*@0) + (-0.0422059*@0*@0) + (7.02931e-05*@0*@0*@0) + (-5.59847e-08*@0*@0*@0*@0) + (1.71866e-11*@0*@0*@0*@0*@0),1.)";
      }
    }
    
    if (m<400.) {
        if (ch == 0 || ch == 1) fss << " ) * (1+@1)";
        else                    fss << " ) * (1+@1)";
    }
    return fss.str();
}

std::string getSignalCBAlphaLString(float m, int ch, bool do7TeV) {
    stringstream fss;
   
    if (m<400.) {
      if (do7TeV) {
        if (ch == 0) fss << "(-8.78895) + (0.243604*@0) + (-0.00224593*@0*@0) + (9.85662e-06*@0*@0*@0) + (-2.07242e-08*@0*@0*@0*@0) + (1.68193e-11*@0*@0*@0*@0*@0)";
        if (ch == 1) fss << "(5.09741) + (-0.0927372*@0) + (0.000775468*@0*@0) + (-3.11759e-06*@0*@0*@0) + (6.42245e-09*@0*@0*@0*@0) + (-5.39568e-12*@0*@0*@0*@0*@0)";
        if (ch == 2) fss << "(-38.6983) + (1.05514*@0) + (-0.0107969*@0*@0) + (5.30736e-05*@0*@0*@0) + (-1.25309e-07*@0*@0*@0*@0) + (1.1426e-10*@0*@0*@0*@0*@0)";
      }
      else {
        if (ch == 0) fss << "(-3.6088) + (0.107156*@0) + (-0.000832395*@0*@0) + (2.76884e-06*@0*@0*@0) + (-3.4753e-09*@0*@0*@0*@0) + (6.63626e-13*@0*@0*@0*@0*@0)";
        if (ch == 1) fss << "(-1.97072) + (0.0725852*@0) + (-0.000670387*@0*@0) + (2.75605e-06*@0*@0*@0) + (-4.67709e-09*@0*@0*@0*@0) + (2.41684e-12*@0*@0*@0*@0*@0)";
        if (ch == 2) fss << "(-14.6609) + (0.399488*@0) + (-0.00385576*@0*@0) + (1.74976e-05*@0*@0*@0) + (-3.71685e-08*@0*@0*@0*@0) + (2.97992e-11*@0*@0*@0*@0*@0)";
      }
    }
    else {
      if (do7TeV) {
        if (ch == 0) fss << "(122.238) + (-0.619049*@0) + (0.00107841*@0*@0) + (-5.92523e-07*@0*@0*@0) + (-2.13616e-10*@0*@0*@0*@0) + (2.27662e-13*@0*@0*@0*@0*@0)";
        if (ch == 1) fss << "(294.765) + (-2.04895*@0) + (0.0057221*@0*@0) + (-7.9927e-06*@0*@0*@0) + (5.57788e-09*@0*@0*@0*@0) + (-1.55403e-12*@0*@0*@0*@0*@0)";
        if (ch == 2) fss << "(-544.401) + (4.25525*@0) + (-0.0127769*@0*@0) + (1.86394e-05*@0*@0*@0) + (-1.3293e-08*@0*@0*@0*@0) + (3.72304e-12*@0*@0*@0*@0*@0)";
      }
      else {
        if (ch == 0) fss << "(-42.2779) + (0.443877*@0) + (-0.00157254*@0*@0) + (2.55569e-06*@0*@0*@0) + (-1.95761e-09*@0*@0*@0*@0) + (5.73647e-13*@0*@0*@0*@0*@0)";
        if (ch == 1) fss << "(490.924) + (-3.40932*@0) + (0.00934933*@0*@0) + (-1.26364e-05*@0*@0*@0) + (8.42624e-09*@0*@0*@0*@0) + (-2.22e-12*@0*@0*@0*@0*@0)";
        if (ch == 2) fss << "(444.048) + (-3.02643*@0) + (0.00816391*@0*@0) + (-1.08777e-05*@0*@0*@0) + (7.16619e-09*@0*@0*@0*@0) + (-1.86934e-12*@0*@0*@0*@0*@0)";
      }
    }

    return fss.str();
}

std::string getSignalCBNLString(float m, int ch, bool do7TeV) {
    stringstream fss;

    if (m<400.) {
      if (do7TeV) {
        if (ch == 0) fss << "TMath::Max((23.0806) + (-0.485634*@0) + (0.00435146*@0*@0) + (-1.85587e-05*@0*@0*@0) + (3.77321e-08*@0*@0*@0*@0) + (-2.95482e-11*@0*@0*@0*@0*@0),1)";
        if (ch == 1) fss << "TMath::Max((-69.5367) + (1.68327*@0) + (-0.0140301*@0*@0) + (5.44368e-05*@0*@0*@0) + (-1.01044e-07*@0*@0*@0*@0) + (7.27363e-11*@0*@0*@0*@0*@0),1)";
        if (ch == 2) fss << "TMath::Max((33.5773) + (-0.884627*@0) + (0.00992575*@0*@0) + (-5.24725e-05*@0*@0*@0) + (1.29971e-07*@0*@0*@0*@0) + (-1.22018e-10*@0*@0*@0*@0*@0),1)";
      }
      else {
        if (ch == 0) fss << "TMath::Max((21.8412) + (-0.457725*@0) + (0.00405228*@0*@0) + (-1.69485e-05*@0*@0*@0) + (3.3184e-08*@0*@0*@0*@0) + (-2.44899e-11*@0*@0*@0*@0*@0),1)";
        if (ch == 1) fss << "TMath::Max((-68.5573) + (1.68878*@0) + (-0.0144006*@0*@0) + (5.76535e-05*@0*@0*@0) + (-1.11285e-07*@0*@0*@0*@0) + (8.38162e-11*@0*@0*@0*@0*@0),1)";
        if (ch == 2) fss << "TMath::Max((-13.9463) + (0.328247*@0) + (-0.00208904*@0*@0) + (5.30154e-06*@0*@0*@0) + (-4.91882e-09*@0*@0*@0*@0) + (4.42671e-13*@0*@0*@0*@0*@0),1)";
      }
    }
    else {
      if (do7TeV) {
        if (ch == 0) fss << "5.";
        if (ch == 1) fss << "5.";
        if (ch == 2) fss << "5.";
      }
      else {
        if (ch == 0) fss << "5.";
        if (ch == 1) fss << "5.";
        if (ch == 2) fss << "5.";
      }
    }

    return fss.str();
}

std::string getSignalCBAlphaRString(float m, int ch, bool do7TeV) {
    stringstream fss;

    if (m<400.) {
      if (do7TeV) {
        if (ch == 0) fss << "(34.3845) + (-0.842213*@0) + (0.00830027*@0*@0) + (-3.91737e-05*@0*@0*@0) + (8.85372e-08*@0*@0*@0*@0) + (-7.6354e-11*@0*@0*@0*@0*@0)";
        if (ch == 1) fss << "(5.99445) + (-0.0781315*@0) + (0.000261967*@0*@0) + (1.59983e-06*@0*@0*@0) + (-1.08286e-08*@0*@0*@0*@0) + (1.67934e-11*@0*@0*@0*@0*@0)";
        if (ch == 2) fss << "(-131.564) + (4.04312*@0) + (-0.0479457*@0*@0) + (0.000275903*@0*@0*@0) + (-7.67618e-07*@0*@0*@0*@0) + (8.25323e-10*@0*@0*@0*@0*@0)";
      }
      else {
        if (ch == 0) fss << "(-19.5288) + (0.525804*@0) + (-0.00487398*@0*@0) + (2.03764e-05*@0*@0*@0) + (-3.66955e-08*@0*@0*@0*@0) + (2.20557e-11*@0*@0*@0*@0*@0)";
        if (ch == 1) fss << "(134.772) + (-3.52321*@0) + (0.0358562*@0*@0) + (-0.000175381*@0*@0*@0) + (4.115e-07*@0*@0*@0*@0) + (-3.69445e-10*@0*@0*@0*@0*@0)";
        if (ch == 2) fss << "(10.0277) + (-0.243287*@0) + (0.0026732*@0*@0) + (-1.45571e-05*@0*@0*@0) + (3.9265e-08*@0*@0*@0*@0) + (-4.02105e-11*@0*@0*@0*@0*@0)";
      }
    }
    else {
      if (do7TeV) {
        if (ch == 0) fss << "(0.759191) + (0.000450461*@0)";
        if (ch == 1) fss << "TMath::Max((2194.76) + (-17.3968*@0) + (0.0543999*@0*@0) + (-8.38711e-05*@0*@0*@0) + (6.37441e-08*@0*@0*@0*@0) + (-1.90937e-11*@0*@0*@0*@0*@0),1.)";
        if (ch == 2) fss << "TMath::Max((1930.45) + (-14.9001*@0) + (0.0451276*@0*@0) + (-6.70106e-05*@0*@0*@0) + (4.87907e-08*@0*@0*@0*@0) + (-1.39331e-11*@0*@0*@0*@0*@0),1.)";
      }
      else {
        if (ch == 0) fss << "(0.941385) + (9.68065e-05*@0)";
        if (ch == 1) fss << "(0.320852) + (0.00116058*@0)";
        if (ch == 2) fss << "(0.996315) + (7.40185e-06*@0)";
      }
    }

    return fss.str();
}

std::string getSignalCBNRString(float m, int ch, bool do7TeV) {
    stringstream fss;
    
    if (m<400.) {
      if (do7TeV) {
        if (ch == 0) fss << "20";
        if (ch == 1) fss << "20";
        if (ch == 2) fss << "20";
      }
      else {
        if (ch == 0) fss << "20";
        if (ch == 1) fss << "20";
        if (ch == 2) fss << "20";
      }
    }
    else {
      if (do7TeV) {
        if (ch == 0) fss << "20";
        if (ch == 1) fss << "20";
        if (ch == 2) fss << "20";
      }
      else {
        if (ch == 0) fss << "20";
        if (ch == 1) fss << "20";
        if (ch == 2) fss << "20";
      }
    }

    return fss.str();
}


std::string getSignalBWGammaString(float m, int ch, bool do7TeV) {
    stringstream fss;
    fss << "( ";  

    if (do7TeV) {
      if (ch == 0) fss << "TMath::Max((-151.23) + (0.566127*@0) + (-0.000313658*@0*@0),20)";
      if (ch == 1) fss << "TMath::Max((-396.585) + (2.00647*@0) + (-0.00301621*@0*@0) + (1.58572e-06*@0*@0*@0),20)";
      if (ch == 2) fss << "TMath::Max((54.8246) + (-0.139948*@0) + (0.000237799*@0*@0),20)";
    }
    else {
      if (ch == 0) fss << "TMath::Max((17.9981) + (-0.0235633*@0) + (0.000160994*@0*@0),20)";
      if (ch == 1) fss << "TMath::Max((-7.17119) + (0.0763212*@0) + (6.92004e-05*@0*@0)+(0.1*@0-46.0)*(@0<450),20)";
      if (ch == 2) fss << "TMath::Max((-39.9023) + (0.177439*@0) + (2.3931e-07*@0*@0),20)";
    }

    fss << " ) * (1+@1)";    
    return fss.str();
}

std::string getSignalEBELandauMeanString(int ch, bool do7TeV) {
  stringstream fss;
  if (do7TeV) {
    if (ch == 0) fss << "(0.0134009) + (-8.01228e-05*@0) + (2.77214e-07*@0*@0)";
    if (ch == 1) fss << "(-0.00687259) + (0.000211674*@0) + (-7.26176e-07*@0*@0)";
    if (ch == 2) fss << "(0.0210129) + (-0.000220759*@0) + (8.7588e-07*@0*@0)";
  } 
  else {
    if (ch == 0) fss << "(0.146537) + (-0.00221371*@0) + (8.81577e-06*@0*@0)";
    if (ch == 1) fss << "(0.00798885) + (2.07364e-05*@0) + (-7.68043e-08*@0*@0)";
    if (ch == 2) fss << "(-0.0303858) + (0.000587672*@0) + (-2.21995e-06*@0*@0)";
  } 
  return fss.str();
}

std::string getSignalEBELandauSigmaString(int ch, bool do7TeV) {
  stringstream fss;
  if (do7TeV) {
    if (ch == 0) fss << "(-0.00408833) + (8.28301e-05*@0) + (-3.23195e-07*@0*@0)";
    if (ch == 1) fss << "(0.000955492) + (7.11031e-06*@0) + (-3.35679e-08*@0*@0)";
    if (ch == 2) fss << "(0.00379671) + (-4.41107e-05*@0) + (1.7516e-07*@0*@0)";
  } 
  else {
    if (ch == 0) fss << "(-0.00136417) + (3.93313e-05*@0) + (-1.5185e-07*@0*@0)";
    if (ch == 1) fss << "(0.0040108) + (-3.60197e-05*@0) + (1.16329e-07*@0*@0)";
    if (ch == 2) fss << "(-0.0164325) + (0.000268018*@0) + (-1.00625e-06*@0*@0)";
  } 
  return fss.str();
}

std::string getSignalEBELogNMeanString(int ch, bool do7TeV) {
  stringstream fss;
  if (do7TeV) {
    if (ch == 0) fss << "(0.0134009) + (-8.01228e-05*@0) + (2.77214e-07*@0*@0)";
    if (ch == 1) fss << "ERROR! not a log normal for 4e!";
    if (ch == 2) fss << "ERROR! not a log normal for 2e2mu!";
  } 
  else {
    if (ch == 0) fss << "(0.146537) + (-0.00221371*@0) + (8.81577e-06*@0*@0)";
    if (ch == 1) fss << "ERROR! not a log normal for 4e!";
    if (ch == 2) fss << "ERROR! not a log normal for 2e2mu!";
  } 
  return fss.str();
}

std::string getSignalEBELogNKString(int ch, bool do7TeV) {
  stringstream fss;
  if (do7TeV) {
    if (ch == 0) fss << "(1.09548) + (-0.00429616*@0) + (1.42497e-05*@0*@0)";
    if (ch == 1) fss << "ERROR! not a log normal for 4e!";
    if (ch == 2) fss << "ERROR! not a log normal for 2e2mu!";
  } 
  else {
    if (ch == 0) fss << "(1.35325) + (-0.00927874*@0) + (3.68071e-05*@0*@0)";
    if (ch == 1) fss << "ERROR! not a log normal for 4e!";
    if (ch == 2) fss << "ERROR! not a log normal for 2e2mu!";
  } 
  return fss.str();
}

std::string getSignalEBEGaussianMeanString(int ch, bool do7TeV) {
  stringstream fss;
  if (do7TeV) {
    if (ch == 0) fss << "ERROR! not a Gaussian for 4mu!";
    if (ch == 1) fss << "(0.0792865) + (-0.00094503*@0) + (3.55867e-06*@0*@0)";
    if (ch == 2) fss << "(0.0150001) + (-1.00122e-09*@0) + (3.89981e-12*@0*@0)";
  } 
  else {
    if (ch == 0) fss << "ERROR! not a Gaussian for 4mu!";
    if (ch == 1) fss << "(0.0481624) + (-0.00040788*@0) + (1.33567e-06*@0*@0)";
    if (ch == 2) fss << "(0.016304) + (1.22315e-05*@0) + (-1.4359e-07*@0*@0)";
  } 
  return fss.str();
}

std::string getSignalEBEGaussianSigmaString(int ch, bool do7TeV) {
  stringstream fss;
  if (do7TeV) {
    if (ch == 0) fss << "ERROR! not a Gaussian for 4mu!";
    if (ch == 1) fss << "(0.00812389) + (-4.66255e-05*@0) + (1.55668e-07*@0*@0)";
    if (ch == 2) fss << "(0.00853809) + (-6.01857e-05*@0) + (1.93121e-07*@0*@0)";
  } 
  else {
    if (ch == 0) fss << "ERROR! not a Gaussian for 4mu!";
    if (ch == 1) fss << "(-0.00433283) + (0.000134763*@0) + (-5.13103e-07*@0*@0)";
    if (ch == 2) fss << "(0.00421353) + (4.27287e-06*@0) + (-5.9121e-08*@0*@0)";
  } 
  return fss.str();
}

std::string getSignalEBELandauFracString(int ch, bool do7TeV) {
  stringstream fss;
  if (do7TeV) {
    if (ch == 0) fss << "(-6.35246) + (0.106138*@0) + (-0.000406468*@0*@0)";
    if (ch == 1) fss << "(-2.63862) + (0.0528919*@0) + (-0.000210164*@0*@0)";
    if (ch == 2) fss << "(-0.142724) + (0.0132325*@0) + (-4.92025e-05*@0*@0)";
  } 
  else {
    if (ch == 0) fss << "(0.407962) + (0.00116124*@0) + (-7.66417e-07*@0*@0)";
    if (ch == 1) fss << "(0.414303) + (0.00661032*@0) + (-4.01388e-05*@0*@0)";
    if (ch == 2) fss << "(-0.565547) + (0.0204287*@0) + (-8.13434e-05*@0*@0)";
  } 
  return fss.str();
}

std::string getYieldEfficiencyString(float m, int ch, bool do7TeV) {
    stringstream fss;

    if (do7TeV) {
        if      (ch == 0) return "(-3.7706) + (0.0796283)*@0 + (-0.000602973)*@0*@0 + (2.49098e-06)*@0*@0*@0 + (-6.16741e-09)*@0*@0*@0*@0 + (9.52592e-12)*@0*@0*@0*@0*@0 + (-9.22178e-15)*@0*@0*@0*@0*@0*@0 + (5.42269e-18)*@0*@0*@0*@0*@0*@0*@0 + (-1.76573e-21)*@0*@0*@0*@0*@0*@0*@0*@0 + (2.43457e-25)*@0*@0*@0*@0*@0*@0*@0*@0*@0";
        else if (ch == 1) return "(-1.64845) + (0.0231369)*@0 + (-2.65764e-05)*@0*@0 + (-7.3702e-07)*@0*@0*@0 + (4.8123e-09)*@0*@0*@0*@0 + (-1.40977e-11)*@0*@0*@0*@0*@0 + (2.30675e-14)*@0*@0*@0*@0*@0*@0 + (-2.17259e-17)*@0*@0*@0*@0*@0*@0*@0 + (1.10249e-20)*@0*@0*@0*@0*@0*@0*@0*@0 + (-2.3382e-24)*@0*@0*@0*@0*@0*@0*@0*@0*@0";
        else              return "(-3.44986) + (0.07331)*@0 + (-0.00056394)*@0*@0 + (2.3445e-06)*@0*@0*@0 + (-5.71751e-09)*@0*@0*@0*@0 + (8.36146e-12)*@0*@0*@0*@0*@0 + (-7.10656e-15)*@0*@0*@0*@0*@0*@0 + (3.09027e-18)*@0*@0*@0*@0*@0*@0*@0 + (-3.86211e-22)*@0*@0*@0*@0*@0*@0*@0*@0 + (-9.09233e-26)*@0*@0*@0*@0*@0*@0*@0*@0*@0";
    }
    else {
        if      (ch == 0) return "(-3.50283) + (0.0732612)*@0 + (-0.000538529)*@0*@0 + (2.10457e-06)*@0*@0*@0 + (-4.71619e-09)*@0*@0*@0*@0 + (6.07443e-12)*@0*@0*@0*@0*@0 + (-4.07444e-15)*@0*@0*@0*@0*@0*@0 + (7.84015e-19)*@0*@0*@0*@0*@0*@0*@0 + (5.33848e-22)*@0*@0*@0*@0*@0*@0*@0*@0 + (-2.36464e-25)*@0*@0*@0*@0*@0*@0*@0*@0*@0";
        else if (ch == 1) return "(-1.18151) + (0.0101292)*@0 + (0.000110575)*@0*@0 + (-1.49343e-06)*@0*@0*@0 + (7.26202e-09)*@0*@0*@0*@0 + (-1.89963e-11)*@0*@0*@0*@0*@0 + (2.91799e-14)*@0*@0*@0*@0*@0*@0 + (-2.63516e-17)*@0*@0*@0*@0*@0*@0*@0 + (1.29623e-20)*@0*@0*@0*@0*@0*@0*@0*@0 + (-2.68166e-24)*@0*@0*@0*@0*@0*@0*@0*@0*@0";
        else              return "(-3.1813) + (0.0663403)*@0 + (-0.00050051)*@0*@0 + (2.06232e-06)*@0*@0*@0 + (-5.06335e-09)*@0*@0*@0*@0 + (7.65102e-12)*@0*@0*@0*@0*@0 + (-7.06088e-15)*@0*@0*@0*@0*@0*@0 + (3.76445e-18)*@0*@0*@0*@0*@0*@0*@0 + (-9.98403e-22)*@0*@0*@0*@0*@0*@0*@0*@0 + (8.30617e-26)*@0*@0*@0*@0*@0*@0*@0*@0*@0";
    }

    return fss.str();
}

