/*
========================================================================================================================================================================================
Name : 25.c
Author : Kartavyakumar Patel
Description : 25. Write a program to create three child processes. The parent should wait for a particular child (use waitpid system call).

Date : 30th Aug, 2025
========================================================================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
 int cpid1,cpid2,cpid3;
 cpid1=fork();
 if(cpid1==0)
 {
  printf("CHILD ID: %d , PARENT of CHILD: %d\n",getpid(),getppid());
  sleep(2);
  exit(0);
 }

 cpid2=fork();
 if(cpid1==0)
 {
  printf("CHILD ID: %d , PARENT of CHILD: %d\n",getpid(),getppid());
  sleep(4);
  exit(0);
 }

 cpid3=fork();
 if(cpid1==0)
 {
  printf("CHILD ID: %d , PARENT of CHILD: %d\n",getpid(),getppid());
  sleep(6);
  exit(0);
 }
 //PARENT WAIT FOR 3 CHILD TERMINATE THEN EXIT :::
 printf("PARENT ID IS ::%d\n",getpid());

 int status,w;
 w=waitpid(cpid3,&status,0);
 if(w==-1)
 {
  perror("WAIT SYSTEM CALL");
 }
 else
 {
  printf("Child Process PID : %d is FINISHED\n",w);	 
 }
 printf("THEN PARENT Finished\n");

 return 0;
}



/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out
CHILD ID: 314030 , PARENT of CHILD: 314029
PARENT ID IS ::314029
PARENT ID IS ::314032
WAIT SYSTEM CALL: No child processes
THEN PARENT Finished
PARENT ID IS ::314031
PARENT ID IS ::314033
WAIT SYSTEM CALL: No child processes
THEN PARENT Finished
Child Process PID : 314032 is FINISHED
THEN PARENT Finished
Child Process PID : 314033 is FINISHED
THEN PARENT Finished


  
*/
