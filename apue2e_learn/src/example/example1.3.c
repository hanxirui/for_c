//用标准IO将标准输入复制到标准输出
#include"apue.h"
int main_3(void)
{
  int c;
  while((c=getc(stdin))!=EOF)
	  if(putc(c,stdout)==EOF)
		  err_sys("output error");

  if(ferror(stdin))
	  err_sys("input error");

  exit(0);

}
