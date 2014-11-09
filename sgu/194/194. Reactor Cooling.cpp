#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int n,m,s,t;
#define vm 300
#define em 300000
const int inf = 0x3fffffff;
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
bool spfa()
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

int dfs(int u, int flow)
{
    if (u == t)
    {
        return flow;
    }
    int tf = 0, sf;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        if (dis[u]+1 == dis[edge[i].to] && edge[i].cap > 0 &&
             (sf = dfs(edge[i].to, min(flow-tf, edge[i].cap))))
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

void Dinic(int &ans)
{
    while (spfa())
    {
        ans += dfs(s, INF);
    }
}
queue<pair<int,int> >q;
int main()
{
    int i,j,k,a,b,l,r;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        s=0;t=n+1;
        int sum=0;
        while(!q.empty())q.pop();
        while(m--)
        {
            scanf("%d%d%d%d",&a,&b,&l,&r);
            q.push(make_pair(l,e));
            addedge(a,b,r-l);
            addedge(s,b,l);
            addedge(a,t,l);
            sum+= l;
        }
        int tmp=0;
        Dinic(tmp);
        if(tmp!=sum)
            printf("NO\n");
        else
        {
            printf("YES\n");
            while(!q.empty())
            {
                tmp = q.front().first;
                int ee = q.front().second;
                q.pop();
                printf("%d\n",tmp+edge[ee^1].cap);
            }
        }
    }
}
