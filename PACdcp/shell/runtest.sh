#!/bin/bash
cd ../bin
./SensiAsimov_nu_nubar \
-a ../outputs/Template_files/setA500k/Templates_pac30e21.root \
-f ../outputs/MergedFiles/pac30e21_200k4check_optv2_wreactorthrow_merger_200000 \
-e ../outputs/AsimovPoint01_PAC_30e21_Xp_StatOnly.root \
-b 1 \
-ft ../inputs/Throws/Osc_2015_Reac_dm32narrow_opt30v2.root \
-n 200000 \
-o ../outputs/SensiAsimov/test/sensiAsimov_0000.root

