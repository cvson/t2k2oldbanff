#!/usr/bin/perl
$script = "submit_asimov_dcp_7d8e21_dcp1.pl";
$start_run = 2;
$end_run = 39;
for($run_num = $start_run; $run_num <= $end_run; $run_num++) {
system("/bin/cp -f $script submit_asimov_dcp_7d8e21_dcp$run_num.pl");
#$tmp = `-type f -exec sed -i 's/dcp1/dcp$run_num/g' {} \;`;
#system("find submit_asimov_dcp_7d8e21_dcp$run_num.pl $tmp");
system("/usr/bin/perl -pi -e 's/dcp1/dcp$run_num/g;' submit_asimov_dcp_7d8e21_dcp$run_num.pl")
}
