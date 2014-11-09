#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
#define lc l,m,index<<1
#define rc m+1,r,index<<1|1
#define N 100005
#define ll __int64

struct node
{
	bool same;
	ll col,sum,add;
}seg[N<<2];

ll n,m;

void color(ll x,ll add,ll l,ll r,ll index)
{
	seg[index].same=true;
	seg[index].sum+=add*(r-l+1);
	seg[index].col=x;
	seg[index].add+=add;
}

void pushup(ll l,ll r,ll index)
{
	seg[index].sum=seg[index<<1].sum+seg[index<<1|1].sum;
	if(seg[index<<1].same&&seg[index<<1|1].same&&seg[index<<1].col==seg[index<<1|1].col)
	{
		seg[index].same=true;
		seg[index].col=seg[index<<1].col;
	}
	else seg[index].same=false;
}

void pushdown(ll l,ll r,ll index)
{
	ll m=(l+r)>>1;
	if(seg[index].add)
	{
		color(seg[index].col,seg[index].add,lc);
		color(seg[index].col,seg[index].add,rc);
		seg[index].add=0;
	}
}

void build(ll l,ll r,ll index)
{
	ll m=(l+r)>>1;
	if(l==r)
	{
		seg[index].same=true;
		seg[index].col=l;
		seg[index].sum=0;
		return;
	}
	build(lc);
	build(rc);
	pushup(l,r,index);
}

void update(ll L,ll R,ll x,ll l,ll r,ll index)
{
	ll m=(l+r)>>1;
	pushdown(l,r,index);
	if(L<=l&&R>=r&&seg[index].same)
	{
		color(x,abs(seg[index].col-x),l,r,index);
		return;
	}

	if(L<=m)
		update(L,m,x,lc);
    if(R>m)
		update(m+1,R,x,rc);
	pushup(l,r,index);
}

ll query(ll L,ll R,ll l,ll r,ll index)
{
	ll m=(l+r)>>1;
	pushdown(l,r,index);
	if(L<=l&&R>=r)return seg[index].sum;

	ll sum=0;
	if(L<=m)sum += query(L,m,lc);
	if(R>m)sum += query(m+1,R,rc);
	return sum;
}

int main()
{
	scanf("%I64d%I64d",&n,&m);
	build(1,n,1);
	while(m--)
	{
		ll op,a,b,c;
		scanf("%I64d",&op);
		if(op==1)
		{
			scanf("%I64d%I64d%I64d",&a,&b,&c);
			update(a,b,c,1,n,1);
		}
		else
		{
			scanf("%I64d%I64d",&a,&b);
			printf("%I64d\n",query(a,b,1,n,1));
		}
	}
	return 0;
}
