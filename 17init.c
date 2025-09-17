/*
========================================================================================================================================================================================
Name : 17init.c
Author : Kartavyakumar Patel
Description : 17. Write a program to simulate online ticket reservation. Implement write lock..............
		Write a program to open a file, store a ticket number and exit. Write a separate program, to
	        open the file, implement write lock, read the ticket number, increment the number and print
		the new ticket number then close the file.

Date : 20th Aug, 2025
========================================================================================================================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
 int file_des;
 int tkt=1200;
 file_des=open("Ticket_store.txt",O_WRONLY | O_CREAT|O_TRUNC,0644);
 if(file_des<0)
 {
  perror("OPEN::");
  exit(1);  
 }
 if(write(file_des,&tkt,sizeof(tkt))<0)
 {
    perror("WRITE::");
    close(file_des);
    exit(1);  
 }

 printf("TICKET NUMBER INIT IS :: %d\n",tkt);
 close(file_des);
 return 0;

}


/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ gcc 17init.c -o 17init
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ gcc 17booking.c -o 17booking
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./17init
TICKET NUMBER INIT IS :: 1200

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./17booking
TICKET NUMBER ::1201

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./17booking
TICKET NUMBER ::1202

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./17booking
TICKET NUMBER ::1203

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./17booking
TICKET NUMBER ::1204

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./17booking
TICKET NUMBER ::1205

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./17booking
TICKET NUMBER ::1206

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./17booking
TICKET NUMBER ::1207
  
  
*/
