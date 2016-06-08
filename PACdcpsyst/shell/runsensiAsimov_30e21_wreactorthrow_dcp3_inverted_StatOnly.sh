#!/bin/sh

#set Minimal/Apps/FitterSettings.h first !!!!!
#check folder name (ODN) is different from past 

#changing 13delta
#end=17

#changing 23
#end=51
end=1 #dcp only

IDN=100000
ODN=100000
#ODN=50000
#ODN=10000

cd /home/t2k/cvson/gpfs/ptheta/pac2016/20151128/Ptheta_MultiSample/PACdcpsyst/bin
DIR=/home/t2k/cvson/gpfs/ptheta/pac2016/20151128/Ptheta_MultiSample/PACdcpsyst
DIRBASE=/home/t2k/cvson/gpfs/ptheta/pac2016/Ptheta_MultiSample/frJame
#ID=pac30e21_narrow4_wreactorthrow_StatOnly_merger_${ODN}
#OD=pac30e21_narrow4_wreactorthrow_StatOnly_sensiAsimov_${ODN}
#ID=pac30e21_narrow1_100k_wreactorthrow_StatOnly_merger_${ODN}
#OD=pac30e21_narrow1_100k_wreactorthrow_StatOnly_sensiAsimov_${ODN}

#ID=pac30e21_narrow2x_wreactorthrow_StatOnly_merger_${IDN}
#OD=pac30e21_narrow2x_wreactorthrow_StatOnly_sensiAsimov_${ODN}
#ID=pac30e21_opt_wreactorthrow_StatOnly_merger_${IDN}
#OD=pac30e21_opt_wreactorthrow_StatOnly_sensiAsimov_${ODN}
ID=pac30e21_optv2s13off_inv_wreactorthrow_StatOnly_merger_${IDN}
OD=pac30e21_optv2s13off_dcp3_inv_wreactorthrow_StatOnly_sensiAsimov_${ODN}

#ID=pac30e21_narrow2x_wreactorthrow_StatOnly_merger_${IDN}
#OD=pac30e21_narrow2x_sin23lo_wreactorthrow_StatOnly_sensiAsimov_${ODN}
#OD=pac30e21_narrow2x_sin23hi_wreactorthrow_StatOnly_sensiAsimov_${ODN}

#ID=pac30e21_wreactorthrow_StatOnly_merger_${IDN}
#OD=pac30e21_wreactorthrow_StatOnly_sensiAsimov_${ODN}

#ID=pac30e21_narrow3x_wreactorthrow_StatOnly_merger_${IDN}
#OD=pac30e21_narrow3x_wreactorthrow_StatOnly_sensiAsimov_${ODN}


mkdir ../outputs/SensiAsimov/${OD}
mkdir ../jobs/logs/${OD}

count=0
inum=0
while [ ${count} -ne ${end} ]
do

inum=`expr $1 \* ${end} - ${end} + ${count}`
OFN=sensiAsimov_`printf %04d ${inum}`

./SensiAsimov_nu_nubar \
-a ${DIR}/outputs/Template_files/Templates_pac30e21_StatOnly.root \
-f ${DIR}/outputs/MergedFiles/${ID} \
-e ${DIR}/outputs/AsimovPoint01_PAC_30e21_Xp_StatOnly_dcp3.root \
-b ${inum} \
-ft ${DIR}/inputs/Throws/Osc_2015_Reac_dm32narrow_opt30v2s13off.root \
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
