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

const int maxn = 100005;
const int maxm = 200005;
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
int value[maxn],mp[maxn];
int w[maxn],top[maxn],siz[maxn],son[maxn],fa[maxn],dep[maxn];
void dfs(int u,int fa2)
{
    fa[u]=fa2;
    siz[u]=1;
    son[u]=0;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa2)continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
        siz[u]+=siz[v];
        if(siz[v]>siz[son[u]])
            son[u]=v;
    }
}
int idx;
void build(int u,int tp)
{
    w[u]=idx++;
    top[u]=tp;
    if(son[u]!=0)
        build(son[u],tp);
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa[u]||v==son[u])continue;
        build(v,v);
    }
}
int tree[maxn<<2],L[maxn<<2],R[maxn<<2],sum[maxn<<2];
int lazy[maxn<<2];
const int inf = 0x3fffffff;
#define lson rt<<1
#define rson rt<<1|1
void up(int l,int r,int mid,int rt)
{
    sum[rt]=sum[lson]+sum[rson];
    tree[rt]=max(tree[lson],tree[rson]);
    tree[rt]=max(tree[rt],R[lson]+L[rson]);
    L[rt]=max(L[lson],sum[lson]+L[rson]);
    R[rt]=max(R[rson],sum[rson]+R[lson]);
}
void down(int l,int r,int mid,int rt)
{
    if(lazy[rt]!=inf)
    {
        lazy[lson]=lazy[rson]=lazy[rt];
        L[lson]=R[lson]=tree[lson]=lazy[rt]*(mid-l+1);
        R[rson]=L[rson]=tree[rson]=lazy[rt]*(r-mid);
        sum[lson]=lazy[rt]*(mid-l+1);
        sum[rson]=lazy[rt]*(r-mid);
        lazy[rt]=inf;
    }
}
void maketree(int l,int r,int rt)
{
    tree[rt]=L[rt]=R[rt]=sum[rt]=0;
    lazy[rt]=inf;
    if(l==r)
    {
        tree[rt]=L[rt]=R[rt]=sum[rt]=mp[l];
        return;
    }
    int mid = (l+r)>>1;
    maketree(l,mid,lson);
    maketree(mid+1,r,rson);
    up(l,r,mid,rt);
}

int querysum(int x,int y,int l,int r,int rt)
{
    if(x<=l&&y>=r)
    {
        return sum[rt];
    }
    int mid = (l+r)>>1;
    down(l,r,mid,rt);
    if(y<=mid)return querysum(x,y,l,mid,lson);
    if(x>mid)return querysum(x,y,mid+1,r,rson);
    return querysum(x,y,l,mid,lson)+querysum(x,y,mid+1,r,rson);
}
int queryl(int x,int y,int l,int r,int rt)
{
    if(x<=l&&y>=r)
    {
        return L[rt];
    }
    int mid = (l+r)>>1;
    down(l,r,mid,rt);
    if(y<=mid)return queryl(x,y,l,mid,lson);
    if(x>mid)return queryl(x,y,mid+1,r,rson);
    int res = queryl(x,y,l,mid,lson);
    res = max(res,querysum(x,y,l,mid,lson)+queryl(x,y,mid+1,r,rson));
    return res;
}
int queryr(int x,int y,int l,int r,int rt)
{
    if(x<=l&&y>=r)
    {
        return R[rt];
    }
    int mid = (l+r)>>1;
    down(l,r,mid,rt);
    if(y<=mid)return queryr(x,y,l,mid,lson);
    if(x>mid)return queryr(x,y,mid+1,r,rson);
    int res = queryr(x,y,mid+1,r,rson);
    res = max(res,queryr(x,y,l,mid,lson)+querysum(x,y,mid+1,r,rson));
    return res;
}
int query(int x,int y,int l,int r,int rt)
{
    if(x<=l&&y>=r)
    {
        return tree[rt];
    }
    int mid = (l+r)>>1;
    down(l,r,mid,rt);
    if(y<=mid)return query(x,y,l,mid,lson);
    if(x>mid)return query(x,y,mid+1,r,rson);
    int res = max(query(x,y,l,mid,lson),query(x,y,mid+1,r,rson));
    res = max(res,queryr(x,y,l,mid,lson)+queryl(x,y,mid+1,r,rson));
    return res;
}
int query(int a,int b)
{
    int f1=top[a],f2=top[b];
    int lmax=0,rmax=0;
    int ans=0;
    while(f1!=f2)
    {
        if(dep[f1]<dep[f2])
        {
            swap(a,b);
            swap(f1,f2);
            swap(lmax,rmax);
        }
        ans = max(ans,query(w[f1],w[a],1,idx-1,1));
        ans = max(ans,lmax+max(0,queryr(w[f1],w[a],1,idx-1,1)));
        lmax = max(max(0,queryl(w[f1],w[a],1,idx-1,1)),
                   lmax+querysum(w[f1],w[a],1,idx-1,1));
        a = fa[f1];
        f1 = top[a];
    }
    if(dep[a]>dep[b])
    {
        swap(a,b);
        swap(lmax,rmax);
    }
    ans = max(ans,query(w[a],w[b],1,idx-1,1));
    ans = max(ans,lmax+max(0,queryl(w[a],w[b],1,idx-1,1)));
    ans = max(ans,rmax+max(0,queryr(w[a],w[b],1,idx-1,1)));
    ans = max(ans,lmax+querysum(w[a],w[b],1,idx-1,1)+rmax);

    return ans;
}
void update(int x,int y,int c,int l,int r,int rt)
{
    if(x<=l&&y>=r)
    {
        L[rt]=R[rt]=tree[rt]=sum[rt]=c*(r-l+1);
        lazy[rt]=c;
        return;
    }
    int mid = (l+r)>>1;
    down(l,r,mid,rt);
    if(x<=mid)
        update(x,y,c,l,mid,lson);
    if(y>mid)
        update(x,y,c,mid+1,r,rson);
    up(l,r,mid,rt);
}
void update(int a,int b,int c)
{
    int f1=top[a],f2=top[b];
    while(f1!=f2)
    {
        if(dep[f1]<dep[f2])
        {
            swap(f1,f2);
            swap(a,b);
        }
        //cout<<w[f1]<<"*"<<w[a]<<endl;
        update(w[f1],w[a],c,1,idx-1,1);
        a = fa[f1];
        f1 = top[a];
    }
    if(dep[a]>dep[b])
        swap(a,b);
    //cout<<w[a]<<" * "<<w[b]<<endl;
    update(w[a],w[b],c,1,idx-1,1);
}
void output(int l,int r,int rt)
{
    if(l==r)
    {
        cout<<l<<"()"<<tree[rt]<<endl;
        return;
    }
    int mid = (l+r)>>1;
    down(l,r,mid,rt);
    output(l,mid,lson);
    output(mid+1,r,rson);
}
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(head,-1,sizeof(head));
        tot=0;
        for(i=1;i<=n;i++)
            scanf("%d",&value[i]);
        for(i=1;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b);
            add(b,a);
        }
        dep[1]=0;
        dfs(1,-1);
        idx=1;
        build(1,1);
        for(i=1;i<=n;i++)
            mp[w[i]]=value[i];
        maketree(1,idx-1,1);
//        for(i=1;i<=n;i++)
//            cout<<i<<" "<<w[i]<<endl;
        int m;
        scanf("%d",&m);
        while(m--)
        {
            int d,a,b,c;
            scanf("%d",&d);
            if(d==1)
            {
                scanf("%d%d",&a,&b);
                printf("%d\n",query(a,b));
            }
            else
            {
                scanf("%d%d%d",&a,&b,&c);
                update(a,b,c);
                //output(1,idx-1,1);
            }
        }
    }
    return 0;
}


