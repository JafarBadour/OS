#include<signal.h>
#include<unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
void sigFunc(int para) {
    if (para == SIGINT)
        printf("Received the SIGINT Signal!");
    return;
}
int main() {
    signal(SIGINT, sigFunc);
    while (1) {
        sleep(2);
    }
}

