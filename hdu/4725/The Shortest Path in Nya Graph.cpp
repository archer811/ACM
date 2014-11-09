#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
#include<queue>
using namespace std;
#define inf 0x7fffffff
const int maxn = 300005;
int l[maxn];
int head[maxn],tot;
struct array
{
    int to,next;
    int w;
} edge[maxn*4];
int n,m;
void add(int u,int v,int w)
{
    edge[tot].to=v;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int dis[maxn];
struct ok
{
    int to,dis;
   bool operator < (const ok &rhs) const
    {
        return dis > rhs.dis;
    }
} now,next;
int vis[maxn];
int Dijkstra()
{
    priority_queue <ok> q;
    for(int i=0; i<=3*n; i++)
        dis[i]=inf,vis[i]=0;
    now.to=1;
    now.dis=0;
    q.push(now);
    while (!q.empty())
    {
        now =q.top() ;
        q.pop() ;
        int u=now.to;
        if(u==n)return dis[n];

        //if(vis[u])continue;
        //vis[u]=1;
        int d=now.dis;
        for (int i=head[u]; i!=-1; i=edge[i].next)
        {
            int v = edge[i].to;
            int dd=d+edge[i].w;
            if (dis[v]>dd)
            {
                dis[v]=dd;
                next.to=v;
                next.dis=dd;
                q.push(next);
            }
        }
    }
    int ans = dis[n];
    if(ans>=inf)ans=-1;
    return ans;
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        int c;
        memset(head,-1,sizeof(head));
        tot=0;
        scanf("%d%d%d",&n,&m,&c);
        for(i=1; i<=n; i++)
        {
            scanf("%d",&l[i]);
            add(l[i]+n,i,0);
            add(i,l[i]+n*2,0);
        }
        for(i=1;i<n;i++)
        {
            add(2*n+i,n+1+i,c);
            add(2*n+i+1,n+i,c);
        }

        int u,v;
        int w;
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
        }
        int ant;
        ant = Dijkstra();
        if(ant>=inf)ant=-1;
        printf("Case #%d: %d\n",++cas,ant);
    }
    return 0;
}
/*
1111
4 1 10
1 1  3 3
2 3 1

4 1 10
1 1  3 1
2 3 1

3 3 3
1 3 2
1 2 1
2 3 1
1 3 3

3 3 3
1 3 2
1 2 2
2 3 2
1 3 4

2 0 10
1 1
*/
