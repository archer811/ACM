#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 1200;
const int inf  = 1000000000;
int head[maxn],head1[maxn];
int n,m,s,t;
char str[1000];
int e;
struct array
{
    int to,next,w,d;
}edge[5000*6];
void add(int u,int v,int w,int len)
{
    if(head[u]!=-1&&edge[head[u]].w<w)
        return;
    if(head[u]!=-1&&edge[head[u]].w>w)
        head[u]=-1;
    edge[e].to=v;
    edge[e].w=w;
    edge[e].d=len;
    edge[e].next=head[u];
    head[u]=e++;
}
int vis[maxn],ok[maxn],mon[maxn],dis[maxn];
int times[maxn];
queue<int>q;
/*
int spfa(int s)
{
    int i,j;
    memset(vis,0,sizeof(vis));
    memset(times,0,sizeof(times));
    for(i=0; i<n; i++)
    {
        dis[i]=mon[i]=inf;
    }
    dis[s]=0;mon[s]=0;vis[s]=1;times[s]++;
    while(!q.empty())q.pop();
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();q.pop();
        vis[u]=0;
        if(times[u]>n)return 1;
        for(i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].to;
            if(ok[v]==0)continue;
            if(mon[v]>mon[u]+edge[i].w||(mon[v]==mon[u]+edge[i].w&&dis[v]>dis[u]+edge[i].l))
            {
                mon[v]=mon[u]+edge[i].w;
                dis[v]=dis[u]+edge[i].l;
                if(vis[v]==0)
                {
                    vis[v]=1;
                    times[v]++;
                    q.push(v);
                }
            }
        }
    }
    return 0;
}*/
int spfa(int u)
{
    int i,j;
    memset(vis,0,sizeof(vis));
    memset(times,0,sizeof(times));
    for(i=0; i<n; i++)
    {
        dis[i]=mon[i]=inf;
    }
    queue<int>que;
    que.push(u);
    vis[u]=1;
    dis[u]=mon[u]=0;
    times[u]++;
    while(!que.empty())
    {
        int tem=que.front();
        que.pop();
        vis[tem]=0;                   //把这句移到这里可以把负的自环判断出来
        if(times[tem]>n)
            return 1;
        for(i=head[tem]; i!=-1; i=edge[i].next)
        {
            int v=edge[i].to;
            if(!ok[v])
                continue;
            if(mon[v]>mon[tem]+edge[i].w || (mon[v] == mon[tem]+edge[i].w && dis[v]>dis[tem]+edge[i].d))
            {
                mon[v]=mon[tem]+edge[i].w;
                dis[v]=dis[tem]+edge[i].d;
                if(!vis[v])
                {
                    que.push(v);
                    vis[v]=1;
                    times[v]++;
                }
            }
        }
    }
    return 0;
}
void dfs(int a)
{
    int i,yes=0;
    ok[a]=1;
    for(i=head1[a]; i!=-1; i=edge[i].next)
    {
        if(!ok[edge[i].to])
            dfs(edge[i].to);
    }
}
int main()
{
    int i,j,k;
    while(scanf("%d%d%d%d",&n,&m,&s,&t)!=EOF)
    {
        e=0;
        memset(head,-1,sizeof(head));
        for(i=0;i<m;i++)
        {
             int u,v,f1,l,f2;
            scanf("%s",str);
            sscanf(str,"(%d,%d,%d[%d]%d)",&u,&v,&f1,&l,&f2);
            add(u,v,f1,l);
            add(v,u,f2,l);
        }
        memset(head1,-1,sizeof(head1));
        memset(ok,0,sizeof(ok));
        for(i=0; i<n; i++)                               //建立反图
        {
            for(j=head[i]; j!=-1; j=edge[j].next)
            {
                edge[e].to=i;
                edge[e].next=head1[edge[j].to];
                head1[edge[j].to]=e++;
            }
        }
        dfs(t);
        int tmp = spfa(s);
        if(mon[t]>=inf)puts("VOID");
        else if(tmp==0)printf("%d %d\n",mon[t],dis[t]);
        else printf("UNBOUND\n");
    }
}
