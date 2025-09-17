/*
========================================================================================================================================================================================
Name : 27.c
Author : Kartavyakumar Patel
Description : 27. Write a program to execute ls -Rl by the following system calls
		a. execl
		b. execlp
		c. execle
		d. execv
		e. execvp

Date : 30th Aug, 2025
========================================================================================================================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
 int choice;
 printf("ENTER NUM FOR YOUR FAVORITE SYSTEM CALL\n");
 printf("1.EXECL\n2.EXECLP\n3.EXECLE\n4.EXECV\n5.EXECVP\n");
 scanf("%d",&choice);
switch(choice) 
{
	case 1:	
 printf("USING EXECL\n\n");	
 if(execl("/bin/ls","ls","-Rl",(char *)NULL)==-1)
 {
  perror("execl ERROR:: ");	 
 }
 break;
	case 2:
 printf("USING EXECLP\n\n");	
 if(execlp("ls","ls","-Rl",(char *)NULL)==-1)
 {
  perror("execlp ERROR:: ");	 
 }
 break;

	case 3:
 printf("USING EXECLE\n\n");	
 if(execle("/bin/ls","ls","-Rl",(char *)NULL,(char *)NULL)==-1)
 {
  perror("execle ERROR:: ");	 
 }

break;
	case 4:
 printf("USING EXECV\n\n");
char *argv[]={"ls","-Rl",NULL}; 
 if(execv("/bin/ls",argv)==-1)
 {
  perror("execv ERROR:: ");	 
 }
break;
	case 5:
 printf("USING EXECVP\n\n");
 if(execvp("ls",argv)==-1)
 {
  perror("execv ERROR:: ");	 
 }
 break;
	default:
 {
  printf("INvalid number:\n");	 
 }

 }
return 0;
}


/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out
ENTER NUM FOR YOUR FAVORITE SYSTEM CALL
1.EXECL
2.EXECLP
3.EXECLE
4.EXECV
5.EXECVP
3
USING EXECLE

.:
total 380
-rw-rw-r-- 1 dell dell  1484 Aug 19 19:46 10.c
-rw-rw-r-- 1 dell dell  2714 Aug 19 19:52 11.c
-rw-rw-r-- 1 dell dell  1401 Aug 19 19:55 12.c
-rw-rw-r-- 1 dell dell  1308 Aug 20 11:40 13.c
-rw-rw-r-- 1 dell dell  1943 Aug 20 12:07 14.c
-rw-rw-r-- 1 dell dell  4431 Aug 20 12:24 15.c
-rwxrwxr-x 1 dell dell 16352 Aug 20 16:20 16
-rw-rw-r-- 1 dell dell  1838 Aug 20 15:04 16.c
-rwxrwxr-x 1 dell dell 16352 Aug 20 16:57 17booking
-rw-rw-r-- 1 dell dell  2596 Aug 20 16:47 17booking.c
-rwxrwxr-x 1 dell dell 16224 Aug 20 16:57 17init
-rw-rw-r-- 1 dell dell  2171 Aug 20 16:57 17init.c
-rw-rw-r-- 1 dell dell  2942 Aug 21 00:19 18.c
-rw-rw-r-- 1 dell dell   577 Aug 22 22:56 19.c
-rw-rw-r-- 1 dell dell   945 Aug 19 16:13 1f.c
-rw-rw-r-- 1 dell dell   902 Aug 19 16:08 1h.c
-rw-rw-r-- 1 dell dell   902 Aug 19 16:10 1s.c
-rwxrwxr-x 1 dell dell 15960 Aug 13 14:00 2
-rw-rw-r-- 1 dell dell  2338 Aug 19 16:26 2.c
-rw-rw-r-- 1 dell dell   568 Aug 22 22:57 20.c
-rw-rw-r-- 1 dell dell   929 Aug 22 23:28 21.c
-rw-rw-r-- 1 dell dell  1308 Aug 22 23:45 22.c
-rw-rw-r-- 1 dell dell  1176 Aug 31 15:50 23.c
-rw-rw-r-- 1 dell dell  1432 Aug 31 15:51 24.c
-rw-rw-r-- 1 dell dell  1837 Aug 31 16:11 25.c
-rwxrwxr-x 1 dell dell 16000 Aug 31 23:34 26a
-rw-rw-r-- 1 dell dell  1258 Aug 31 23:41 26a.c
-rwxrwxr-x 1 dell dell 16000 Aug 31 23:34 26b
-rw-rw-r-- 1 dell dell  1272 Aug 31 23:41 26b.c
-rw-rw-r-- 1 dell dell  1572 Sep  1 17:43 27.c
-rw-rw-r-- 1 dell dell   545 Aug 30 21:31 28.c
-rw-rw-r-- 1 dell dell   579 Aug 30 21:32 29.c
-rwxrwxr-x 1 dell dell 16168 Aug 13 14:59 3
-rw-rw-r-- 1 dell dell   967 Aug 19 16:32 3.c
-rw-rw-r-- 1 dell dell   558 Aug 31 11:56 30.c
-rw-rw-r-- 1 dell dell  1077 Aug 19 16:37 4.c
-rwxrwxr-x 1 dell dell 16128 Aug 15 11:56 5
-rw-rw-r-- 1 dell dell  2293 Aug 19 16:45 5.c
-rw-rw-r-- 1 dell dell   943 Aug 19 16:50 6.c
-rw-rw-r-- 1 dell dell  1525 Aug 19 19:23 7.c
-rwxrwxr-x 1 dell dell 16256 Aug 16 18:12 8
-rw-rw-r-- 1 dell dell  1673 Aug 19 19:29 8.c
-rw-rw-r-- 1 dell dell  1771 Aug 19 19:33 9.c
-rw-r--r-- 1 dell dell     0 Aug 17 12:42 Demo12.txt
-rw-rw-r-- 1 dell dell     0 Aug 20 14:36 Demo16.txt
-rw-r--r-- 1 dell dell    67 Aug 22 23:44 Demo22.txt
-rw-r--r-- 1 dell dell   201 Aug 19 19:27 Demo3.txt
-rw-r--r-- 1 dell dell    30 Aug 19 19:36 Demo4.txt
-rw-r--r-- 1 dell dell   108 Aug 19 19:50 Demo5.txt
-rw-r--r-- 1 dell dell     4 Aug 20 16:59 Ticket_store.txt
-rwxrwxr-x 1 dell dell 16312 Sep  1 17:43 a.out
-rw-rw-r-- 1 dell dell    62 Aug 19 16:54 destination_file.txt
-rwxrwxr-x 1 dell dell 16048 Aug 10 14:47 fifo_link
-rw-r--r-- 1 dell dell     0 Aug 19 16:40 file1.txt
-rw-r--r-- 1 dell dell     0 Aug 19 16:40 file2.txt
-rw-r--r-- 1 dell dell     0 Aug 19 16:40 file3.txt
-rw-r--r-- 1 dell dell     0 Aug 19 16:40 file4.txt
-rw-r--r-- 1 dell dell     0 Aug 19 16:40 file5.txt
-rwxrwxr-x 1 dell dell 16048 Aug 10 14:35 hard_link
-rw-rw-r-- 3 dell dell     0 Aug 10 12:44 hardlink1
-rw-rw-r-- 3 dell dell     0 Aug 10 12:44 hardlink2
prw-rw-r-- 1 dell dell     0 Aug 10 12:45 myfifo
prw-rw-r-- 1 dell dell     0 Aug 19 16:12 myfifo2
-rw-rw-r-- 3 dell dell     0 Aug 10 12:44 shell_hard.text
-rw-rw-r-- 1 dell dell     0 Aug 10 12:42 shell_soft.text
-rwxrwxr-x 1 dell dell 16048 Aug 10 12:53 soft_link
lrwxrwxrwx 1 dell dell    15 Aug 10 12:43 softlink1 -> shell_soft.text
lrwxrwxrwx 1 dell dell    14 Aug 10 12:53 softlink2 -> shell_soft.txt
-rw-rw-r-- 1 dell dell    62 Aug 15 19:37 source_file.txt
-rw-r--r-- 1 dell dell    24 Aug 21 00:16 ticket_show18.txt

  
*/
