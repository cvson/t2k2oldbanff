#!/bin/sh

#set Minimal/Apps/FitterSettings.h first !!!!!
#check folder name (ODN) is different from past 

#changing 13delta
#end=17

#changing 23
#end=51
end=1 #dcp only

IDN=100000
#IDN=200000
ODN=100000
#ODN=50000
#ODN=10000
#ODN=200000

cd /home/t2k/cvson/gpfs/ptheta/pac2016/20151128/Ptheta_MultiSample/PACdcpsyst/bin
DIR=/home/t2k/cvson/gpfs/ptheta/pac2016/20151128/Ptheta_MultiSample/PACdcpsyst
DIRBASE=/home/t2k/cvson/gpfs/ptheta/pac2016/Ptheta_MultiSample/frJame

ID=pac7d8e21_100k4check_optv2s13off_inv_wreactorthrow_merger_${IDN}
OD=pac7d8e21_100k4check_optv2s13off_dcp26_inv_wreactorthrow_sensiAsimov_${ODN}
#ID=pac7d8e21_100k4checkAlt_optv2s13off_wreactorthrow_merger_${IDN}
#OD=pac7d8e21_100k4checkAlt_optv2s13off_wreactorthrow_sensiAsimov_${ODN}
#ID=pac7d8e21_100k4checkAltx2_optv2s13off_wreactorthrow_merger_${IDN}
#OD=pac7d8e21_100k4checkAltx2_optv2s13off_wreactorthrow_sensiAsimov_${ODN}

mkdir ../outputs/SensiAsimov/${OD}
mkdir ../jobs/logs/${OD}

count=0
inum=0
while [ ${count} -ne ${end} ]
do

inum=`expr $1 \* ${end} - ${end} + ${count}`
OFN=sensiAsimov_`printf %04d ${inum}`

./SensiAsimov_nu_nubar \
-a ${DIR}/outputs/Template_files/Templates_pac7d8e21.root \
-f ${DIR}/outputs/MergedFiles/${ID} \
-e ${DIR}/outputs/AsimovPoint01_PAC_7d8e21_Xp_StatOnly_dcp26.root \
-b ${inum} \
-ft ${DIR}/inputs/Throws/Osc_2015_Reac_dm32narrow_opt7d8v2s13off.root \
-h \
-n ${ODN} \
-o ${DIR}/outputs/SensiAsimov/${OD}/${OFN}.root \
> ${DIR}/jobs/logs/${OD}/${OFN}.log 2>&1

count=`expr ${count} + 1`

done
# -h inverted

# -t <template file> //from the result of maketemplate
# -t ${DIR}/Output/Template/template_antinu_test10000.root \ merging
# -t ${DIR}/Output/Template/template_antinu_test1.root \ fixing
# -ft <file with parameter throws> : prior
# -ft ${DIR}/inputs/Throws/Osc_2014_nom_noreactor.root \ normal hierarchy without reactor

#./Merger -t ../Output/Template/template_antinu_2015v1.root -p ../inputs/NuePDF/anti-nu_run_5_6 -pm ../inputs/NumuPDF/antinumode_numu_binning_run_5_6.root -o ../Output/test/hoge -ft ../inputs/Throws/Osc_2014_nom_noreactor.root -i 0 -n 1
