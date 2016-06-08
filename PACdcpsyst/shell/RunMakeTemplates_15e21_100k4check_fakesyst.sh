#!/bin/bash

cd ../bin
#gdb --args \ 
./MakeTemplate \
-f ../Tools/Matrix/FullPthetaMatrix.root \
-pe ../../Inputs/PDFNue/numode_nue_binning_J/ \
-pm ../../Inputs/PDFNumu/numode_numu_binning_J.root \
-pbe ../../Inputs/PDFNue/antinu_nue_binning_J/ \
-pbm ../../Inputs/PDFNumu/antinu_numu_binning_J.root \
-xe ../inputs/RFnue/nu_beam/ \
-xmu ../inputs/RFnumu/nu_beam/ \
-xbe ../inputs/RFnue/nubar_beam/ \
-xbmu ../inputs/RFnumu/nubar_beam/ \
-tnb 7.5 \
-tnu 7.5 \
-sf ../inputs/SplineFile/weightsv8_t2ksk.14a.neut5.3.2.13a_tuned_v1r0.250ka.fine.numubar_x_numubar_numuselec.root \
-ft ../inputs/Throws/sys_throws_ptheta_rpaStatic_fix_new_100k_fakesyst.root \
-n 100000 \
-o ../outputs/Template_files/Templates_pac15e21.root

# -pe ../inputs/NuePDF/nu_2014/ \
# -pm ../inputs/NumuPDF/numode_numu_binning_2014.root \
# -pbe ../inputs/NuePDF/antinu_run5-6/ \
# -pbm ../inputs/NumuPDF/antinu_numu_run5-6.root \
# -tnb 2.79525 \
# -tnu 4.823 \
#-ft ../inputs/Throws/sys_throws_ptheta.root \

#Run1-6 POT
#-tnb 0.4011 \
#-tnu 0.6914 \
