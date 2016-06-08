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

cd /home/t2k/cvson/gpfs/ptheta/pac2016/20151128/Ptheta_MultiSample/PACdcp/bin
DIR=/home/t2k/cvson/gpfs/ptheta/pac2016/20151128/Ptheta_MultiSample/PACdcp
DIRBASE=/home/t2k/cvson/gpfs/ptheta/pac2016/Ptheta_MultiSample/frJame
#ID=pac2d5e21c2_narrow4_inv_wreactorthrow_merger_${ODN}
#OD=pac2d5e21c2_narrow4_inv_wreactorthrow_sensiAsimov_${ODN}
#ID=pac2d5e21c2_narrow1_newsys_inv_wreactorthrow_merger_${ODN}
#OD=pac2d5e21c2_narrow1_newsys_inv_wreactorthrow_sensiAsimov_${ODN}
#ID=pac2d5e21c2_100k4check_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_100k4check_inv_wreactorthrow_sensiAsimov_${ODN}

#ID=pac2d5e21c2_100k4check_narrow1_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_100k4check_narrow1_inv_wreactorthrow_sensiAsimov_${ODN}
#ID=pac2d5e21c2_100k4check_narrow1x_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_100k4check_narrow1x_inv_wreactorthrow_sensiAsimov_${ODN}

#ID=pac2d5e21c2_100k4checkAlt_narrow1_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_100k4checkAlt_narrow1_inv_wreactorthrow_sensiAsimov_${ODN}

#ID=pac2d5e21c2_100k4checkAlt_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_100k4checkAlt_inv_wreactorthrow_sensiAsimov_${ODN}

#ID=pac2d5e21c2_100k4checkAlt_narrow1x_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_100k4checkAlt_narrow1x_inv_wreactorthrow_sensiAsimov_${ODN}

#ID=pac2d5e21c2_100k4checkAltx2_narrow1x_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_100k4checkAltx2_narrow1x_inv_wreactorthrow_sensiAsimov_${ODN}
#ID=pac2d5e21c2_100k4checkAltx2_narrow1_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_100k4checkAltx2_narrow1_inv_wreactorthrow_sensiAsimov_${ODN}

#ID=pac2d5e21c2_100k4checkAltx2_narrow2x_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_100k4checkAltx2_narrow2x_inv_wreactorthrow_sensiAsimov_${ODN}

#ID=pac2d5e21c2_100k4checkAltx2_opt_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_100k4checkAltx2_opt_inv_wreactorthrow_sensiAsimov_${ODN}
#ID=pac2d5e21c2_100k4checkAlt_opt_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_100k4checkAlt_opt_inv_wreactorthrow_sensiAsimov_${ODN}
#ID=pac2d5e21c2_100k4check_opt_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_100k4check_opt_inv_wreactorthrow_sensiAsimov_${ODN}

#ID=pac2d5e21c2_100k4check_optv2_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_100k4check_optv2_inv_wreactorthrow_sensiAsimov_${ODN}
#ID=pac2d5e21c2_100k4checkAlt_optv2_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_100k4checkAlt_optv2_inv_wreactorthrow_sensiAsimov_${ODN}
#ID=pac2d5e21c2_100k4checkAltx2_optv2_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_100k4checkAltx2_optv2_inv_wreactorthrow_sensiAsimov_${ODN}

#ID=pac2d5e21c2_100k4check_optv2s13_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_100k4check_optv2s13_inv_wreactorthrow_sensiAsimov_${ODN}
#ID=pac2d5e21c2_100k4checkAlt_optv2s13_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_100k4checkAlt_optv2s13_inv_wreactorthrow_sensiAsimov_${ODN}
#ID=pac2d5e21c2_100k4checkAltx2_optv2s13_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_100k4checkAltx2_optv2s13_inv_wreactorthrow_sensiAsimov_${ODN}

#ID=pac2d5e21c2_100k4check_optv2s13off_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_100k4check_optv2s13off_inv_wreactorthrow_sensiAsimov_${ODN}
#ID=pac2d5e21c2_100k4check_optv2s13off_sin23hi_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_100k4check_optv2s13off_sin23hi_inv_wreactorthrow_sensiAsimov_${ODN}
ID=pac2d5e21c2_100k4check_optv2s13off_inv_wreactorthrow_merger_${IDN}
OD=pac2d5e21c2_100k4check_optv2s13off_sin23hi528_inv_wreactorthrow_sensiAsimov_${ODN}

#ID=pac2d5e21c2_100k4check_optv2s13off_sin23lo_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_100k4check_optv2s13off_sin23lo_inv_wreactorthrow_sensiAsimov_${ODN}
#ID=pac2d5e21c2_100k4check_optv2s13off_sin23lod4_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_100k4check_optv2s13off_sin23lod4_inv_wreactorthrow_sensiAsimov_${ODN}
#ID=pac2d5e21c2_100k4check_optv2s13off_sin23lo_christprior_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_100k4check_optv2s13off_sin23lo_christprior_inv_wreactorthrow_sensiAsimov_${ODN}
#ID=pac2d5e21c2_100k4check_optv2s13off_sin23lo_nohioct_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_100k4check_optv2s13off_sin23lo_nohioct_inv_wreactorthrow_sensiAsimov_${ODN}
#ID=pac2d5e21c2_100k4checkAlt_optv2s13off_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_100k4checkAlt_optv2s13off_inv_wreactorthrow_sensiAsimov_${ODN}
#ID=pac2d5e21c2_100k4checkAltx2_optv2s13off_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_100k4checkAltx2_optv2s13off_inv_wreactorthrow_sensiAsimov_${ODN}

#ID=pac2d5e21c2_200k4check_optv2_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_200k4check_optv2_inv_wreactorthrow_sensiAsimov_${ODN}
#ID=pac2d5e21c2_200k4checkAlt_optv2_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_200k4checkAlt_optv2_inv_wreactorthrow_sensiAsimov_${ODN}
#ID=pac2d5e21c2_200k4checkAltx2_optv2_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_200k4checkAltx2_optv2_inv_wreactorthrow_sensiAsimov_${ODN}

#ID=pac2d5e21c2_100k4checkAlt_narrow2x_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_100k4checkAlt_narrow2x_inv_wreactorthrow_sensiAsimov_${ODN}

#ID=pac2d5e21c2_100k4check_narrow2x_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_100k4check_narrow2x_inv_wreactorthrow_sensiAsimov_${ODN}
#ID=pac2d5e21c2_100k4check_narrow2x_inv_wreactorthrow_merger_${IDN}
#OD=pac2d5e21c2_100k4check_narrow2x_sin23lo_inv_wreactorthrow_sensiAsimov_${ODN}
#OD=pac2d5e21c2_100k4check_narrow2x_sin23hi_inv_wreactorthrow_sensiAsimov_${ODN}
mkdir ../outputs/SensiAsimov/${OD}
mkdir ../jobs/logs/${OD}

count=0
inum=0
while [ ${count} -ne ${end} ]
do

inum=`expr $1 \* ${end} - ${end} + ${count}`
OFN=sensiAsimov_`printf %04d ${inum}`

./SensiAsimov_nu_nubar \
-a ${DIR}/outputs/Template_files/setA/Templates_pac2d5e21c2.root \
-f ${DIR}/outputs/MergedFiles/${ID} \
-e ${DIR}/outputs/asimovhi528/AsimovPoint01_PAC_2d5e21c2_Xp_StatOnly.root \
-b ${inum} \
-ft ${DIR}/inputs/Throws/Osc_2015_Reac_dm32narrow_opt2d5c2v2s13off.root \
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
