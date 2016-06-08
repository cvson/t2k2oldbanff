#!/bin/bash

cd ../bin
#gdb --args \ 
./GenerateXP \
-f ../Tools/Matrix/FullPthetaMatrix.root \
-pe ../../Inputs/PDFNue/numode_nue_binning_J/ \
-pm ../../Inputs/PDFNumu/numode_numu_binning_J.root \
-pbe ../../Inputs/PDFNue/antinu_nue_binning_J/ \
-pbm ../../Inputs/PDFNumu/antinu_numu_binning_J.root \
-xe ../inputs/RFnue/nu_beam/ \
-xmu ../inputs/RFnumu/nu_beam/ \
-xbe ../inputs/RFnue/nubar_beam/ \
-xbmu ../inputs/RFnumu/nubar_beam/ \
-n 10000 \
-tnb 15.0 \
-tnu 15.0 \
-m 15 \
-s 0 \
-sf ../inputs/SplineFile/weightsv8_t2ksk.14a.neut5.3.2.13a_tuned_v1r0.250ka.fine.numubar_x_numubar_numuselec.root \
-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp39.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp38.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp37.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp36.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp35.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp34.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp33.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp32.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp31.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp30.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp29.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp28.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp27.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp26.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp25.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp24.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp23.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp22.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp21.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp20.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp19.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp18.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp17.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp16.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp15.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp14.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp13.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp12.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp11.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp10.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp9.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp8.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp7.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp6.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp5.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp4.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp3.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp2.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp1.root
#-o ../outputs/dcptruehi/AsimovPoint01_PAC_30e21_Xp_StatOnly.root

# -pe ../inputs/NuePDF/nu_2014/ \
# -pm ../inputs/NumuPDF/numode_numu_binning_2014.root \
# -pbe ../inputs/NuePDF/antinu_run5-6/ \
# -pbm ../inputs/NumuPDF/antinu_numu_run5-6.root \
# -tnb 2.79525 \
# -tnu 4.823 \

#Run1-6

#-tnb 0.4011 \
#-tnu 0.6914 \
