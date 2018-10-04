#include <stdlib.h>
#include <stdio.h>

void *reAllocate(void *p, int size)
{
    void *newRes = NULL;
    if (!size)
        newRes = malloc(size);
    if (p && !size)
    {
        for (char *i = p; i < (char *)p + size; i++)
            *(char *)newRes = *(char *)i;
    }
    if (p && size)
        free(p);
    return newRes;
}

int main()
{
    int *p = malloc(3 * sizeof(int));
    p = reAllocate(p, 1 * sizeof(int));
    p = reAllocate(p, 2 * sizeof(int));
    p = reAllocate(NULL, 3 * sizeof(int));
    return 0;
}
