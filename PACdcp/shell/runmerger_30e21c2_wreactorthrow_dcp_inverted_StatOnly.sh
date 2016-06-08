#!/bin/sh

#set Minimal/Apps/FitterSettings.h first !!!!!
#check folder name (ODN) is different from past 

#changing 13delta
#end=17

#changing 23
#end=51
##for dcp
end=1

#ODN=50000
ODN=100000

cd /home/t2k/cvson/gpfs/ptheta/pac2016/20151128/Ptheta_MultiSample/PACdcp/bin
DIR=/home/t2k/cvson/gpfs/ptheta/pac2016/20151128/Ptheta_MultiSample/PACdcp
#OD=pac30e21c2_narrow4_wreactorthrow_StatOnly_merger_${ODN}
#OD=pac30e21c2_narrow1_100k_wreactorthrow_StatOnly_merger_${ODN}
#OD=pac30e21c2_narrow2x_wreactorthrow_StatOnly_merger_${ODN}
#OD=pac30e21c2_opt_wreactorthrow_StatOnly_merger_${ODN}
OD=pac30e21c2_optv2s13off_inv_wreactorthrow_StatOnly_merger_${ODN}
#OD=pac30e21c2_optv2s13off_sin23hi_inv_wreactorthrow_StatOnly_merger_${ODN}
#OD=pac30e21c2_optv2s13off_sin23lo_inv_wreactorthrow_StatOnly_merger_${ODN}
#OD=pac30e21c2_wreactorthrow_StatOnly_merger_${ODN}
#OD=pac30e21c2_narrow3x_wreactorthrow_StatOnly_merger_${ODN}
mkdir ../outputs/MergedFiles/${OD}
mkdir ../jobs/logs/${OD}

count=0
inum=0
while [ ${count} -ne ${end} ]
do

inum=`expr $1 \* ${end} - ${end} + ${count}`
OFN=merger_`printf %04d ${inum}`

./Merger \
-t ${DIR}/outputs/Template_files/statonly/Templates_pac30e21c2_StatOnly.root \
-o ${DIR}/outputs/MergedFiles/${OD} \
-i ${inum} \
-ft ${DIR}/inputs/Throws/Osc_2015_Reac_dm32narrow_opt30v2s13off.root \
-h \
-n ${ODN} \
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
