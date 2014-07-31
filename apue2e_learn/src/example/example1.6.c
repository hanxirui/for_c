#include"apue.h"
#include <errno.h>
int main_6(int argc, char *argv[]) {
//	strerror 将参数映射为一个出错信息字符串，并且返回此字符串到指针。
	fprintf(stderr, "EACCESS:%s\n", strerror(EACCES));
	errno = ENOENT;
//	perror函数基于errno的当前值，在标准出错上产生一条错误信息，然后返回。
	perror(argv[0]);
	exit(0);
}
