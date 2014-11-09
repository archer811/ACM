#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int N = 110;
const int M = 200000;
int head[N],gap[N],dis[N],pre[N],cur[N],vis[N];
const int inf = 1000000000;
int in[N],out[N],d[N][N];
int n,m,tot;
struct Edge
{
    Edge(){};
    Edge(int a,int b,int c,int d){v=a;f=b;w=c;next=d;}
    int v,f,w,next;
}e[M];
void addedge(int u,int v,int c,int w)
{
    e[tot]=Edge(v,c,w,head[u]);
    head[u]=tot++;
    e[tot]=Edge(u,0,-w,head[v]);
    head[v]=tot++;
}
queue<int>q;
bool inque[N+10];
int prev[N+10],pree[N+10];
int src,sink,fa[N];
int Ans,sum;
int find(int x)
{
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
bool findPath()
{
    while(!q.empty())q.pop();
    q.push(src);
    memset(dis,63,sizeof(dis));
    dis[src]=0;

    memset(inque,0,sizeof(inque));
    inque[src]=true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();inque[u]=false;
        for(int i=head[u];i!=-1;i=e[i].next)
        {
            if(e[i].f>0&&dis[u]+e[i].w<dis[e[i].v])
            {
                dis[e[i].v]=dis[u]+e[i].w;
                prev[e[i].v]=u;
                pree[e[i].v]=i;
                if(!inque[e[i].v])
                {
                    inque[e[i].v]=true;
                    q.push(e[i].v);
                }
            }
        }
    }
    if(dis[sink]<inf)return true;
    return false;
}
int augment()
{
    int u=sink;
    int delta = inf;
    while(u!=src)
    {
        if(e[pree[u]].f<delta)delta=e[pree[u]].f;
        u=prev[u];
    }
    u=sink;
    while(u!=src)
    {
        e[pree[u]].f -= delta;
        e[pree[u]^1].f += delta;
        u=prev[u];
    }
    //cout<<delta<<"GGGG"<<endl;
    Ans += delta;
   // cout<<dis[sink]*delta<<"*(*(*(*(*(*(*(*"<<endl;
    return dis[sink]*delta;
}
void dfs(int x)
{
    vis[x]=1;
    for(int i=1;i<=n;i++)
    {
        if(d[x][i]==0)continue;
        if(d[x][i]==inf)continue;
        if(vis[i]==0)
        {
            vis[i]=1;dfs(i);
        }
    }
}
int mincostflow()
{
    int cur=0,ans=0;
    while(findPath())
    {
        //cout<<"$$$$$"<<endl;
        cur += augment();
        //if(cur<ans)ans=cur;
    }
    return cur;
}
int check()
{
    int t = find(1);
    for(int i=2;i<=n;i++)
        if(find(i)!=t)return 0;
    return 1;
}
void solve()
{
    if(!check())
    {
        puts("-1");
        return;
    }
    Ans=0;
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(d[i][k]+d[k][j]<d[i][j])
                    d[i][j]=d[i][k]+d[k][j];
            }
        }
    }
    int ans=0,i,j;
    for(i=1;i<=n;i++)
    {
        if(in[i]>out[i])
            addedge(n+1,i,in[i]-out[i],0),ans+=in[i]-out[i];
        if(out[i]>in[i])
            addedge(i,n+2,out[i]-in[i],0);
    }
    for(i=1;i<=n;i++)
    {
        if(in[i]<=out[i])continue;
        for(j=1;j<=n;j++)
        {
            if(in[j]>=out[j])continue;
            addedge(i,j,inf,d[i][j]);
            //cout<<i<<" "<<j<<" "<<d[i][j]<<endl;
        }
    }
    src = n+1;sink=n+2;
    int d = mincostflow();
    //cout<<Ans<<" "<<ans<<" "<<d<<" "<<sum<<endl;
    if(Ans!=ans)puts("-1");
    else printf("%d\n",d+sum);
}
int main()
{
    int i,j,t,a,b,c;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d%d",&n,&m);
       tot=0;
       memset(head,-1,sizeof(head));
       for(i=1;i<=n;i++)
          in[i]=out[i]=0,fa[i]=i;
        sum=0;
       for(i=1;i<=n;i++)
       {
           for(j=1;j<=n;j++)
           {
               if(i==j)d[i][j]=0;
               else d[i][j]=inf;
           }
       }
       for(i=0;i<m;i++)
       {
           scanf("%d%d%d",&a,&b,&c);
           a++;b++;
           out[a]++;in[b]++;
           d[a][b]=min(d[a][b],c);
           sum+=c;
           fa[find(a)]=find(b);
       }
       solve();
    }
}
/*
3
2 1
0 1 3
4 4
0 1 1
1 2 2
2 3 3
3 0 4
4 7
0 1 1
1 2 2
2 3 3
3 0 4
1 3 5
3 1 2
1 3 2
*/
