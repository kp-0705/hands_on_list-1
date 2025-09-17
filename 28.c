/*
========================================================================================================================================================================================
Name : 28.c
Author : Kartavyakumar Patel
Description : 28. Write a program to get maximum and minimum real time priority.

Date :31th Aug, 2025
========================================================================================================================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<sched.h>
#include<unistd.h>
int main()
{
 int maf=sched_get_priority_max(SCHED_FIFO);
 int mif=sched_get_priority_min(SCHED_FIFO);
 int maRR=sched_get_priority_max(SCHED_RR);
 int miRR=sched_get_priority_min(SCHED_RR); 
 
 
 printf("RR: minimum real time priority= %d\n",miRR);
 printf("RR: maximum real time priority= %d\n",maRR);
 printf("FIFO: minimum real time priority= %d\n",mif);
 printf("FIFO: maximum real time priority= %d\n",maf);
 return 0;

}

/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out
RR: minimum real time priority= 1
RR: maximum real time priority= 99
FIFO: minimum real time priority= 1
FIFO: maximum real time priority= 99

  
*/
