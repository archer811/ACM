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
#ifdef __int64
typedef __int64 ll;
#else
typedef long long ll;
#endif

const int maxn =  10005;
const int maxm = 200005;
int head[maxn],tot;
struct Edge
{
    int to,next,id;
}edge[maxm];
void add(int u,int v,int id)
{
    edge[tot].to=v;
    edge[tot].id=id;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int mark[maxm];
int n,m;
int vis[maxn],dfn[maxn],low[maxn],dfns;
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

int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(head,-1,sizeof(head));
        tot=0;
        for(i=0;i<m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b,i+1);
            add(b,a,i+1);
        }
        memset(mark,0,sizeof(mark));
        tarjan();
        int sum=0;
        for(i=1;i<=m;i++)
        {
            if(mark[i])sum++;
        }
        printf("%d\n",sum);
        int flag=0;
        for(i=1;i<=m;i++)
        {
            if(mark[i])
            {
                if(flag==0)printf("%d",i);
                else printf(" %d",i);
                flag=1;
            }
        }
        puts("");
    }
    return 0;
}
