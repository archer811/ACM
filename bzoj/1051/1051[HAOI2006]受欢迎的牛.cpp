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
struct Edge
{
    int to,next;
}edge[maxm];
int head[maxn],stack[maxn],dfn[maxn],low[maxn],belong[maxn];
int instack[maxn],cnt,scnt,top,n,tot,num[maxn];
void add(int x,int y)
{
    edge[tot].to=y;
    edge[tot].next=head[x];
    head[x]=tot++;
}
void tarjan(int u)
{
    int i,j,t;
    dfn[u]=low[u]=++cnt;
    instack[u]=1;
    stack[top++]=u;
    for(i=head[u];i!=-1;i=edge[i].next)
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
        num[scnt]=0;
        do
        {
            t=stack[--top];
            instack[t]=0;
            belong[t]=scnt;
            num[scnt]++;
        }while(t!=u);
    }
}
void solve()
{
    scnt=cnt=top=0;
    memset(dfn,0,sizeof(dfn));
    for(int i=1;i<=n;i++)
      if(!dfn[i])
        tarjan(i);
}
int in[maxn],out[maxn],d[maxn];
map<pair<int,int>,int>M;
struct input
{
    int x,y;
}g[50005];
int main()
{
    int i,j,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(head,-1,sizeof(head));
        tot=0;
        M.clear();
        int k=0;
        for(i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            add(x,y);
            g[i].x=x;
            g[i].y=y;

        }
        solve();
        memset(head,-1,sizeof(head));
        tot=0;
        for(i=1;i<=scnt;i++)
        {
            in[i]=out[i]=d[i]=0;
        }
        for(i=0;i<m;i++)
        {
            int x = belong[g[i].x];
            int y = belong[g[i].y];
            if(x==y)continue;
            pair<int,int> u = make_pair(x,y);
            if(M[u]==0)
            {
                M[u]=1;
                in[y]++;
                out[x]++;
                //cout<<x<<"()"<<y<<endl;
                add(x,y);
            }
        }

        queue<int>q;
        for(i=1;i<=scnt;i++)
        {
            d[i]=num[i];
            if(in[i]==0){q.push(i);}
        }
        while(!q.empty())
        {
            int u = q.front();q.pop();
            for(i=head[u];i!=-1;i=edge[i].next)
            {
                int v = edge[i].to;
               // cout<<d[v]<<"()"<<d[u]+num[v]<<endl;
                //if(d[v]<d[u]+num[v])
                {
                    d[v]+=d[u];
                    q.push(v);
                }
            }
        }
        int sum=0;
        for(i=1;i<=scnt;i++)
        {
            //cout<<i<<" "<<d[i]<<endl;
            if(d[i]==n)sum+=num[i];
        }
        printf("%d\n",sum);
    }
    return 0;
}
