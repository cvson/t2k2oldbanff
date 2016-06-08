#!/bin/sh
#mkdir ../plots/pac30e21_dcp_point1_50k_narrow1_newsys_wreactorthrow
#root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("pac30e21_narrow1_newsys_wreactorthrow_sensiAsimov_50000/*.root","pac30e21_dcp_point1_50k_narrow1_newsys_wreactorthrow")'

#mkdir ../plots/pac20e21_dcp_point1_50k_narrow1_newsys_wreactorthrow
root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("pac20e21_narrow1_newsys_wreactorthrow_sensiAsimov_50000/*.root","pac20e21_dcp_point1_50k_narrow1_newsys_wreactorthrow")'

#mkdir ../plots/pac7d8e21_dcp_point1_50k_narrow1_newsys_wreactorthrow
root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("pac7d8e21_narrow1_newsys_wreactorthrow_sensiAsimov_50000/*.root","pac7d8e21_dcp_point1_50k_narrow1_newsys_wreactorthrow")'

