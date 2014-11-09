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
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
int v[maxn],son[maxn];
void dfs(int u,int fa)
{
    int i,j;
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa)continue;
        dfs(v,u);
        son[u]+=son[v];
        //cout<<u<<"  "<<v<<"   "<<son[v]<<endl;
    }
    son[u]+=v[u];
}
const ll mod=  1000000007 ;
ll ant=0;
ll ans[maxn],sum[maxn],w[maxn];
ll dfs2(int u,int fa)
{
     int i,j;
    ans[u]=0;
    sum[u]=0;
    w[u]=0;
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa)continue;
        if(son[v]==0)continue;
        ans[v] = dfs2(v,u);
        sum[u]+=ans[v];
    }
    ll tmp=0;
    int f=0;
    ll tmp2=1;
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa)continue;
        if(son[v]==0)continue;
        f++;
        tmp += ans[v]*(sum[u]-ans[v]);
        tmp2 = tmp2*(w[v]);
        //if(u==0)
        cout<<u<<" "<<v<<"  "<<ans[v]<<"  "<<sum[u]<<" "<<tmp<<"   "<<w[v]<<
        "  "<<tmp2<<endl;
    }
    //cout<<u<<"()"<<sum[u]<<" "<<tmp<<endl;

    if(v[u])w[u]=1;
    else w[u]=tmp2+1;

    if(v[u])
    {
        if(f==1)ans[u]=tmp2;
        else
        ans[u]=tmp2;
    }
    else if(v[u]==0)
    {
        if(f==1)ans[u]=sum[u];
        else ans[u]=tmp+1;
    }


    return ans[u];
}
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(head,-1,sizeof(head));
        tot=0;
        memset(son,0,sizeof(son));
        for(i=1;i<n;i++)
        {
            scanf("%d",&j);
            add(j,i);
            add(i,j);
        }
        for(i=0;i<n;i++)
            scanf("%d",&v[i]);
        dfs(0,-1);
        ant = dfs2(0,-1);
        printf("%I64d\n",ant);
    }
    return 0;
}
