/*
========================================================================================================================================================================================
Name : 23.c
Author : Kartavyakumar Patel
Description: 23. Write a program to create a Zombie state of the running program.  

Date : 22th Aug, 2025
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
  exit(0);
 }
 else
 {
  printf("PARENT ID: %d\n",getpid());
  printf("PARENT GO IN SLEEP MODE::\n");
  sleep(20);
 } 
 return 0;
}	

/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out
PARENT ID: 291636
PARENT GO IN SLEEP MODE::
CHILD ID: 291637 , PARENT of CHILD: 291636

//IN SECOND TERMINAL
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ps aux | grep 'Z'
dell      291637  0.0  0.0      0     0 pts/0    Z+   16:10   0:00 [a.out] <defunct>
  
  
*/
