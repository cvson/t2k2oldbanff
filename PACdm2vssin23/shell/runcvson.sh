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
#end=3

echo "from $start"
echo "to $end"
cd /home/t2k/cvson/gpfs/ptheta/frHiraki/jnusrv20150612/JointFitter/Minimal/bin
DIR=/home/t2k/cvson/gpfs/ptheta/frHiraki/jnusrv20150612/JointFitter/Minimal
#OD=skdatafit_numubar_20150603fine_n_wr_nosyst
OD=test
#mkdir ../Output/MargFitter/${OD}
#mkdir ../job/log/${OD}
OFN=marg_`printf %04d $1`

./MargFitter \
-f ${DIR}/Tools/Matrix/covmat_post_antinuonly_erec_m.root \
-p ${DIR}/inputs/NuePDF/antinu_run5-6 \
-pm ${DIR}/inputs/NumuPDF/antinu_numu_run5-6.root \
-o ${DIR}/Output/MargFitter/${OD}/${OFN}.root \
-xe ${DIR}/inputs/RFnue/nubar_beam \
-xmu ${DIR}/inputs/RFnumu/nubar_beam \
-sf ${DIR}/Tools/splines_v8/weightsv8_t2ksk.14a.neut5.3.2.13a_tuned_v1r0.m250ka.fine.numu_x_numu_numuselec.root \
-n 10000 \
-e ${DIR}/Output/ToyXp/toyxp_antinu_run56.root \
-g 1 \
-t 2.8049 \
-b ${start} ${end} \
-m 2 \
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