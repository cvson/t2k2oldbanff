#!/bin/bash

cd ../bin
#gdb --args \
./Sensi_nu_nubar \
-f ../outputs/MergedFiles/ \
-e ../outputs/nu_nubar_Xp.root \
-a ../outputs/Templates.root \
-n 1000 \
-g 1000 \
-b 1 \
-o ../outputs/SensiResults.root
