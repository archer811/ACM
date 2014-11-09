#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int n,m;
#define vm 300
#define em 30000
const int inf = 1e9;
#define INF inf
struct E
{
    int to,next,cap;
}edge[em];
int e;
int head[vm],dis[vm];
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
bool spfa(int s,int t)
{
    int u;
    queue<int>q;
    memset(dis, 0xff, sizeof (dis));
    dis[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (int i = head[u]; i != -1; i = edge[i].next)
        {
            if (dis[edge[i].to] == -1 && edge[i].cap > 0)
            {
                dis[edge[i].to] = dis[u]+1;
                q.push(edge[i].to);
            }
        }
    }
    return dis[t] != -1;
}

int dfs(int u, int flow,int s,int t)
{
    if (u == t)
    {
        return flow;
    }
    int tf = 0, sf;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        if (dis[u]+1 == dis[edge[i].to] && edge[i].cap > 0 &&
             (sf = dfs(edge[i].to, min(flow-tf, edge[i].cap),s,t)))
        {
            edge[i].cap -= sf, edge[i^1].cap += sf;
            tf += sf;
            if (tf == flow)
            {
                return flow;
            }
        }
    }
    if (!tf)
    {
        dis[u] = -1;
    }
    return tf;
}

int Dinic(int s,int t)
{
    int ans=0;
    while (spfa(s,t))
    {
        ans += dfs(s, INF,s,t);
    }
    return ans;
}
queue<pair<int,int> >q;
int main()
{
    int i,j,k;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        while(!q.empty())q.pop();
        int ss=n+1,tt=n+2;
        int a,b,c,d;
        int sum=0;
        while(m--)
        {
            scanf("%d%d%d%d",&a,&b,&c,&d);
            if(d==1)
            {
                sum += c;
                q.push(make_pair(1,c));
                addedge(ss,b,c);
                addedge(a,tt,c);
            }
            else
            {
                q.push(make_pair(0,e));
                addedge(a,b,c);
            }
        }
        int flow1 = Dinic(ss,tt);
        int tmp = e;
        addedge(n,1,inf);
        int flow2 = Dinic(ss,tt);
        if(flow1+flow2!=sum)
        {
            printf("Impossible\n");
            continue;
        }
        printf("%d\n",edge[tmp^1].cap);
        while ( !q.empty() )
        {
            if (q.front().first == 1)
                printf("%d ", q.front().second);
            else
            {
                int t = q.front().second;
                printf("%d ", edge[t^1].cap);
            }
            q.pop();
        }
        printf("\n");
    }
}
