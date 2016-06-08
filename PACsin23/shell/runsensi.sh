#!/bin/sh

#set Minimal/Apps/FitterSettings.h first

##
#start=`expr $1 - 1`
#end=1

#changing 13delta
#start=`expr $1 \* 17 - 17`
#end=17

#changing 23
#start=`expr $1 \* 21 - 21`                                                     
end=21

cd /home/t2k/thiraki/work/osc/JointFitter/Minimal/bin
DIR=/home/t2k/thiraki/work/osc/JointFitter/Minimal
OD=antinu_run56exp3_sensi_23_wor_nom_test1
mkdir ../Output/Sensi/${OD}
mkdir ../job/log/${OD}

count=0
inum=0
while [ ${count} -ne ${end} ]
do

inum=`expr $1 \* ${end} - ${end} + ${count}`
OFN=sensi_`printf %04d ${inum}`

./Sensi \
-f ${DIR}/Output/Merger/antinu_run56exp3_merger_23_wor_nom_test1 \
-o ${DIR}/Output/Sensi/${OD}/${OFN}.root \
-e ${DIR}/Output/ToyXp/statxp13a_antinu_run56exp3.root \
-g 10000 \
-m 1 \
-n 1 \
-b ${inum} \
> ${DIR}/job/log/${OD}/${OFN}.log 2>&1

count=`expr ${count} + 1`

done
# -h inverted


