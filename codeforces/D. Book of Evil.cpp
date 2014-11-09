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

const int maxn = 100005;
const int maxm = 400005;
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
int mark[maxn],d[maxn],d2[maxn],id[maxn],ans[maxn];
void dfs(int u,int fa)
{
    if(d[u]==-1&&mark[u])d[u]=0;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v =edge[i].to;
        if(v==fa)continue;
        dfs(v,u);
        if(d[v]!=-1)
        {
            int tmp = d[v]+1;
            if(tmp>d[u])
            {
                d2[u]=d[u];
                d[u]=tmp;
                id[u]=v;
            }
            else if(tmp>d2[u])
            {
                d2[u]=tmp;
            }
        }
    }

}
void DFS(int u,int fa)
{
    if(d2[u]==-1&&mark[u])d2[u]=0;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa)continue;
        int tp=-1;
        if(id[u]!=v)
        {
            if(d[u]!=-1)
                tp= max(tp,d[u]+1);
        }
        else
        {
            if(d2[u]!=-1)
                tp = max(tp,d2[u]+1);
        }
        int tmp = tp;
        if(tmp>d[v])
        {
            d2[v]=d[v];
            d[v]=tmp;
            id[v]=u;
        }
        else if(tmp>d2[v])
        {
            d2[v]=tmp;
        }

        DFS(v,u);

    }
}
int main()
{
    int i,j,n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        memset(head,-1,sizeof(head));
        tot=0;
        memset(mark,0,sizeof(mark));
        for(i=0; i<m; i++)
        {
            scanf("%d",&j);
            mark[j]=1;
        }
        for(i=1; i<n; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            add(x,y);
            add(y,x);
        }
        memset(d,-1,sizeof(d));
        memset(d2,-1,sizeof(d2));
        memset(id,-1,sizeof(id));
        dfs(1,-1);
        j=1;
        for(i=1; i<=n; i++)
        {
            if(d[i]>d[j])j=i;
        }
        //cout<<j<<"()"<<endl;
        DFS(j,-1);
        int sum=0;
        for(i=1; i<=n; i++)
        {
            //cout<<i<<" "<<d[i]<<" "<<d2[i]<<endl;
            if(d[i]<=k)sum++;
        }
        cout<<sum<<endl;
    }
    return 0;
}

