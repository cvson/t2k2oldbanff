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
	printf ' -f %s/outputs/Merged_Results/Merger_Test/ \\\n' $STORAGE
	printf ' -e %s/outputs/nu_nubar_Xp.root \\\n' $LOCAL
	printf ' -a %s/outputs/Templates.root \\\n' $LOCAL
	printf ' -n 1 \\\n'
	printf ' -b %s \\\n' $COUNTER
	printf ' -o %s/outputs/SensiAsimov_Results/SensiAsimov_Stat_Test/SensiAsimov_Results_%s.root' $STORAGE $COUNTERZEROS
    ) > shell/SensiAsimov_scripts/RunSensiAsimov_$COUNTERZEROS.sh

    let COUNTER=COUNTER+1
done

chmod 744 shell/SensiAsimov_scripts/*.sh
