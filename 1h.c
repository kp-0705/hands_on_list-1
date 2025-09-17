/*
========================================================================================================================================================================================
Name : 1h.c
Author : Kartavyakumar Patel
Description : 1. Create the following types of a files using (i) shell command (ii) system call
              b. hard link (link system call)
Date : 10th Aug, 2025
========================================================================================================================================================================================
*/

#include<unistd.h>
#include<stdio.h>
int main()
{
 if(link("shell_hard.text","hardlink2") == -1)
 {
  perror("link");
  return 1;
 }
 printf("Hard Link Done Successfully.\n");
 return 0;
}

/*
Output:
        dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out
        Hard Link Done Successfully.
*/   
