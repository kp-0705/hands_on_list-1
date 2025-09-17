/*
========================================================================================================================================================================================
Name : 9.c
Author : Kartavyakumar Patel
Description :  9. Write a program to print the following information about a given file.
		a. inode
		b. number of hard links
		c. uid
		d. gid
		e. size
		f. block size
		g. number of blocks
		h. time of last access
		i. time of last modification
		j. time of last change

Date :17th Aug, 2025
========================================================================================================================================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<time.h>

int main()
{
  struct stat fs;
  if(stat("Demo3.txt",&fs)==-1)
  {
   perror("stat_fail:");
   exit(1);   
  }

 printf("file_name: Demo3.txt\n"); 
 printf("Inode %ld\n",(long)fs.st_ino); 
 printf("# hardLinks: %ld\n",(long)fs.st_nlink); 
 printf("UID: %d\n",fs.st_uid); 
 printf("GID: %d\n",fs.st_gid); 
 printf("SIZE OF FILE: %ld\n",(long)fs.st_size);  
 printf("BLOCK SIZE: %ld\n",(long)fs.st_blksize);
 printf("# blocks: %ld\n",(long)fs.st_blocks);
 printf("Last acces time%s\n",ctime(&fs.st_atime)); 
 printf("last modify time%s\n",ctime(&fs.st_mtime)); 
 printf("last change status time%s",ctime(&fs.st_ctime)); 
 }

/*
  Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out
file_name: Demo3.txt
Inode 4462814
# hardLinks: 1
UID: 1000
GID: 1000
SIZE OF FILE: 201
BLOCK SIZE: 4096
# blocks: 8
Last acces timeTue Aug 19 19:27:56 2025

last modify timeTue Aug 19 19:27:33 2025

last change status timeTue Aug 19 19:27:33 2025
     
*/

