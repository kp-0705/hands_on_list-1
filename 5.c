/*
========================================================================================================================================================================================
Name : 5.c
Author : Kartavyakumar Patel
Description : 5. Write a program to create five new files with infinite loop. Execute the program in the background
              and check the file descriptor table at /proc/pid/fd. 

Date :14th Aug, 2025
========================================================================================================================================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
 int file_des[5];
 char f_name[]="file0.txt";

 for(int i=0;i<5;i++)
  {
    f_name[4]='1'+i;
    file_des[i]=creat(f_name,0644);
    if(file_des[i]==-1)
    {
	perror("Fail Creat: ");
        exit(1);	
    } 
   printf("Sucssessfuly %s Done: File_descriptor is = %d\n",f_name,file_des[i]);   
  }
  
 while(1){sleep(2);}
 return 0;
}
/*
 Output:
     
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out &
[2] 32794
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ 
Sucssessfuly file1.txt Done:File_descriptor is = 3
Sucssessfuly file2.txt Done: File_descriptor is = 4
Sucssessfuly file3.txt Done: File_descriptor is = 5
Sucssessfuly file4.txt Done: File_descriptor is = 6
Sucssessfuly file5.txt Done: File_descriptor is = 7

dell@dell-Inspiron-3593:~$ cd /proc/32794/fd
dell@dell-Inspiron-3593:/proc/32794/fd$ ls
0  1  2  3  4  5  6  7

dell@dell-Inspiron-3593:/proc/32794/fd$ ls -l
total 0
lrwx------ 1 dell dell 64 Aug 19 16:42 0 -> /dev/pts/0
lrwx------ 1 dell dell 64 Aug 19 16:42 1 -> /dev/pts/0
lrwx------ 1 dell dell 64 Aug 19 16:42 2 -> /dev/pts/0
l-wx------ 1 dell dell 64 Aug 19 16:42 3 -> /home/dell/Desktop/MT2025059/Hands-on_List1/file1.txt
l-wx------ 1 dell dell 64 Aug 19 16:42 4 -> /home/dell/Desktop/MT2025059/Hands-on_List1/file2.txt
l-wx------ 1 dell dell 64 Aug 19 16:42 5 -> /home/dell/Desktop/MT2025059/Hands-on_List1/file3.txt
l-wx------ 1 dell dell 64 Aug 19 16:42 6 -> /home/dell/Desktop/MT2025059/Hands-on_List1/file4.txt
l-wx------ 1 dell dell 64 Aug 19 16:42 7 -> /home/dell/Desktop/MT2025059/Hands-on_List1/file5.txt
 

*/
