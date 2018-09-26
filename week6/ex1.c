#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

int D[2];
int main(){

    char bb[] = "Hello, World!\n";
    char out[sizeof(bb)/sizeof('a')];
    int err;
    err = pipe(D);
    assert(err >= 0);
    write(D[1], bb, sizeof(bb));
    read(D[0], out, sizeof(out));

    printf("out string is: %s\n", out);
    return 0;

}
