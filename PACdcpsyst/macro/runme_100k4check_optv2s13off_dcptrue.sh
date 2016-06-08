#!/bin/bash
for i in {1..39}
do
#   mkdir ../plots/pac30e21_dcp_point1_100k4check_optv2s13off_100ksensi_dcp${i}_wreactorthrow
#    root -l -b -q PlotSensiAsimov_deltaCP_reactor_test.C++\(\"pac30e21_100k4check_optv2s13off_dcp${i}_wreactorthrow_sensiAsimov_100000/*.root\",\"pac30e21_dcp_point1_100k4check_optv2s13off_100ksensi_dcp${i}_wreactorthrow\"\)

# mkdir ../plots/pac30e21_dcp_point1_100k4check_optv2s13off_100ksensi_dcp${i}_inv_wreactorthrow
# root -l -b -q PlotSensiAsimov_deltaCP_reactor_test.C++\(\"pac30e21_100k4check_optv2s13off_dcp${i}_inv_wreactorthrow_sensiAsimov_100000/*.root\",\"pac30e21_dcp_point1_100k4check_optv2s13off_100ksensi_dcp${i}_inv_wreactorthrow\"\)

 mkdir ../plots/pac30e21_dcp_point1_100k4check_optv2s13off_sin23hi_100ksensi_dcp${i}_wreactorthrow
    root -l -b -q PlotSensiAsimov_deltaCP_reactor_test.C++\(\"pac30e21_100k4check_optv2s13off_sin23hi_dcp${i}_wreactorthrow_sensiAsimov_100000/*.root\",\"pac30e21_dcp_point1_100k4check_optv2s13off_sin23hi_100ksensi_dcp${i}_wreactorthrow\"\)

 mkdir ../plots/pac30e21_dcp_point1_100k4check_optv2s13off_sin23hi_100ksensi_dcp${i}_inv_wreactorthrow
 root -l -b -q PlotSensiAsimov_deltaCP_reactor_test.C++\(\"pac30e21_100k4check_optv2s13off_sin23hi_dcp${i}_inv_wreactorthrow_sensiAsimov_100000/*.root\",\"pac30e21_dcp_point1_100k4check_optv2s13off_sin23hi_100ksensi_dcp${i}_inv_wreactorthrow\"\)

 mkdir ../plots/pac30e21_dcp_point1_100k4check_optv2s13off_sin23lo_100ksensi_dcp${i}_wreactorthrow
    root -l -b -q PlotSensiAsimov_deltaCP_reactor_test.C++\(\"pac30e21_100k4check_optv2s13off_sin23lo_dcp${i}_wreactorthrow_sensiAsimov_100000/*.root\",\"pac30e21_dcp_point1_100k4check_optv2s13off_sin23lo_100ksensi_dcp${i}_wreactorthrow\"\)

 mkdir ../plots/pac30e21_dcp_point1_100k4check_optv2s13off_sin23lo_100ksensi_dcp${i}_inv_wreactorthrow
 root -l -b -q PlotSensiAsimov_deltaCP_reactor_test.C++\(\"pac30e21_100k4check_optv2s13off_sin23lo_dcp${i}_inv_wreactorthrow_sensiAsimov_100000/*.root\",\"pac30e21_dcp_point1_100k4check_optv2s13off_sin23lo_100ksensi_dcp${i}_inv_wreactorthrow\"\)
done


