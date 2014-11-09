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
const int maxn  = 400005;
#define ll __int64
int lazy[maxn<<1];
ll sum[maxn<<1];
ll tree[maxn<<1];
#define lson rt<<1
#define rson rt<<1|1
void build(int l,int r,int rt)
{
    lazy[rt]=-1;sum[rt]=0;
    tree[rt]=-1;
    if(l==r)
    {
        lazy[rt]=l;
        tree[rt]=l;
        return;
    }
    int mid = (l+r)>>1;
    build(l,mid,lson);
    build(mid+1,r,rson);
}
ll ABS(ll a,ll b)
{
    ll c = a-b;
    if(c<0)return -c;
    return c;
}
void pushup(int l,int r,int mid,int rt)
{
    sum[rt]=sum[lson]+sum[rson];
}
void pushdown(int l,int r,int mid,int rt)
{
    if(lazy[rt]!=-1)
    {
        sum[lson]+=ABS(tree[lson],lazy[rt]);
        sum[rson]+=ABS(tree[rson],lazy[rt]);
        lazy[lson]=lazy[rt];
        lazy[rson]=lazy[rt];
        tree[lson]=lazy[rt];
        tree[rson]=lazy[rt];
        lazy[rt]=-1;
    }
}
void update(int x,int y,int c,int l,int r,int rt)
{
    int mid = (l+r)>>1;

    if(x<=l&&y>=r)
    {
        //cout<<l<<"*"<<r<<endl;
        if(l==r)
        {
            sum[rt]+=ABS(tree[rt],c);
            //cout<<tree[rt]<<" "<<c<<" () "<<sum[rt]<<endl;
            lazy[rt]=-1;
            tree[rt]=c;
            return;
        }
        if(tree[rt]==-1)
        {
            update(x,y,c,l,mid,lson);
            update(x,y,c,mid+1,r,rson);
        }
        else
        {
            sum[rt]+=(ll)(r-l+1)*(ll)ABS(tree[rt],c);
            lazy[rt]=c;
            tree[rt]=c;
        }
        return;
    }
    pushdown(l,r,mid,rt);
    if(x<=mid)
        update(x,y,c,l,mid,lson);
    if(y>mid)
        update(x,y,c,mid+1,r,rson);
    pushup(l,r,mid,rt);
}
ll query(int x,int y,int l,int r,int rt)
{
    int mid = (l+r)>>1;

    if(x<=l&&y>=r)
    {
        return sum[rt];
    }
    pushdown(l,r,mid,rt);
    ll sum2=0;
    if(x<=mid)
        sum2+=query(x,y,l,mid,lson);
    if(y>mid)
        sum2+=query(x,y,mid+1,r,rson);
    return sum2;
}
int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        build(1,n,1);
        while(m--)
        {
            int l,r,x;
            int kind;
            scanf("%d",&kind);
            if(kind==1)
            {
                scanf("%d%d%d",&l,&r,&x);
                update(l,r,x,1,n,1);
            }
            else
            {
                scanf("%d%d",&l,&r);
                printf("%I64d\n",query(l,r,1,n,1));
            }
        }
    }
    return 0;
}
