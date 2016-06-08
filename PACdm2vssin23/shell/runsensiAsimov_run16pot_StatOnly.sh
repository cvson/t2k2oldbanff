#!/bin/sh

#set Minimal/Apps/FitterSettings.h first !!!!!
#check folder name (ODN) is different from past 

#changing 13delta
#end=17

#changing 23
end=51

ODN=10000

cd /home/t2k/cvson/gpfs/ptheta/pac2016/Ptheta_MultiSample/frJame/Numudis/bin
DIR=/home/t2k/cvson/gpfs/ptheta/pac2016/Ptheta_MultiSample/frJame/Numudis
DIRBASE=/home/t2k/cvson/gpfs/ptheta/pac2016/Ptheta_MultiSample/frJame
ID=run16_merger_StatOnly_${ODN}
OD=run16_sensiAsimov_StatOnly_${ODN}
mkdir ../outputs/SensiAsimov/${OD}
mkdir ../jobs/logs/${OD}

count=0
inum=0
while [ ${count} -ne ${end} ]
do

inum=`expr $1 \* ${end} - ${end} + ${count}`
OFN=sensiAsimov_`printf %04d ${inum}`

./SensiAsimov_nu_nubar \
-a ${DIR}/outputs/Template_files/Templates_Run1-6POT_fix_StatOnly.root \
-f ${DIR}/outputs/MergedFiles/${ID} \
-e ${DIR}/outputs/AsimovPoint01_Run1-6_Xp_StatOnly.root \
-b ${inum} \
-ft ${DIR}/inputs/Throws/Osc_2015.root \
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
