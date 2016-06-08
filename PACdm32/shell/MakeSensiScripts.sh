#!/bin/bash

TOTAL=$1
COUNTER=0

cd ../
LOCAL=`pwd`
STORAGE=/disk2/usr5/jeimber/Ptheta_MultiSample

while [ $COUNTER -lt $TOTAL ]; do
    COUNTERZEROS=`printf %05d $COUNTER`
    touch shell/Sensi_scripts/RunSensi_$COUNTERZEROS.sh
    (
	printf '#!/bin/bash \n'
	printf 'cd %s/bin \n' $LOCAL
	printf './Sensi_nu_nubar \\\n'
	printf ' -f %s/outputs/Merged_Results/Merger_Run1-4POT_dcp_inv_oldreactor/ \\\n' $STORAGE
	printf ' -e %s/outputs/AsimovPoint01_Run1-4_Xp.root \\\n' $LOCAL
	printf ' -a %s/outputs/Template_files/Templates_Run1-4POT.root \\\n' $STORAGE
	printf ' -n 10000 \\\n'
	printf ' -g 10000 \\\n'
	printf ' -b %s \\\n' $COUNTER
	printf ' -o %s/outputs/Sensi_Results/Sensi_Run1-4POT_dcp_inv_oldreactor/AS_point01/Sensi_Results_%s.root' $STORAGE $COUNTERZEROS
    ) > shell/Sensi_scripts/RunSensi_$COUNTERZEROS.sh

    let COUNTER=COUNTER+1
done

chmod 744 shell/Sensi_scripts/*.sh

#	printf ' -e /home/jeimber/Ptheta_MultiSample/Inputs/Data/Run1-4/data_Run1-4.root \\\n'
