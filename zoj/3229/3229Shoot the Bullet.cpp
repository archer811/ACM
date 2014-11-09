#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
#define vm 3000
#define em 300000
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
int n,m;
int main()
{
    int i,j,k,d,a,b,c;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        while(!q.empty())q.pop();
        int s=n+m+10,t=s+1;
        int ss=t+1,tt=ss+1;
        int sum=0;
        for(i=1;i<=m;i++)
        {
            scanf("%d",&j);
            sum+=j;
            addedge(ss,t,j);
            addedge(i,tt,j);
            addedge(i,t,inf);
        }

        for(i=1;i<=n;i++)
        {
            int C,D;
            scanf("%d%d",&C,&D);
            addedge(s,i+m,D);
            for(j=1;j<=C;j++)
            {
               scanf("%d%d%d",&a,&b,&c);
               a++;
               sum += b;
               addedge(ss,a,b);
               addedge(m+i,tt,b);
               q.push(make_pair(b,e));
               addedge(i+m,a,c-b);
            }
        }
        addedge(t,s,inf);
        int tmp=0;
        tmp = Dinic(ss,tt);
        if(tmp!=sum)
            puts("-1");
        else
        {
            tmp = Dinic(s,t);
            printf("%d\n",tmp);
            while(!q.empty())
            {
                tmp = q.front().first;
                int ee = q.front().second;
                q.pop();
                printf("%d\n",tmp+edge[ee^1].cap);
            }
        }
        printf("\n");
    }
}
