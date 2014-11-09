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
#pragma comment(linker, "/STACK:102400000,102400000")
#ifdef __int64
typedef __int64 ll;
#else
typedef long long ll;
#endif
const int maxn = 200005;
const int maxm = 200005;
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
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
int fa[maxn][22],d[maxn];
void dfs(int u,int f)
{
    fa[u][0]=f;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==f)continue;
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
char s[6];
int ans1[maxn],ans2[maxn],des[maxn];
int Dfs(int u,int f)
{
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==f)continue;
        ans1[u] += Dfs(v,u);
        ans2[u]+=ans2[v];
    }
    return ans1[u]-des[u];
}
struct input
{
    int x,y;
}o[maxn];
inline int readint()
{
    char c = getchar();
    while(!isdigit(c))c = getchar();
    int x=0;
    while(isdigit(c))
    {
        x = x*10+c-'0';
        c = getchar();
    }
    return x;
}
int main()
{
    int i,j,t,n,m;
    t = readint();
    int cas=0;
    while(t--)
    {
        n = readint();
        m = readint();
        memset(head,-1,sizeof(head));
        for(i=1;i<=n;i++)
            ans1[i]=ans2[i]=des[i]=0;
        tot=0;
        memset(fa,0,sizeof(fa));
        for(i=1; i<n; i++)
        {
            int a,b;
            a = readint();b=readint();
            o[i].x=a;
            o[i].y=b;
            add(a,b);
            add(b,a);
        }
        d[1]=0;
        dfs(1,-1);
        for(i=1; i<=20; ++i)
            for(j=1; j<=n; ++j)
                fa[j][i]=fa[fa[j][i-1]][i-1];
        while(m--)
        {
            int u,v,k;
            scanf("%s",s);
            u = readint();
            v = readint();
            k = readint();
            if(s[3]=='1')
            {
                int w = lca(u,v);
                des[w]+=k;
                ans1[u]+=k;
                ans1[v]+=k;
                ans1[w]-=k;
            }
            else
            {
                int w = lca(u,v);
                ans2[w]-=k*2;
                ans2[u]+=k;
                ans2[v]+=k;
            }
        }

        Dfs(1,-1);
        printf("Case #%d:\n",++cas);
        for(i=1;i<=n;i++)
        {
            if(i==1)printf("%d",ans1[i]);
            else printf(" %d",ans1[i]);
        }
        puts("");

        for(i=1;i<n;i++)
        {
            if(d[o[i].x]<d[o[i].y])swap(o[i].x,o[i].y);
            if(i==1)printf("%d",ans2[o[i].x]);
            else printf(" %d",ans2[o[i].x]);
        }
        puts("");
    }
    return 0;
}
