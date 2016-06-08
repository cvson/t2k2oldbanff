#!/bin/bash

cd ../bin
#gdb --args \
./SepFitter \
-f /disk2/usr5/jeimber/Ptheta_MultiSample/outputs/Merged_Results/Merger_Run1-4POT_t23dm32_oldreactor/ \
-e /home/jeimber/Ptheta_MultiSample/Minimal/outputs/AsimovPoint01_Run1-4_Xp_test.root \
-a /disk2/usr5/jeimber/Ptheta_MultiSample/outputs/Template_files/Templates_Run1-4POT.root \
-n 10000 \
-g 1 \
-b 0 \
-o ../outputs/SepFitter.root


# -f /disk2/usr5/jeimber/Ptheta_MultiSample/outputs/Merged_Results/Merger_Run1-4POT_t13dcp_reactor/ \
#-e /home/jeimber/Ptheta_MultiSample/Inputs/Data/Run1-4/data_Run1-4.root \
# -a /disk2/usr5/jeimber/Ptheta_MultiSample/outputs/Template_files/Templates_Run1-4POT.root \

