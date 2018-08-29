
#include <stdio.h>
#include <memory.h>
char str[100];
void swap(char* p1, char* p2)
{
   char temp =*p1;
   *p1 = *p2;
   *p2 = temp;
}
int main() {

    scanf("%s",str);
    int n = strlen(str);
   for(int i=0;i<n/2;i++)
   {
      swap(&str[i],&str[n-1-i]);
   }
   printf("%s",str);
    return 0;
}