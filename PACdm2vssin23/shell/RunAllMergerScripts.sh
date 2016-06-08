#!/bin/bash

TOTAL=$1
COUNTER=0
COUNTERTWO=0

cd Merger_scripts

while [ $COUNTER -lt $TOTAL ]; do
    COUNTERZEROS=`printf %05d $COUNTER`
    ./RunMerger_$COUNTERZEROS.sh
    mv RunMerger_$COUNTERZEROS.sh ../Merger_scripts-launched
    let COUNTER=COUNTER+1
done

cd ../

cd Merger_scripts2

while [ $COUNTERTWO -lt $TOTAL ]; do
    COUNTERTWOZEROS=`printf %05d $COUNTERTWO`
    ./RunMerger_$COUNTERTWOZEROS.sh
    mv RunMerger_$COUNTERTWOZEROS.sh ../Merger_scripts2-launched
    let COUNTERTWO=COUNTERTWO+1
done

cd ../
