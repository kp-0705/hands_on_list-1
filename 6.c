/*
========================================================================================================================================================================================
Name : 6.c
Author : Kartavyakumar Patel
Description : 6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
    
Date :16th Aug, 2025
========================================================================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	char buf[200];
	int read_data;

	read_data=read(0,buf,sizeof(buf));

        write(1,buf,read_data);
        return 0;
}

/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out
hello_my name is kp and how are you all today.......
hello_my name is kp and how are you all today.......


*/

