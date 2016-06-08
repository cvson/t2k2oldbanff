#!/bin/bash

cd ../bin

./Tester2015 \
-f ../Tools/Matrix/FullPthetaMatrix.root \
-n 10000 \
-o ../inputs/Throws/sys_throws_ptheta_rpaStatic_fix.root
