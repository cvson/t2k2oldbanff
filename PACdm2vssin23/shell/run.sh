#!/bin/sh

#check -m, -r, -h 

#changing 13delta
#start=`expr $1 \* 17 - 17`
#end=17

#changing 23
#start=`expr $1 \* 21 - 21`                                                     
#end=21

start=`expr $1 \* 51 - 51`
end=51

cd /home/t2k/thiraki/work/osc/JointFitter/Minimal/bin
DIR=/home/t2k/thiraki/work/osc/JointFitter/Minimal
OD=skdatafit_numubar_20150603fine_n_wr_nosyst
mkdir ../Output/MargFitter/${OD}
mkdir ../job/log/${OD}
OFN=marg_`printf %04d $1`

./MargFitter \
-f ${DIR}/Tools/Matrix/covmat_post_antinuonly_erec_20150603_m.root \
-p ${DIR}/inputs/NuePDF/anti-nu_20150603 \
-pm ${DIR}/inputs/NumuPDF/antinumode_numu_binning_20150603.root \
-o ${DIR}/Output/MargFitter/${OD}/${OFN}.root \
-xe ${DIR}/inputs/RFnue/nubar_beam \
-xmu ${DIR}/inputs/RFnumu/nubar_beam \
-sf /home/t2k/thiraki/work/tmpOA/JointFitter/Minimal/Tools/splines_v8/weightsv8_t2ksk.14a.neut5.3.2.13a_tuned_v1r0.m250ka.fine.numu_x_numu_numuselec.root \
-n 0 \
-e ${DIR}/Output/test/antinu_run5-6_20150603.root \
-g 1 \
-t 2.8049 \
-b ${start} ${end} \
-m 1 \
> ${DIR}/job/log/${OD}/${OFN}.log 2>&1

# -h inverted
# -r with reactor
# -m <mode: 0<->app, 1<->disapp, 2<->joint >
# -e ${DIR}/../ToyXP/Smoothed_0_bis.root  toy experiment
# -e ${DIR}/../Data/Run1-4FQ.root  RUN1-4 data
# -e ${DIR}/Output/test/antinu_run5-6_20150603.root \
# -n 0 without throw
# -n 10000 with throw
# 1.43  1
# 1.7   1.1888
# 4.011 2.8049