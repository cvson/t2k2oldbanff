#!/usr/bin/perl
#$script = "runsensiAsimov_30e21_wreactorthrow_dcp1.sh";
#$script = "runsensiAsimov_30e21_wreactorthrow_dcp1_StatOnly.sh";
#$script = "runsensiAsimov_30e21_wreactorthrow_dcp1_inverted_StatOnly.sh";
$script = "runsensiAsimov_30e21_wreactorthrow_dcp1_inverted.sh";
$start_run = 2;
$end_run = 39;
for($run_num = $start_run; $run_num <= $end_run; $run_num++) {
#system("/bin/cp $script runsensiAsimov_30e21_wreactorthrow_dcp$run_num.sh");
#system("/usr/bin/perl -pi -e 's/dcp1/dcp$run_num/g;' runsensiAsimov_30e21_wreactorthrow_dcp$run_num.sh")
#system("/bin/cp $script runsensiAsimov_30e21_wreactorthrow_dcp${run_num}_StatOnly.sh");
#system("/usr/bin/perl -pi -e 's/dcp1/dcp$run_num/g;' runsensiAsimov_30e21_wreactorthrow_dcp${run_num}_StatOnly.sh")
#system("/bin/cp -f $script runsensiAsimov_30e21_wreactorthrow_dcp${run_num}_inverted_StatOnly.sh");
#system("/usr/bin/perl -pi -e 's/dcp1/dcp$run_num/g;' runsensiAsimov_30e21_wreactorthrow_dcp${run_num}_inverted_StatOnly.sh")

system("/bin/cp -f $script runsensiAsimov_30e21_wreactorthrow_dcp${run_num}_inverted.sh");
system("/usr/bin/perl -pi -e 's/dcp1/dcp$run_num/g;' runsensiAsimov_30e21_wreactorthrow_dcp${run_num}_inverted.sh")
}
