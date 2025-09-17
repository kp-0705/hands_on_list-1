/*
========================================================================================================================================================================================
Name : 13.c
Author : Kartavyakumar Patel
Description : 13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
              verify whether the data is available within 10 seconds or not (check in $man 2 select).

Date :19th Aug, 2025
========================================================================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/types.h>

int main()
{
 fd_set file_des;
 struct timeval tv={10,0};
 FD_ZERO(&file_des);
 FD_SET(0,&file_des);
 if(select(1,&file_des,NULL,NULL,&tv)>0)
 {
  char buf[100];
  read(0,buf,sizeof(buf));
  printf("YOUR TASK: %s\n",buf);  
 }
 else
 {
  printf("\nTIMEout??");	 
 }
return 0;
}
/*
  Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out
hello
YOUR TASK: hello

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ cc 13.c
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out
hello my name is kp and your
TIMEout??   
  
*/
