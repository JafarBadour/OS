#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 1<<8
char inputFile[MAX_LEN];
int main() {

	while(1) {
		printf(" > ");
		fgets(inputFile, MAX_LEN, stdin);
		char *bb = strchr(inputFile, '&');
		if (bb) {
				*bb = '\0';
				int pid = fork();
				if (!pid) {
					system(inputFile);
					printf("\n[%d] finished\n", getpid());
				}
		} else {
			system(inputFile);
		}
	}

	return 0;
}
