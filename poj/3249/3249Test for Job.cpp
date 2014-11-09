#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int n,m ;
const int N = 100100;
const int M = 1100000;
int head[N],tot;
#define ll __int64
struct array
{
    int to,next;
    ll value;
}edge[M];
const ll inf = ((ll)1)<<50;
ll v[N];
void addedge(int u,int v,ll va)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    edge[tot].value = va;
    head[u]=tot++;
}
int in[N],out[N];
int q[N*20];
ll dis[N];
int vis[N];
ll spfa()
{
    int i,j,k;
    k=0;
    q[k++]=0;
    for(i=0;i<=n+1;i++)
        vis[i]=0,dis[i]=inf;
    vis[0]=1;dis[0]=0;
    for(int g=0;g<k;g++)
    {
        int u = q[g];vis[u]=0;
        for(i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].to;
            if(dis[v]>dis[u]+edge[i].value)
            {
                dis[v]=dis[u]+edge[i].value;
                if(vis[v]==0)
                {
                    vis[v]=1;
                    q[k++]=v;
                }
            }
        }
    }
    return dis[n+1];
}
int main()
{
    int i,j,k,a,b;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(head,-1,sizeof(head));
        tot=0;
        for(i=1;i<=n;i++)
            scanf("%I64d",&v[i]),in[i]=out[i]=0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            addedge(a,b,-v[b]);
            in[b]++;out[a]++;
        }
        for(i=1;i<=n;i++)
        {
            if(in[i]==0)addedge(0,i,-v[i]);
            if(out[i]==0)addedge(i,n+1,0);
        }
        printf("%I64d\n",-spfa());
    }
}
