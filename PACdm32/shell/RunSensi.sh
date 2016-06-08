#!/bin/bash

cd ../bin
#gdb --args \
./Sensi_nu_nubar \
-f /disk2/usr5/jeimber/Ptheta_MultiSample/outputs/Merged_Results/Merger_Run1-4POT_t13dcp_reactor/ \
-e /home/jeimber/Ptheta_MultiSample/Minimal/outputs/AsimovPoint01_Run1-4_Xp_test.root \
-a /disk2/usr5/jeimber/Ptheta_MultiSample/outputs/Template_files/Templates_Run1-4POT.root \
-n 10 \
-g 10 \
-b 0 \
-o ../outputs/SensiResults.root


# -f /disk2/usr5/jeimber/Ptheta_MultiSample/outputs/Merged_Results/Merger_Run1-4POT_t13dcp_reactor/ \
# -e /home/jeimber/Ptheta_MultiSample/Minimal/outputs/AsimovPoint01_Run1-4_Xp_test.root \
# -a /disk2/usr5/jeimber/Ptheta_MultiSample/outputs/Template_files/Templates_Run1-4POT.root \
