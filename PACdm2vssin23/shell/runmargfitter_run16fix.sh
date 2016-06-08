#!/bin/sh

#set Minimal/Apps/FitterSettings.h first !!!!!
#check folder name (ODN) is different from past 

#changing 13delta
#end=17

#changing 23
##Start bin
NBIN=5

ODN=10000

cd /home/t2k/cvson/gpfs/ptheta/pac2016/Ptheta_MultiSample/frJame/Numudis/bin
DIR=/home/t2k/cvson/gpfs/ptheta/pac2016/Ptheta_MultiSample/frJame/Numudis
DIRBASE=/home/t2k/cvson/gpfs/ptheta/pac2016/Ptheta_MultiSample/frJame
OD=run16_fix_margfitter_${ODN}
mkdir ../outputs/MargFit_Results/${OD}
mkdir ../jobs/logs/${OD}

count=0
StartBin=0

StartBin=`expr $1 \* ${NBIN}`
OFN=merger_`printf %04d $1`

./MargFitter_nu_nubar \
-f ${DIR}/Tools/Matrix/FullPthetaMatrix.root \
-pe ${DIRBASE}/Inputs/PDFNue/numode_nue_binning_J/ \
-pm ${DIRBASE}/Inputs/PDFNumu/numode_numu_binning_J.root \
-pbe ${DIRBASE}/Inputs/PDFNue/antinu_nue_binning_J/ \
-pbm ${DIRBASE}/Inputs/PDFNumu/antinu_numu_binning_J.root \
-xe ${DIR}/inputs/RFnue/nu_beam/ \
-xmu ${DIR}/inputs/RFnumu/nu_beam/ \
-xbe ${DIR}/inputs/RFnue/nubar_beam/ \
-xbmu ${DIR}/inputs/RFnumu/nubar_beam/ \
-tnb 0.4011 \
-tnu 0.6914 \
-sf ${DIR}/inputs/SplineFile/weightsv8_t2ksk.14a.neut5.3.2.13a_tuned_v1r0.250ka.fine.numubar_x_numubar_numuselec.root \
-d ${DIR}/outputs/AsimovPoint01_Run1-6_Xp_fix.root \
-b ${StartBin} ${NBIN} \
-ft ${DIR}/inputs/Throws/sys_throws_ptheta_rpaStatic_fix.root \
-n ${ODN} \
-o ${DIR}/outputs/MargFit_Results/${OD}/${OFN}.root
> ${DIR}/jobs/logs/${OD}/${OFN}.log 2>&1


# -h inverted

# -t <template file> //from the result of maketemplate
# -t ${DIR}/Output/Template/template_antinu_test10000.root \ merging
# -t ${DIR}/Output/Template/template_antinu_test1.root \ fixing
# -ft <file with parameter throws> : prior
# -ft ${DIR}/inputs/Throws/Osc_2014_nom_noreactor.root \ normal hierarchy without reactor

#./Merger -t ../Output/Template/template_antinu_2015v1.root -p ../inputs/NuePDF/anti-nu_run_5_6 -pm ../inputs/NumuPDF/antinumode_numu_binning_run_5_6.root -o ../Output/test/hoge -ft ../inputs/Throws/Osc_2014_nom_noreactor.root -i 0 -n 1
