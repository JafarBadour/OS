#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int fd, f, option, file_has;
    ssize_t rd, wr_1, wr_2;
    char buf[BUFFER_SIZE + 1];

    if (argc > 1)
        file_has = 1;
    if (file_has)
    {
        f = O_WRONLY | O_CREAT | O_TRUNC;
        while ((option = getopt(argc, argv, "a")) != -1)
        {
            if (option == 'a')
                f = O_WRONLY | O_APPEND | O_CREAT;
            else
            {
                fprintf(stderr, "%s file [-a]\n", argv[0]);
                exit(EXIT_FAILURE);
            }
        }
        fd = open(argv[argc - 1], f, 0644);

        if (fd == -1)
        {
            perror("open");
            return EXIT_FAILURE;
        }
    }

    while ((rd = read(STDIN_FILENO, buf, BUFFER_SIZE)) != 0)
    {
        if (rd == -1)
        {
            if (errno == EINTR)
                continue;
            perror("read");
            break;
        }
        wr_1 = write(STDOUT_FILENO, buf, rd);
        if (wr_1 == -1)
        {
            perror("write");
            exit(EXIT_FAILURE);
        }
        if (file_has)
        {
            wr_2 = write(fd, buf, rd);
            if (wr_2 == -1)
            {
                perror("write");
                exit(EXIT_FAILURE);
            }
        }
    }

    return 0;
}