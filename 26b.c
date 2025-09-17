/*
========================================================================================================================================================================================
Name : 26b.c
Author : Kartavyakumar Patel
Description : 26. Write a program to execute an executable program.
                  a. use some executable program
                  b. pass some input to an executable program. (for example execute an executable of $./a.out name)

Date : 30th Aug, 2025
========================================================================================================================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
  execl("./26a","26a","MT2025059",(char *)NULL);
  perror("EXECL ERROR:");  
  return 1;	
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

