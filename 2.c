/*
========================================================================================================================================================================================
Name : 2.c
Author : Kartavyakumar Patel
Description : 2. Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.

Date :10th Aug, 2025
========================================================================================================================================================================================
*/
#include<unistd.h>
#include<stdio.h>
int main()
{
 while(1)
 {
  sleep(5);
 }
 return 0;
}

/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out &
[1] 32518

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ cd /proc/32518
dell@dell-Inspiron-3593:/proc/32518$ ls 
arch_status  clear_refs          cpuset   fdinfo             latency    mem         ns             pagemap      sched      smaps_rollup  syscall         uid_map
attr         cmdline             cwd      gid_map            limits     mountinfo   numa_maps      patch_state  schedstat  stack         task            wchan
autogroup    comm                environ  io                 loginuid   mounts      oom_adj        personality  sessionid  stat          timens_offsets
auxv         coredump_filter     exe      ksm_merging_pages  map_files  mountstats  oom_score      projid_map   setgroups  statm         timers
cgroup       cpu_resctrl_groups  fd       ksm_stat           maps       net         oom_score_adj  root         smaps      status        timerslack_ns

dell@dell-Inspiron-3593:/proc/32518$ cd task
dell@dell-Inspiron-3593:/proc/32518/task$ ls
32518

dell@dell-Inspiron-3593:/proc/32518$ cd fd
dell@dell-Inspiron-3593:/proc/32518/fd$ ls
0  1  2

dell@dell-Inspiron-3593:/proc/32518/fd$ ls -l
total 0
lrwx------ 1 dell dell 64 Aug 19 16:21 0 -> /dev/pts/1
lrwx------ 1 dell dell 64 Aug 19 16:21 1 -> /dev/pts/1
lrwx------ 1 dell dell 64 Aug 19 16:21 2 -> /dev/pts/1

dell@dell-Inspiron-3593:/proc/32518/fd$ cd ..
dell@dell-Inspiron-3593:/proc/32518$ cd ..
dell@dell-Inspiron-3593:/proc$ kill 32518

dell@dell-Inspiron-3593:/proc$ cd 32518
bash: cd: 32518: No such file or directory


*/
