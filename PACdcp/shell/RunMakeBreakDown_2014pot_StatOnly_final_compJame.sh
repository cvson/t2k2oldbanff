#!/bin/bash

cd ../bin
#gdb --args \ 
./MakeBreakDown \
-f /home/t2k/cvson/ptheta/pac2016/Matrix/FullPthetaMatrix_postfit_xsec2015c_1p1h.root \
-pe ../../Inputs/PDFNue/numode_nue_binning_J/ \
-pm ../../Inputs/PDFNumu/numode_numu_binning_J.root \
-pbe ../../Inputs/PDFNue/antinu_nue_binning_J/ \
-pbm ../../Inputs/PDFNumu/antinu_numu_binning_J.root \
-xe ../inputs/RFnue/nu_beam/ \
-xmu ../inputs/RFnumu/nu_beam/ \
-xbe ../inputs/RFnue/nubar_beam/ \
-xbmu ../inputs/RFnumu/nubar_beam/ \
-tnb 0.4011 \
-tnu 0.6914 \
-sf ../inputs/SplineFile/weightsv8_t2ksk.14a.neut5.3.2.13a_tuned_v1r0.250ka.fine.numubar_x_numubar_numuselec.root \
-ft ../inputs/Throws/sys_throws_ptheta_rpaStatic_fix_new_500knomFF.root \
-n 0 \
-o ../outputs/BreakDown_PAC_2014pot_StatOnly_compJame.root
#-o ../outputs/BreakDown_PAC_30e21_StatOnly_sin0d6_dcppospiO2.root
#-o ../outputs/BreakDown_PAC_30e21_StatOnly_sin0d6_dcp0.root
#-o ../outputs/BreakDown_PAC_30e21_StatOnly_sin0d6_dcpnegpiO2.root
#-o ../outputs/BreakDown_PAC_30e21_StatOnly_sin0d43_dcpnegpiO2.root
#-o ../outputs/BreakDown_PAC_30e21_StatOnly_sin0d43_dcp0.root
#-o ../outputs/BreakDown_PAC_30e21_StatOnly_sin0d43_dcppospiO2.root
#-o ../outputs/BreakDown_PAC_30e21_StatOnly_sin0d5_dcppospiO2.root
#-o ../outputs/BreakDown_PAC_30e21_StatOnly_sin0d5_dcp0.root
#-ft ../inputs/Throws/sys_throws_ptheta_rpaStatic_fix_new_500knom.root \
#Run1-6 POT
#-tnb 0.4011 \
#-tnu 0.6914 \
