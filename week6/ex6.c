
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <stdlib.h>
#include <signal.h>

int arrayFD[2], status;
int main() {
    pipe(arrayFD);
    pid_t cpid, ccpid, retrieve_id;
    pid_t tmp;

    cpid = fork();
    if (cpid == 0) {
    	printf("ID of first child :: %d\n", getpid());
    	sleep(10);
    	read(arrayFD[0], retrieve_id, sizeof(retrieve_id));
    	kill(retrieve_id, SIGSTOP);
    }

    if (ccpid == 0) {
    	sleep(10);
    	printf("ID of second child :: %d\n", getpid());
    } else {
    	write(arrayFD[1], tmp, sizeof(tmp)+1);
    	waitpid(ccpid, &status, 0);
    }
    close(arrayFD[0]);
    close(arrayFD[1]);
}

