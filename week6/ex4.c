#include<signal.h>
#include<unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

void sigFunc(int para) {
    if (para == SIGUSR1)
        printf("SIGUSR1\n");
    else if (para == SIGKILL)
        printf("SIGKILL\n");
    else if (para == SIGSTOP)
        printf("SIGSTOP\n");
}

int main() {
    if (signal(SIGKILL, sigFunc) == SIG_ERR)
        puts("NO SIGKILL");
    if (signal(SIGSTOP, sigFunc) == SIG_ERR)
       puts("NO SIGSTOP");
    if (signal(SIGUSR1, sigFunc) == SIG_ERR)
        puts("NO SIGUSR1");
    while(1)
        sleep(1);
}

