#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;
#ifdef __int64
typedef __int64 ll;
#else
typedef long long ll;
#endif

const int maxn = 400005;
const int maxm = 400005;
int head[maxn],tot;
struct Edge
{
    int to,next;
} edge[maxm];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int stack[maxn],dfn[maxn],low[maxn],belong[maxn];
int instack[maxn],cnt,scnt,top,n;
void tarjan(int u)
{
    int i,j,t;
    dfn[u]=low[u]=++cnt;
    instack[u]=1;
    stack[top++]=u;
    for(i=head[u]; i!=-1; i=edge[i].next)
    {
        j=edge[i].to;
        if(!dfn[j])
        {
            tarjan(j);
            if(low[u]>low[j])
                low[u]=low[j];
        }
        else if(instack[j]&&dfn[j]<low[u])
            low[u]=dfn[j];
    }
    if(dfn[u]==low[u])
    {
        scnt++;
        do
        {
            t=stack[--top];
            instack[t]=0;
            belong[t]=scnt;
        }
        while(t!=u);
    }
}
void solve()
{
    scnt=cnt=top=0;
    memset(dfn,0,sizeof(dfn));
    for(int i=1; i<=n; i++)
        if(!dfn[i])
            tarjan(i);
}
const ll mod = 1000000007 ;
int a[maxn];
ll d[100005];
int out[303];
struct input
{
    int x,y;
} g[305];
int vv[305],in[305],c[305];
int main()
{
    int i,j,q,t;
    while(scanf("%d%d%d",&n,&q,&t)!=EOF)
    {
        memset(head,-1,sizeof(head));
        memset(d,0,sizeof(d));
        d[0]=1;
        tot=0;
        for(i=1; i<=n; i++)
            scanf("%d",&a[i]),out[i]=0,vv[i]=0,in[i]=0;
        for(i=0; i<q; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            g[i].x=x;
            g[i].y=y;
            add(y,x);
        }
        solve();
        if(scnt<n)
        {
            puts("0");
            continue;
        }
        for(i=0; i<q; i++)
        {
            int x = g[i].x;
            int y = g[i].y;
            if(x!=y)
            {
                out[x]=y;
                in[y]=1;
                //cout<<x<<"@"<<y<<endl;
            }
        }
        for(i=1; i<=scnt; i++)
        {
            if(vv[i])continue;
            if(in[i])continue;
            j = i;
            int sum=0;
            while(j)
            {
                sum += a[j];
                c[j]=sum;
                vv[j]=1;
                j = out[j];
            }
        }
//        for(i=1;i<=n;i++)
//        {
//            cout<<i<<" "<<c[i]<<endl;
//        }
        for(i=1; i<=n; i++)
        {
            if(out[i])
            {
                //cout<<i<<endl;
                for(int tp=t;tp>=0;tp--)
                {
                    if(tp<c[i])d[tp]=0;
                    else d[tp]=d[tp-c[i]];
                }
            }
            for(int tp=0; tp<=t-c[i]; tp++)
            {
                d[tp+c[i]]+=d[tp];
                d[tp+c[i]]%=mod;
            }
        }
        cout<<d[t]<<endl;
    }
    return 0;
}

