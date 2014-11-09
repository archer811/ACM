#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int a[30];
int vis[30][11][11][2];
int dfs(int pos,int status,int limit,int pre)
{
    if(pos==-1)return 1;
    if(vis[pos][pre][status][limit])return vis[pos][pre][status][limit];
    int end = limit?a[pos]:9;
    int sum=0;
    for(int i=0;i<=end;i++)
    {
        if(i==4)continue;
        if(status==6&&i==2)continue;
        sum += dfs(pos-1,i,limit&&(i==end),status);
    }
    return vis[pos][pre][status][limit]=sum;
}
int f(int n)
{
    int i,j=0;
    while(n)
    {
        a[j++]=n%10;
        n/=10;
    }
    memset(vis,0,sizeof(vis));
    dfs(j-1,0,1,0);
}
int main()
{
    int i,j;
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)break;
        printf("%d\n",f(m)-f(n-1));
    }
}
