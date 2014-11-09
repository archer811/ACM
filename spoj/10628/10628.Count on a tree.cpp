#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 200010;
const int V=maxn,E=maxn,Q=maxn;
int father[maxn],num[maxn];
int kk;
int Find(int a)
{
    if(father[a]==a)return a;
    return father[a]=Find(father[a]);
}
void Union(int a,int b)
{
    int u1=Find(a),u2=Find(b);
    if(u1!=u2)father[u2]=u1;
}
void init(int n)
{
    for(int i=0;i<=n;i++)
        father[i]=i,num[i]=1;
}
bool vis[V];
int ans[Q];
vector<pair<int,int> > edge[V];
vector<pair<int,int> > query[V];
void tarjan(int u,int fa)
{
    vis[u]=1;
    for(int i=0; i<query[u].size(); i++)
    {
        int v=query[u][i].first;
        if(vis[v])
        {
            ans[query[u][i].second]=Find(v);
        }
    }
    for(int i=0; i<edge[u].size(); i++)
    {
        int v=edge[u][i].first;
        if(v==fa)continue;
        tarjan(v,u);
        Union(u,v);
    }
}
struct tree
{
    int sum;
    int l,r;
    int ls,rs;
} t[maxn*400];
int d[maxn],sd[maxn];
int tot,root[maxn],n;
int build(int l,int r)
{
    int k = ++tot;
    t[k].l = l;
    t[k].r = r;
    t[k].sum =0;
    if(l==r)return k;
    int mid = (l+r)>>1;
    t[k].ls = build(l,mid);
    t[k].rs = build(mid+1,r);
    return k;
}
int change(int o,int x,int v)
{
    int k = ++tot;
    t[k] = t[o];
    t[k].sum += v;
    if(t[o].l == x&&t[o].r == x)return k;
    int mid = (t[o].l+t[o].r)>>1;
    if(x<=mid)t[k].ls = change(t[o].ls,x,v);
    else t[k].rs = change(t[o].rs,x,v);
    return k;
}
int gg;
int Query(int a,int b,int c,int k)
{
    if(t[a].l==t[a].r)return t[a].l;
    int mid = (t[a].l+t[a].r)/2;
    int tmp = (gg>=t[a].l&&gg<=mid)?1:0;
    int res = t[t[a].ls].sum+t[t[b].ls].sum-2*t[t[c].ls].sum+tmp;
    if(k <= res)
        return Query(t[a].ls,t[b].ls,t[c].ls,k);
    else return Query(t[a].rs,t[b].rs,t[c].rs,k-res);
}
void dfs(int u,int fa)
{
    for(int i=0; i<edge[u].size(); i++)
    {
        int v = edge[u][i].first;
        if(v==fa)continue;
        int tmp = lower_bound(sd+1,sd+1+kk,d[v])-sd;
        //cout<<v<<"$$"<<tmp<<" "<<root[u]<<endl;
        root[v] = change(root[u],tmp,1);
        //cout<<endl;
        // cout<<v<<" +++ "<<t[root[v]].sum<<" "<<root[v]<<endl;
        dfs(v,u);
    }
}
struct array
{
    int x,y,c;
} ok[Q];
int main()
{
    int m,i,j,k;
    int v,a,b,l,c;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init(n+1);
        for(i=1; i<=n; i++)
            scanf("%d",&d[i]),sd[i]=d[i];
        sort(sd+1,sd+1+n);
        for(i=1,j=2; j<=n; j++)
            if(sd[j]!=sd[i])
                sd[++i]=sd[j];
        kk = i;
        tot = 0;
        root[0] =  build(1,i);

        int tmp  = lower_bound(sd+1,sd+1+kk,d[1])-sd;

        root[1] = change(root[0],tmp,1);


        for(i=0; i<n-1; i++)
        {
            scanf("%d%d",&a,&b);
            edge[a].push_back(make_pair(b,1));
            edge[b].push_back(make_pair(a,1));
        }
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            ok[i].x = a;
            ok[i].y = b;
            ok[i].c = c;
            query[a].push_back(make_pair(b,i));
            query[b].push_back(make_pair(a,i));
        }
        dfs(1,-1);
        for(i=1; i<=n; i++)
            vis[i]=false;
        tarjan(1,-1);
//        for(i=1;i<=n;i++)
//            cout<<i<<" "<<_fa[i]<<endl;
        for(i=0; i<m; i++)
        {
            //cout<<ok[i].x<<" "<<ok[i].y << " "<<ok[i].c<<" "<<
            //ans[i]<<" "<<_fa[ans[i]]<<endl;

            gg = lower_bound(sd+1,sd+1+n,d[ans[i]])-sd;
            //cout<<ok[i].x<< " "<<ok[i].y<< " "<<ans[i]<< " "<<gg<<endl;
            printf("%d\n",sd[Query(root[ok[i].x],root[ok[i].y],root[ans[i]],ok[i].c)]);
        }
    }
}
