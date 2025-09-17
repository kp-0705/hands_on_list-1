/*
========================================================================================================================================================================================
Name : 8.c
Author : Kartavyakumar Patel
Description : 8. Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
             
Date :17th Aug, 2025
========================================================================================================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   
#include <fcntl.h>   
#include <string.h>   

int main() {
    int file_des;
    char buffer[512];
    ssize_t bytes_read;
    char line[512];
    int c = 0;

    file_des= open("Demo3.txt", O_RDONLY);
    if (file_des== -1) {
        perror("open");
        exit(1);
    }

    while ((bytes_read = read(file_des, buffer, sizeof(buffer))) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            line[c++] = buffer[i];
             if(buffer[i]=='\n')
	     { line[c] = '\0';
               write(1, line, strlen(line)); 
	       c=0;
            }
        }
    }

    if (c>0) {
        line[c] = '\0';
        write(1, line, strlen(line));
    }

    close(file_des);
    return 0;
}
/*
  Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out
A hard link is another directory entry pointing to the same inode (same data on disk).
Both filenames share the same
inode → deleting one doesn’t remove the data (as long as one hard link exists).
   
    
*/
