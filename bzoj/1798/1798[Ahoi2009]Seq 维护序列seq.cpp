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
ll p;
const int maxn = 110100;
ll tree[maxn<<2];
ll mul[maxn<<2],add[maxn<<2];
#define lson rt<<1
#define rson rt<<1|1
void pushup(int l,int r,int mid,int rt)
{
    tree[rt]=(tree[lson]+tree[rson])%p;
}
void build(int l,int r,int rt)
{
    mul[rt]=1;add[rt]=0;
    if(l==r)
    {
        scanf("%lld",&tree[rt]);
        tree[rt]%=p;return;
    }
    int mid = (l+r)>>1;
    build(l,mid,lson);
    build(mid+1,r,rson);
    pushup(l,r,mid,rt);
}
void pushdown(int l,int r,int mid,int rt)
{
    if(mul[rt]!=1)
    {
        (mul[lson]*=mul[rt])%=p;
        (mul[rson]*=mul[rt])%=p;
        (add[lson]*=mul[rt])%=p;
        (add[rson]*=mul[rt])%=p;
        (tree[lson]*=mul[rt])%=p;
        (tree[rson]*=mul[rt])%=p;
        mul[rt]=1;
    }
    if(add[rt])
    {
        (add[lson]+=add[rt])%=p;
        (add[rson]+=add[rt])%=p;
        (tree[lson]+=add[rt]*(mid-l+1))%=p;
        (tree[rson]+=add[rt]*(r-mid))%=p;
        add[rt]=0;
    }
}
void Mul(int x,int y,ll c,int l,int r,int rt)
{
    if(x<=l&&y>=r)
    {
        add[rt]=c*add[rt];add[rt]%=p;
        mul[rt]*=c;mul[rt]%=p;
        tree[rt]=(tree[rt]*c)%p;
        return;
    }
    int mid = (l+r)>>1;
    pushdown(l,r,mid,rt);
    if(x<=mid)
        Mul(x,y,c,l,mid,lson);
    if(y>mid)
        Mul(x,y,c,mid+1,r,rson);
    pushup(l,r,mid,rt);
}
void Add(int x,int y,ll c,int l,int r,int rt)
{
    if(x<=l&&y>=r)
    {
        add[rt]+=c;add[rt]%=p;
        tree[rt]=(tree[rt]+c*(r-l+1))%p;
        return;
    }
    int mid = (l+r)>>1;
    pushdown(l,r,mid,rt);
    if(x<=mid)
        Add(x,y,c,l,mid,lson);
    if(y>mid)
        Add(x,y,c,mid+1,r,rson);
    pushup(l,r,mid,rt);
}
ll query(int x,int y,int l,int r,int rt)
{
    if(x<=l&&y>=r)
    {
        return tree[rt];
    }
    int mid = (l+r)>>1;
    pushdown(l,r,mid,rt);
    ll ans=0;
    if(x<=mid)
        (ans += query(x,y,l,mid,lson))%=p;
    if(y>mid)
        (ans += query(x,y,mid+1,r,rson))%=p;
    return ans;
}
int main()
{
    int i,j;
    int n;
    scanf("%d%lld",&n,&p);
    build(1,n,1);
    int m;
    scanf("%d",&m);
    int t,g,d;
    ll c;
    while(m--)
    {
        scanf("%d",&d);
        if(d==1)
        {
            scanf("%d%d%lld",&t,&g,&c);
            Mul(t,g,c,1,n,1);
        }
        else if(d==2)
        {
            scanf("%d%d%lld",&t,&g,&c);
            Add(t,g,c,1,n,1);
        }
        else if(d==3)
        {
            scanf("%d%d",&t,&g);
            ll ans = query(t,g,1,n,1);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
