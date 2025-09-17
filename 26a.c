/*
========================================================================================================================================================================================
Name : 26a.c
Author : Kartavyakumar Patel
Description : 26. Write a program to execute an executable program.
		  a. use some executable program
		  b. pass some input to an executable program. (for example execute an executable of $./a.out name)

Date : 30th Aug, 2025
========================================================================================================================================================================================
*/
#include<stdio.h>
int main(int vecc,char *vecn[])
{
 if(vecc>1)
 {
   printf("MY ROLL NUMBER IS,%s",vecn[1]);	 
 }
 else
 {
  printf("NAME IS not Given\n");	 
 }
 return 0;
}

/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ cc 26a.c
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out MT2025059
MY ROLL NUMBER IS,MT2025059

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ cc 26a.c
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ cc 26b.c
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out 
MY ROLL NUMBER IS,MT2025059
  
  
  
*/
