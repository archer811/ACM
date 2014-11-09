#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 5000,maxm = 500000,inf = 1000000000;
struct Edge
{
    Edge(){};
    Edge(int a,int b,int c,int d){v=a;f=b;w=c;next=d;}
    int v,f,w,next;
};
int n,m;
int g[maxn+10];
Edge e[maxm+10];
int tot;
int src,sink;
void addedge(int u,int v,int c,int w)
{
    e[tot] = Edge(v,c,w,g[u]);
    g[u] = tot++;
    e[tot]  = Edge(u,0,-w,g[v]);
    g[v] = tot++;
}
queue<int>que;
bool inQue[maxn+10];
int dist[maxn+10];
int prev[maxn+10],pree[maxn+10];
int go[][2]={1,0,-1,0,0,1,0,-1};
bool findPath()
{
    while(!que.empty())que.pop();
    que.push(src);
    memset(dist,63,sizeof(dist));
    dist[src]=0;
    inQue[src]=true;
    while(!que.empty())
    {
        int u= que.front();que.pop();
        inQue[u] = false;
        for(int i=g[u];i!=-1;i=e[i].next)
        {
            if(e[i].f>0&&dist[u]+e[i].w<dist[e[i].v])
            {
                dist[e[i].v]=dist[u]+e[i].w;
                prev[e[i].v]=u;
                pree[e[i].v]=i;
                if(!inQue[e[i].v])
                {
                    inQue[e[i].v]=true;
                    que.push(e[i].v);
                }
            }
        }
    }
    if(dist[sink]<inf)return true;
    else return false;
}
int augment()
{
    int u = sink;
    int delta = inf;
    while(u!=src)
    {
        if(e[pree[u]].f<delta)delta = e[pree[u]].f;
        u = prev[u];
    }
    u = sink;
    while(u!=src)
    {
        e[pree[u]].f -= delta;
        e[pree[u]^1].f+=delta;
        u=prev[u];
    }
    return dist[sink]*delta;
}
int mincostflow()
{
    int cur =0,ans=0;
    while(findPath())
    {
        cur += augment();
        if(cur<ans)ans=cur;
    }
    return ans;
}
int a[55][55];
int main()
{
    int i,j,k,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(g,-1,sizeof(g));
        tot = 0;
        src = 2*n*n+1;
        sink = 2*n*n+2;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&k);
                addedge(2*n*n,i*n+j,inf,0);
                addedge(i*n+j,i*n+j+n*n,1,-k);
                addedge(i*n+j,i*n+j+n*n,inf,0);
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
               scanf("%d",&a[i][j]);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<4;k++)
                {
                    int x = i+go[k][0];
                    int y = j+go[k][1];
                    if(x<0||y<0||x>=n||y>=n)continue;
                    if(a[x][y]<=a[i][j])continue;
                    addedge(x*n+y+n*n,i*n+j,inf,0);
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==0||j==0||i==n-1||j==n-1)
                {
                    addedge(i*n+j+n*n,2*n*n+2,inf,0);
                }
            }
        }
        addedge(2*n*n+1,2*n*n,m,0);
        printf("%d\n",-mincostflow());
    }
}
