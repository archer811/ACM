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
int mark[maxn];
const ll mod =  1000000007;
ll d[maxn][2];
void dfs(int u,int fa)
{
    int i,j;
    d[u][1]=mark[u];
    d[u][0]=mark[u]^1;
    for(i=head[u]; i!=-1; i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa)continue;
        dfs(v,u);
        int tp0=d[u][0];
        int tp1=d[u][1];
        d[u][0]=d[u][1]=0;
        d[u][0]=(d[u][0]+tp0*d[v][0])%mod;
        d[u][0]=(d[u][0]+tp0*d[v][1])%mod;
        d[u][1]=(d[u][1]+tp1*d[v][0])%mod;
        d[u][1]=(d[u][1]+tp1*d[v][1])%mod;
        d[u][1]=(d[u][1]+tp0*d[v][1])%mod;
    }
    //cout<<u<<" "<<d[u][0]<<"*"<<d[u][1]<<endl;
}
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(head,-1,sizeof(head));
        tot=0;
        for(i=1; i<n; i++)
        {
            scanf("%d",&j);
            add(j,i);
        }
        for(i=0; i<n; i++)
            scanf("%d",&mark[i]);

        dfs(0,-1);
        cout<<d[0][1]<<endl;

    }
    return 0;
}

