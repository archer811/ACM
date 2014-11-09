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
#define ll long long
const ll inf = 0x3FFFFFFFFFFFFFFFLL;
const int maxn = 100;
const int maxm = maxn*maxn*2;
struct Edge
{
    int to,next;
    ll cap;
    Edge(){};
    Edge(int tt,ll cc,int nx)
    {
        to=tt;cap=cc;next=nx;
    };
}edge[maxm];
int head[maxn],tot,s,t;
void add(int u,int v,ll cap)
{
    edge[tot]=Edge(v,cap,head[u]);
    head[u]=tot++;
    edge[tot]=Edge(u,0,head[v]);
    head[v]=tot++;
}
int d[maxn];
bool bfs()
{
    queue<int>q;
    memset(d,-1,sizeof(d));
    d[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();q.pop();
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].to;
            if(d[v]==-1&&edge[i].cap)
            {
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
    return d[t]!=-1;
}
ll _min(ll a,ll b)
{
    if(a<b)return a;
    return b;
}
ll dfs(int u,ll a)
{
    if(u==t||a==0)return a;
    ll flow=0,f;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(d[v]==d[u]+1&&(f=dfs(v,_min(a,edge[i].cap)))>0)
        {
            edge[i].cap-=f;
            edge[i^1].cap+=f;
            flow+=f;
            a-=f;
            if(a==0)break;
        }
    }
    return flow;
}
ll maxflow()
{
    ll flow=0;
    while(bfs())
    {
        flow+=dfs(s,inf);
    }
    return flow;
}
ll gcd(ll a,ll b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,p,q;
        scanf("%d%d%d%d",&n,&m,&p,&q);
        int a,b;
        ll c;
        memset(head,-1,sizeof(head));
        tot=0;
        ll sum=0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%lld",&a,&b,&c);
            add(a,b,c*10000+1);
            add(b,a,c*10000+1);
            sum+=c;
        }
        s=p;t=q;
        ll ans=maxflow();
        ll x = sum-ans/(ll)10000;
        ll y= ans%(ll)10000;
        ll g = gcd(x,y);


        if(g>0)
        {
           x/=g;y/=g;
        }
        if(y==0)
        {
            puts("Inf");continue;
        }
        double tmp = x*1.0/y;
        printf("%.2f\n",tmp);
    }
    return 0;
}
