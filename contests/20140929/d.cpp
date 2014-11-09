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
int dis[2005][2005];
const int maxn = 2005;
struct array
{
    int x,y,v;
} g[2005*2005];
int cmp(array a,array b)
{
    return a.v<b.v;
}
int _fa[20005];
int find(int x)
{
    if(_fa[x]==x)return x;
    return _fa[x]=find(_fa[x]);
}
struct Edge
{
    int to,next,w;
} edge[maxn*14];
int head[maxn],tot;
void add(int u,int v,int w)
{
    edge[tot].to=v;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int ds[maxn];
int fa[maxn][22];
int d[maxn];
void dfs(int u,int fa2)
{
    fa[u][0]=fa2;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa2)continue;
        ds[v]=ds[u]+edge[i].w;
        d[v]=d[u]+1;
        dfs(v,u);
    }
}

int lca(int x,int y)
{
    if(x==y) return x;
    if(d[x]>d[y]) swap(x,y);
    for(int i=20; i>=0; --i)
        if(d[fa[y][i]]>d[x]) y=fa[y][i];
    if(fa[y][0]==x)
        return x;
    if(d[y]>d[x]) y=fa[y][0];
    for(int i=20; i>=0; --i)
    {
        if(fa[x][i]!=fa[y][i])
        {
            x=fa[x][i];
            y=fa[y][i];
        }
    }
    return fa[x][0];
}


int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1; i<=n; i++)
            _fa[i]=i;
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                scanf("%d",&dis[i][j]);
        int k=0;
        int ans=0;
        for(i=1; i<=n; i++)
        {
            if(dis[i][i]!=0)ans=1;
            for(j=i+1; j<=n; j++)
            {
                if(dis[i][j]!=dis[j][i])
                    ans=1;
                if(dis[i][j]<=0)
                    ans=1;
            }
        }
        if(ans)
        {
            puts("NO");
            continue;
        }
        for(i=1; i<=n; i++)
        {
            for(j=i+1; j<=n; j++)
            {
                g[k].x=i;
                g[k].y=j;
                g[k++].v=dis[i][j];
            }
        }
        sort(g,g+k,cmp);
        memset(head,-1,sizeof(head));
        tot=0;

        for(i=0; i<k; i++)
        {
            int x = find(g[i].x);
            int y = find(g[i].y);
            if(x==y)continue;
            _fa[x]=y;
            x = g[i].x;
            y = g[i].y;
            //cout<<x<<" "<<y<<endl;
            add(x,y,g[i].v);
            add(y,x,g[i].v);
        }
        memset(ds,0,sizeof(ds));
        memset(d,0,sizeof(d));
        memset(fa,0,sizeof(fa));
        dfs(1,0);
        for(i=1; i<=20; ++i)
            for(j=1; j<=n; ++j)
                fa[j][i]=fa[fa[j][i-1]][i-1];



        for(i=1; i<=n&&ans==0; i++)
        {
            for(j=i+1; j<=n&&ans==0; j++)
            {
                int x = lca(i,j);
                if(dis[i][j]!=ds[i]+ds[j]-ds[x]*2)
                {
//                    cout<<i<<" "<<j<<" "<<dis[i][j]<<" "<<
//                    ds[i]<<" "<<ds[j]<<"  "<<ds[x]<<endl;
                    ans=1;
                    break;
                }
            }
        }
        if(ans)puts("NO");
        else puts("YES");
    }
    return 0;
}
