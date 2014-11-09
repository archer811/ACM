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
const int maxn = 150;
int v[maxn],head[maxn],tot;
struct array
{
    int to,next,t;
} edge[maxn*4];
void add(int u,int v,int t)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    edge[tot].t=t;
    head[u]=tot++;
}
int d[maxn][300];
int m;
void dfs(int u,int fa)
{
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v2 = edge[i].to;
        if(v2==fa)continue;
        dfs(v2,u);
        for(int j=m;j>=2*edge[i].t;j--)
        {
            //for(int s=0;s<=j-2*edge[i].t;s++)
            for(int s=j-2*edge[i].t;s>=0;s--)
            {
                d[u][j]=max(d[u][j],d[u][j-2*edge[i].t-s]+d[v2][s]);
            }
        }
    }
    for(int j=m; j>=0; j--)
    {
        if(d[u][j]!=-1)
            d[u][j]=d[u][j]+v[u];
       //cout<<u<<" "<<j<<"  "<<d[u][j]<<endl;
    }
}
int main()
{
    int i,j,n,k;
    while(scanf("%d",&n)!=EOF)
    {
        tot=0;
        memset(head,-1,sizeof(head));
        for(i=1; i<=n; i++)
            scanf("%d",&v[i]);
        int a,b,t;
        for(i=0; i<n-1; i++)
        {
            scanf("%d%d%d",&a,&b,&t);
            add(a,b,t);
            add(b,a,t);
        }
        memset(d,0,sizeof(d));
        for(i=1; i<=n; i++)
            d[i][0]=0;
        scanf("%d%d",&k,&m);
        dfs(k,-1);
        int ans=0;
        for(j=m; j>=0; j--)
            ans=max(ans,d[k][j]);
        printf("%d\n",ans);
    }
    return 0;
}
