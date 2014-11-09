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
const int maxn = 2002;
int w[maxn],d[maxn],head[maxn],tot;
const int maxm = 2100000;
const int inf = 0x3fffffff;
int s,t;
struct Edge
{
    int to,next,cap;
    Edge(){};
    Edge(int tt,int cc,int nx)
    {
        to=tt;cap=cc;next=nx;
    };
}edge[maxm];
void add(int u,int v,int cap)
{
    edge[tot]=Edge(v,cap,head[u]);
    head[u]=tot++;
    edge[tot]=Edge(u,0,head[v]);
    head[v]=tot++;
}
bool bfs()
{
    queue<int>q;
    q.push(s);
    memset(d,-1,sizeof(d));
    d[s]=0;
    while(!q.empty())
    {
        int u = q.front();q.pop();
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].to;
            if(d[v]==-1&&edge[i].cap>0)
            {
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
    return d[t]!=-1;
}
int dfs(int u,int a)
{
    if(u==t||a==0)return a;
    int flow=0,f;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(d[v]==d[u]+1&&(f=dfs(v,min(a,edge[i].cap)))>0)
        {
            edge[i].cap-=f;
            edge[i^1].cap+=f;
            flow+=f;
            a-=f;
            if(a==0)break;
        }
    }
    if(flow==0)d[u]=-1;
    return flow;
}
int maxflow()
{
    int flow=0;
    while(bfs())
    {
        flow+=dfs(s,inf);
    }
    return flow;
}
struct oo
{
    int x,y;
}g[1005];
int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%d",&w[i]);
        int a,b,num=0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            if(a==n||b==n)
            {
                w[n]+=2;continue;
            }
            ++num;
            g[num].x=a;g[num].y=b;
        }
        s=0;
        memset(head,-1,sizeof(head));
        tot=0;
        int t1=num+n+1,t2=t1+1;
        t=t2+1;
        for(i=1;i<=num;i++)
            add(s,i,1);
        for(i=1;i<=num;i++)
        {
            add(i,g[i].x+num,inf);
            add(i,g[i].y+num,inf);
        }
        int flag=0;
        for(i=1;i<n;i++)
        {
            //cout<<w[n]-w[i]-1<<endl;
            if(w[n]-w[i]-1<0)
            {
                flag=1;break;
            }
            add(i+num,t1,(w[n]-w[i]-1)/2);
            cout<<i+num<<" "<<t1<<" "<<((w[n]-w[i]-1)/2)<<endl;

            add(i+num,t2,(w[n]-w[i]-1));

            cout<<i+num<<" "<<t1<<" "<<((w[n]-w[i]-1))<<endl;
        }
        add(t1,t,inf);
        add(t2,t,inf);
        int ans=maxflow();
        cout<<ans<<" "<<num<<endl;
        if(flag==0&&ans>=num)puts("YES");
        else puts("NO");
    }
    return 0;
}
