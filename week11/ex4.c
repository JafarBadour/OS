#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int sfd, dfd;
	char *file1, *file2;
	size_t fsize;

	sfd = open("ex1.txt", O_RDONLY);
	fsize = lseek(sfd, 0, SEEK_END);

	file1 = mmap(NULL, fsize, PROT_READ, MAP_PRIVATE, sfd, 0);

	dfd = open("ex1.memcpy.txt", O_RDWR | O_CREAT, 0666);
	ftruncate(dfd, fsize);

	file2 = mmap(NULL, fsize, PROT_READ | PROT_WRITE, MAP_SHARED, dfd, 0);
	memcpy(file2, file1, fsize);

	munmap(file1, fsize);
	munmap(file2, fsize);

	close(sfd); close(dfd);
	return 0;
}
