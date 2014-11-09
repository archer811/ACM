#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
#include<set>
#include<ctime>
using namespace std;
const int maxn = 100100;
const int maxm = 300100;
struct array
{
    int to,next;
} edge[maxm];
int head[maxn],stack[maxn],dfn[maxn],low[maxn],belong[maxn];
int instack[maxn],cnt,scnt,top,n,tot;
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int in[maxn],d[maxn];
queue<int>q;

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
int belongnum[maxn],w[maxn];
struct input
{
    int a,b;
}g[maxn];
void dfs()
{
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=head[u]; i!=-1; i=edge[i].next)
        {
            int v = edge[i].to;
            in[v]--;
            d[v]=max(d[v],d[u]+belongnum[v]);
            if(in[v]==0)
            {
                q.push(v);
            }
        }
    }
}
int main()
{
    int i,j,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(head,-1,sizeof(head));
        memset(in,0,sizeof(in));
        memset(d,0,sizeof(d));
        memset(belongnum,0,sizeof(belongnum));
        tot=0;
        int a,b;
        int ans=1;
        for(i=0; i<m; i++)
        {
            scanf("%d%d",&a,&b);
            g[i].a=a;g[i].b=b;
            in[b]++;
            add(a,b);
        }
        solve();
        for(i=1; i<=n; i++)
        {
            belongnum[belong[i]]++;
            //if(d[i]>ans)ans=d[i];
        }
        memset(head,-1,sizeof(head));
        tot=0;
        memset(in,0,sizeof(in));
//        for(i=1;i<=n;i++)
//        {
//            cout<<i<<"    "<<belong[i]<<endl;
//        }
        for(i=0;i<m;i++)
        {
            a=g[i].a;b=g[i].b;
            if(belong[a]==belong[b])continue;
            in[belong[b]]++;
//            cout<<belong[a]<<"*"<<belong[b]<<endl;
            add(belong[a],belong[b]);
        }
        while(!q.empty())q.pop();
        for(i=1;i<=scnt;i++)
        {
//            cout<<i<<"@"<<belongnum[i]<<" "<<in[i]<<endl;
            if(in[i]==0){d[i]=belongnum[i];q.push(i);}
        }
        dfs();
        for(i=1;i<=scnt;i++)
        {
//            cout<<i<<" "<<d[i]<<endl;
            if(d[i]>ans)ans=d[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
