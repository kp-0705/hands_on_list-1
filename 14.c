/*
========================================================================================================================================================================================
Name : 14.c
Author : Kartavyakumar Patel
Description : 14 Write a program to find the type of a file.
	      a. Input should be taken from command line.
	      b. program should be able to identify any type of a file. 

Date : 20th Aug, 2025
========================================================================================================================================================================================

*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
	struct stat fs;
	if(argc!=2)
	{
	 fprintf(stderr,":: %s<filename>",argv[0]);
         exit(1);	 
	}

	if(stat(argv[1],&fs)==-1)
	{
	perror("stat using:: ");
        exit(1);	
	}
	if(S_ISREG(fs.st_mode))
	printf("%s is regular file\n",argv[1]);	
        
	else if(S_ISDIR(fs.st_mode))
	printf("%s is Directory\n",argv[1]);	

	else if(S_ISCHR(fs.st_mode))
	printf("%s is character Device\n",argv[1]);	

	else if(S_ISBLK(fs.st_mode))
	printf("%s is Block device\n",argv[1]);	

	else if(S_ISFIFO(fs.st_mode))
	printf("%s is FIFO FILE\n",argv[1]);	

	else if(S_ISLNK(fs.st_mode))
	printf("%s is Symbolic link\n",argv[1]);	

	else if(S_ISSOCK(fs.st_mode))
	printf("%s is socket\n",argv[1]);	

	else
	printf("%s is unknow file type\n",argv[1]);	
  
	return 0;
}



/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out Demo3.txt
Demo3.txt is regular file

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ cc 14.c
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out myfifo2
myfifo2 is FIFO FILE

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ cc 14.c
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out 1s.c
1s.c is regular file

  
*/
