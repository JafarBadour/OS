#include <stdio.h>
#include <stdbool.h>
#define ll long long
#define n 3
#define m 5
int C[m][n];
int R[m][n];
int E[n];
int A[n];
bool solve()
{
    bool flag = true;
    bool fl = false;
    for(int j = 0; j < m; j++)
    {
        bool flag = true;
        bool lineflagoes = true;
        for(int k = 0; k < n; k++)
        {
            if(R[j][k] != 0)
                lineflagoes = false;

            if(R[j][k] > A[k])
            {
                flag = false;
                break;
            }
        }
        if(!lineflagoes)
            flag = false;
        if(flag && !lineflagoes)
        {
            fl = true;
            for(int k = 0; k < n; k++)
            {
                R[j][k] = 0;
                A[k] +=C[j][k];
                C[j][k] = 0;
            }
        }
    }

    if(!fl)
    {
        if(flag)
            printf("no deadlock\n");
        else
        {
            printf("deadlock:\n");
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(R[i][j] != 0 )
                    {
                        printf("%d ", (i+1));
                        break;
                    }
                }
            }
            puts("");
        }
        exit(0);
    }
    if(flag^1)
        solve();
}
int main()
{


    freopen("input_.txt","r",stdin);
    for(int i = 0; i < n; i++)
        scanf("%d",&E[i]);
    for(int i = 0; i < n; i++)
        scanf("%d",&A[i]);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &C[i][j]);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &R[i][j]);
    solve();
}
