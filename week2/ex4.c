
#include <stdio.h>
#include <memory.h>

void swap(int * p1, int * p2)
{
   int temp =*p1;
   *p1 = *p2;
   *p2 = temp;
}
int main() {
   int a,b;
   scanf("%d%d",&a,&b);
   swap(&a,&b);
   printf("%d %d",a,b);

    return 0;
}