#!/bin/bash

cd ../bin

./Tester2015 \
-f ../Tools/Matrix/FullPthetaMatrix.root \
-n 500000 \
-o ../inputs/Throws/sys_throws_ptheta_rpaStatic_fix_new_500knom.root
