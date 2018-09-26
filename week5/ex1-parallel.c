#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define CNT 3

int ThId[CNT];

void *Marhaba(int i) {
  printf("hi from thread %d - this thread was created in iteration %d !\n", (int) pthread_self(), i);
  pthread_exit(NULL);
}

void parallel(){
  int result, i;
  for (i = 0; i < CNT; i++) {
    result = pthread_create(&ThId[i], NULL, Marhaba, i);
    if (result) {
      printf("we have error with code %d \n", result);
      exit(1);
    }
    printf("our thread %d , created a new one with id %d after %d iterations \n", (int) pthread_self(), (int) ThId[i], i);
  }
  pthread_exit(NULL);
}

int main(){
	parallel();
}