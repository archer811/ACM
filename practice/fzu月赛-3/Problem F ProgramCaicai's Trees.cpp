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
int n;
const int maxn = 210000;
struct array
{
    int to,next;
    int cost[2][2];
} edge[maxn*2];
int v1[maxn],v2[maxn];
int head[maxn],tot;
void add(int u,int v,int a,int b,int c,int d)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    edge[tot].cost[0][0]=a;
    edge[tot].cost[0][1]=b;
    edge[tot].cost[1][0]=c;
    edge[tot].cost[1][1]=d;
    head[u]=tot++;
}
ll dp[maxn][2];
ll _min(ll a,ll b)
{
    if(a>b)return b;
    return a;
}
void dfs(int u,int fa)
{
    int i,j;
    ll tmp0=0;
    tmp0 = v1[u];
    ll tmp1 = 0;
    tmp1 = v2[u];
    for(i=head[u]; i!=-1; i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa)continue;
        dfs(v,u);
        ll temp0 = dp[v][0]+edge[i].cost[0][0];
        ll temp1 = dp[v][1]+edge[i].cost[0][1];
        tmp0 += _min(temp0,temp1);

        temp0 = dp[v][0]+edge[i].cost[1][0];
        temp1 = dp[v][1]+edge[i].cost[1][1];
        tmp1 += _min(temp0,temp1);
    }
    //cout<<u<<endl;
    dp[u][0]=tmp0;
    dp[u][1]=tmp1;
}
int main()
{
    int i,j,T;
    scanf("%d",&T);
    int p,q,a,b,c,d;
    while(T--)
    {
        scanf("%d",&n);
        tot=0;
        memset(head,-1,sizeof(head));
        for(i=1; i<=n; i++)
            scanf("%d",&v1[i]);
        for(i=1; i<=n; i++)
            scanf("%d",&v2[i]);
        for(i=0; i<n-1; i++)
        {
            scanf("%d%d%d%d%d%d",&p,&q,&a,&b,&c,&d);
            add(p,q,a,b,c,d);
            add(q,p,a,b,c,d);
        }
        memset(dp,0,sizeof(dp));
        dfs(1,-1);
        printf("%lld\n",_min(dp[1][0],dp[1][1]));
    }
}
