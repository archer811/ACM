#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int n,m;
int v[1005];
#define vm 300
#define em 300000
const int inf = 0x3fffffff;
struct E
{
    int to,next,cap;
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
    edge[e].next=head[u];
    edge[e].to=v;
    head[u]=e++;
    edge[e].cap=0;
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
int val[1005];
int main()
{
    int i,j,k,g;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(v,0,sizeof(v));
        init();
        for(i=1;i<=n;i++)
            scanf("%d",&val[i]);
        for(i=1;i<=m;i++)
        {
            scanf("%d",&k);
            for(j=1;j<=k;j++)
            {
                scanf("%d",&g);
                if(v[g]==0)addedge(0,i,val[g]);
                else addedge(v[g],i,inf);
                v[g]=i;
            }
            scanf("%d",&k);
            addedge(i,m+1,k);
        }
        cout<<sap(0,m+1,m+2)<<endl;
        //for(i=1;i<=n;i++)
    }
}
