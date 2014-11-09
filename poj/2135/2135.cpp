#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int m;
const int maxn = 500,maxm = 500000,inf = 999999999;
struct Edge
{
    Edge(){};
    Edge(int a,int b,int c,int d){v=a;f=b;w=c;next=d;};
    int v,f,w,next;
};
int n,lmt;
int g[maxn+10];
Edge e[maxm+10];
int nume;
int src,sink;
void addedge(int u,int v,int c,int w)
{
    e[nume] = Edge(v,c,w,g[u]);
    g[u] = nume++;
    e[nume] = Edge(u,0,-w,g[v]);
    g[v]  = nume++;
}
queue<int>que;
bool inQue[maxn+10];
int dist[maxn+10];
int prev[maxn+10],pree[maxn+10];
bool findPath()
{
    while(!que.empty())que.pop();
    que.push(src);
    int i;
    for(i=0;i<=sink;i++)
        dist[i]=inf,inQue[i]=false;
    dist[src]=0;
    inQue[src]=true;
    while(!que.empty())
    {
        int u=  que.front();
        que.pop();
        inQue[u] = false;
        for(int i=g[u];i!=-1;i=e[i].next)
        {
            if(e[i].f>0&&dist[u]+e[i].w<dist[e[i].v])
            {
                //cout<<u<<" "<<e[i].v<<endl;
                dist[e[i].v]=dist[u]+e[i].w;
                prev[e[i].v]=u;
                pree[e[i].v]=i;
                if(!inQue[e[i].v])
                {
                    inQue[e[i].v] = true;
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
    int u=  sink;//cout<<u<<endl;
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
        u = prev[u];
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
int main()
{
    int i,j,k,a,b,c;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(g,-1,sizeof(g));
        nume=0;
        src = 0,sink = n+1;
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            addedge(a,b,1,c);
            addedge(b,a,1,c);
        }
        addedge(0,1,2,0);
        addedge(n,n+1,2,0);
        printf("%d\n",mincostflow());
    }
}
