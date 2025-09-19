/*
========================================================================================================================================================================================
Name : 20.c
Author : Kartavyakumar Patel
Description : 20. Find out the priority of your running program. Modify the priority with nice command.

Date :22th Aug, 2025
========================================================================================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <string.h>
int main()
{
	int newp;
	printf("\nEnter New priority : ");
	scanf(" %d",&newp);
	
	int p = getpriority(PRIO_PROCESS , getpid());
	printf("\nCurrent priority is %d.\n",p);
	printf("\nAfter update : %d.\n",nice(newp));
	return 0;
}


/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out

Enter New priority : 40

Current priority is 0.

After update : 19.
 
  
*/
