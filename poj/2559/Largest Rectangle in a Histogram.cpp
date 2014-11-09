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
/*
const int maxn = 400005;
int head[maxn],tot;
struct Edge
{
    int to,next;
}edge[maxn];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}*/
const int maxn = 1000006;
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
struct O
{
    int ind,h;
} g[100006];
int cmp(O x,O y)
{
    return x.h>y.h;
}
int fa[100006],siz[100005],vis[100005];
int find(int x)
{
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        for(i=1; i<=n; i++)
        {
            g[i].ind=i;
            scanf("%d",&g[i].h);
            fa[i]=i;
            siz[i]=1;
            vis[i]=0;
        }
        sort(g+1,g+1+n,cmp);
        ll ans=0;
        for(i=1; i<=n; i++)
        {
            //cout<<i<<endl;
            int x = g[i].ind;
            ll y  = g[i].h;
            ll s=1;
            if(x>=2)
            {
                int a = find(x-1);
                if(vis[a])
                    s += siz[a];
            }
            if(x<=n-1)
            {
                int a= find(x+1);
                if(vis[a])
                    s+= siz[a];
            }
            ans = max(ans,s*y);
            vis[x]=1;
            if(x>=2)
            {
                int a = find(x-1);
                if(vis[a])
                {
                    fa[a]=x;
                    siz[x]+=siz[a];
                }

            }
            if(x<=n-1)
            {
                int a = find(x+1);
                if(vis[a])
                {
                    fa[a]=x;
                    siz[x]+=siz[a];
                }

            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
