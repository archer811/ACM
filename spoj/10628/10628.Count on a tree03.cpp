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
vector<int > edge[V];
vector<pair<int,int> > query[V];
int Find(int a)
{
    if(father[a]==a)return a;
    return father[a]=Find(father[a]);
}
//int sd[maxn],d[maxn],kk;
int a[maxn],id[maxn],s[maxn];
void Union(int a,int b)
{
    int u1=Find(a),u2=Find(b);
    if(u1!=u2)father[u2]=u1;
}
int m;
void init(int n)
{
    for(int i=0; i<=n; i++)
        father[i]=i,num[i]=1,edge[i].clear();
    for(int i=0; i<=m; i++)
        query[i].clear();
}
bool vis[V];
int ans[Q];
void tarjan(int u,int fa)
{
    vis[u]=true;
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
        int v=edge[u][i];
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
} t[maxn*40];

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
        int v = edge[u][i];
        if(v==fa)continue;
       // int tmp = lower_bound(sd+1,sd+1+kk,d[v])-sd;
       int tmp = a[v];
        root[v] = change(root[u],tmp,1);
        dfs(v,u);
    }
}
struct array
{
    int x,y,c;
} ok[Q];
inline bool cmp(int x,int y)
{
    return a[x] < a[y];
}
int main()
{
    int i,j,k;
    int v,b,l,c;
    while(scanf("%d%d",&n,&m)==2)
    {
        init(n+1);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]),id[i]=a[i];
        sort(id+1,id+1+n);
        int fk = unique(id+1,id+1+n)-id;
        for(i=1;i<=n;i++)
        {
            a[i] = lower_bound(id+1,id+fk,a[i])-id;
            //cout<<i<<" "<<a[i]<<endl;
        }
        for(i=1;i<fk;i++)
            s[i]=id[i];
//        for (s[1] = a[id[1]], a[id[1]] = tot = 1, i = 2; i <= n ; ++i)
//            a[id[i]] = s[tot] == a[id[i]] ? tot : (s[tot + 1] = a[id[i]], ++tot);

//        for(i = 1; i <= n; ++i)
//            scanf("%d", &d[i]), sd[i] = d[i];
//        sort(sd + 1, sd + n + 1);
//        kk = unique(sd+1,sd+1+n)-sd;
        tot = 0;
        root[0] =  build(1,i);

        //int tmp  = lower_bound(sd+1,sd+1+kk,d[1])-sd;
        int tmp = a[1];

        root[1] = change(root[0],tmp,1);

        int aa;
        for(i=0; i<n-1; i++)
        {
            scanf("%d%d",&aa,&b);
            edge[aa].push_back(b);
            edge[b].push_back(aa);
        }
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d",&aa,&b,&c);
            ok[i].x = aa;
            ok[i].y = b;
            ok[i].c = c;
            query[aa].push_back(make_pair(b,i));
            query[b].push_back(make_pair(aa,i));
        }
        dfs(1,-1);
        memset(vis,false,sizeof(vis));
        tarjan(1,-1);
        for(i=0; i<m; i++)
        {
           // gg =lower_bound(sd+1,sd+1+kk,d[ans[i]])-sd;
           gg = a[ans[i]];
            printf("%d\n",s[Query(root[ok[i].x],root[ok[i].y],root[ans[i]],ok[i].c)]);
        }
    }
}
