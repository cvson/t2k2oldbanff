#!/bin/bash

cd ../bin

./Merger \
-t ../outputs/Templates.root \
-ft ../inputs/Throws/Osc_2014_nom.root \
-n 10000 \
-o ../outputs/MergedFiles/ \
-i $1
