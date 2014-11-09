#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;
#define ll long long
template <class T>
inline bool rd(T &ret)
{
    char c;
    int sgn;
    if(c=getchar(),c==EOF) return 0;
    while(c!='-'&&(c<'0'||c>'9')) c=getchar();
    sgn=(c=='-')?-1:1;
    ret=(c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
    ret*=sgn;
    return 1;
}
struct Node
{
    ll d ;
    int idx ;
    Node () {}
    Node ( ll d , int idx ) : d ( d ) , idx ( idx ) {}
    bool operator < ( const Node& a ) const
    {
        return d > a.d ;
    }
} ;
const int maxn = 20005;
const int maxm = 400005;
int head[maxn],tot;
ll d[maxn];
struct Edge
{
    int to,next,id,w;
} edge[maxm];
void add(int u,int v,int w,int id)
{
    edge[tot].to=v;
    edge[tot].w=w;
    edge[tot].id=id;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int n,m,vis[maxn];
int dfns;
ll d2[maxn];
queue<int>q;
map<pair<int,int>,int >M;
int dfn[maxn],mark[maxm],low[maxn];
void bfs()
{
    memset(d,0x3f,sizeof(d));

    int i,j;
    for(i=1;i<=n;i++)
        vis[i]=0;
    vis[1]=0;
    priority_queue < Node > q ;
    d[1] = 0 ;
    q.push ( Node ( d[1] , 1 ) ) ;
    while ( !q.empty () )
    {
        int u = q.top ().idx ;
        q.pop () ;
        for(i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].to;
            if ( d[v] > d[u] + edge[i].w )
            {
                d[v] = d[u] + edge[i].w ;
                q.push ( Node ( d[v] , v ) ) ;
            }
        }
    }


    memset(d2,0x3f,sizeof(d2));
    d2[n]=0;
    for(i=1; i<=n; i++)
        vis[i]=0;
    vis[n]=1;
    q.push ( Node ( d2[n] , n ) ) ;
    while ( !q.empty () )
    {
        int u = q.top ().idx ;
        q.pop () ;
        for(i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].to;
            if ( d2[v] > d2[u] + edge[i].w )
            {
                d2[v] = d2[u] + edge[i].w ;
                q.push ( Node ( d2[v] , v ) ) ;
            }
        }
    }
}

void dfs(int cur,int fa)
{
    vis[cur] = 1;
    int chongbian = 0;
    dfn[cur] = low[cur] = dfns ++;
    for(int i = head[cur]; i != -1; i = edge[i].next)
    {
        if(fa == edge[i].to)
            chongbian ++;
        if(vis[edge[i].to] == 0)
        {
            dfs(edge[i].to,cur);
            low[cur] = min(low[cur],low[edge[i].to]);
            if(low[edge[i].to] > dfn[cur])
            {

                mark[edge[i].id]=1;

            }
        }
        else if(fa != edge[i].to || chongbian > 1)
            low[cur] = min(low[cur],dfn[edge[i].to]);
    }
}
void tarjan()
{
    int i;
    dfns = 1;
    for(i=1; i<=n; i++)
        vis[i]=dfn[i]=0;
    for(i = 1; i <= n; i ++)
        if(vis[i] == 0)
            dfs(i,-1);
}
struct array
{
    int x,y,w,id;
} g[maxm];
int cmp(array a,array b)
{
    return a.w<b.w;
}

int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(head,-1,sizeof(head));
        tot=0;
        for(i=1; i<=m; i++)
        {
            int a,b,c;
            rd(a);
            rd(b);
            rd(c);
            add(a,b,c,i);
            add(b,a,c,i);
            g[i].x=a;
            g[i].y=b;
            g[i].w=c;
            g[i].id=i;
            mark[i]=0;
        }
        bfs();
        memset(head,-1,sizeof(head));
        tot=0;
        for(i=1; i<=m; i++)
        {
            int x = g[i].x;
            int y = g[i].y;
            int w = g[i].w;
            if(d[x]>d[y])swap(x,y);
            if(d[x]+d2[y]+w==d[n])
            {
                //cout<<x<<" "<<y<<endl;
                add(x,y,w,i);
                add(y,x,w,i);
            }
        }
        tarjan();
        int sum=0;
        for(i=1; i<=m; i++)
            if(mark[i])sum++;
        int ff=0;
        printf("%d\n",sum);
        for(i=1; i<=m; i++)
        {
            if(ff==0&&mark[i])
            {
                printf("%d",i);
                ff=1;
            }
            else if(ff&&mark[i])printf(" %d",i);
        }
        if(sum)puts("");
    }
    return 0;
}
