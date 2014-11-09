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
const int maxn = 100005;
const int maxm = 800005;
struct array
{
    int to,next,w;
}edge[maxm];
int head[maxn],tot;
void add(int u,int v,int w)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    edge[tot].w=w;
    head[u]=tot++;
}
#define ll __int64
ll d[maxn];
queue<int>q;
int vis[maxn];
void spfa()
{
    while(!q.empty())q.pop();
    memset(d,-1,sizeof(d));
    memset(vis,0,sizeof(vis));
    q.push(1);
    vis[1]=0;
    d[1]=0;
    while(!q.empty())
    {
        int u = q.front();q.pop();
        vis[u]=0;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].to;
            if(d[v]==-1||d[v]>d[u]+edge[i].w)
            {
                d[v]=d[u]+edge[i].w;
                if(vis[v]==0)
                {
                    vis[v]=1;q.push(v);
                }
            }
        }
    }
}
int main()
{
    int i,j,n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        memset(head,-1,sizeof(head));
        tot=0;
        while(m--)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
            add(b,a,c);
        }
        spfa();
        int sum=0;
        for(i=1;i<=k;i++)
        {
            ll g;
            int a;
            scanf("%d%I64d",&a,&g);
            if(d[a]<=g)sum++;
            if(g<d[a])d[a]=g;
        }
        cout<<sum<<endl;
    }
    return 0;
}
