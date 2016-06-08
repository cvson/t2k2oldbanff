#!/bin/bash

TOTAL=$1
EACH=$2
COUNTER=0

cd ../
LOCAL=`pwd`
STORAGE=/disk2/usr5/jeimber/Ptheta_MultiSample

while [ $COUNTER -lt $TOTAL ]; do
    COUNTERZEROS=`printf %05d $COUNTER`
    START=$(($COUNTER * $EACH))
    touch shell/MargFitter_scripts/RunMargFitter_$COUNTERZEROS.sh
    (
	printf '#!/bin/bash \n'
	
	printf 'cd %s/bin \n' $LOCAL

	printf './MargFitter_nu_nubar \\\n'
	printf ' -f %s/Tools/Matrix/FullPthetaMatrix.root \\\n' $LOCAL
	printf ' -pe %s/inputs/NuePDF/numode_nue_binning_J \\\n' $LOCAL
	printf ' -pm %s/inputs/NumuPDF/numode_numu_binning_J.root\\\n' $LOCAL
	printf ' -pbe %s/inputs/NuePDF/antinu_nue_binning_J \\\n' $LOCAL
	printf ' -pbm %s/inputs/NumuPDF/antinu_numu_binning_J.root \\\n' $LOCAL
	printf ' -xe %s/inputs/RFnue/nu_beam/ \\\n' $LOCAL
	printf ' -xmu %s/inputs/RFnumu/nu_beam/ \\\n' $LOCAL
	printf ' -xbe %s/inputs/RFnue/nubar_beam/ \\\n' $LOCAL
	printf ' -xbmu %s/inputs/RFnumu/nubar_beam/ \\\n' $LOCAL
	printf ' -tnu 0.6914 \\\n'
	printf ' -tnb 0.4011 \\\n'
	printf ' -sf %s/inputs/SplineFile/weightsv8_t2ksk.14a.neut5.3.2.13a_tuned_v1r0.250ka.fine.numubar_x_numubar_numuselec.root \\\n' $LOCAL
	printf ' -d %s/outputs/AsimovPoint01_Xp.root \\\n' $LOCAL
	printf ' -ft %s/inputs/Throws/nu_nubar_throws.root \\\n' $LOCAL
	printf ' -n 10000 \\\n'
	printf ' -b %s %s \\\n' $START $EACH
	printf ' -r \\\n'
	printf ' -o %s/outputs/MargFit_Results/MargFit_ToyXp_Run1-6POT_t13dcp_reactor/MargFit_Results_%s.root' $STORAGE $COUNTERZEROS
    ) > shell/MargFitter_scripts/RunMargFitter_$COUNTERZEROS.sh

    let COUNTER=COUNTER+1
done

chmod 744 shell/MargFitter_scripts/*.sh
