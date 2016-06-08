#!/bin/bash

TOTAL=$1
COUNTER=0

cd ../
LOCAL=`pwd`
STORAGE=/disk2/usr5/jeimber/Ptheta_MultiSample

while [ $COUNTER -lt $TOTAL ]; do
    COUNTERZEROS=`printf %05d $COUNTER`
    touch shell/SepFitter_scripts2/RunSepFitter_$COUNTERZEROS.sh
    (
        printf '#!/bin/bash \n'
        printf 'cd %s/bin \n' $LOCAL
        printf './SepFitter \\\n'
        printf ' -f %s/outputs/Merged_Results_ParTest/Merger_Run1-4POT_dcp_reactor/ \\\n' $STORAGE
        printf ' -e /home/jeimber/Ptheta_MultiSample/Inputs/Data/Run1-4/data_Run1-4.root \\\n'
        printf ' -a %s/outputs/Template_files/Templates_Run1-4POT_fix.root \\\n' $STORAGE
        printf ' -n 10000 \\\n'
        printf ' -g 1 \\\n'
        printf ' -b %s \\\n' $COUNTER
        printf ' -o %s/outputs/SepFitter_Results_ParTest/SepFitter_Run1-4POT_dcp_reactor/Data_Run1-4_refit/SepFitter_Results_%s.root' $STORAGE $COUNTERZEROS
    ) > shell/SepFitter_scripts2/RunSepFitter_$COUNTERZEROS.sh

    let COUNTER=COUNTER+1
done

chmod 744 shell/SepFitter_scripts2/*.sh

#        printf ' -r \\\n'
