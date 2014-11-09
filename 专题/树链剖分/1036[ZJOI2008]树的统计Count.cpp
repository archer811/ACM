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

const int maxn = 30005;
const int maxm = 30005*2+100;
int head[maxn],tot;
struct Edge
{
    int to,next;
}edge[maxm];
int dep[maxn],top[maxn],siz[maxn],son[maxn],fa[maxn];
void dfs(int u,int fa2)
{
    siz[u]=1;
    son[u]=0;
    fa[u]=fa2;
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
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int value[maxn];
int idx,w[maxn];
void build(int u,int tp)
{
    top[u]=tp;
    w[u]=idx++;
    if(son[u]!=0)
        build(son[u],tp);
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int  v = edge[i].to;
        if(v==fa[u]||v==son[u])continue;
        build(v,v);
    }
}
#define lson rt<<1
#define rson rt<<1|1
int Max[maxn<<2],sum[maxn<<2];
void up(int l,int r,int mid,int rt)
{
    Max[rt]=max(Max[lson],Max[rson]);
    sum[rt]=sum[lson]+sum[rson];
}
void maketree(int l,int r,int rt)
{
    if(l==r)
    {
        Max[rt]=sum[rt]=value[l];
        return;
    }
    int mid = (l+r)>>1;
    maketree(l,mid,lson);
    maketree(mid+1,r,rson);
    up(l,r,mid,rt);
}
char s[10];
const int inf = 0x3fffffff;
int query(int x,int y,int c,int l,int r,int rt)
{
    if(x<=l&&y>=r)
    {
        if(c==0)return Max[rt];
        else return sum[rt];
    }
    int mid = (l+r)>>1;
    int a=0,b=0,a2=-inf,b2=-inf;
    if(x<=mid)
        a = a2 = query(x,y,c,l,mid,lson);
    if(y>mid)
        b = b2 = query(x,y,c,mid+1,r,rson);
    if(c==0)return max(a2,b2);
    else return a+b;
}
void update(int x,int c,int l,int r,int rt)
{
    if(l==r)
    {
        Max[rt]=sum[rt]=c;
        return;
    }
    int mid = (l+r)>>1;
    if(x<=mid)
        update(x,c,l,mid,lson);
    else
        update(x,c,mid+1,r,rson);
    up(l,r,mid,rt);
}

int query(int a,int b,int c)
{
    int f1=top[a],f2 = top[b];
    int ans=-inf;
    if(c==1)ans=0;
    while(f1!=f2)
    {
        if(dep[f1]<dep[f2])
        {
            swap(f1,f2);
            swap(a,b);
        }
        int tmp = query(w[f1],w[a],c,1,idx-1,1);
        if(c==0)
            ans=max(ans,tmp);
        else
            ans = ans+tmp;
        a = fa[f1];
        f1 = top[a];
    }
    if(dep[a]>dep[b])swap(a,b);
    int tmp = query(w[a],w[b],c,1,idx-1,1);
    if(c==0)
        ans=max(ans,tmp);
    else
        ans=ans+tmp;
    return ans;
}
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(head,-1,sizeof(head));
        tot=0;
        for(i=1;i<=n-1;i++)
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
            int tmp;
            scanf("%d",&tmp);
            value[w[i]]=tmp;
            //cout<<w[i]<<"*"<<tmp<<endl;
        }


        maketree(1,idx-1,1);
//        for(i=1;i<=n;i++)
//            cout<<i<<"  "<<w[i]<<endl;
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int a,b;
            scanf("%s%d%d",s,&a,&b);
            if(s[0]=='Q'&&s[1]=='M')
                printf("%d\n",query(a,b,0));
            else if(s[0]=='Q'&&s[1]=='S')
                printf("%d\n",query(a,b,1));
            else update(w[a],b,1,idx-1,1);
        }
    }
    return 0;
}
