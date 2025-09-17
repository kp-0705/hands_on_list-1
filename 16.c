/*
========================================================================================================================================================================================
Name : 16.c
Author : Kartavyakumar Patel
Description : 16. Write a program to perform mandatory locking.
	      a. Implement write lock
	      b. Implement read lock

Date : 20th Aug, 2025
========================================================================================================================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
 int file_des;
 struct flock lk;
 char ch;

file_des=open("Demo16.txt",O_RDONLY |O_CREAT,0666);
if(file_des==-1)
 {
  perror("open file:");
 exit(1);  
 } 

printf("lock write for w\nlock read for r\n");
scanf("%c",&ch);

lk.l_whence=SEEK_SET;
lk.l_start=0;
lk.l_len=0;

if(ch=='r')
{
 lk.l_type=F_RDLCK;	
}
else if(ch=='w')
{
  lk.l_type=F_WRLCK;	
}
else
{printf("INVALID::");
  close(file_des);
 exit(1);
  }

printf("trying to acquier lock::\n");
if(fcntl(file_des,F_SETLKW,&lk)==-1)
{
 perror("fcntl:: ");
 close(file_des);
 exit(1);
}	

printf("lock acquired (press enter to release:)");
getchar();
getchar();

lk.l_type=F_UNLCK;
if(fcntl(file_des,F_SETLK,&lk)==-1)
{
 perror("UNLOCK::\n");	
}
else
{
 printf("lock release:::\n");	
}
return 0;
}
/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out
lock write for w
lock read for r
w
trying to acquier lock::
fcntl:: : Bad file descriptor

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ cc 16.c
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out
lock write for w
lock read for r
r
trying to acquier lock::
lock acquired (press enter to release:)
lock release:::
  
  
*/

