#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int n,m;
#define vm 5005
#define em 500005
#define ll __int64
const ll inf = (ll)1<<30;
struct E
{
    int to,next;
    ll cap;
}edge[em];
int head[vm],gap[vm],dist[vm],cur[vm],pre[vm];
int e;
void init()
{
    e=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,ll c)
{
    edge[e].cap=c;
    edge[e].next=head[u];
    edge[e].to=v;
    head[u]=e++;
    edge[e].cap=0;
    edge[e].next=head[v];
    edge[e].to=u;
    head[v]=e++;
}
ll sap(int s,int t,int n)
{
    memset(dist,0,sizeof(dist));
    memset(gap,0,sizeof(gap));
    memcpy(cur,head,sizeof(head));
    ll res = 0;
    int u=pre[s]=s;
    ll aug = inf;
    gap[0]=n;
    while(dist[s]< n)
    {
        loop:
        for(int &i=cur[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            if(edge[i].cap&&dist[u]==dist[v]+1)
            {
                aug=min(aug,edge[i].cap);
                pre[v]=u;
                u=v;
                if(v==t)
                {
                    res+=aug;
                    for(u=pre[u];v!=s;v=u,u=pre[u])
                    {
                        edge[cur[u]].cap-=aug;
                        edge[cur[u]^1].cap+=aug;
                    }
                    aug=inf;
                }
                goto loop;
            }
        }
        int mindist = n;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            if(edge[i].cap&&mindist>dist[v])
            {
                cur[u]=i;
                mindist=dist[v];
            }
        }
        if((--gap[dist[u]])==0)
          break;
        dist[u]=mindist+1;
        gap[dist[u]]++;
        u=pre[u];
    }
    return res;
}
int vis[5005];
void dfs(int s)
{
    int i,j;
    vis[s]=1;
    for(i=head[s];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(vis[v]==0&&edge[i].cap)
            dfs(v);
    }
}
int main()
{
    int i,j,k,a,b;
    ll g;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        ll sum=0;
        for(i=1;i<=n;i++)
        {
            scanf("%I64d",&g);
            if(g>0)
                addedge(0,i,g),sum+=g;
            else
                addedge(i,n+1,-g);
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            addedge(a,b,inf);
        }
        g = sap(0,n+1,n+2);
        memset(vis,0,sizeof(vis));
        dfs(0);
        int num=0;
        for(i=1;i<=n;i++)
            num+=vis[i];
        printf("%d %I64d\n",num,sum-g);
    }
}
