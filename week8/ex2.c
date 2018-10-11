#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define _length 10*1024*1024

int main(){

  char *qr;
  for (int i=0; i<10; i++){
    qr = calloc(_length*sizeof(char));
    sleep(1);
  }

  return 0;
}
