#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int mn=2222;
const int mm=1000000;
const int oo=100000000;
int node, st, sd, edge;
int reach[mm], flow[mm], next[mm];
int head[mn], work[mn], dis[mn], que[mn];
int du[mn], dn[444][1111], id[444][1111];

inline void init(int _node, int _st, int _sd)
{
    node=_node, st=_st, sd=_sd;
    for(int i=0; i<node; i++)
        head[i]=-1, du[i]=0;
    edge=0;
}

inline void addedge(int u, int v, int c1, int c2)
{
    reach[edge]=v, flow[edge]=c1, next[edge]=head[u],head[u]=edge++;
    reach[edge]=u, flow[edge]=c2, next[edge]=head[v],head[v]=edge++;
}

bool bfs()
{
    int u, v, l=0, h=0;
    for(int i=0; i<node; i++) dis[i]=-1;
    que[l++]=st;
    dis[st]=0;
    while(l!=h)
    {
        u=que[h++];
        if(h==mn) h=0;
        for(int i=head[u]; i>=0; i=next[i])
        {
            v=reach[i];
            if(flow[i]&&dis[v]<0)
            {
                dis[v]=dis[u]+1;
                que[l++]=v;
                if(l==mn) l=0;
                if(v==sd) return true;
            }
        }
    }
    return false;
}

int dfs(int u, int exp)
{
    if(u==sd) return exp;
    for(int &i=work[u]; i>=0; i=next[i])
    {
        int v=reach[i], tp;
        if(flow[i]&&dis[v]==dis[u]+1&&(tp=dfs(v,min(flow[i],exp)))>0)
        {
            flow[i]-=tp;
            flow[i^1]+=tp;
            return tp;
        }
    }
    return 0;
}

int Dinic()
{
    int max_flow=0, flow;
    while(bfs())
    {
        for(int i=0; i<node; i++) work[i]=head[i];
        while(flow=dfs(st,oo)) max_flow+=flow;
    }
    return max_flow;
}

int main()
{
    int n, m, g, l, r, c, d;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init(n+m+2,n+m,n+m+1);
        for(int i=0; i<m; i++)
        {
            scanf("%d",&g);
            du[sd]+=g;
            du[i+n]-=g;
            addedge(i+n,sd,oo-g,0);
        }
        memset(id,0,sizeof(id));
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&c,&d);
            addedge(st,i,d,0);
            for(int j=0; j<c; j++)
            {
                scanf("%d%d%d",&g,&l,&r);
                du[i]-=l;
                du[g+n]+=l;
                dn[i][g]=l;
                addedge(i,g+n,r-l,0);
                id[i][g]=edge-1;
            }
        }
        addedge(sd,st,oo,0);
        st=node, sd=node+1, node+=2;
        head[st]=head[sd]=-1; ///!!
        int sum=0;
        for(int i=0; i<node-2; i++)
        {
            if(du[i]>0) sum+=du[i], addedge(st,i,du[i],0);
            else addedge(i,sd,-du[i],0);
        }
        int maxflow=Dinic();
        if(maxflow!=sum)  puts("-1");
        else
        {
            head[st]=head[sd]=-1, node-=2;
            st=node-2, sd=node-1;
            maxflow=Dinic();
            printf("%d\n",maxflow);
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                   if(id[i][j])
                     printf("%d\n",flow[id[i][j]]+dn[i][j]);
            }
        }
        puts("");
    }
    return 0;
}
