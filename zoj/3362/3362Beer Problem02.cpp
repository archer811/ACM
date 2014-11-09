#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <stack>

using namespace std;

#define LL_INF 0x3fffffffffffffffll
#define EPS 1e-12
#define MOD 1000000007
#define PI 3.141592653579798
#define N 505
#define E 20000

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef double DB;

struct Edge
{
    LL st,en,cap,flow,cost,next;
} edge[E];
LL head[N] , tot , now[N];
LL source,sink;
LL pre[N] , dis[N];
queue<LL> q;
bool vs[N];

void add_edge(LL st,LL en,LL cap,LL cost)
{
    edge[tot].st=st;
    edge[tot].en=en;
    edge[tot].cap=cap;
    edge[tot].flow=0;
    edge[tot].cost=cost;
    edge[tot].next=head[st];
    head[st]=tot++;

    edge[tot].st=en;
    edge[tot].en=st;
    edge[tot].cap=0;
    edge[tot].flow=0;
    edge[tot].cost=-cost;
    edge[tot].next=head[en];
    head[en]=tot++;
}

bool SPFA()
{
    for(LL i=0; i<N; i++)
        dis[i]=LL_INF;
    memset(vs,0,sizeof(vs));
    memset(now,-1,sizeof(now));
    while(!q.empty()) q.pop();
    q.push(source); dis[source]=0; vs[source]=1;
    while(!q.empty())
    {
        LL u=q.front(); q.pop(); vs[u]=0;
        for(LL i=head[u],v; i!=-1; i=edge[i].next)
            if(edge[i].cap-edge[i].flow>0 && dis[v=edge[i].en]>dis[u]+edge[i].cost)
            {
                dis[v]=dis[u]+edge[i].cost;
                now[v]=i;
                if(!vs[v])
                {
                    vs[v]=1;
                    q.push(v);
                }
            }
    }
    if(dis[sink]!=LL_INF) return true;
    else return false;
}

LL MCMF()
{
    LL cost=0;
    while(SPFA())
    {
        LL flow=LL_INF;
        for(LL u=sink; u!=source; u=edge[now[u]].st)
            if(flow>edge[now[u]].cap-edge[now[u]].flow)
                flow=edge[now[u]].cap-edge[now[u]].flow;
        for(LL u=sink; u!=source; u=edge[now[u]].st)
        {
            edge[now[u]].flow+=flow;
            edge[now[u]^1].flow-=flow;
        }
        cost+=flow*dis[sink];
    }
    return cost;
}
LL val[N];
void build(LL n,LL m)
{
    memset(head,-1,sizeof(head));
    tot=0;
    source=1; sink=n+1;
    long long MAX=0;
    add_edge(source,1,LL_INF,0);
    for(LL i=1,a,b,c,d;i<=m;i++)
    {
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        add_edge(a,b,c,d);
        add_edge(b,a,c,d);
    }
    for(LL i=2;i<=n;i++)
    {
        add_edge(i,sink,LL_INF,-val[i]);
       // add_edge(i,sink,LL_INF,0);
    }

}

int main()
{
    LL n,m;
    //freopen("input.txt","r",stdin);
    while(scanf("%lld%lld",&n,&m)!=EOF)
    {
        for(LL i=2;i<=n;i++)
            scanf("%lld",&val[i]);
        build(n,m);
        LL ans=MCMF();
        printf("%lld\n",-ans);
    }
    return 0;
}
