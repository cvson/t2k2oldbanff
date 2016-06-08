#!/bin/bash

TOTAL=$1
COUNTER=0

cd ../
LOCAL=`pwd`
STORAGE=/disk2/usr5/jeimber/Ptheta_MultiSample

while [ $COUNTER -lt $TOTAL ]; do
    COUNTERZEROS=`printf %05d $COUNTER`
    touch shell/Merger_scripts/RunMerger_$COUNTERZEROS.sh
    (
	printf '#!/bin/bash \n'
	printf 'cd %s/bin \n' $LOCAL
	printf './Merger \\\n'
	printf ' -t %s/outputs/Template_files/Templates_Run1-4POT_fix.root \\\n' $STORAGE
	printf ' -ft %s/inputs/Throws/Osc_2015.root \\\n' $LOCAL
	printf ' -n 10000 \\\n'
	printf ' -h \\\n'
	printf ' -i %s \\\n' $COUNTER
	printf ' -o %s/outputs/Merged_Results_ParTest/Merger_Run1-4POT_t13dcp_inv/' $STORAGE
    ) > shell/Merger_scripts/RunMerger_$COUNTERZEROS.sh

    let COUNTER=COUNTER+1
done

chmod 744 shell/Merger_scripts/*.sh


