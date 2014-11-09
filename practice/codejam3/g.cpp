#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define N 200+10
#define M 1000+10
#define inf 10000000
struct Edge
{
    int from, to, nex;
} edge[M];
int head[N], edgenum;
void add(int u,int v)
{
    Edge E= {u,v,head[u]};
    edge[edgenum] = E;
    head[u] = edgenum++;
}
struct node
{
    int u, w, d;//当前点u的状态为w，距离1点距离为d。
    node(int a=0,int b=0,int c=0):u(a),w(b),d(c) {}
};
int n, m, k;
int dis[N][1024];
map<int,int>mymap;

void spfa(int start)
{
    for(int i = 0; i < (1<<k); i++)
        for(int j = 1; j <= n; j++)
            dis[j][i] = inf;
    queue<node> q;
    if(mymap.find(start)->second == 0)
    {
        dis[start][0] = 0;
        q.push(node(start, 0, 0));
    }
    else
    {
        dis[start][mymap.find(start)->second] = 0;
        q.push(node(start, mymap.find(start)->second, 0));
    }
    while(!q.empty())
    {
        node from = q.front();
        q.pop();
        for(int i = head[from.u]; ~i; i = edge[i].nex)
        {
            node to = node(edge[i].to, from.w, from.d+1);
            if(mymap.find(edge[i].to)->second)
                to.w |= mymap.find(edge[i].to)->second;
            if(dis[to.u][to.w] > to.d)
            {
                dis[to.u][to.w] = to.d;
                q.push(to);
            }
        }
    }
}

void init()
{
    memset(head, -1, sizeof head);
    edgenum = 0;
    mymap.clear();
}
int main()
{
    int i, j, u, v;
    while(~scanf("%d %d %d",&n,&m,&k))
    {
        init();
        for(i = 1; i <= n; i++)mymap.insert(pair<int,int>(i,0));
        for(i = 0; i < k; i++)
        {
            scanf("%d",&u);
            mymap[u] = 1<<i;
        }
        while(m--)
        {
            scanf("%d %d",&u,&v);
            add(u,v);
        }
        spfa(1);
        int ans = inf;
        for(i = 1; i <= n; i++)
            ans = min(ans, dis[i][(1<<k)-1]);
        if(ans >= inf)puts("-1");
        else printf("%d\n",ans);
    }
    return 0;
}
