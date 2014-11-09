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
int n,k;
const int maxn = 505;
int head[maxn],tot;
const int maxm = 300000;
int s,t;
const int inf = 0x3fffffff;
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
int d[maxn];
int bfs()
{
    queue<int>q;
    q.push(s);
    memset(d,-1,sizeof(d));
    d[s]=0;
    while(!q.empty())
    {
        int u  = q.front();q.pop();
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
vector<int>ans[maxn];
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        memset(head,-1,sizeof(head));
        tot=0;
        int g,d;
        int s1=0,t1=n+k+1;
        s=t1+1;t=s+1;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&g);
            while(g--)
            {
                scanf("%d",&d);
                add(i,n+d,1);
            }
            add(s1,i,1);
        }
        for(i=1;i<=k;i++)
        {
            add(n+i,t1,inf);
            add(n+i,t,2);
            add(s,t1,2);
            ans[i].clear();
        }
        add(t1,s1,inf);
        int tmp = maxflow();
        if(tmp<2*k)
        {
            puts("NO");continue;
        }
        puts("YES");
        for(i=1;i<=n;i++)
        {
            for(j=head[i];j!=-1;j=edge[j].next)
            {
                int v = edge[j].to;
                if(!(v>=n+1&&v<=n+k))continue;
                if(edge[j].cap==0)
                {
                    int tmp = v-n;
                    ans[tmp].push_back(i);
                }
            }
        }
        for(i=1;i<=k;i++)
        {
            printf("%d",ans[i].size());
            for(j=0;j<ans[i].size();j++)
                printf(" %d",ans[i][j]);
            puts("");
        }
    }
    return 0;
}
