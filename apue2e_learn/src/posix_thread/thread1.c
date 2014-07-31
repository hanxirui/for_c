#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
void *thread_sayhi(void *arg) {
	int i;
	for (i = 0; i < 20; i++) {
		printf("Thread says hi!\n");
		sleep(1);
	}
	return NULL ;
}
int thread1(void) {
	pthread_t mythread;

	if (pthread_create(&mythread, NULL, thread_sayhi, NULL )) {
		printf("error creating thread.");
		abort();
	}
	if (pthread_join(mythread, NULL )) {
		printf("error joining thread.");
		abort();
	}
	exit(0);
}
