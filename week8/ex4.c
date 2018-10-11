#include <sys/resource.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define _length 10*(1<<20)

int main(){

  char *q;
  struct rusage r_usage;

  for (int i=0; i<10; i++){
    q = calloc(_length, sizeof(char));
    getrusage(RUSAGE_SELF, &r_usage);
    printf("%ld kb\n", r_usage.ru_maxrss / 1024);
    sleep(1);
  }

  return 0;
}
