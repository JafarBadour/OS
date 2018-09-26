#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define MAXLIM 100


int *our_buffer;

int i = 0;

pthread_cond_t havespace = PTHREAD_COND_INITIALIZER;
pthread_cond_t stillhaveelemnt = PTHREAD_COND_INITIALIZER;
pthread_mutex_t vLock = PTHREAD_MUTEX_INITIALIZER;



void *con() {
    while (1) {
        pthread_mutex_lock(&vLock);
        if (i == -1)
            pthread_cond_wait(&stillhaveelemnt, &vLock);
        printf("consumer now id is : %d\n", i--);
        pthread_mutex_unlock(&vLock);
        pthread_cond_signal(&havespace);
    }
}
void *pro() {
    while (1) {
		pthread_mutex_lock(&vLock);
        if (i == MAXLIM)
            pthread_cond_wait(&havespace, &vLock);
        our_buffer[i++] = 1;
        printf("producer now id is :%d\n", i);
        pthread_mutex_unlock(&vLock);
        pthread_cond_signal(&stillhaveelemnt);
    }
}
int main() {
    pthread_t pid, cid;
    our_buffer = (int*) malloc(sizeof(int)*MAXLIM);
    pthread_create(&cid, NULL, con, NULL);
	pthread_create(&pid, NULL, pro, NULL);
	pthread_join(cid, NULL);
    pthread_join(pid, NULL);
    return 0;
}
