#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int myglobal;
/**说明线程和创建它的线程之间没有父子关系*/
void *thread_function(void *arg) {
	int i, j;
	for (i = 0; i < 20; i++) {
		j = myglobal;
		j = j + 1;
		printf(".");
		fflush(stdout);
		sleep(1);
		myglobal = j;
	}
	return NULL ;
}
int thread2(void) {
	pthread_t mythread;
	int i;
	if (pthread_create(&mythread, NULL, thread_function, NULL )) {
		printf("error creating thread.");
		abort();
	}
	for (i = 0; i < 20; i++) {
		myglobal = myglobal + 1;
		printf("o");
		fflush(stdout);
		sleep(1);
	}
	if (pthread_join(mythread, NULL )) {
		printf("error joining thread.");
		abort();
	}
	printf("\nmyglobal equals %d\n", myglobal);
	exit(0);
}
