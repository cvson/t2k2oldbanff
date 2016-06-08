#!/bin/bash

cd ../bin

./OneSigma_NewCodeSys \
-f ../Tools/Matrix/FullPthetaMatrix.root \
-t 15 \
-xe ../inputs/RFnue/nubar_beam/ \
-xmu ../inputs/RFnumu/nubar_beam/ \
-pe ../../Inputs/PDFNue/antinu_nue_binning_J/ \
-pm ../../Inputs/PDFNumu/antinu_numu_binning_J.root \
-sf ../inputs/SplineFile/weightsv8_t2ksk.14a.neut5.3.2.13a_tuned_v1r0.250ka.fine.numubar_x_numubar_numuselec.root
#-xe ../inputs/RFnue/nu_beam/ \
#-xmu ../inputs/RFnumu/nu_beam/ \
#-pe ../../Inputs/PDFNue/numode_nue_binning_J/ \
#-pm ../../Inputs/PDFNumu/numode_numu_binning_J.root \ 
