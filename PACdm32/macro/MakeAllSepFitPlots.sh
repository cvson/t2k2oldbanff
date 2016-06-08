#!/bin/bash

cd /home/jeimber
source make_env.sh

cd /home/jeimber/Ptheta_MultiSample/Minimal/macro

#############################################
#Run1-4

# # #t23dm32
# root -l -b -q 'PlotSepFitter_zoom_test.C++("SepFitter_Run1-4POT_t23dm32/Data_Run1-4_refit/*","Run1-4POT_t23dm32_Data_refit")'
# root -l -b -q 'PlotSepFitter_zoom_test.C++("SepFitter_Run1-4POT_t23dm32_inv/Data_Run1-4_refit/*","Run1-4POT_t23dm32_inv_Data_refit")'

# # #t23dm32 reactor
# root -l -b -q 'PlotSepFitter_zoom_test.C++("SepFitter_Run1-4POT_t23dm32_reactor/Data_Run1-4_refit/*","Run1-4POT_t23dm32_reactor_Data_refit")'
# root -l -b -q 'PlotSepFitter_zoom_test.C++("SepFitter_Run1-4POT_t23dm32_inv_reactor/Data_Run1-4_refit/*","Run1-4POT_t23dm32_inv_reactor_Data_refit")'

# # #t23dm32 oldreactor
# root -l -b -q 'PlotSepFitter_zoom_test.C++("SepFitter_Run1-4POT_t23dm32_oldreactor/Data_Run1-4_refit/*","Run1-4POT_t23dm32_oldreactor_Data_refit")'
# root -l -b -q 'PlotSepFitter_zoom_test.C++("SepFitter_Run1-4POT_t23dm32_inv_oldreactor/Data_Run1-4_refit/*","Run1-4POT_t23dm32_inv_oldreactor_Data_refit")'


# # #t13dcp
# root -l -b -q 'PlotSepFitter_appearance_test.C++("SepFitter_Run1-4POT_t13dcp/Data_Run1-4_refit/*","Run1-4POT_t13dcp_Data_refit")'
# root -l -b -q 'PlotSepFitter_appearance_test.C++("SepFitter_Run1-4POT_t13dcp_inv/Data_Run1-4_refit/*","Run1-4POT_t13dcp_inv_Data_refit")'


# # #t13dcp reactor
# root -l -b -q 'PlotSepFitter_appearance_reactor_test.C++("SepFitter_Run1-4POT_t13dcp_reactor/Data_Run1-4_refit/*","Run1-4POT_t13dcp_reactor_Data_refit")'
# root -l -b -q 'PlotSepFitter_appearance_reactor_test.C++("SepFitter_Run1-4POT_t13dcp_inv_reactor/Data_Run1-4_refit/*","Run1-4POT_t13dcp_inv_reactor_Data_refit")'

# #t13dcp oldreactor
root -l -b -q 'PlotSepFitter_appearance_reactor_test.C++("SepFitter_Run1-4POT_t13dcp_oldreactor/Data_Run1-4_refit/*","Run1-4POT_t13dcp_oldreactor_Data_refit")'
root -l -b -q 'PlotSepFitter_appearance_reactor_test.C++("SepFitter_Run1-4POT_t13dcp_inv_oldreactor/Data_Run1-4_refit/*","Run1-4POT_t13dcp_inv_oldreactor_Data_refit")'


# #dcp reactor
# root -l -b -q 'PlotSepFitter_deltaCP_reactor_test.C++("SepFitter_Run1-4POT_dcp_reactor/Data_Run1-4_refit/*","Run1-4POT_dcp_reactor_Data_refit")'
# root -l -b -q 'PlotSepFitter_deltaCP_reactor_test.C++("SepFitter_Run1-4POT_dcp_inv_reactor/Data_Run1-4_refit/*","Run1-4POT_dcp_inv_reactor_Data_refit")'

#dcp old reactor
root -l -b -q 'PlotSepFitter_deltaCP_reactor_test.C++("SepFitter_Run1-4POT_dcp_oldreactor/Data_Run1-4_refit/*","Run1-4POT_dcp_oldreactor_Data_refit")'
root -l -b -q 'PlotSepFitter_deltaCP_reactor_test.C++("SepFitter_Run1-4POT_dcp_inv_oldreactor/Data_Run1-4_refit/*","Run1-4POT_dcp_inv_oldreactor_Data_refit")'

###########################################################################
#Run1-6
# #t23dm32 reactor
# root -l -b -q 'PlotSepFitter_zoom_test.C++("SepFitter_Run1-6POT_t23dm32_reactor/Data_Run1-4_refit/*","Run1-6POT_t23dm32_reactor_point1")'

# #t23dm32
# root -l -b -q 'PlotSepFitter_zoom_test.C++("SepFitter_Run1-6POT_t23dm32/Data_Run1-4_refit/*","Run1-6POT_t23dm32_point1")'

# #t13dcp
# root -l -b -q 'PlotSepFitter_appearance_test.C++("SepFitter_Run1-6POT_t13dcp/Data_Run1-4_refit/*","Run1-6POT_t13dcp_point1")'

# #t13dcp reactor
# root -l -b -q 'PlotSepFitter_appearance_reactor_test.C++("SepFitter_Run1-6POT_t13dcp_reactor/Data_Run1-4_refit/*","Run1-6POT_t13dcp_reactor_point1")'

# #dcp reactor
# root -l -b -q 'PlotSepFitter_deltaCP_reactor_test.C++("SepFitter_Run1-6POT_dcp_reactor/Data_Run1-4_refit/*","Run1-6POT_dcp_reactor_point1")'
