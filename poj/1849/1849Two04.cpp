#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 100005;
int n,s;
int head[maxn];
int d[maxn][3];
const int inf = 0x3fffffff;
struct array
{
    int to,next,w;
} edge[maxn*2];
int e;
void add(int u,int v,int w)
{
    edge[e].to=v;
    edge[e].w=w;
    edge[e].next=head[u];
    head[u]=e++;
}
void dfs(int u,int fa)
{
    int i,j,k;
    int tmp[3];
    int g[]={2,1,2};
    for(i=head[u]; i!=-1; i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa)continue;
        dfs(v,u);
        for(k=0;k<=2;k++)
            tmp[k]=d[u][k],d[u][k]=inf;
        for(k=2;k>=0;k--)
        {
            for(j=0;j<=k;j++)
            {
                d[u][k]=min(d[u][k],d[v][k-j]+tmp[j]+edge[i].w*g[k-j]);
            }
        }
    }
}
int main()
{
    int i,j,k,a,b,c;
    while(scanf("%d%d",&n,&s)!=EOF)
    {
        memset(d,0,sizeof(d));
        e=0;
        memset(head,-1,sizeof(head));
        for(i=0; i<n-1; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
            add(b,a,c);
        }
        dfs(s,-1);
        cout<<d[s][2]<<endl;
    }
}
