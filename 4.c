/*
========================================================================================================================================================================================
Name : 4.c
Author : Kartavyakumar Patel
Description : 4. Write a program to open an existing file with read write mode. Try O_EXCL flag also.

Date :14th Aug, 2025
========================================================================================================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
  int file_des;
  file_des=open("Demo3.txt",O_RDWR |O_CREAT |O_EXCL,0644);
  if(file_des == -1)
  {
    perror("OPEN");
  }  
  else
  {
   printf("Sucessfully done and file_descriptor is %d ",file_des);
   close(file_des);   
  }
  return 0;
}

/*
 Output:

  dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ vim 4.c
  dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out
  Sucessfully done and file_descriptor is 3 

*/
