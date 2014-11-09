#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int sum[10][10];
int n,m;
int  t,ans,s;
void dfs(int num,int ss)
{
    int i,j;
    if(num==n+1)
    {
        if(ss<0)ss=-ss;
        if(ss<ans)ans=ss;
        return;
    }
    for(i=1;i<m;i++)
    {
        dfs(num+1,ss+sum[num][i]);
    }
}
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        s=0;
        for(i=1;i<=n;i++)
        {
            sum[i][0]=0;
            for(j=1;j<=m;j++)
            {
                scanf("%d",&sum[i][j]);
                sum[i][j]+=sum[i][j-1];
            }
        }
        scanf("%d",&t);
         for(i=1;i<=n;i++)
                       for(j=1;j<m;j++)
                               sum[i][j]=sum[i][m]-sum[i][j]-sum[i][j];
        ans=  0xffffff;
        dfs(1,0);
        printf(ans>t ? "You'd better buy another one!\n" : "%d\n",ans);
    }
}
