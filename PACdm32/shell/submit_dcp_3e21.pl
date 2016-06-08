#!/usr/bin/perl

##
#$script = "./run.sh";
#$script = "./runcvson.sh";
#$script = "./runmergercvson.sh";
#$script = "./runmergercvson_StatOnly.sh";
#$script = "./runmergercvson_StatOnly_fix.sh";
#$script = "./runmergercvson_run16pot.sh";
#$script = "./runmergercvson_run16pot_StatOnly.sh";
#$script = "./runmergercvson_run16fix.sh";
#$script = "./runmergercvson_run16fix_StatOnly.sh";
#$script = "./runmergercvson_run16fix_wreactorthrow.sh";
#$script = "./runmergercvson_run16fix_wreactorthrow_StatOnly.sh";
###for dcp
$script = "./runmerger_3e21_wreactorthrow_dcp_StatOnly.sh";
#$script = "./runmerger_3e21_wreactorthrow_dcp_inverted_StatOnly.sh";
#$script = "./runmerger_3e21_wreactorthrow_dcp.sh";
#$script = "./runmerger_3e21_wreactorthrow_dcp_inverted.sh";

#$script = "./runsensiAsimov.sh";
#$script = "./runsensiAsimov_StatOnly.sh";
#$script = "./runsensiAsimov_StatOnly_fix.sh";
#$script = "./runsensiAsimov_run16pot.sh";
#$script = "./runsensiAsimov_run16pot_StatOnly.sh";

#$script = "./runmargfitter.sh";
#$script = "./runmargfitter_run16fix.sh";

#$end_run = 4131;
#changing 13delta, ,23->fix or merge //81*51/17=243
#$end_run = 243;
#changing 23, ,13delta->fix or merge //101*21/21=101
$start_run = 1;
$end_run = 101;
##for dcp
#$end_run = 51;
#$end_run = 1;

###For MargFitter
#$start_run = 101;
#$end_run = 1030;

####
for($run_num = $start_run; $run_num <= $end_run; $run_num++) {

  system("echo $run_num");
  system("/bin/rm -f run/job_merger_3e21_$run_num.sh");

##
  open(OUT,">run/job_merger_3e21_$run_num.sh");
  print(OUT "\#\!/bin/sh -f\n");
  #print(OUT "\#BSUB -q e\n");
  print(OUT "\#BSUB -q s\n");
  print(OUT "\#BSUB -J \"job_merger_3e21_$run_num\"\n");
  print(OUT "cd ~/gpfs/ptheta/pac2016/20151128/Ptheta_MultiSample/PACdm32/shell\n");
  print(OUT "$script $run_num");
  close(OUT);

  system("chmod a+x run/job_merger_3e21_$run_num.sh");
     system("bsub < run/job_merger_3e21_$run_num.sh");
    #system("/bin/rm -f run/job_merger_3e21_$run_num.sh");

    #$num = `bjobs | wc -l`;
    #while ($num > 130){
    # system("echo sleeping");
    # sleep (59);
    #  $num = `bjobs | wc -l`;
    #}
  select(undef, undef, undef, 0.05);
}
