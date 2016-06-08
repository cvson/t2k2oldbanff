#!/bin/sh

#set Minimal/Apps/FitterSettings.h first !!!!!
#check folder name (ODN) is different from past 

#changing 13delta
#end=17

#changing 23
end=51

ODN=10000

cd /home/t2k/thiraki/work/osc/JointFitter/Minimal/bin
DIR=/home/t2k/thiraki/work/osc/JointFitter/Minimal
OD=antinu_20150603fine_merger_${ODN}
mkdir ../Output/Merger/${OD}
mkdir ../job/log/${OD}

count=0
inum=0
while [ ${count} -ne ${end} ]
do

inum=`expr $1 \* ${end} - ${end} + ${count}`
OFN=merger_`printf %04d ${inum}`

./Merger \
-t ${DIR}/Output/Template/template_antinu_20150603.root \
-p ${DIR}/inputs/NuePDF/anti-nu_20150603 \
-pm ${DIR}/inputs/NumuPDF/antinumode_numu_binning_20150603.root \
-o ${DIR}/Output/Merger/${OD} \
-i ${inum} \
-ft ${DIR}/inputs/Throws/Osc_2014_test3.root \
-n ${ODN} \
> ${DIR}/job/log/${OD}/${OFN}.log 2>&1

count=`expr ${count} + 1`

done
# -h inverted

# -t <template file> //from the result of maketemplate
# -t ${DIR}/Output/Template/template_antinu_test10000.root \ merging
# -t ${DIR}/Output/Template/template_antinu_test1.root \ fixing
# -ft <file with parameter throws> : prior
# -ft ${DIR}/inputs/Throws/Osc_2014_nom_noreactor.root \ normal hierarchy without reactor

#./Merger -t ../Output/Template/template_antinu_2015v1.root -p ../inputs/NuePDF/anti-nu_run_5_6 -pm ../inputs/NumuPDF/antinumode_numu_binning_run_5_6.root -o ../Output/test/hoge -ft ../inputs/Throws/Osc_2014_nom_noreactor.root -i 0 -n 1