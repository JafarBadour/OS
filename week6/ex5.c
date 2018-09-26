
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <stdlib.h>
#include <signal.h>


void sigFunc(int para);

int main() {
    pid_t cpid;

    cpid = fork();

    if (cpid == -1) {
        perror("fork error");
        exit(1);
    }

    if (cpid == 0) {
        while (1) {
            printf("I'm alive!");
            sleep(1);
        }
    } else {
        sleep(10);
        if (signal(SIGTERM, sigFunc) == SIG_ERR)
            printf("\nNO SIGKILL\n");
    }

    return 0;
}
void sigFunc(int para) {
    if (para == SIGTERM)
        printf("SIGTERM!\n");
}
