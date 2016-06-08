#!/bin/bash

cd /home/jeimber
source make_env.sh

cd /home/jeimber/Ptheta_MultiSample/Minimal/macro

#############################################
#Run1-4

# #t23dm32
#root -l -b -q 'PlotSensiAsimov_zoom_test.C++("SensiAsimov_Run1-4POT_t23dm32/AS_point01/*","Run1-4POT_t23dm32_point1")'
##cvson
root -l -b -q 'PlotSensiAsimov_zoom_test.C++("run14_sensiAsimov_10000/*.root","Run1-4POT_t23dm32_point1")'

# root -l -b -q 'PlotSensiAsimov_zoom_test.C++("SensiAsimov_Run1-4POT_t23dm32/AS_point04/*","Run1-4POT_t23dm32_point4")'

root -l -b -q 'PlotSensiAsimov_zoom_test.C++("SensiAsimov_Run1-4POT_t23dm32_inv/AS_point01/*","Run1-4POT_t23dm32_inv_point1")'
# root -l -b -q 'PlotSensiAsimov_zoom_test.C++("SensiAsimov_Run1-4POT_t23dm32_inv/AS_point04/*","Run1-4POT_t23dm32_inv_point4")'

# #t23dm32 reactor
root -l -b -q 'PlotSensiAsimov_zoom_test.C++("SensiAsimov_Run1-4POT_t23dm32_reactor/AS_point01/*","Run1-4POT_t23dm32_reactor_point1")'
# root -l -b -q 'PlotSensiAsimov_zoom_test.C++("SensiAsimov_Run1-4POT_t23dm32_reactor/AS_point04/*","Run1-4POT_t23dm32_reactor_point4")'

root -l -b -q 'PlotSensiAsimov_zoom_test.C++("SensiAsimov_Run1-4POT_t23dm32_inv_reactor/AS_point01/*","Run1-4POT_t23dm32_inv_reactor_point1")'
# root -l -b -q 'PlotSensiAsimov_zoom_test.C++("SensiAsimov_Run1-4POT_t23dm32_inv_reactor/AS_point04/*","Run1-4POT_t23dm32_inv_reactor_point4")'

# #t23dm32 oldreactor
root -l -b -q 'PlotSensiAsimov_zoom_test.C++("SensiAsimov_Run1-4POT_t23dm32_oldreactor/AS_point01/*","Run1-4POT_t23dm32_oldreactor_point1")'
# root -l -b -q 'PlotSensiAsimov_zoom_test.C++("SensiAsimov_Run1-4POT_t23dm32_oldreactor/AS_point04/*","Run1-4POT_t23dm32_oldreactor_point4")'

root -l -b -q 'PlotSensiAsimov_zoom_test.C++("SensiAsimov_Run1-4POT_t23dm32_inv_oldreactor/AS_point01/*","Run1-4POT_t23dm32_inv_oldreactor_point1")'
# root -l -b -q 'PlotSensiAsimov_zoom_test.C++("SensiAsimov_Run1-4POT_t23dm32_inv_oldreactor/AS_point04/*","Run1-4POT_t23dm32_inv_oldreactor_point4")'


# #t13dcp
root -l -b -q 'PlotSensiAsimov_appearance_test.C++("SensiAsimov_Run1-4POT_t13dcp/AS_point01/*","Run1-4POT_t13dcp_point1")'
# root -l -b -q 'PlotSensiAsimov_appearance_test.C++("SensiAsimov_Run1-4POT_t13dcp/AS_point02/*","Run1-4POT_t13dcp_point2")'

root -l -b -q 'PlotSensiAsimov_appearance_test.C++("SensiAsimov_Run1-4POT_t13dcp_inv/AS_point01/*","Run1-4POT_t13dcp_inv_point1")'
# root -l -b -q 'PlotSensiAsimov_appearance_test.C++("SensiAsimov_Run1-4POT_t13dcp_inv/AS_point02/*","Run1-4POT_t13dcp_inv_point2")'


# #t13dcp reactor
root -l -b -q 'PlotSensiAsimov_appearance_reactor_test.C++("SensiAsimov_Run1-4POT_t13dcp_reactor/AS_point01/*","Run1-4POT_t13dcp_reactor_point1")'
# root -l -b -q 'PlotSensiAsimov_appearance_reactor_test.C++("SensiAsimov_Run1-4POT_t13dcp_reactor/AS_point02/*","Run1-4POT_t13dcp_reactor_point2")'

root -l -b -q 'PlotSensiAsimov_appearance_reactor_test.C++("SensiAsimov_Run1-4POT_t13dcp_inv_reactor/AS_point01/*","Run1-4POT_t13dcp_inv_reactor_point1")'
# root -l -b -q 'PlotSensiAsimov_appearance_reactor_test.C++("SensiAsimov_Run1-4POT_t13dcp_inv_reactor/AS_point02/*","Run1-4POT_t13dcp_inv_reactor_point2")'

# #t13dcp oldreactor
root -l -b -q 'PlotSensiAsimov_appearance_reactor_test.C++("SensiAsimov_Run1-4POT_t13dcp_oldreactor/AS_point01/*","Run1-4POT_t13dcp_oldreactor_point1")'
# root -l -b -q 'PlotSensiAsimov_appearance_reactor_test.C++("SensiAsimov_Run1-4POT_t13dcp_oldreactor/AS_point02/*","Run1-4POT_t13dcp_oldreactor_point2")'

root -l -b -q 'PlotSensiAsimov_appearance_reactor_test.C++("SensiAsimov_Run1-4POT_t13dcp_inv_oldreactor/AS_point01/*","Run1-4POT_t13dcp_inv_oldreactor_point1")'
# root -l -b -q 'PlotSensiAsimov_appearance_reactor_test.C++("SensiAsimov_Run1-4POT_t13dcp_inv_oldreactor/AS_point02/*","Run1-4POT_t13dcp_inv_oldreactor_point2")'


#dcp reactor
root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("SensiAsimov_Run1-4POT_dcp_reactor/AS_point01/*","Run1-4POT_dcp_reactor_point1")'
#root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("SensiAsimov_Run1-4POT_dcp_reactor/AS_point02/*","Run1-4POT_dcp_reactor_point2")'

root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("SensiAsimov_Run1-4POT_dcp_inv_reactor/AS_point01/*","Run1-4POT_dcp_inv_reactor_point1")'
#root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("SensiAsimov_Run1-4POT_dcp_inv_reactor/AS_point02/*","Run1-4POT_dcp_inv_reactor_point2")'

#dcp old reactor
root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("SensiAsimov_Run1-4POT_dcp_oldreactor/AS_point01/*","Run1-4POT_dcp_oldreactor_point1")'
#root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("SensiAsimov_Run1-4POT_dcp_oldreactor/AS_point02/*","Run1-4POT_dcp_oldreactor_point2")'

root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("SensiAsimov_Run1-4POT_dcp_inv_oldreactor/AS_point01/*","Run1-4POT_dcp_inv_oldreactor_point1")'
#root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("SensiAsimov_Run1-4POT_dcp_inv_oldreactor/AS_point02/*","Run1-4POT_dcp_inv_oldreactor_point2")'

###########################################################################
#Run1-6
# #t23dm32 reactor
# root -l -b -q 'PlotSensiAsimov_zoom_test.C++("SensiAsimov_Run1-6POT_t23dm32_reactor/AS_point01/*","Run1-6POT_t23dm32_reactor_point1")'
# root -l -b -q 'PlotSensiAsimov_zoom_test.C++("SensiAsimov_Run1-6POT_t23dm32_reactor/AS_point04/*","Run1-6POT_t23dm32_reactor_point4")'

# #t23dm32
# root -l -b -q 'PlotSensiAsimov_zoom_test.C++("SensiAsimov_Run1-6POT_t23dm32/AS_point01/*","Run1-6POT_t23dm32_point1")'
# root -l -b -q 'PlotSensiAsimov_zoom_test.C++("SensiAsimov_Run1-6POT_t23dm32/AS_point04/*","Run1-6POT_t23dm32_point4")'

# #t13dcp
# root -l -b -q 'PlotSensiAsimov_appearance_test.C++("SensiAsimov_Run1-6POT_t13dcp/AS_point01/*","Run1-6POT_t13dcp_point1")'
# root -l -b -q 'PlotSensiAsimov_appearance_test.C++("SensiAsimov_Run1-6POT_t13dcp/AS_point02/*","Run1-6POT_t13dcp_point2")'

# #t13dcp reactor
# root -l -b -q 'PlotSensiAsimov_appearance_reactor_test.C++("SensiAsimov_Run1-6POT_t13dcp_reactor/AS_point01/*","Run1-6POT_t13dcp_reactor_point1")'
# root -l -b -q 'PlotSensiAsimov_appearance_reactor_test.C++("SensiAsimov_Run1-6POT_t13dcp_reactor/AS_point02/*","Run1-6POT_t13dcp_reactor_point2")'

# #dcp reactor
# root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("SensiAsimov_Run1-6POT_dcp_reactor/AS_point01/*","Run1-6POT_dcp_reactor_point1")'
# root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("SensiAsimov_Run1-6POT_dcp_reactor/AS_point02/*","Run1-6POT_dcp_reactor_point2")'
