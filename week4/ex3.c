#include <stdlib.h>
#include <stdio.h>
char shell[99];
void zbr()
{

        printf(">");
        scanf("%s", shell);
        system(shell);
}
int main(int argc, char const *argv[])
{
    while (1)
    {
        zbr();
    }
    return 0;
}
