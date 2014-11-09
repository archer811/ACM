#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 400000;
struct tree
{
    int l,r;
    int ls,rs;
    int sum;
}t[maxn*20];
int d[maxn],ds[maxn],id[maxn];
vector<int>edge[maxn];
vector<pair<int,int> >q[101000];
int root[maxn];
int n,m,tot,fa[maxn];
int build(int l,int r)
{
    int k = ++tot;
    t[k].l = l;
    t[k].r = r;
    t[k].sum = 0;
    if(l==r)return k;
    int mid = (l+r)>>1;
    t[k].ls = build(l,mid);
    t[k].rs = build(mid+1,r);
    return k;
}
bool v[maxn];
int change(int o,int x,int v)
{
    int k = ++tot;
    t[k] = t[o];
    t[k].sum += v;
    if(t[o].l == t[o].r)return k;
    int mid = (t[o].l+t[o].r)>>1;
    if(x<=mid)
        t[o].ls = change(t[o].ls,x,v);
    else t[o].rs = change(t[o].rs,x,v);
    return k;
}
void dfs(int u,int _fa)
{
    v[id[u]]=true;
    for(int i=0;i<edge[u].size();i++)
    {
        int _v = edge[u][i];
        if(_v==_fa)continue;
        fa[_v]=u;
        if(v[id[_v]])
            root[_v] = change(root[u],id[_v],0);
        else
            root[_v] = change(root[u],id[_v],1);
        v[id[_v]]=true;
        dfs(_v,u);
        v[id[_v]]=false;
    }
}
bool vis[maxn],f[maxn];
int ans[101000];
int find(int x)
{
    if(f[x]==x)return x;
    return f[x] = find(f[x]);
}
void unin(int a,int b)
{
    int x = find(a), y = find(b);
    if(x!=y)f[y]=x;
}
void tarjan(int u,int fa)
{
    vis[u]=true;
    for(int i=0;i<q[u].size();i++)
    {
        int v = q[u][i].first;
        if(vis[v])
            ans[q[u][i].second] = find(v);
    }
    for(int i=0;i<edge[u].size();i++)
    {
        int v = edge[u][i];
        if(v==fa)continue;
        tarjan(v,u);
        unin(u,v);
    }
}
struct array
{
    int x,y;
}Q[101000];
int main()
{
    int i,j,k,a,b;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%d",&d[i]),ds[i]=d[i],f[i]=i;
        sort(ds+1,ds+1+n);
        for(i=1;i<=n;i++)
            edge[i].clear();
        for(i=0;i<m;i++)
            q[i].clear();
        k = unique(ds,ds+1+n)-ds;
        for(i=1;i<=n;i++)
        {
            id[i] = lower_bound(ds+1,ds+k,d[i])-ds;
        }
        tot = 0;
        root[0] = build(1,k-1);
        int tmp  =id[1];
        root[1] = change(root[0],tmp,1);
        for(i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            Q[i].x = a;Q[i].y = b;
            q[a].push_back(make_pair(b,i));
            q[b].push_back(make_pair(a,i));
        }
        fa[1]=0;
        memset(vis,false,sizeof(vis));
        memset(v,false,sizeof(v));
        dfs(1,-1);
        tarjan(1,-1);
        //for(i=1;i<=n;i++)
        for(i=0;i<m;i++)
        {
            //cout<<i<<" "<<ans[i]<<endl;
            printf("%d\n",t[root[Q[i].x]].sum+t[root[Q[i].y]].sum-t[root[ans[i]]].sum-t[root[fa[ans[i]]]].sum);
            //cout<<<<endl;
        }
    }
}
