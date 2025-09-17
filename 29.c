/*
========================================================================================================================================================================================
Name : 29.c
Author : Kartavyakumar Patel
Description : 29. Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,SCHED_RR).

Date :1st sept, 2025
========================================================================================================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sched.h>
#include<unistd.h>

int main()
{
int sc;
struct sched_param set;

sc=sched_getscheduler(0);
 if(sc==-1)
 {
  perror("ERROR SHEDULER:: ");	 
  return 1;
 }

 if(sc==SCHED_OTHER)
	 printf("CURRENT POLICY :: SCHED_OTHER\n");
 else if(sc==SCHED_FIFO)
	 printf("CURRENT POLICY :: SCHED_FIFO\n");
 else if(sc==SCHED_RR)
	 printf("CURRENT POLICY :: SCHED_RR\n");
 else 
   printf("CURRENT POLICY :: UNKNOW\n");

 set.sched_priority=40;
 
 if(sched_setscheduler(0,SCHED_RR,&set)==-1)
  {
  perror("ERROR SCHEDULER::");
  return 1;  
  }

 sc=sched_getscheduler(0);
 
 if(sc==SCHED_OTHER)
         printf("CURRENT POLICY :: SCHED_OTHER\n");
 else if(sc==SCHED_FIFO)
         printf("CURRENT POLICY :: SCHED_FIFO\n");
 else if(sc==SCHED_RR)
         printf("CURRENT POLICY :: SCHED_RR\n");
 else 
   printf("CURRENT POLICY :: UNKNOW\n");

 return 0;
}
/*
 Output:  // run using sudo bcz set real time policies, you need root.....

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ cc 29.c
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ sudo ./a.out
[sudo] password for dell: 
CURRENT POLICY :: SCHED_OTHER
CURRENT POLICY :: SCHED_RR
  
  
*/
