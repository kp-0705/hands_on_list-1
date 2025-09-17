/*
========================================================================================================================================================================================
Name : 22.c
Author : Kartavyakumar Patel
Description : 22. Write a program, open a file, call fork, and then write to the file by both the child as well as the
	      parent processes. Check output of the file.

Date : 22th Aug, 2025
========================================================================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
 int file_des;
 file_des=open("Demo22.txt",O_RDWR|O_CREAT|O_TRUNC,0644);
 if(file_des<0)
 {
  perror("OPEN::");
  exit(1);  
 }
 
 if(!fork())
  {
   char msgc[100];
   int len1=sprintf(msgc,"Child PID:: %d , Parent of child PID:: %d\n",getpid(),getppid());
   write(file_des,msgc,len1);
  }
  else
  {
   char msgp[100];
   int len2=sprintf(msgp,"Parent PID:: %d\n",getpid());
   write(file_des,msgp,len2);
  }
  close(file_des);
  return 0;
}

/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ cat Demo22.txt
Parent PID:: 78593
Child PID:: 78594 , Parent of child PID:: 78593
  
*/
