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
const int maxn = 100010;
#define ll long long
const ll mod = 10007;
ll tree[maxn<<2][3];
ll add[maxn<<2],mul[maxn<<2];
#define lson rt<<1
#define rson rt<<1|1
void build(int l,int r,int rt)
{
    add[rt]=0;
    mul[rt]=1;
    tree[rt][0]=tree[rt][1]=tree[rt][2]=0;
    if(l==r)return;
    int mid=(l+r)>>1;
    build(l,mid,lson);
    build(mid+1,r,rson);
}
void pushup(int l,int r,int mid,int rt)
{
    tree[rt][0]=(tree[lson][0]+tree[rson][0])%mod;
    tree[rt][1]=(tree[lson][1]+tree[rson][1])%mod;
    tree[rt][2]=(tree[lson][2]+tree[rson][2])%mod;
}
void change1(int rt,ll M)
{
    ll x = M;
    tree[rt][0]=(tree[rt][0]*x)%mod;
    x = x*M%mod;
    (tree[rt][1]*=x)%=mod;
    x = x*M%mod;
    (tree[rt][2]*=x)%=mod;
}
void change2(int rt,ll A,int len)
{
    ll tmp1 = tree[rt][0],tmp2 = tree[rt][1];
    (tree[rt][0]+=A*(len))%=mod;

    ll  a3 = A*A*A%mod;
    tree[rt][1]=(tree[rt][1]+A*A*(len)+2*A*tmp1)%mod;
    tree[rt][2]=(tree[rt][2]+a3*len+3*tmp1*A*A+3*tmp2*A)%mod;

}
void pushdown(int l,int r,int mid,int rt)
{
    if(mul[rt]!=1)
    {
        (mul[lson]*=mul[rt])%=mod;
        (mul[rson]*=mul[rt])%=mod;
        (add[lson]*=mul[rt])%=mod;
        (add[rson]*=mul[rt])%=mod;
        change1(lson,mul[rt]);
        change1(rson,mul[rt]);
        mul[rt]=1;
    }
    if(add[rt]!=0)
    {
        (add[lson]+=add[rt])%=mod;
        (add[rson]+=add[rt])%=mod;
        change2(lson,add[rt],mid-l+1);
        change2(rson,add[rt],r-mid);

        add[rt]=0;
    }

}

void update(int x,int y,ll Mul,ll Add,int l,int r,int rt,int kind)
{
    if(x<=l&&y>=r)
    {
        if(kind==3)
        {
            mul[rt]=0;
            add[rt]=Add;
            tree[rt][0]=(r-l+1)*Add%mod;
            tree[rt][1]=tree[rt][0]*Add%mod;
            tree[rt][2]=tree[rt][1]*Add%mod;
        }
        else if(kind==2)
        {
            mul[rt]*=Mul;mul[rt]%=mod;
            add[rt]*=Mul;add[rt]%=mod;
            change1(rt,Mul);
        }
        else
        {
            add[rt]+=Add;add[rt]%=mod;
            change2(rt,Add,r-l+1);
        }
        return;
    }
    int mid = (l+r)>>1;
    pushdown(l,r,mid,rt);
    if(x<=mid)
        update(x,y,Mul,Add,l,mid,lson,kind);
    if(y>mid)
        update(x,y,Mul,Add,mid+1,r,rson,kind);
    pushup(l,r,mid,rt);
}
ll query(int x,int y,int l,int r,int rt,int k)
{
    if(x<=l&&y>=r)
        return tree[rt][k];
    int mid = (l+r)>>1;
    pushdown(l,r,mid,rt);
    ll sum=0;
    if(x<=mid)
        sum += query(x,y,l,mid,lson,k);
    if(y>mid)
        sum += query(x,y,mid+1,r,rson,k);
    return sum%mod;
}
int main()
{
    int i,j;
    int n,m;
    int d,x,y;
    ll c;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)break;
        build(1,n,1);
        while(m--)
        {
            scanf("%d%d%d%I64d",&d,&x,&y,&c);
            if(d==1)
                update(x,y,1,c,1,n,1,1);
            else if(d==2)
                update(x,y,c,0,1,n,1,2);
            else if(d==3)
                update(x,y,0,c,1,n,1,3);
            else
            {
                ll ans = query(x,y,1,n,1,c-1);
                printf("%I64d\n",ans);
            }
        }
    }
    return 0;
}
