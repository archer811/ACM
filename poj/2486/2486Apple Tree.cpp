#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int n,k;
int v[1005];
int head[1005],e;
int d[1005][2][205];
struct array
{
    int to,next;
}edge[1005*2];
void add(int u,int v)
{
    edge[e].to=v;
    edge[e].next=head[u];
    head[u]=e++;
}
void dfs(int u,int fa)
{
    int i,j,t;
    bool flag =  false;

    for(i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa)continue;
        dfs(v,u);
        flag = true;
        for(t=k;t>=0;t--)
        {
            for(j=t;j>=0;j--)
            {
                d[u][0][t+2]=max(d[u][0][t+2],d[v][0][t-j]+d[u][0][j]);
                d[u][1][t+1]=max(d[u][1][t+1],d[v][1][t-j]+d[u][0][j]);
                d[u][1][t+2]=max(d[u][1][t+2],d[v][0][t-j]+d[u][1][j]);


            }
        }
    }
    if(flag==false)
    {
        for(i=0;i<=k;i++)
    d[u][1][i]=d[u][0][i]=v[u];
    }
}
int main()
{
    int i,j,a,b;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%d",&v[i]);
        e=0;
        memset(head,-1,sizeof(head));
        memset(d,0,sizeof(d));
        for(i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            add(a,b);
            add(b,a);
        }
        dfs(1,-1);
        printf("%d\n",d[1][1][k]);
    }
}
