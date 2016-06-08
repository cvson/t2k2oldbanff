#!/bin/bash

cd ../bin

./Merger \
-t ../outputs/Template_files/Templates_Run1-4POT_fix.root \
-ft ../inputs/Throws/Osc_2015.root \
-n 10000 \
-o ../outputs/MergedFiles \
-i $1
