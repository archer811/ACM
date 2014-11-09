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

const int maxn = 100005;
vector<int>v[maxn];
struct array
{
    int kind,x,y;
} g[maxn];
int fa[maxn],pre[100005][22],d[maxn];
int lca(int x,int y)
{
    if(x==y) return x;
    if(d[x]>d[y]) swap(x,y);
    for(int i=20;i>=0;--i)
      if(d[pre[y][i]]>d[x]) y=pre[y][i];
    if(pre[y][0]==x)
       return x;
    if(d[y]>d[x]) y=pre[y][0];
    for(int i=20;i>=0;--i)
    {
        if(pre[x][i]!=pre[y][i])
        {
            x=pre[x][i];
            y=pre[y][i];
        }
    }
    return pre[x][0];
}
void dfs(int u)
{
    for(int i=0;i<v[u].size();i++)
    {
        int v2 = v[u][i];
        d[v2]=d[u]+1;
        dfs(v2);
    }
}
int mark[maxn];
int find(int x)
{
    if(x==fa[x])return x;
    return fa[x]=find(fa[x]);
}
int id[maxn];
void add2(int x,int y)
{
    int a = find(x),b = find(y);
    if(a!=b)
        fa[a]=b;
}
struct oo
{
    int x,y;
}s[maxn];
int judge(int x,int y)
{
    int a = find(x),b = find(y);
    return a==b;
}
int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(pre,0,sizeof(pre));
        memset(d,0,sizeof(d));
        memset(mark,0,sizeof(mark));
        memset(id,0,sizeof(id));
        for(i=1; i<=n; i++)
            fa[i]=i,v[i].clear();
        for(i=0; i<m; i++)
        {
            scanf("%d",&g[i].kind);
            if(g[i].kind==2)
                scanf("%d",&g[i].x);
            else
            {
                scanf("%d%d",&g[i].x,&g[i].y);
                if(g[i].kind==1)
                {
                    pre[g[i].x][0]=g[i].y;
                    //cout<<pre[g[i].x][0]<<endl;
                    v[g[i].y].push_back(g[i].x);
                    //id[g[i].y]=i;
                }
            }

        }
        for(i=1; i<=20; ++i)
            for(j=1; j<=n; ++j)
                pre[j][i]=pre[pre[j][i-1]][i-1];
        int x,y;
        for(i=1;i<=n;i++)
        {
            //cout<<i<<"()"<<pre[i][0]<<endl;
            if(pre[i][0]==0)dfs(i);
        }
        int ft=1;
        for(i=0;i<m;i++)
        {
            if(g[i].kind==1)
            {
                add2(g[i].x,g[i].y);
                id[g[i].y]=i;
            }
            else if(g[i].kind==2)
            {
                mark[g[i].x]=1;
                s[ft].x=g[i].x;
                s[ft++].y=i;
            }
            else
            {
                if(judge(g[i].x,s[g[i].y].x)==0)
                {
                    puts("NO");
                }
                else
                {
                    if(mark[ s[g[i].y].x ]==0)
                    {
                        puts("NO");
                    }
                    else
                    {
                        int Lca = lca(g[i].x,s[g[i].y].x);
                        if(Lca==g[i].x && s[g[i].y].y>=id[g[i].x])
                            puts("YES");
                        else
                        {
//                            cout<<Lca<<"*"<<g[i].x<<" "<<s[g[i].y].y<<
//                            "  "<<id[g[i].x]<<endl;
                            puts("NO");
                        }

                    }
                }
            }
        }
    }
    return 0;
}
