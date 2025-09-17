/*
========================================================================================================================================================================================
Name : 24.c
Author : Kartavyakumar Patel
Description : 24. Write a program to create an orphan process.

Date : 29 Aug, 2025
========================================================================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
 if(!fork())
 {
  printf("CHILD ID: %d , PARENT of CHILD: %d\n",getpid(),getppid());
  sleep(20);
  printf("\nNOW ORPHAN PROCESS BCZ PARENT TERMINATE\n");
  printf("NEW PARENT PID::%d\n",getppid());
 
 }
 else
 {
  printf("PARENT ID: %d\n",getpid());
  printf("parent process terminate.....\n");
  exit(0);
 }
 return 0;
}

/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out
PARENT ID: 297682
parent process terminate.....
CHILD ID: 297683 , PARENT of CHILD: 297682

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ps -ef | grep 297683
dell      297683    1986  0 21:22 pts/0    00:00:00 ./a.out
dell      297685  290519  0 21:22 pts/0    00:00:00 grep --color=auto 297683

//after 20 sec
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ 
NOW ORPHAN PROCESS BCZ PARENT TERMINATE
NEW PARENT PID::1986

  
*/
