#!/bin/sh

#mkdir ../plots/pac30e21_dcp_point1_100k_narrow1_wreactorthrow_50k

#root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("pac30e21_narrow1_newsys100k_wreactorthrow_sensiAsimov_50000/*.root","pac30e21_dcp_point1_100k_narrow1_wreactorthrow_50k")'

#mkdir ../plots/pac30e21_dcp_point1_100k_narrow1_wreactorthrow_100k
#root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("pac30e21_narrow1_newsys100k_wreactorthrow_sensiAsimov_100000/*.root","pac30e21_dcp_point1_100k_narrow1_wreactorthrow_100k")'

#mkdir ../plots/pac30e21_dcp_point1_100k_narrow1_wreactorthrow_100k_StatOnly
#root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("pac30e21_narrow1_100k_wreactorthrow_StatOnly_sensiAsimov_100000/*.root","pac30e21_dcp_point1_100k_narrow1_wreactorthrow_100k_StatOnly")'

mkdir ../plots/pac30e21_dcp_point1_100k4check_narrow1_wreactorthrow_50k
root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("pac30e21_narrow1_newsys100k4check_wreactorthrow_sensiAsimov_50000/*.root","pac30e21_dcp_point1_100k4check_narrow1_wreactorthrow_50k")'

mkdir ../plots/pac30e21_dcp_point1_100k4check_narrow1_wreactorthrow_100k
root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("pac30e21_narrow1_newsys100k4check_wreactorthrow_sensiAsimov_100000/*.root","pac30e21_dcp_point1_100k4check_narrow1_wreactorthrow_100k")'

