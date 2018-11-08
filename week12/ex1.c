#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define string_size 20

int main()
{
    int f = open("/dev/random", O_RDONLY);
    if (f < 0)
    {
        return -1;
    }
    else
    {
        char array[string_size + 1];
        int res = read(f, array, string_size);
        if (res < 0)
        {
            return -1;
        }
        else
        {
            printf("%s\n", array);
        }
    }
    close(f);
    return 0;
}
