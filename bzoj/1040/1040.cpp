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

const int maxn = 1000005;
const int maxm = 4000005;
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
ll v[maxn];
int vis[maxn];
int root,node,id;
void dfs(int u,int fa)
{
    vis[u]=1;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa)continue;
        if(vis[v])
        {
            root=v;
            node=u;
            id=edge[i].id;
        }
        else dfs(v,u);
    }
}
ll d[maxn][2];
void DP(int u,int fa)
{
    d[u][0]=0;
    d[u][1]=v[u];
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(edge[i].id==id||v==fa)continue;
        DP(v,u);
        d[u][0]+=max(d[v][0],d[v][1]);
        d[u][1]+=d[v][0];
    }
    //cout<<u<<"***"<<d[u][0]<<" "<<d[u][1]<<endl;
}
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(head,-1,sizeof(head));
        tot=0;
        for(i=1;i<=n;i++)
        {
            scanf("%lld%d",&v[i],&j);
            add(i,j,i);
            add(j,i,i);
            vis[i]=0;
        }
        ll sum=0;

        for(i=1;i<=n;i++)
        {
            if(vis[i])continue;
            root=-1;node=-1;id=-1;
            ll tmp=0;
            dfs(i,-1);
            //cout<<root<<"()"<<node<<endl;

            DP(root,-1);
            //cout<<"oo"<<root<<" "<<d[root][0]<<endl;
            tmp = max(tmp,d[root][0]);

            DP(node,-1);
            tmp = max(tmp,d[node][0]);

            sum += tmp;
        }
        printf("%lld\n",sum);
    }
    return 0;
}

