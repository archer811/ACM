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
const int M = 1<<16;
double f[16][M];
int vis[16][M];
const int maxn = 100005;
struct Edge
{
    int to,next,w;
}edge[maxn<<2];
int head[16],tot,Y;
void add(int u,int  v,int w)
{
    edge[tot].to=v;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int dfs(int u,int st)
{
    if(st==Y)
    {
        f[u][st]=0;
        return 1;
    }
    if(vis[u][st])return f[u][st]>1e-8;
    vis[u][st]=1;
    int cnt=0;
    f[u][st]=5.0;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(st&(1<<v))continue;

        int p = st|(1<<v);
        if(!dfs(v,p))continue;
        double tmp = f[v][p];
        //printf("%.10f %d %d\n",tmp,v,p);
        f[u][st]+=tmp+edge[i].w;
        cnt++;
    }
    if(cnt==0)
    {
        f[u][st]=0;
        vis[u][st]=1;
        return 0;
    }
    f[u][st]/=((cnt)*1.0);
    return f[u][st];
}
int main()
{
    int i,j,t,n,m;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        Y = (1<<n)-1;
        memset(head,-1,sizeof(head));
        tot=0;
        for(i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
            add(b,a,c);
        }
        memset(vis,0,sizeof(vis));
        dfs(0,1);
        printf("Case %d: ",++cas);
        printf("%.6f\n",f[0][1]);
    }
    return 0;
}
