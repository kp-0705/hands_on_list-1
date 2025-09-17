/*
========================================================================================================================================================================================
Name : 10.c
Author : Kartavyakumar Patel
Description : 10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
		  bytes (use lseek) and write again 10 bytes.
              a. check the return value of lseek
              b. open the file with od and check the empty spaces in between the data.

Date :17th Aug, 2025
========================================================================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
 int file_des;
 char buf1[10]="0123456789";
 char buf2[10]="9876543210";
 int write_data;
 int offset;
 
 file_des=open("Demo4.txt",O_RDWR |O_CREAT|O_TRUNC,0666);
 if(file_des==-1)
 {
  perror("open_file");
  exit(1);  
 }
 write_data=write(file_des,buf1,10);
 printf("\n");
 offset=lseek(file_des,10,SEEK_CUR);
 printf("FILE_POINTER::%ld\n",(long)offset);
 write_data=write(file_des,buf2,10);
 printf("\n");
 printf("successfully::\n");
 close(file_des);
 return 0;
}
/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out

FILE_POINTER::20

successfully::

Demo4.txt

0123456789 \00\00\00\00\00\00\00\00\00\00 9876543210

*/
