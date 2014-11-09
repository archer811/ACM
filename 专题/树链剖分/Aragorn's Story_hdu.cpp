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

const int maxn = 50005;
const int maxm = 100005;
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
int value[maxn];
int fa[maxn],top[maxn],dep[maxn],siz[maxn],son[maxn];
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
int idx,w[maxn];
void build(int u,int tp)
{
    top[u]=tp;
    w[u]=idx++;
    if(son[u]!=0)
        build(son[u],tp);
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v  =edge[i].to;
        if(v==fa[u]||v==son[u])continue;
        build(v,v);
    }
}
int mp[maxn];
int lazy[maxn<<2],tree[maxn<<2];
#define lson rt<<1
#define rson rt<<1|1
void maketree(int l,int r,int rt)
{
    lazy[rt]=tree[rt]=0;
    if(l==r)
    {
        tree[rt]=mp[l];
        return;
    }
    int mid = (l+r)>>1;
    maketree(l,mid,lson);
    maketree(mid+1,r,rson);
}
void down(int l,int r,int mid,int rt)
{
    if(lazy[rt])
    {
        lazy[lson]+=lazy[rt];
        lazy[rson]+=lazy[rt];
        tree[lson]+=(mid-l+1)*lazy[rt];
        tree[rson]+=(r-mid)*lazy[rt];
        lazy[rt]=0;
    }
}
void update(int x,int y,int c,int l,int r,int rt)
{
    if(x<=l&&y>=r)
    {
        lazy[rt] += c;
        tree[rt] += (r-l+1)*c;
        return;
    }
    int mid = (l+r)>>1;
    down(l,r,mid,rt);
    if(x<=mid)
        update(x,y,c,l,mid,lson);
    if(y>mid)
        update(x,y,c,mid+1,r,rson);
}
char s[2];
void fun(int a,int b,int c)
{
    int f1 = top[a];
    int f2 = top[b];
    while(f1!=f2)
    {
        if(dep[f1]<dep[f2])
        {
            swap(f1,f2);
            swap(a,b);
        }
        update(w[f1],w[a],c,1,idx-1,1);
        a=fa[f1];
        f1=top[a];
    }
    if(dep[a]<dep[b])swap(a,b);
    update(w[b],w[a],c,1,idx-1,1);
}
int query(int x,int l,int r,int rt)
{
    if(l==r)return tree[rt];
    int mid = (l+r)>>1;
    down(l,r,mid,rt);
    if(x<=mid)return query(x,l,mid,lson);
    else return query(x,mid+1,r,rson);
}
int main()
{
    int i,j,n,m,p;
    while(scanf("%d%d%d",&n,&m,&p)!=EOF)
    {
        memset(head,-1,sizeof(head));
        tot=0;
        for(i=1;i<=n;i++)
            scanf("%d",&value[i]);
        for(i=1;i<=m;i++)
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
        {
            mp[w[i]]=value[i];
        }
        maketree(1,idx-1,1);
        while(p--)
        {
            int a,b,c;
            scanf("%s",s);
            if(s[0]=='Q')
            {
                scanf("%d",&a);
                printf("%d\n",query(w[a],1,idx-1,1));
            }
            else
            {
                scanf("%d%d%d",&a,&b,&c);
                if(s[0]=='D')
                    c=-c;
                fun(a,b,c);
            }
        }
    }
    return 0;
}
