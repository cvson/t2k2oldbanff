#!/bin/sh
source /home/t2k/cvson/rootr5v34.sh
cd /home/t2k/cvson/ptheta/pac2016/Ptheta_MultiSample/frJame/NueappPACdcp/bin
DIR=/home/t2k/cvson/gpfs/ptheta/pac2016/Ptheta_MultiSample/frJame/NueappPACdcp
DIRBASE=/home/t2k/cvson/gpfs/ptheta/pac2016/Ptheta_MultiSample/frJame

./MakeTemplate \
-f ${DIR}/Tools/Matrix/FullPthetaMatrix.root \
-pe ${DIRBASE}/Inputs/PDFNue/numode_nue_binning_J/ \
-pm ${DIRBASE}/Inputs/PDFNumu/numode_numu_binning_J.root \
-pbe ${DIRBASE}/Inputs/PDFNue/antinu_nue_binning_J/ \
-pbm ${DIRBASE}/Inputs/PDFNumu/antinu_numu_binning_J.root \
-xe ${DIR}/inputs/RFnue/nu_beam/ \
-xmu ${DIR}/inputs/RFnumu/nu_beam/ \
-xbe ${DIR}/inputs/RFnue/nubar_beam/ \
-xbmu ${DIR}/inputs/RFnumu/nubar_beam/ \
-tnb 10.0 \
-tnu 10.0 \
-sf ${DIR}/inputs/SplineFile/weightsv8_t2ksk.14a.neut5.3.2.13a_tuned_v1r0.250ka.fine.numubar_x_numubar_numuselec.root \
-ft ${DIR}/inputs/Throws/sys_throws_ptheta_rpaStatic_fix.root \
-n 100000 \
-o ${DIR}/outputs/Template_files/backup100k/Templates_pac20e21.root 


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
