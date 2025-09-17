/*
========================================================================================================================================================================================
Name : 7.c
Author : Kartavyakumar Patel
Description : 7. Write a program to copy file1 into file2 ($cp file1 file2). 

Date :16th Aug, 2025
========================================================================================================================================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
  int file_des1,file_des2;
  char buf[1024];
  int read_data;

  file_des1=open("source_file.txt",O_RDONLY);
  if(file_des1 ==-1)
    { perror("Source OPEN ERROR: ");
      exit(1);
    }
  file_des2=open("destination_file.txt",O_WRONLY |O_CREAT|O_TRUNC,0644);
  if(file_des2==-1)
    {
     perror("Destination OPEN ERROR: ");
     exit(1);
    }

  while((read_data=read(file_des1,buf,1024))>0)
  {
   if(write(file_des2,buf,read_data)!=read_data)
   {
    	perror("write Problem:: ");
    	close(file_des1);
   	close(file_des2);
	exit(1);   
   }	
     
  }
  if(read_data<0)
	  perror("read problem:: ");
   close(file_des1);
   close(file_des2);
   return 0;
}

/*
 Output:
  
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out
source_file.txt

hello my dear friend....
nice to meet you....
see you soon...

destination_file.txt

hello my dear friend....
nice to meet you....
see you soon...

*/
