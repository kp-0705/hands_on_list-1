/*
========================================================================================================================================================================================
Name : 1f.c
Author : Kartavyakumar Patel
Description : 1. Create the following types of a files using (i) shell command (ii) system call
              c. FIFO (mkfifo Library Function or mknod system call) 
Date :10th Aug, 2025
========================================================================================================================================================================================
*/

#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>

int main()
{
 if(mkfifo("myfifo2", 0666)== -1)
 {
       perror("mkfifo");
        return 1;
 }
    printf("FIFO created successfully.\n");
    return 0;
}

/*
 Output:

    dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out
    FIFO created successfully.

*/

