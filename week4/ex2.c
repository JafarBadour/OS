#include <stdio.h>
#include <stdlib.h>
int main()
{
    for(int i = 0; i < 3; i++)
    {
        fork();
        sleep(1);
    }
    sleep(5);
    return 0;
}
