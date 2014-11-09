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
    int to,next,w;
}edge[maxm];
void add(int u,int v,int w)
{
    edge[tot].to=v;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot++;
}
ll d[maxn][2];
int mark[maxn];
const ll inf = ((ll)1)<<40;
//d[u][0] 表示u以下0个点要分割 最少花费
void dfs(int u,int fa)
{
    int i,j;
    d[u][0]=d[u][1]=inf;
    ll tmp=0;
    ll dd=0;
    int flag=0;
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa)continue;
        flag=1;
        dfs(v,u);
       //cout<<u<<"()"<<v<<" "<<d[v][0]<<" "<<d[v][1]+edge[i].w<<endl;
        tmp += min(d[v][0],d[v][1]+edge[i].w);
        dd = max(dd,min(d[v][0],d[v][1]+edge[i].w));
    }
    if(flag==0)
    {
        if(mark[u])
        {
            d[u][0]=inf;d[u][1]=0;
        }
        else
        {
            d[u][0]=0;
            d[u][1]=0;
        }
        return;
    }
    if(mark[u])
    {
       // cout<<u<<"*"<<tmp<<endl;
        d[u][1]=min(d[u][1],tmp);
        d[u][0]=inf;
    }
    else
    {
        d[u][0]=min(d[u][0],tmp);

        for(i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].to;
            if(v==fa)continue;
            d[u][1]=min(d[u][1],tmp-min(d[v][0],d[v][1]+edge[i].w)+d[v][1]);
        }
    }
}
int main()
{
    int i,j,t,n,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        memset(head,-1,sizeof(head));
        tot=0;
        memset(mark,0,sizeof(mark));
        for(i=1;i<n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            add(x,y,z);
            add(y,x,z);
        }
        for(i=0;i<k;i++)
        {
            scanf("%d",&j);
            mark[j]=1;
        }
        dfs(0,-1);
        ll ans;
        ans=min(d[0][0],d[0][1]);
        printf("%I64d\n",ans);
    }
    return 0;
}

