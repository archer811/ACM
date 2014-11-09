#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn = 5000,maxm = 50000,inf = 100000000;
struct Edge
{
    Edge(){};
    Edge(int a,int b,int c,int d){v=a;f=b;w=c;next=d;};
    int v,f,w,next;
};
int n,head[maxn+10];
Edge e[maxm+10];
int tot;
int src,sink;
void addedge(int u,int v,int c,int w)
{
    e[tot]=Edge(v,c,w,head[u]);
    head[u]=tot++;
    e[tot]=Edge(u,0,-w,head[v]);
    head[v]=tot++;
}
queue<int>q;
bool inque[maxn+10];
int dist[maxn+10];
int prev[maxn+10],pree[maxn+10];
bool findPath()
{
    while(!q.empty())q.pop();
    q.push(src);
    memset(dist,63,sizeof(dist));
    dist[src]=0;
    inque[src]=true;
    while(!q.empty())
    {
        int u = q.front();q.pop();
        inque[u]=false;
        for(int i=head[u];i!=-1;i=e[i].next)
        {
            if(e[i].f>0&&dist[u]+e[i].w<dist[e[i].v])
            {
                dist[e[i].v]=dist[u]+e[i].w;
                prev[e[i].v]=u;
                pree[e[i].v]=i;
                if(!inque[e[i].v])
                {
                    inque[e[i].v]=true;
                    q.push(e[i].v);
                }
            }
        }
    }
    if(dist[sink]<inf)return true;
    return false;
}
int augment()
{
    int u = sink;
    int delta = inf;
    for(int i=sink;i!=src;i=prev[i])
    {
        if(e[pree[i]].f<delta)delta = e[pree[i]].f;
    }
    for(int i=sink;i!=src;i=prev[i])
    {
        e[pree[i]].f-=delta;
        e[pree[i]^1].f += delta;
    }
    return dist[sink]*delta;
}
int mincostflow()
{
    int ans=0;
    while(findPath())
    {
        ans += augment();
    }
    return ans;
}
int main()
{
    int i,j,k,a,b,c,w,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(head,-1,sizeof(head));
        tot =0 ;
        sink = n+1;src = 1;
        for(i=2;i<=n;i++)
        {
            scanf("%d",&k);
            addedge(i,sink,inf,-k);
            //addedge(i,sink,inf,0);
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d%d",&a,&b,&c,&w);
            addedge(a,b,c,w);
            addedge(b,a,c,w);
        }
        printf("%d\n",-mincostflow());
    }
}
