#include <stdio.h>
#include <stdlib.h>

int main()
{   int n = 11;
    int pid = fork();
    if (!pid)
        printf("Hello from child [%d - %d]\n", pid, n);
     else if (pid > 0)
        printf("Hello from parent [%d - %d]\n", pid, n);
    else
        return 1;
    return 0;
}
