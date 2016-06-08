#!/bin/sh

mkdir ../plots/current_s13off_wreactorthrow_StatOnly_sensiAsimov_100k_dm32
root -b -q 'PlotSensiAsimov_dm32_reactor_test.C++("current_s13off_wreactorthrow_StatOnly_sensiAsimov_100000/*.root","current_s13off_wreactorthrow_StatOnly_sensiAsimov_100k_dm32")'
mkdir ../plots/pac7d8e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_100k_dm32
root -b -q 'PlotSensiAsimov_dm32_reactor_test.C++("pac7d8e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_100000/*.root","pac7d8e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_100k_dm32")'
mkdir ../plots/pac15e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_100k_dm32
root -b -q 'PlotSensiAsimov_dm32_reactor_test.C++("pac15e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_100000/*.root","pac15e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_100k_dm32")'
mkdir ../plots/pac20e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_100k_dm32
root -b -q 'PlotSensiAsimov_dm32_reactor_test.C++("pac20e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_100000/*.root","pac20e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_100k_dm32")'
mkdir ../plots/pac30e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_100k_dm32
root -b -q 'PlotSensiAsimov_dm32_reactor_test.C++("pac30e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_100000/*.root","pac30e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_100k_dm32")'

#mkdir ../plots/current_s13off_wreactorthrow_StatOnly_sensiAsimov_50k_dm32
#    root -b -q 'PlotSensiAsimov_dm32_reactor_test.C++("current_s13off_wreactorthrow_StatOnly_sensiAsimov_50000/*.root","current_s13off_wreactorthrow_StatOnly_sensiAsimov_50k_dm32")'
#    mkdir ../plots/pac7d8e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_50k_dm32
#    root -b -q 'PlotSensiAsimov_dm32_reactor_test.C++("pac7d8e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_50000/*.root","pac7d8e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_50k_dm32")'
#    mkdir ../plots/pac15e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_50k_dm32
#    root -b -q 'PlotSensiAsimov_dm32_reactor_test.C++("pac15e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_50000/*.root","pac15e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_50k_dm32")'
#    mkdir ../plots/pac20e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_50k_dm32
#    root -b -q 'PlotSensiAsimov_dm32_reactor_test.C++("pac20e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_50000/*.root","pac20e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_50k_dm32")'
#    mkdir ../plots/pac30e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_50k_dm32
#    root -b -q 'PlotSensiAsimov_dm32_reactor_test.C++("pac30e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_50000/*.root","pac30e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_50k_dm32")'
    
#mkdir ../plots/current_s13off_wreactorthrow_StatOnly_sensiAsimov_10k_dm32
#    root -b -q 'PlotSensiAsimov_dm32_reactor_test.C++("current_s13off_wreactorthrow_StatOnly_sensiAsimov_10000/*.root","current_s13off_wreactorthrow_StatOnly_sensiAsimov_10k_dm32")'
#    mkdir ../plots/pac7d8e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_10k_dm32
#    root -b -q 'PlotSensiAsimov_dm32_reactor_test.C++("pac7d8e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_10000/*.root","pac7d8e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_10k_dm32")'
#    mkdir ../plots/pac15e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_10k_dm32
#    root -b -q 'PlotSensiAsimov_dm32_reactor_test.C++("pac15e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_10000/*.root","pac15e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_10k_dm32")'
#    mkdir ../plots/pac20e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_10k_dm32
#    root -b -q 'PlotSensiAsimov_dm32_reactor_test.C++("pac20e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_10000/*.root","pac20e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_10k_dm32")'
#    mkdir ../plots/pac30e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_10k_dm32
#    root -b -q 'PlotSensiAsimov_dm32_reactor_test.C++("pac30e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_10000/*.root","pac30e21_optv2s13off_wreactorthrow_StatOnly_sensiAsimov_10k_dm32")'
