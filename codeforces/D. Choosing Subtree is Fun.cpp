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
}
int f[100005][22];
int cnt[100005];
int G,id[100005],dep[100005];
void dfs(int u,int fa)
{
    f[u][0]=u;
    cnt[u]=G++;
    id[cnt[u]]=u;
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa)continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
    }
}
set<int>S;
int num=0;
int k;
void modify(int op,int u)
{
    set<int>::iterator it = S.lower_bound(cnt[u]);
    if(*it == cnt[u])
    {
        S.erase(it);
        it = lower_bound(cnt[u]);
    }
    if(!S.size())
    {
        if(op==1)S.insert(cnt[u]);
        return;
    }
    int pre,next;
    if(it==S.begin())

}
int ok(int M)
{
    sum=0;
    S.clear();
    int i,j;
    for(i=1;i<=M-1;i++)
        modify(1,i);
    for(;i<=n;i++)
    {
        modify(1,i);
        if(sum+1<=k)return 1;
        modify(0,i+1-M);
    }
    return 0;
}
int main()
{
    int i,j,n;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        memset(head,-1,sizeof(head));
        tot=0;
        for(i=1;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b);
            add(b,a);
        }
        G=0;
        dep[1]=0;
        dfs(1,0);
        for(i=1;i<20;i++)
        {
            for(j=1;j<=n;j++)
                f[j][i]=f[f[j][i-1]][i-1];
        }
        int l = 1, r = n;
        while(l<r)
        {
            int mid = (l+r)>>1;
            if(ok(mid)==0)r=mid;
            else l=mid+1;
        }
        printf("%d\n",l-1);
    }
    return 0;
}
