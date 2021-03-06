#!/bin/sh



mkdir ../plots/current_dcp_point1_s13off_sin23hi528_100ksensi_wreactorthrow_StatOnly
    root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("current_s13off_sin23hi528_wreactorthrow_StatOnly_sensiAsimov_100000/*.root","current_dcp_point1_s13off_sin23hi528_100ksensi_wreactorthrow_StatOnly")'
    mkdir ../plots/current_dcp_point1_s13off_sin23hi_100ksensi_wreactorthrow_StatOnly
    root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("current_s13off_sin23hi_wreactorthrow_StatOnly_sensiAsimov_100000/*.root","current_dcp_point1_s13off_sin23hi_100ksensi_wreactorthrow_StatOnly")'
    mkdir ../plots/current_dcp_point1_s13off_sin23lo_100ksensi_wreactorthrow_StatOnly
    root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("current_s13off_sin23lo_wreactorthrow_StatOnly_sensiAsimov_100000/*.root","current_dcp_point1_s13off_sin23lo_100ksensi_wreactorthrow_StatOnly")'
    
    mkdir ../plots/current_dcp_point1_100k4check_s13off_sin23hi528_100ksensi_wreactorthrow
    root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("current_100k4check_s13off_sin23hi528_wreactorthrow_sensiAsimov_100000/*.root","current_dcp_point1_100k4check_s13off_sin23hi528_100ksensi_wreactorthrow")'
    mkdir ../plots/current_dcp_point1_100k4check_s13off_sin23hi_100ksensi_wreactorthrow
    #root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("current_100k4check_s13off_sin23hi_wreactorthrow_sensiAsimov_100000/*.root","current_dcp_point1_100k4check_s13off_sin23hi_100ksensi_wreactorthrow")'
    mkdir ../plots/current_dcp_point1_100k4check_s13off_sin23lo_100ksensi_wreactorthrow
    #root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("current_100k4check_s13off_sin23lo_wreactorthrow_sensiAsimov_100000/*.root","current_dcp_point1_100k4check_s13off_sin23lo_100ksensi_wreactorthrow")'

mkdir ../plots/pac2d5e21_dcp_point1_optv2s13off_sin23hi528_100ksensi_wreactorthrow_StatOnly
    root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("pac2d5e21_optv2s13off_sin23hi528_wreactorthrow_StatOnly_sensiAsimov_100000/*.root","pac2d5e21_dcp_point1_optv2s13off_sin23hi528_100ksensi_wreactorthrow_StatOnly")'
    mkdir ../plots/pac2d5e21c2_dcp_point1_optv2s13off_sin23hi528_100ksensi_wreactorthrow_StatOnly
    root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("pac2d5e21c2_optv2s13off_sin23hi528_wreactorthrow_StatOnly_sensiAsimov_100000/*.root","pac2d5e21c2_dcp_point1_optv2s13off_sin23hi528_100ksensi_wreactorthrow_StatOnly")'
    
    mkdir ../plots/pac2d5e21_dcp_point1_100k4check_optv2s13off_sin23hi528_100ksensi_wreactorthrow
    root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("pac2d5e21_100k4check_optv2s13off_sin23hi528_wreactorthrow_sensiAsimov_100000/*.root","pac2d5e21_dcp_point1_100k4check_optv2s13off_sin23hi528_100ksensi_wreactorthrow")'
    mkdir ../plots/pac2d5e21c2_dcp_point1_100k4check_optv2s13off_sin23hi528_100ksensi_wreactorthrow
    root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("pac2d5e21c2_100k4check_optv2s13off_sin23hi528_wreactorthrow_sensiAsimov_100000/*.root","pac2d5e21c2_dcp_point1_100k4check_optv2s13off_sin23hi528_100ksensi_wreactorthrow")'

mkdir ../plots/pac2d5e21_dcp_point1_optv2s13off_sin23hi528_100ksensi_inv_wreactorthrow_StatOnly
    root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("pac2d5e21_optv2s13off_sin23hi528_inv_wreactorthrow_StatOnly_sensiAsimov_100000/*.root","pac2d5e21_dcp_point1_optv2s13off_sin23hi528_100ksensi_inv_wreactorthrow_StatOnly")'
    mkdir ../plots/pac2d5e21c2_dcp_point1_optv2s13off_sin23hi528_100ksensi_inv_wreactorthrow_StatOnly
    root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("pac2d5e21c2_optv2s13off_sin23hi528_inv_wreactorthrow_StatOnly_sensiAsimov_100000/*.root","pac2d5e21c2_dcp_point1_optv2s13off_sin23hi528_100ksensi_inv_wreactorthrow_StatOnly")'
    
    mkdir ../plots/pac2d5e21_dcp_point1_100k4check_optv2s13off_sin23hi528_100ksensi_inv_wreactorthrow
    root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("pac2d5e21_100k4check_optv2s13off_sin23hi528_inv_wreactorthrow_sensiAsimov_100000/*.root","pac2d5e21_dcp_point1_100k4check_optv2s13off_sin23hi528_100ksensi_inv_wreactorthrow")'
    mkdir ../plots/pac2d5e21c2_dcp_point1_100k4check_optv2s13off_sin23hi528_100ksensi_inv_wreactorthrow
    root -l -b -q 'PlotSensiAsimov_deltaCP_reactor_test.C++("pac2d5e21c2_100k4check_optv2s13off_sin23hi528_inv_wreactorthrow_sensiAsimov_100000/*.root","pac2d5e21c2_dcp_point1_100k4check_optv2s13off_sin23hi528_100ksensi_inv_wreactorthrow")'
