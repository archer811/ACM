#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define ll __int64
const int maxn = 10005;
int head[maxn],vis[maxn],v[maxn];
struct array
{
    int to,next,c;
} edge[1010000];
int tot;
void add(int u,int v,int c)
{
    edge[tot].to=v;
    edge[tot].c=c;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int n,m;
int num,t;
void dfs(int u,int fa)
{
    num++;
    for(int i= head[u]; i!=-1; i=edge[i].next)
    {
        int v  = edge[i].to;
        if(v==fa)continue;
        if(vis[v])continue;
        if(edge[i].c<=t-1)
        {
            vis[v]=1;
            dfs(v,fa);
        }
    }
}
int tt,Num;
void DFS(int u,int fa)
{
    Num ++;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int _v = edge[i].to;
        if(_v==fa)continue;
        if(v[_v])continue;
        v[_v]=tt;
        DFS(_v,u);
    }
}
int main()
{
    int i,j,k,u,_v,c,q;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(head,-1,sizeof(head));
        tot=0;
        while(m--)
        {
            scanf("%d%d%d",&u,&_v,&c);
            add(u,_v,c);
            add(_v,u,c);
        }
        scanf("%d",&q);
        for(i=0; i<n; i++)
            v[i]=0;
        tt = 1;
        ll sum =0;
        for(i=0; i<n; i++)
        {
            if(v[i]==0)
            {
                v[i]=tt;
                Num=0;
                DFS(i,-1);
                tt++;
                sum += (ll)Num*(Num-1);
            }
        }
        while(q--)
        {
            scanf("%d",&t);
            ll ans  = sum;
            for(i=0; i<n; i++)
                vis[i]=0;

            for(i=0; i<n; i++)
            {
                if(vis[i]==0)
                {
                    num =0;
                    vis[i]=1;
                    dfs(i,-1);
                    //cout<<i<<" *** "<<num<<endl;
                    ans -= (ll)num*(num-1);
                }

            }
            printf("%I64d\n",ans);
            //cout<<ans<<endl;
        }
    }
}

