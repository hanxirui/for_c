#include"apue.h"
#include<sys/wait.h>
//信号捕捉方法
static void sig_int(int);
int main_8(void) {
	char buf[MAXLINE];
	pid_t pid;
	int status;

	if (signal(SIGINT, sig_int) == SIG_ERR )
		err_sys("signal error");

	printf("%% ");
	while (fgets(buf, MAXLINE, stdin) != NULL ) {
//		因为fgets返回到每一行都以换行符终止，后随一个null字节，故用标准c函数strlen计算此
//		字符串到长度，然后用一个null自己替换换行符。这样做是因为execlp函数要求参数以null而不是以换行符结束。
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = 0;

//		调用fork创建一个新进程。新进程是调用进程到复制品，我们称调用进程为父进程，新创建到进程为子进程。
//		fork向父进程返回新子进程到进程ID，对子进程则返回0.
//		因为fork创建一新进程，所以说它被调用一次，但返回两次（分别在父进程及子进程中。
		if ((pid = fork()) < 0) {
			err_sys("fork error");
		} else if (pid == 0) {
			execlp(buf, buf, (char *) 0);
			err_ret("couldn't execute:%s", buf);
			exit(127);

		}
		if (pid > 0) {
			printf("the childen pid is %d", pid);
		}

		if ((pid = waitpid(pid, &status, 0)) < 0)
			err_sys("waitpid error");

		printf("%% ");

	}
	exit(0);
}
void sig_int(int signo) {
	printf("interrupt\n%%");
}
