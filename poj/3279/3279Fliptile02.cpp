#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXN 20
int a[MAXN][MAXN],b[MAXN][MAXN],ans[MAXN][MAXN];
int n,m;
int check(int s)
{
    int i,j;
    for(i=0; i<m; i++)
        if(s&(1<<i))
        {
            ans[0][i]=1;
            b[0][i]^=1;
            if(1<n) b[1][i]^=1;
            if(i-1>=0) b[0][i-1]^=1;
            if(i+1<m) b[0][i+1]^=1;
        }

    for(i=1; i<n; i++)
        for(j=0; j<m; j++)
            if(b[i-1][j])
            {
                ans[i][j]=1;
                b[i][j]^=1;
                b[i-1][j]^=1;
                if(i+1<n) b[i+1][j]^=1;
                if(j-1>=0)b[i][j-1]^=1;
                if(j+1<m) b[i][j+1]^=1;
            }
    for(i=0;i<m;i++)
    if(b[n-1][i]) return 0;
    return 1;
}
void print()
{
    int i,j;
    for(i=0; i<n; i++)
    {

        for(j=0; j<m-1; j++)
            printf("%d ",ans[i][j]);
        printf("%d\n",ans[i][j]);
    }
}
int main(void)
{
    int i,j,flag;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            scanf("%d",&a[i][j]);
    flag=0;
    for(i=0; i<(1<<m); i++)
    {
        memcpy(b,a,sizeof(a));
         memset(ans,0,sizeof(ans));
        if(check(i))
        {
            flag=1;
            print();
            break;
        }
    }
    if(!flag)
        printf("IMPOSSIBLE\n");
    }
    return 0;
}
