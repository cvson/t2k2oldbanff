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
#$script = "./runmerger_30e21c5_wreactorthrow_dcp_StatOnly.sh";
#$script = "./runmerger_30e21c5_wreactorthrow_dcp_case1_StatOnly.sh";
#$script = "./runmerger_30e21c5_wreactorthrow_dcp_case2_StatOnly.sh";
#$script = "./runmerger_30e21c5_wreactorthrow_dcp_case3_StatOnly.sh";
#$script = "./runmerger_30e21c5_wreactorthrow_dcp_case4_StatOnly.sh";
#$script = "./runmerger_30e21c5_wreactorthrow_dcp_case5_StatOnly.sh";
#$script = "./runmerger_30e21c5_wreactorthrow_dcp_StatOnly_new.sh";
#$script = "./runmerger_30e21c5_wreactorthrow_dcp_StatOnly_new2.sh";#new template, all para =1
$script = "./runmerger_30e21c5_wreactorthrow_dcp_inverted_StatOnly.sh";
#$script = "./runmerger_30e21c5_wreactorthrow_dcp.sh";
#$script = "./runmerger_30e21c5_wreactorthrow_dcp_case1.sh";
#$script = "./runmerger_30e21c5_wreactorthrow_dcp_case2.sh";
#$script = "./runmerger_30e21c5_wreactorthrow_dcp_case3.sh";
#$script = "./runmerger_30e21c5_wreactorthrow_dcp_case4.sh";
#$script = "./runmerger_30e21c5_wreactorthrow_dcp_case5.sh";
#$script = "./runmerger_30e21c5_wreactorthrow_dcp_inverted.sh";
#$script = "./runmerger_30e21c5_wreactorthrow_dcp_new.sh";

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
#$end_run = 101;
##for dcp
$end_run = 51;
#$end_run = 101;

###For MargFitter
#$start_run = 101;
#$end_run = 1030;

####
for($run_num = $start_run; $run_num <= $end_run; $run_num++) {

  system("echo $run_num");
  system("/bin/rm -f run/job_merger_30e21c5_$run_num.sh");

##
  open(OUT,">run/job_merger_30e21c5_$run_num.sh");
  print(OUT "\#\!/bin/sh -f\n");
  #print(OUT "\#BSUB -q e\n");
  print(OUT "\#BSUB -q s\n");
  print(OUT "\#BSUB -J \"job_merger_30e21c5_$run_num\"\n");
  print(OUT "cd ~/gpfs/ptheta/pac2016/20151128/Ptheta_MultiSample/PACdcp/shell\n");
  print(OUT "$script $run_num");
  close(OUT);

  system("chmod a+x run/job_merger_30e21c5_$run_num.sh");
  system("bsub < run/job_merger_30e21c5_$run_num.sh");
    #system("/bin/rm -f run/job_merger_30e21c5_$run_num.sh");

    #$num = `bjobs | wc -l`;
    #while ($num > 130){
    # system("echo sleeping");
    # sleep (59);
    #  $num = `bjobs | wc -l`;
    #}
  select(undef, undef, undef, 0.05);
}
#open(OUT,">run/job_merger_30e21c5_all.sh");
#    print(OUT "\#\!/bin/sh -f\n");
#    print(OUT "cd ~/gpfs/ptheta/pac2016/20151128/Ptheta_MultiSample/PACdcp/shell/run\n");
#    for($run_num = $start_run; $run_num <= $end_run; $run_num++) {
#        print(OUT "./job_merger_30e21c5_$run_num.sh\n");
#        select(undef, undef, undef, 0.05);
#    }
#    close(OUT);
#    system("chmod a+x run/job_merger_30e21c5_all.sh");
#    system("bsub < run/job_merger_30e21c5_all.sh");
