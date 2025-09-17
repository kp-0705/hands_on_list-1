/*
========================================================================================================================================================================================
Name : 12.c
Author : Kartavyakumar Patel
Description : 12. Write a program to find out the opening mode of a file. Use fcntl.
             
Date :18th Aug, 2025
========================================================================================================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
 int file_des,flag;
 file_des=open("Demo12.txt",O_WRONLY | O_CREAT |O_APPEND,0644);
 if(file_des==-1)
 {
  perror("Open_file");
  exit(1);  
 }

 flag=fcntl(file_des,F_GETFL);
 if(flag==-1)
 {
  perror("fcntl_error");
  close(file_des);
  exit(1);
 }
 
 if((flag & O_ACCMODE)==O_RDONLY)
	 printf("file open in only read \n");

 if((flag & O_ACCMODE)==O_WRONLY)
	 printf("file open in only write\n");
 
 if((flag & O_ACCMODE)==O_RDWR)
	 printf("file open in RD and WR both\n");

 if(flag & O_APPEND)
	 printf("file open in Append  \n");
 if(flag & O_NONBLOCK)
	 printf("file open in NON blocking \n");

  close(file_des);
 return 0;  
 }

/*
  Output:
  
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out
file open in only write
file open in Append      

*/
