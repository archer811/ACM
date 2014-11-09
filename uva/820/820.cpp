#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
using namespace std;
const int maxn = 1000;
const int maxm = 5000006;
const int inf = 0x3fffffff;
int s,t,e;
struct Edge
{
    int to,next,cap;
    Edge(){};
    Edge(int tt,int cc,int nx)
    {
        to=tt;cap=cc;next=nx;
    };
}edge[maxm];
int head[maxn],tot,d[maxn];
int n;
bool bfs()
{
    memset(d,-1,sizeof(d));
    queue<int>q;
    q.push(s);
    d[s]=0;
    while(!q.empty())
    {
        int u=  q.front();q.pop();
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].to;
            if(d[v]==-1&&edge[i].cap>0)
            {
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
    return d[t]!=-1;
}
void add(int u,int v,int cap)
{
    edge[tot]=Edge(v,cap,head[u]);
    head[u]=tot++;
    edge[tot]=Edge(u,0,head[v]);
    head[v]=tot++;
}
int dfs(int u,int a)
{
    if(u==t||a==0)return a;
    int flow=0,f;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {

        int v = edge[i].to;

        if(d[v]==d[u]+1&&(f=dfs(v,min(a,edge[i].cap)))>0)
        {
            edge[i].cap-=f;
            edge[i^1].cap+=f;
            flow+=f;
            a-=f;
            if(a==0)break;
        }
    }
    if(flow==0)d[u]=-1;
    return flow;
}
int maxflow()
{
    int flow=0;
    while(bfs())
    {
        flow+=dfs(s,inf);
    }
    return flow;
}
int g[maxn][maxn];
int main()
{
    int i,j;
    int cas=0;
    while(scanf("%d",&n)!=EOF)
    {
        memset(g,0,sizeof(g));
        if(n==0)break;
        scanf("%d%d%d",&s,&t,&e);
        memset(head,-1,sizeof(head));
        tot=0;
        int a,b,c;
        for(i=0;i<e;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            g[a][b]+=c;
            g[b][a]=g[a][b];
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(i==j)continue;
                if(g[i][j])add(i,j,g[i][j]);
                //cout<<i<<" "<<j<<" "<<g[i][j]<<endl;
            }
        }
        int tmp = maxflow();
        printf("Network %d\n",++cas);
        printf("The bandwidth is %d.\n\n",tmp);
    }
    return 0;
}
