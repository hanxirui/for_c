#include "apue.h"
#include <dirent.h>
#include "error.c"
int main_1(int argc,char *argv[])
{
//	文件夹的数据类型结构，真实结构对最终用户不可见
    DIR *dp;
    struct dirent *dirp;
//    如果参数个数不是2个
    if(argc!=2)
    	err_quit("usage:ls directory_name");
//    文件无法打开,opendir返回一个指向DIR结构到指针
    if((dp=opendir(argv[1]))==NULL)
    	err_sys("can't open %s",argv[1]);
//读取文件夹
    while((dirp=readdir(dp))!=NULL)
    	printf("%s\n",dirp->d_name);

    	closedir(dp);
    exit(0);
}
