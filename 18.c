/*
========================================================================================================================================================================================
Name : 18.c
Author : Kartavyakumar Patel
Description : 18. Write a program to perform Record locking.
		a. Implement write lock
		b. Implement read lock
		Create three records in a file. Whenever you access a particular record, first lock it then modify/access to avoid race condition.

Date : 21th Aug, 2025
========================================================================================================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

struct ticket_num
{
 int tik_id;
 int tik_num; 
};



int main()
{
 int file_des,method,rec_no;
 struct ticket_num t;
 struct flock lk;

 file_des=open("ticket_show18.txt",O_RDWR|O_CREAT,0644);
 if(file_des<0)
 {
  perror("OPEN PROBLEM:");
  exit(1);  
 }

 for(int i=1;i<=3;i++)
 {
   t.tik_id=i;
   t.tik_num=1200+i;
   write(file_des,&t,sizeof(t));
 }

while(1)
{
 printf("\n1.READ LOCK\n2.WRITE LOCK\n3.CLOSE:\nWHICH METHOD USE: ");
 scanf("%d",&method);

 if(method==3)
	break;
 printf("enter record num(1-3)\n");
 scanf("%d",&rec_no);
 rec_no--;
 
lk.l_whence=SEEK_SET;
lk.l_start=rec_no*sizeof(struct ticket_num);
lk.l_len=sizeof(struct ticket_num);


 if(method==1)
 {
  lk.l_type=F_RDLCK;
  fcntl(file_des,F_SETLK,&lk);
  lseek(file_des,rec_no*sizeof(t),SEEK_SET);
  read(file_des,&t,sizeof(t));
  printf("ID : %d, TICKET : %d\n",t.tik_id,t.tik_num);
  lk.l_type=F_UNLCK;
  fcntl(file_des,F_SETLK,&lk);
 }

 else if(method==2)
 {
  lk.l_type=F_WRLCK;
  fcntl(file_des,F_SETLKW,&lk);
  lseek(file_des,rec_no*sizeof(t),SEEK_SET);
  read(file_des,&t,sizeof(t));
  t.tik_num++;
  lseek(file_des,rec_no*sizeof(t),SEEK_SET);
  write(file_des,&t,sizeof(t));
  printf("UPDATE ID : %d,UPDATE TICKET : %d\n",t.tik_id,t.tik_num);
  lk.l_type=F_UNLCK;
  fcntl(file_des,F_SETLK,&lk);
 }
 else
 {
  printf("INVALID METHOD TO CHOICE//\n");	 
 }
}
close(file_des);
return 0;

}

/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List1$ ./a.out

1.READ LOCK
2.WRITE LOCK
3.CLOSE:
WHICH METHOD USE: 1
enter record num(1-3)
1
ID : 1, TICKET : 1201

1.READ LOCK
2.WRITE LOCK
3.CLOSE:
WHICH METHOD USE: 1
enter record num(1-3)
2
ID : 2, TICKET : 1202

1.READ LOCK
2.WRITE LOCK
3.CLOSE:
WHICH METHOD USE: 2
enter record num(1-3)
1
UPDATE ID : 1,UPDATE TICKET : 1202

1.READ LOCK
2.WRITE LOCK
3.CLOSE:
WHICH METHOD USE: 2
enter record num(1-3)
1
UPDATE ID : 1,UPDATE TICKET : 1203

1.READ LOCK
2.WRITE LOCK
3.CLOSE:
WHICH METHOD USE: 2
enter record num(1-3)
2
UPDATE ID : 2,UPDATE TICKET : 1203

1.READ LOCK
2.WRITE LOCK
3.CLOSE:
WHICH METHOD USE: 1
enter record num(1-3)
2
ID : 2, TICKET : 1203

1.READ LOCK
2.WRITE LOCK
3.CLOSE:
WHICH METHOD USE: 3
  
  
*/
