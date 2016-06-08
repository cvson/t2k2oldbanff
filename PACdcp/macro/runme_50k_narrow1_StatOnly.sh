#!/bin/sh
mkdir ../plots/pac30e21_dcp_point1_50k_narrow1_wreactorthrow_StatOnly
root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("pac30e21_narrow1_wreactorthrow_StatOnly_sensiAsimov_50000/*.root","pac30e21_dcp_point1_50k_narrow1_wreactorthrow_StatOnly")'
    mkdir ../plots/pac20e21_dcp_point1_50k_narrow1_wreactorthrow_StatOnly
    root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("pac20e21_narrow1_wreactorthrow_StatOnly_sensiAsimov_50000/*.root","pac20e21_dcp_point1_50k_narrow1_wreactorthrow_StatOnly")'
    mkdir ../plots/pac15e21_dcp_point1_50k_narrow1_wreactorthrow_StatOnly
    root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("pac15e21_narrow1_wreactorthrow_StatOnly_sensiAsimov_50000/*.root","pac15e21_dcp_point1_50k_narrow1_wreactorthrow_StatOnly")'
    mkdir ../plots/pac7d8e21_dcp_point1_50k_narrow1_wreactorthrow_StatOnly
    root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("pac7d8e21_narrow1_wreactorthrow_StatOnly_sensiAsimov_50000/*.root","pac7d8e21_dcp_point1_50k_narrow1_wreactorthrow_StatOnly")'
    mkdir ../plots/current_dcp_point1_50k_narrow1_wreactorthrow_StatOnly
    root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("current_narrow1_wreactorthrow_StatOnly_sensiAsimov_50000/*.root","current_dcp_point1_50k_narrow1_wreactorthrow_StatOnly")'
