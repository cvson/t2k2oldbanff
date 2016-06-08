#!/bin/bash

TOTAL=$1
COUNTER=0

cd SensiAsimov_scripts

while [ $COUNTER -lt $TOTAL ]; do
    COUNTERZEROS=`printf %05d $COUNTER`
    ./RunSensiAsimov_$COUNTERZEROS.sh
    mv RunSensiAsimov_$COUNTERZEROS.sh ../SensiAsimov_scripts-launched
    let COUNTER=COUNTER+1
done

cd ../
