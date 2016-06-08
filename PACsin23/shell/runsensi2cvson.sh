#!/bin/sh

#set Minimal/Apps/FitterSettings.h first

#changing 13delta
#end=17

#changing 23
end=51

ODN=10000

cd /home/t2k/cvson/gpfs/ptheta/frHiraki/jnusrv20150612/JointFitter/Minimal/bin
DIR=/home/t2k/cvson/gpfs/ptheta/frHiraki/jnusrv20150612/JointFitter/Minimal
OD=test_sensi_${ODN}
#mkdir ../Output/Sensi/${OD}
#mkdir ../job/log/${OD}

count=0
inum=0
while [ ${count} -ne ${end} ]
do

inum=`expr $1 \* ${end} - ${end} + ${count}`
OFN=sensi_`printf %04d ${inum}`

./SensiAsimov \
-f ${DIR}/Output/Merger/test_merger_${ODN} \
-o ${DIR}/Output/Sensi/${OD}/${OFN}.root \
-e ${DIR}/Output/ToyXp/toyxp_antinu_run56.root \
-m 1 \
-n ${ODN} \
-b ${inum}
#\
#> ${DIR}/job/log/${OD}/${OFN}.log 2>&1

count=`expr ${count} + 1`

done
# -h inverted


