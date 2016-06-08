#!/usr/bin/perl
$start_run = 1;
$end_run = 39;
for($run_num = $start_run; $run_num <= $end_run; $run_num++) {
system("/usr/bin/perl submit_asimov_dcp_30e21_dcp$run_num.pl")
#system("/usr/bin/perl submit_asimov_dcp_30e21_dcp${run_num}_StatOnly.pl")
}
