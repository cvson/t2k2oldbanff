#!/bin/bash

TOTAL=$1
COUNTER=0

cd ../
LOCAL=`pwd`
STORAGE=/disk2/usr5/jeimber/Ptheta_MultiSample

while [ $COUNTER -lt $TOTAL ]; do
    COUNTERZEROS=`printf %05d $COUNTER`
    touch shell/SensiAsimov_scripts/RunSensiAsimov_$COUNTERZEROS.sh
    (
	printf '#!/bin/bash \n'
	printf 'cd %s/bin \n' $LOCAL
	printf './SensiAsimov_nu_nubar \\\n'
	printf ' -f %s/outputs/Merged_Results_ParTest/Merger_Run1-4POT_dcp_inv_oldreactor/ \\\n' $STORAGE
	printf ' -e %s/outputs/AsimovPoint06_Run1-4_Xp.root \\\n' $LOCAL
	printf ' -a %s/outputs/Template_files/Templates_Run1-4POT_fix.root \\\n' $STORAGE
	printf ' -n 10000 \\\n'
	printf ' -r \\\n'
	printf ' -b %s \\\n' $COUNTER
	printf ' -o %s/outputs/SensiAsimov_Results_ParTest/SensiAsimov_Run1-4POT_dcp_inv_oldreactor/AS_point06/SensiAsimov_Results_%s.root' $STORAGE $COUNTERZEROS
    ) > shell/SensiAsimov_scripts/RunSensiAsimov_$COUNTERZEROS.sh

    let COUNTER=COUNTER+1
done

chmod 744 shell/SensiAsimov_scripts/*.sh

#
