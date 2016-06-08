#!/bin/sh

#set Minimal/Apps/FitterSettings.h first !!!!!
#check folder name (ODN) is different from past 

#changing 23
end=40

cd /home/t2k/thiraki/work/osc/JointFitter/Minimal/bin
DIR=/home/t2k/thiraki/work/osc/JointFitter/Minimal
OD=antinu_20150603_bf_23_goodness_4000
mkdir ../Output/BF/${OD}
mkdir ../job/log/${OD}

count=0
inum=0
while [ ${count} -ne ${end} ]
do

inum=`expr $1 \* ${end} - ${end} + ${count}`
OFN=bf_`printf %04d ${inum}`

./BestFit \
-f ${DIR}/Tools/Matrix/covmat_post_antinuonly_erec_20150603_m.root \
-p ${DIR}/inputs/NuePDF/anti-nu_20150603 \
-pm ${DIR}/inputs/NumuPDF/antinumode_numu_binning_20150603coarse.root \
-o ${DIR}/Output/BF/${OD}/${OFN}.root \
-xe ${DIR}/inputs/RFnue/nubar_beam \
-xmu ${DIR}/inputs/RFnumu/nubar_beam \
-sf ~/work/tmpOA/JointFitter/Minimal/Tools/splines_v8/weightsv8_t2ksk.14a.neut5.3.2.13a_tuned_v1r0.m250ka.fine.numu_x_numu_numuselec.root \
-e ${DIR}/Output/test/toyxp_datafit_20150603_4000_c_lratio.root \
-g 1 \
-t 2.8049 \
-m 1 \
-ex ${inum} \
> ${DIR}/job/log/${OD}/${OFN}.log 2>&1

usleep 100000
count=`expr ${count} + 1`

done
# -h inverted

