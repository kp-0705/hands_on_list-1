/*
========================================================================================================================================================================================
Name : 3.c
Author : Kartavyakumar Patel
Description : 3. Write a program to create a file and print the file descriptor value. Use creat ( ) system call 

Date :10th Aug, 2025
========================================================================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
 int file_dis=creat("Demo3.txt",0666);
 if(file_dis==-1)
 {
 perror("creat");
 exit(1);
 }
 printf("SUccessfully:: \n");
 printf("File Descriptor:%d\n",file_dis);
 close(file_dis);
 return 0;
 
}

/*
 Output:

   dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out
   SUccessfully:: 
   File Descriptor:3

*/

