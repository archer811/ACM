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
const int maxn = 401;
const int maxm = maxn*maxn;
int d[maxn];
const int inf = 1e9;
int mp[maxn][maxn];
int n,m;
bool vis[maxn];
int s,t;
void dijstra()
{
    int i,j;
    for(i=1; i<=n; i++)
        d[i]=inf,vis[i]=false;
    queue<int>q;
    q.push(1);
    d[s]=0;
    vis[s]=true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u]=false;
        for(i=1; i<=n; i++)
        {
            if(d[i]>d[u]+mp[u][i])
            {
                d[i]=d[u]+mp[u][i];
                if(vis[i]==false)
                {
                    vis[i]=true;
                    q.push(i);
                }
            }
        }
    }
//    for(i=1;i<=n;i++)
//        cout<<i<<"fdsf"<<d[i]<<endl;
}
int head[maxn],tot;
struct Edge
{
    int to,next,cap;
    Edge() {};
    Edge(int tt,int cc,int nx)
    {
        to=tt;
        cap=cc;
        next=nx;
    };
} edge[maxm];
void add(int u,int v,int cap)
{
    edge[tot]=Edge(v,cap,head[u]);
    head[u]=tot++;
    edge[tot]=Edge(u,0,head[v]);
    head[v]=tot++;
}
int to[maxn],q[maxm];
bool bfs()
{
    int hh,tail,x,u,v;
    hh=tail=0;
    memset(to,-1,sizeof(to));
    q[tail++]=s;
    to[s]=1;
    while(hh<tail)
    {
        u=q[hh++];
        for(x=head[u]; x!=-1; x=edge[x].next)
        {
            v=edge[x].to;
            if(-1==to[v]&&edge[x].cap>0)
            {
                to[v]=1+to[u];
                q[tail++]=v;
            }
        }
    }
    return to[t]!=-1;
}
int DFS(int u,int a)
{
    if(u==t||a==0)return a;
    int flow=0,f;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v = edge[i].to;
        if(to[v]==to[u]+1&&(f=DFS(v,min(a,edge[i].cap)))>0)
        {
            if(f<0)return f;
            if(f>0)
            {
                edge[i].cap-=f;
                edge[i^1].cap+=f;
                flow+=f;
                a-=f;
            }
            if(a==0)break;
        }
    }
    return flow;
}

int flag=0,mark=0;
void dfsa(int u,int fa)
{
    int i,j;
    if(flag)return;
    for(i=head[u]; i!=-1; i=edge[i].next)
    {
        if(flag)return;
        int v = edge[i]. to;
        if(v==fa)continue;
        if(edge[i].cap!=0)continue;
        if(d[v]==d[u]+mp[u][v])
        {
            edge[i].cap=-1;
            if(v==n)flag=1;
            printf(" %d",v);
            dfsa(v,u);
        }
    }
}
int h[maxn];
int gap[maxn];
int src, des;
inline int dfs(int pos, int cost)
{
    if (pos == des) return cost;
    int j, minh = n - 1;
    int lv = cost, d;
    for (j = head[pos]; j != -1; j = edge[j].next)
    {
        int v = edge[j].to;
        int w = edge[j].cap;
        if(w > 0)
        {
            if (h[v] + 1 == h[pos])
            {
                if (lv < edge[j].cap) d = lv;
                else d = edge[j].cap;
                d = dfs(v, d);
                edge[j].cap -= d;
                edge[j ^ 1].cap += d;
                lv -= d;
                if (h[src] >= n) return cost - lv;
                if (lv == 0) break;
            }
            if (h[v] < minh) minh = h[v];
        }
    }
    if (lv == cost)
    {
        --gap[h[pos]];
        if (gap[h[pos]] == 0) h[src] = n;
        h[pos] = minh + 1;
        ++gap[h[pos]];
    }
    return cost - lv;
}
int sap()
{
    src=1;des=n;
    int ret = 0;
    memset(gap, 0, sizeof(gap));
    memset(h, 0, sizeof(h));
    gap[0] = n;
    while (h[src] < n) ret += dfs(src, inf);
    return ret;
}
int maxflow()
{
//    int flow=0;
//    while(bfs())
//    {
//        flow+=DFS(s,inf);
//    }
//    return flow;
}
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(i==j)mp[i][j]=0;
                else mp[i][j]=inf;
            }
            head[i]=-1;
        }
        int a,b,c;
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            mp[a][b]=mp[b][a]=c;
        }
        s=1;
        t=n;
        dijstra();
        tot=0;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(i==j||mp[i][j]>=inf)continue;
                if(d[j]==d[i]+mp[i][j])
                {
                    add(i,j,1);
                }
            }
        }

        int tmp = sap();
        if(tmp<2)
        {
            puts("No solution");
            continue;
        }
        flag=0;
        printf("1");
        dfsa(1,-1);
        puts("");


        flag=0;
        printf("1");
        dfsa(1,-1);
        puts("");
    }
    return 0;
}
