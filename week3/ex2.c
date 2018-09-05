#include <stdio.h>
void swap(int* p1, int* p2)
{
   int temp =*p1;
   *p1 = *p2;
   *p2 = temp;
}
void bubblesort(int ar[], int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(ar[i]>ar[j])
            {
                swap(&ar[i],&ar[j]);
            }
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int * ar =(int *)malloc((n+1) * sizeof(int));
    for(int i=1;i<=n;i++)
        scanf("%d",ar+i);
    bubblesort(ar,n);
    for(int i=1;i<=n;i++)
       printf("%d ",ar[i]);

 return 0;
}
