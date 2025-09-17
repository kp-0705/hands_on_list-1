/*
========================================================================================================================================================================================
Name : 1s.c
Author : Kartavyakumar Patel
Description : 1. Create the following types of a files using (i) shell command (ii) system call

              a. soft link (symlink system call) 
Date :10th Aug, 2025
========================================================================================================================================================================================
*/
#include<unistd.h>
#include<stdio.h>
int main()
{
  if(symlink("shell_soft.txt","softlink2") == -1)
  {
    perror("symlink");
    return 1;
  }
  printf("Soft Link Done Successfullly.\n");
  return 0;
}
/*
 Output:

  dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out
  symlink: File exists

  
*/
