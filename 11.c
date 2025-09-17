/*
========================================================================================================================================================================================
Name : 11.c
Author : Kartavyakumar Patel
Description :   11. Write a program to open a file, duplicate the file descriptor and append the file with both the
		descriptors and check whether the file is updated properly or not.
		a. use dup
		b. use dup2
		c. use fcntl
             
Date :18th Aug, 2025
========================================================================================================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
  int file_des1,file_des2;
  char buf1[]="IN original file \n";
  char buf2[]="IN duplicate file\n";
  int method;
 
  printf("Choice the method you want to USE:: \n");
  printf("1.dup\n2.dup2\n3.fcntl\n");
  scanf("%d",&method);
  
  file_des1=open("Demo5.txt",O_WRONLY |O_CREAT |O_APPEND,0644);
  if(file_des1==-1)
  {
   perror("open_file");
   exit(1);   
  }
 switch(method)
 {
  case 1:
	  file_des2=dup(file_des1);
	  printf("using Dup::\n file_descriptor1=%d, file_descriptor2=%d\n",file_des1,file_des2);
 	 break;	  
  case 2:
	  file_des2=dup2(file_des1,15);
	  printf("using Dup2::\n file_descriptor1=%d, file_descriptor2=%d\n",file_des1,file_des2);
          break;
  case 3:
	  file_des2=fcntl(file_des1,F_DUPFD,10);
	  printf("using fcntl::\n file_descriptor1=%d, file_descriptor2=%d\n",file_des1,file_des2);
	 break;
  defual:
        printf("wrong your number for method::\n");
	close(file_des1);
	exit(0);
 }

 write(file_des1,buf1,sizeof(buf1)-1);
 write(file_des2,buf2,sizeof(buf2)-1);

 printf("SUCESSFULLY:::");
 close(file_des1);
 close(file_des2);
 return 0;
}
/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out
Choice the method you want to USE:: 
1.dup
2.dup2
3.fcntl
1
using Dup::
 file_descriptor1=3, file_descriptor2=4
SUCESSFULLY:::

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ cc 11.c
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out
Choice the method you want to USE:: 
1.dup
2.dup2
3.fcntl
2
using Dup2::
 file_descriptor1=3, file_descriptor2=15
SUCESSFULLY:::

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ cc 11.c
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out
Choice the method you want to USE:: 
1.dup
2.dup2
3.fcntl
3
using fcntl::
 file_descriptor1=3, file_descriptor2=10
SUCESSFULLY:::

Demo5.txt

IN original file
IN duplicate file
IN original file
IN duplicate file
IN original file
IN duplicate file

*/
