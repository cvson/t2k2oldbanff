#!/usr/bin/perl
$script = "runsensiAsimov_7d8e21_wreactorthrow_dcp1.sh";
$start_run = 1;
$end_run = 39;
for($run_num = $start_run; $run_num <= $end_run; $run_num++) {
system("/usr/bin/perl submit_asimov_dcp_7d8e21_dcp$run_num.pl")
}
