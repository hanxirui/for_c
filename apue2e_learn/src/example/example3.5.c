#include "apue.h"
#include <fcntl.h>
//void set_fl(int,int);
//对一个文件描述符打开一个或多个文件状态标志
//flags就是要设置的文件状态
int main(void){
	   int fp;
	   int val=0;
	   fp = open("DUMMY.txt",O_RDONLY);
	   printf("=========");
//	   if((val=fcntl(fp,F_GETFL,0))<0)
	   printf(val);
//       set_fl(fp,O_RDWR);
       //if((val=fcntl(fp,F_GETFL,0))<0)
       printf(val);
       printf(val);
}
//void set_fl(int fd,int flags)
//{
//  int val;
//if((val=fcntl(fd,F_GETFL,0))<0)
//	printf("fcntl F_GETFL error");
//
//  val |= flags;
//
//  if(fcntl(fd,F_SETFL,val)<0)
//	  printf("fcntl F_SETFL error");
//
//}
