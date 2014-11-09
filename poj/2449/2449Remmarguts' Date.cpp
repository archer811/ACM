
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<queue>
#include<map>
using namespace std;
#define maxn 1005
#define maxm 500005
#define inf 1000000000
struct node
{
    int v,w,next;
}edge[maxm],revedge[maxm];
struct A
{
    int f,g,v;
    bool operator <(const A a)const
    {
        if(a.f==f)return a.g<g;
        return a.f<f;
    }
};
int e,vis[maxn],d[maxn],q[maxn*5];
int head[maxn],revhead[maxn];
int n,m,s,t,k;
void init()
{
    e=0;
    memset(head,-1,sizeof(head));
    memset(revhead,-1,sizeof(revhead));
}
void insert(int x,int y,int w)
{
    edge[e].v=y;edge[e].w=w;
    edge[e].next=head[x];
    head[x]=e;
    revedge[e].v=x;revedge[e].w=w;
    revedge[e].next=revhead[y];
    revhead[y]=e++;
}
void spfa()
{
    for(int i=1;i<=n;i++)
      d[i]=inf;
    memset(vis,0,sizeof(vis));
    vis[src]=1;
    int h=0,t=1;
    q[0]=src;d[src]=0;
    while(h<t)
    {
        int u = q[h++];
        vis[u]=0;
        for(int i=revhead[u];i!=-1;i=revedge[i].next)
        {
            int v = revedge[i].v;
            int w = revedge[i].w;
            if(d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                if(!vis[v])
                {
                    vis[v]=1;
                    q[t++]=v;
                }
            }
        }
    }
}
int astar(int src,int des)
{
    int cnt=0;
    priority_queue<A>q;
    if(src==des)k++;
    if(d[src]==inf)return -1;
    A t,tt;
    t.v=src,t.g=0,t.f=t.g+d[src];
    q.push(t);
    cout<<endl;
    while(!q.empty())
    {
        tt = q.top();q.pop();
        cout<<tt.f<<" "<<tt.g<<" "<<tt.v<<endl;
        if(tt.v==des)
        {
            cnt++;
            if(cnt==k)return tt.g;
        }
        for(int i=head[tt.v];i!=-1;i=edge[i].next)
        {
            t.v=edge[i].v;
            t.g=tt.g+edge[i].w;
            t.f=t.g+d[t.v];
            q.push(t);
        }
    }
    return -1;
}
int main()
{
    int x,y,w;
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d",&x,&y,&w);
            insert(x,y,w);
        }
        scanf("%d%d%d",&s,&t,&k);
        spfa(t);
        printf("%d\n",astar(s,t));
    }
}
