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

const int maxn = 10005;
const int maxm = 20005;
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
struct input
{
    int x,y,c;
}g[maxn];
#define lson rt<<1
#define rson rt<<1|1
char s[10];
int siz[maxn],son[maxn],fa[maxn],w[maxn],top[maxn],dep[maxn];
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
int ind;
void build(int u,int tp)
{
    top[u]=tp;
    w[u]=ind++;
    if(son[u]!=0)
        build(son[u],tp);
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa[u])continue;
        if(v==son[u])continue;
        build(v,v);
    }
}
int tree[maxn<<2];
void up(int l,int r,int mid,int rt)
{
    tree[rt]=max(tree[lson],tree[rson]);
}
void update(int x,int c,int l,int r,int rt)
{
    if(l==r)
    {
        tree[rt]=c;
        return;
    }
    int mid = (l+r)>>1;
    if(x<=mid)
        update(x,c,l,mid,lson);
    else
        update(x,c,mid+1,r,rson);
    up(l,r,mid,rt);
}
int query(int x,int y,int l,int r,int rt)
{
    if(x<=l&&y>=r)
        return tree[rt];
    int mid = (l+r)>>1;
    int ans=0;
    if(x<=mid)
        ans = max(ans,query(x,y,l,mid,lson));
    if(y>mid)
        ans = max(ans,query(x,y,mid+1,r,rson));
    return ans;
}
int query(int a,int b)
{
    int f1 = top[a],f2 = top[b];
    int ans=0;
    while(f1!=f2)
    {
        if(dep[f1]<dep[f2])
        {
            swap(a,b);
            swap(f1,f2);
        }
        ans = max(ans,query(w[f1],w[a],1,ind-1,1));
        a = fa[f1];
        f1 = top[a];
    }
    //cout<<a<<"!"<<b<<" "<<ans<<endl;
    if(a==b)return ans;
    if(dep[a]<dep[b])swap(a,b);
    ans = max(ans,query(w[son[b]],w[a],1,ind-1,1));
    return ans;
}
void output(int l,int r,int rt)
{
    if(l==r)
    {

        cout<<l<<"-"<<tree[rt]<<endl;
        return;
    }
    int mid = (l+r)>>1;
    output(l,mid,lson);
    output(mid+1,r,rson);
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    int n;
    while(t--)
    {
        scanf("%d",&n);
        memset(head,-1,sizeof(head));
        tot=0;
        for(i=1;i<=n-1;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
            add(b,a,c);
            g[i].x=a;
            g[i].y=b;
            g[i].c=c;
        }
        dep[1]=0;
        dfs(1,-1);
        ind=1;
        build(1,1);
        for(i=1;i<=n-1;i++)
        {
            //cout<<g[i].x<<"***"<<g[i].y<<" "<<dep[g[i].x]<<" "<<dep[g[i].y]<<endl;
            if(dep[g[i].x]<dep[g[i].y])
                swap(g[i].x,g[i].y);
            //cout<<w[g[i].x]<<" * "<<g[i].c<<endl;
            update(w[g[i].x],g[i].c,1,ind-1,1);
        }
        //output(1,ind-1,1);
        while(scanf("%s",s)!=EOF)
        {
            if(s[0]=='D')break;
            int a,b;
            scanf("%d%d",&a,&b);
            if(s[0]=='C')
            {
                update(w[g[a].x],b,1,ind-1,1);
            }
            else
            {
                printf("%d\n",query(a,b));
            }
        }
    }
    return 0;
}
