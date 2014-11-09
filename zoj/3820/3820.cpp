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

const int maxn = 200005;
const int maxm = 400005;
int head[maxn],tot;
struct Edge
{
    int to,next;
}edge[maxm];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int d[maxn],Max[maxn];
void dfs(int u,int fa)
{
    Max[u]=0;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa)continue;
        d[v]=d[u]+1;
        dfs(v,u);
        Max[u]=max(Max[v]+1,Max[u]);
    }
}
int b[maxn],k;
void DFS(int u,int fa,int mid)
{
    if(Max[u]<=mid)
    {
        b[k++]=u;return;
    }
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa)continue;
        DFS(v,u,mid);
    }
}
int ansa,ansb;
int check(int mid)
{
    k=0;
    DFS(1,-1,mid);
    if(k>=3)return 0;
    if(k==2)
    {
        int g = min(d[b[0]],d[b[1]]);
        for(i=head[1];i!=-1;i=edge[i].next)
        {
            int v = edge[i].to;
            if(Max[v]==Max[b[0]]||Max[v]==Max[b[1]])continue;
            if(d[v]+g>mid)return 0;
        }
        ansa=b[0];
        ansb=b[1];
        return 1;
    }
    else if(k==1)
    {
        int g = d[b[0]];
        if(g>mid)return 0;
        int sum=0;
        int flag=-1;
        for(i=head[1];i!=-1;i=edge[i].next)
        {
            int v = edge[i].to;
            if(Max[v]==Max[b[0]])continue;
            if(d[v]+g>mid)
            {
                flag=v;sum++;
            }
        }
        if(sum>=2)return 0;
        ansa=b[0];
    }
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        memset(head,-1,sizeof(head));
        tot=0;
        for(i=1;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            add(x,y);
            add(y,x);
        }
        d[1]=0;
        dfs(1,-1);
        int l=0,r=n;
        while(l<r)
        {
            int mid = (l+r)>>1;
            if(check(mid))r=mid;
            else l=mid+1;
        }
        printf("%d\n",l);
    }
    return 0;
}
