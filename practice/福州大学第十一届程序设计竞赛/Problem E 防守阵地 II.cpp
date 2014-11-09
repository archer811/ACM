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

#define L(x) (x*2)
#define R(x) (x*2+1)
#define N 123456
ll Mid(ll a,ll b)
{
    return (a+b)/2;
}
struct node
{
    ll l, r;
    ll sum, val;
    ll size()
    {
        return r-l+1;
    }
} tree[N*8];
ll a[N];
void push_up(ll x)
{
    tree[x].val = tree[L(x)].val + tree[R(x)].val;
}
void push_down(ll id)
{
    if(tree[id].sum)
    {
        tree[L(id)].sum += tree[id].sum;
        tree[R(id)].sum += tree[id].sum;
        tree[L(id)].val += tree[id].sum*tree[L(id)].size();
        tree[R(id)].val += tree[id].sum*tree[R(id)].size();
        tree[id].sum = 0;
    }
}
void build(ll l, ll r, ll id)
{
    tree[id].l = l, tree[id].r = r;
    tree[id].sum = 0;
    if(l==r)
    {
        tree[id].val = a[l];
        return;
    }
    ll mid = Mid(l,r);
    build(l,mid,L(id));
    build(mid+1,r,R(id));
    push_up(id);
}
ll query(ll l, ll r, ll id)
{
    if(l == tree[id].l && tree[id].r == r)return tree[id].val;
    push_down(id);

    ll mid = Mid(tree[id].l, tree[id].r);
    if(r <= mid)return query(l,r,L(id));
    else if(mid < l)return query(l, r, R(id));
    return query(l,mid,L(id))+query(mid+1,r,R(id));
}
void updata(ll l, ll r, ll id)
{
    if(l == tree[id].l && tree[id].r == r)
    {
        tree[id].val -= tree[id].size();
        tree[id].sum --;
        return;
    }
    push_down(id);
    ll mid = Mid(tree[id].l, tree[id].r);
    if(r <= mid)updata(l,r,L(id));
    else if(mid < l)updata(l, r, R(id));
    else
    {
        updata(l,mid,L(id));
        updata(mid+1,r,R(id));
    }
    push_up(id);
}
int main()
{
    ll n, m, q, i, j, u, v;
    while(scanf("%lld %lld %lld",&n,&m,&q)!=EOF)
    {
        for(i=1; i<=n; i++)
        scanf("%lld",&a[i]);
        build(1,n,1);
        while(q--)
        {
            scanf("%lld",&u);
            v = u+m-1;
            v = min(v,n);
            printf("%lld\n",query(u,v,1));
            updata(u,v,1);
        }
    }
    return 0;
}
