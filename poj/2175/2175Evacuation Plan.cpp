#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int n,m;
#define ll __int64
struct array
{
    int x,y;
    ll num;
}b[111],c[111];
ll d[111][111];
const ll inf = ((ll)1<<50);
struct Edge
{
    Edge(){};
    Edge(int a,ll b,ll c,int d){v=a;f=b;w=c;next=d;};
    ll f,w;
    int v,next;
}edge[200000];
int tot;
int head[550];
int src,sink;
int mark[510][510];
void addedge(int u,int v,ll c,ll w,int mm)
{
    if(mm)mark[u][v]=tot;
    edge[tot]=Edge(v,c,w,head[u]);
    head[u]=tot++;
    edge[tot]=Edge(u,0,-w,head[v]);
    head[v]=tot++;
}
queue<int>q;
bool inque[550];
ll dis[550];
int prev[550],pree[550];
bool findPath()
{
    while(!q.empty())q.pop();
    q.push(src);
    for(int i=0;i<210;i++)
        dis[i]=inf,inque[i]=0;
    dis[src]=0;
    inque[src]=true;
    while(!q.empty())
    {
        int u =q.front();q.pop();
        inque[u]=false;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            if(edge[i].f>0&&dis[u]+edge[i].w<dis[edge[i].v])
            {
                dis[edge[i].v]=dis[u]+edge[i].w;
                prev[edge[i].v]=u;
                pree[edge[i].v]=i;
                if(!inque[edge[i].v])
                {
                    inque[edge[i].v]=true;
                    q.push(edge[i].v);
                }
            }
        }
    }
    if(dis[sink]<inf)return true;
    return false;
}
ll augment()
{
    int u= sink;
    ll delta = inf;
    while(u!=src)
    {
        if(edge[pree[u]].f<delta)delta=edge[pree[u]].f;
        u=prev[u];
    }
    u = sink;
    while(u!=src)
    {
        edge[pree[u]].f -= delta;
        edge[pree[u]^1].f += delta;
        u= prev[u];
    }
    return dis[sink]*delta;
}
ll mincostflow()
{
    ll cur=0,ans=0;
    while(findPath())
    {
        cur += augment();
        if(cur<ans)ans=cur;
    }
    return cur;
}
int main()
{
    int i,j,k;
    ll dd;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d%d%I64d",&b[i].x,&b[i].y,&b[i].num);
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%I64d",&c[i].x,&c[i].y,&c[i].num);
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                d[i][j]=abs(b[i].x-c[j].x)+abs(b[i].y-c[j].y)+1;
            }
        }
        ll sum=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                scanf("%I64d",&dd);
                sum += d[i][j]*dd;
            }
        }
        tot=0;
        memset(head,-1,sizeof(head));
        src = 201;sink = 202;
        for(i=1;i<=n;i++)
        {
            addedge(src,i,b[i].num,0,0);
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                addedge(i,j+100,inf,d[i][j],1);
            }
        }
        for(i=1;i<=m;i++)
            addedge(100+i,sink,c[i].num,0,0);
        ll tmp = mincostflow();
        if(tmp==sum)puts("OPTIMAL");
        else
        {
            puts("SUBOPTIMAL");
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=m;j++)
                {
                    if(j==1)printf("%I64d",inf-edge[mark[i][j+100]].f);
                    else printf(" %I64d",inf-edge[mark[i][j+100]].f);
                }
                puts("");
            }
        }
    }
}
