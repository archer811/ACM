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
int n,m;
const int maxn = 2005;
const int inf = 0x3fffffff;
struct array
{
    int s,e,w;
}g[2005];
int map[maxn][maxn];
int judge(int u,int v)
{
    if(g[u].e>=g[v].s&&g[u].e<=g[v].e)return 1;
    return 0;
}
int dis[maxn],vis[maxn];
void dijstra()
{
    int i,j;
    for(i=0;i<=n;i++)
        dis[i]=inf,vis[i]=0;
    dis[0]=0;
    for(i=0;i<n+1;i++)
    {
        int Max=inf,f=-1;
        for(j=0;j<=n;j++)
        {
            if(vis[j]==0&&dis[j]<Max)
            {
                Max=dis[j];
                f=j;
            }
        }
        if(f==-1)break;
       // cout<<f<<"&"<<endl;
        vis[f]=1;
        for(j=0;j<=n;j++)
        {
            if(vis[j]==0&&dis[j]>dis[f]+map[f][j])
                dis[j]=dis[f]+map[f][j];
        }
    }
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
        {
            scanf("%d%d%d",&g[i].s,&g[i].e,&g[i].w);
        }
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
                map[i][j]=inf;
        }
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                if(judge(i,j))
                    map[i][j]=g[j].w;
            }
        }
//        for(i=0;i<=n;i++)
//        {
//            for(j=0;j<=n;j++)
//            {
//                if(map[i][j]<inf)
//                    cout<<i<<" "<<j<<endl;
//            }
//        }
        map[0][1]=g[1].w;
        dijstra();
        int d;
//        for(i=0;i<=n;i++)
//            cout<<dis[i]<<" "<<i<<endl;
        while(m--)
        {
            scanf("%d",&d);
            if(dis[d]>=inf)puts("-1");
            else printf("%d\n",dis[d]);
        }
    }
}
