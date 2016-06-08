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
#ODN=200000

cd /home/t2k/cvson/gpfs/ptheta/pac2016/20151128/Ptheta_MultiSample/PACdcp/bin
DIR=/home/t2k/cvson/gpfs/ptheta/pac2016/20151128/Ptheta_MultiSample/PACdcp
#OD=pac30e21_narrow4_wreactorthrow_merger_${ODN}
#OD=pac30e21_narrow3_newsys_wreactorthrow_merger_${ODN}
#OD=pac30e21_narrow1_newsys_wreactorthrow_merger_${ODN}
#OD=pac30e21_narrow1_newsys100k_wreactorthrow_merger_${ODN}
#OD=pac30e21_narrow1_newsys100k4check_wreactorthrow_merger_${ODN}
#OD=pac30e21_100k4check_narrow1_wreactorthrow_merger_${ODN}
#OD=pac30e21_100k4check_narrow1x_wreactorthrow_merger_${ODN}

#OD=pac30e21_100k4checkAlt_narrow1_wreactorthrow_merger_${ODN}
#OD=pac30e21_100k4checkAlt_wreactorthrow_merger_${ODN}
#OD=pac30e21_100k4checkAlt_narrow1x_wreactorthrow_merger_${ODN}


#OD=pac30e21_100k4checkAltx2_narrow1x_wreactorthrow_merger_${ODN}
#OD=pac30e21_100k4checkAltx2_narrow1_wreactorthrow_merger_${ODN}

#OD=pac30e21_100k4checkAltx2_narrow2x_wreactorthrow_merger_${ODN}
#OD=pac30e21_100k4checkAlt_narrow2x_wreactorthrow_merger_${ODN}
#OD=pac30e21_100k4check_narrow2x_wreactorthrow_merger_${ODN}
#OD=pac30e21_100k4checkAlt_narrow2x_diffdm2range_wreactorthrow_merger_${ODN}

#OD=pac30e21_100k4checkAltx2_opt_wreactorthrow_merger_${ODN}
#OD=pac30e21_100k4checkAlt_opt_wreactorthrow_merger_${ODN}
#OD=pac30e21_100k4check_opt_wreactorthrow_merger_${ODN}

#OD=pac30e21_100k4check_optv2_wreactorthrow_merger_${ODN}
#OD=pac30e21_100k4checkAlt_optv2_wreactorthrow_merger_${ODN}
#OD=pac30e21_100k4checkAltx2_optv2_wreactorthrow_merger_${ODN}

#OD=pac30e21_100k4checkAlt_optv2s13_wreactorthrow_merger_${ODN}
#OD=pac30e21_100k4check_optv2s13_wreactorthrow_merger_${ODN}
#OD=pac30e21_100k4checkAltx2_optv2s13_wreactorthrow_merger_${ODN}

#OD=pac30e21_100k4checkAlt_optv2s13off_wreactorthrow_merger_${ODN}
#OD=pac30e21_100k4check_optv2s13off_wreactorthrow_merger_${ODN}
#OD=pac30e21_100k4check_optv2s13off_sin23hi_wreactorthrow_merger_${ODN}
#OD=pac30e21_100k4check_optv2s13off_sin23lo_wreactorthrow_merger_${ODN}
OD=pac30e21_100k4check_optv2s13off_sin23lo_christprior_wreactorthrow_merger_${ODN}
#OD=pac30e21_100k4check_optv2s13off_sin23lod4_wreactorthrow_merger_${ODN}
#OD=pac30e21_100k4checkAltx2_optv2s13off_wreactorthrow_merger_${ODN}

#OD=pac30e21_200k4check_optv2_wreactorthrow_merger_${ODN}
#OD=pac30e21_200k4checkAlt_optv2_wreactorthrow_merger_${ODN}
#OD=pac30e21_200k4checkAltx2_optv2_wreactorthrow_merger_${ODN}

#OD=pac30e21_100k4check_narrow3x_wreactorthrow_merger_${ODN}
#OD=pac30e21_100k4checkAlt_narrow3x_wreactorthrow_merger_${ODN}
#OD=pac30e21_100k4checkAltx2_narrow3x_wreactorthrow_merger_${ODN}

#OD=pac30e21_100k4checkAltx2_narrow3xdcp_wreactorthrow_merger_${ODN}
#OD=pac30e21_100k4checkAlt_narrow3xdcp_wreactorthrow_merger_${ODN}
#OD=pac30e21_100k4check_narrow3xdcp_wreactorthrow_merger_${ODN}
mkdir ../outputs/MergedFiles/${OD}
mkdir ../jobs/logs/${OD}

count=0
inum=0
while [ ${count} -ne ${end} ]
do

inum=`expr $1 \* ${end} - ${end} + ${count}`
OFN=merger_`printf %04d ${inum}`

./Merger \
-t ${DIR}/outputs/Template_files/Templates_pac30e21.root \
-o ${DIR}/outputs/MergedFiles/${OD} \
-i ${inum} \
-ft ${DIR}/inputs/Throws/Osc_2015_Reac_dm32narrow_opt30v2s13offlo_christ.root \
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
