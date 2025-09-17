/*
========================================================================================================================================================================================
Name : 30.c
Author : Kartavyakumar Patel
Description : 30. Write a program to run a script at a specific time using a Daemon process.

Date : 1st sept, 2025
========================================================================================================================================================================================
*/
//(a daemon process is &process that runs indep of any terminal and performs specific tasks)

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

int main()
{
   while(1)
   {
      time_t cur_time=time(NULL);
      struct tm *t=localtime(&cur_time);
      if(t->tm_hour==19 && t->tm_min==23)
      {
	      printf("OPEN DEAMON PROCESS...\n");
	      system("./demo_deamon.sh");
	      break;
      }
      sleep(30);
   }	 
   return 0;
}

/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out
OPEN DEAMON PROCESS...
I AM DEMO DEAMON.sh ,HOW ARE YOU????:
finished....
  

//demo_deamon.sh

#! /bin/bash
echo "I AM DEMO DEAMON.sh ,HOW ARE YOU????:"
echo "finished...."
  
*/
