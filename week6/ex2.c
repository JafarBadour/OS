#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
int D[2];
int pipeError,forkError;

int main(){

    char bb[] = "Hello, World!\n";
    char out[sizeof(bb)/sizeof(bb[0])];


    pipeError = pipe(D);

    assert(pipeError >= 0);

    forkError = fork();
       assert(forkError!=-1);
        if(forkError != 0){
            close(D[0]);
            write(D[1], bb, sizeof(bb));
            exit(0);
        }
        else{
            close(D[1]);
            read(D[0], out, sizeof(out));
            printf("out string is: %s\n", out);
        }
        return 0;

    }


