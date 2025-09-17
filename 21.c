/*
========================================================================================================================================================================================
Name : 21.c
Author : Kartavyakumar Patel
Description : 21. Write a program, call fork and print the parent and child process id.

Date :22th Aug, 2025
========================================================================================================================================================================================
*/
#include<stdio.h>
#include<unistd.h>

int main()
{
  if(!fork())
  { 
   printf("Child process PID:: %d , Parent of child PID:: %d\n",getpid(),getppid());	  
  }
  else
  {	  
   printf("Parent PID:: %d\n",getpid());	  
  }
  return 0;
}

/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out
Parent PID:: 76917
Child process PID:: 76918 , Parent of child PID:: 76917
   
*/
