#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFF_SIZE 5

int main() {
	char buff[BUFF_SIZE];

	if (setvbuf(stdout, buff, _IOLBF, sizeof(buff))) {
		perror("failed to change buff");
		return EXIT_FAILURE;
	}
	printf("H"); sleep(1);
	printf("e"); sleep(1);
	printf("l"); sleep(1);
	printf("l"); sleep(1);
	printf("o"); sleep(1);

	putchar('\n');
	return 0;
}
