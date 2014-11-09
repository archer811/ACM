#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
using namespace std;
#define ll long long
const int maxn = 100005;
ll tree[maxn<<2], lazy[maxn<<2];
#define lson rt<<1
#define rson rt<<1|1
void pushup(int l,int r,int mid,int rt)
{
    tree[rt]=tree[lson]+tree[rson];
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%lld",&tree[rt]);return;
    }
    int mid = (l+r)>>1;
    build(l,mid,lson);
    build(mid+1,r,rson);
    pushup(l,r,mid,rt);
}
void pushdown(int l,int r,int mid,int rt)
{
    if(lazy[rt])
    {
        lazy[lson]+=lazy[rt];
        lazy[rson]+=lazy[rt];
        tree[lson]-=(mid-l+1)*lazy[rt];
        tree[rson]-=(r-(mid+1)+1)*lazy[rt];
        lazy[rt]=0;
    }
}
ll query(int x,int y,int l,int r,int rt)
{
    if(x<=l&&y>=r)
    {
        return tree[rt];
    }
    int mid = (l+r)>>1;
    pushdown(l,r,mid,rt);
    ll sum=0;
    if(x<=mid)
        sum += query(x,y,l,mid,lson);
    if(y>mid)
        sum += query(x,y,mid+1,r,rson);
    return sum;
}
void sub(int x,int y,int l,int r,int rt)
{
    if(x<=l&&y>=r)
    {
        lazy[rt]++;
        tree[rt]-=(r-l+1);
        return;
    }
    int mid = (l+r)>>1;
    pushdown(l,r,mid,rt);
    if(x<=mid)
        sub(x,y,l,mid,lson);
    if(y>mid)
        sub(x,y,mid+1,r,rson);
    pushup(l,r,mid,rt);
}
int main()
{
    int i,j,n,m,q;
    while(scanf("%d%d%d",&n,&m,&q)!=EOF)
    {
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));
        build(1,n,1);
        int x,pre=-1;
        for(i=0;i<q;i++)
        {
            scanf("%d",&x);
            if(pre!=-1)
                sub(pre,pre+m-1,1,n,1);
            pre = x;
            ll ans = query(x,x+m-1,1,n,1);
            printf("%lld\n",ans);

        }
    }
    return 0;
}
