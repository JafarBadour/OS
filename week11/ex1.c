#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main() {
	int myFile = open("ex1.txt", O_RDWR);
        if (myFile < 0) printf("reading error\n");

        struct stat s = {};
        if (fstat(myFile, &s)) printf("fstat error\n");

        off_t size = s.st_size;
        char *addr;
        addr = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, myFile, 0);
        if (addr == MAP_FAILED) printf("mmap error\n");	

	strncpy(addr, "This is a nice day", 18);
        return 0;
} 
