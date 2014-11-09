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
const int maxn = 100100;
int bit[maxn<<2];
int lazy[maxn<<2];
#define lson rt<<1
#define rson rt<<1|1
void pushup(int l,int r,int mid,int rt)
{
    bit[rt]=bit[lson]|bit[rson];
}
void pushdown(int l,int r,int mid,int rt)
{
    if(lazy[rt]!=-1)
    {
        lazy[lson]=lazy[rson]=lazy[rt];
        bit[lson]=bit[rson]=lazy[rt];
        lazy[rt]=-1;
    }
}
void build(int l,int r,int rt)
{
    lazy[rt]=-1;bit[rt]=1;
    if(l==r)
    {
        return;
    }
    int mid = (l+r)>>1;
    build(l,mid,lson);
    build(mid+1,r,rson);
    pushup(l,r,mid,rt);
}
void update(int x,int y,int c,int l,int r,int rt)
{
    if(x<=l&&y>=r)
    {
        bit[rt]=(1<<(c-1));
        lazy[rt]=(1<<(c-1));
        return;
    }
    int mid = (l+r)>>1;
    pushdown(l,r,mid,rt);
    if(x<=mid)
        update(x,y,c,l,mid,lson);
    if(y>mid)
        update(x,y,c,mid+1,r,rson);

    pushup(l,r,mid,rt);
    //cout<<l<<"*"<<r<<" "<<bit[rt]<<" "<<bit[lson]<<" "<<bit[rson]<<endl;
}
int getans(int x)
{
    int s=0;
    while(x)
    {
        if(x&1)s++;
        x/=2;
    }
    return s;
}
int query(int x,int y,int l,int r,int rt)
{
    if(x<=l&&y>=r)
    {
        return bit[rt];
    }
    int sum=0;
    int mid = (l+r)>>1;
    pushdown(l,r,mid,rt);

    if(x<=mid)
        sum |= query(x,y,l,mid,lson);

    if(y>mid)
    {
        sum |=query(x,y,mid+1,r,rson);
    }
    return sum;
}

char s[2];
int main()
{
    int l,t,o;
    int i,j;
    int a,b,c;
    while(scanf("%d%d%d",&l,&t,&o)!=EOF)
    {
        build(1,l,1);
        while(o--)
        {
            scanf("%s",s);
            if(s[0]=='C')
            {
                scanf("%d%d%d",&a,&b,&c);
                if(a>b)swap(a,b);
                update(a,b,c,1,l,1);
            }
            else
            {
                scanf("%d%d",&a,&b);
                if(a>b)swap(a,b);
                int ans = query(a,b,1,l,1);
                printf("%d\n",getans(ans));
            }
        }
    }
    return 0;
}
