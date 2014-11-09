#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int n,m;
#define vm 505
#define em 300000
const int inf = 0x3fffffff;
struct E
{
    int to,next,cap,u;
}edge[em];
int head[vm],gap[vm],dist[vm],cur[vm],pre[vm];
int e;
void init()
{
    e=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int c)
{
    edge[e].cap=c;
    edge[e].u=u;
    edge[e].next=head[u];
    edge[e].to=v;
    head[u]=e++;
    edge[e].cap=0;
    edge[e].u=v;
    edge[e].next=head[v];
    edge[e].to=u;
    head[v]=e++;
}
int sap(int s,int t,int n)
{
    memset(dist,0,sizeof(dist));
    memset(gap,0,sizeof(gap));
    memcpy(cur,head,sizeof(head));
    int res = 0;
    int u=pre[s]=s;
    int aug = inf;
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
int vis1[505],vis2[505];
void dfs1(int u)
{
    vis1[u]=1;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(vis1[v]==0&&edge[i].cap)
            dfs1(v);
    }
}
void dfs2(int u)
{
    vis2[u]=1;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(vis2[v]==0&&edge[i^1].cap)
            dfs2(v);
    }
}
int main()
{
    int i,j,k,a,b,c;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            addedge(a,b,c);
        }
        sap(0,n-1,n);
        memset(vis1,0,sizeof(vis1));
        memset(vis2,0,sizeof(vis2));
        dfs1(0);
        dfs2(n-1);
        int ans=0;
        for(i=0;i<e;i+=2)
        {
            if(edge[i].cap==0&&vis1[edge[i].u]&&vis2[edge[i].to])
                ans++;
        }
        printf("%d\n",ans);
    }
}
