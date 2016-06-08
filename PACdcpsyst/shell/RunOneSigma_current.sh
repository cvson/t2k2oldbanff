#!/bin/bash

cd ../bin

./OneSigma \
-f ../Tools/Matrix/FullPthetaMatrix.root \
-tnb 0.4011 \
-tnu 0.6914 \
-pe ../../Inputs/PDFNue/numode_nue_binning_J/ \
-pm ../../Inputs/PDFNumu/numode_numu_binning_J.root \
-pbe ../../Inputs/PDFNue/antinu_nue_binning_J/ \
-pbm ../../Inputs/PDFNumu/antinu_numu_binning_J.root \
-xe ../inputs/RFnue/nu_beam/ \
-xmu ../inputs/RFnumu/nu_beam/ \
-xbe ../inputs/RFnue/nubar_beam/ \
-xbmu ../inputs/RFnumu/nubar_beam/ \
-sf ../inputs/SplineFile/weightsv8_t2ksk.14a.neut5.3.2.13a_tuned_v1r0.250ka.fine.numubar_x_numubar_numuselec.root \
-n 100000
