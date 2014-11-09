#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 300;
#define lson rt<<1
#define rson rt<<1|1
int N,B,K;
struct array
{
    int b[maxn<<2],s[maxn<<2];
}tree[maxn<<2];
void  up(int num,int l,int r,int rt)
{
    tree[num].b[rt]=max(tree[num].b[lson],tree[num].b[rson]);
    tree[num].s[rt]=min(tree[num].s[lson],tree[num].s[rson]);
}
void subbuild(int num,int l,int r,int rt)
{
    tree[num].b[rt]=0;
    tree[num].s[rt]=300;
    if(l!=r)
    {
        int mid = (l+r)>>1;
        subbuild(num,l,mid,lson);
        subbuild(num,mid+1,r,rson);
    }
}
void build(int l,int r,int rt)
{
    subbuild(rt,1,N,1);
    if(l!=r)
    {
        int mid = (l+r)>>1;
        build(l,mid,lson);
        build(mid+1,r,rson);
    }
}
void subupdate(int num,int y,int c,int l,int r,int rt)
{
    if(l==r)
    {
        tree[num].b[rt]=max(tree[num].b[rt],c);
        tree[num].s[rt]=min(tree[num].s[rt],c);
        return;
    }
    int mid = (l+r)>>1;
    if(y<=mid)subupdate(num,y,c,l,mid,lson);
    else subupdate(num,y,c,mid+1,r,rson);
    up(num,l,r,rt);
}
void update(int x,int y,int c,int l,int r,int rt)
{
    subupdate(rt,y,c,1,N,1);
    if(l!=r)
    {
        int mid = (l+r)>>1;
        if(x<=mid)
            update(x,y,c,l,mid,lson);
        else update(x,y,c,mid+1,r,rson);
    }
}
int subgetMax(int num,int a,int b,int l,int r,int rt)
{
    if(a<=l&&b>=r)return tree[num].b[rt];
    int mid = (l+r)>>1;
    int M = 0;
    if(a<=mid)
        M = max(M,subgetMax(num,a,b,l,mid,lson));
    if(b>mid)
        M = max(M,subgetMax(num,a,b,mid+1,r,rson));
    return M;
}
int subgetMin(int num,int a,int b,int l,int r,int rt)
{
    if(a<=l&&b>=r)return tree[num].s[rt];
    int mid = (l+r)>>1;
    int M = 300;
    if(a<=mid)
        M = min(M,subgetMin(num,a,b,l,mid,lson));
    if(b>mid)
        M = min(M,subgetMin(num,a,b,mid+1,r,rson));
    return M;
}
int getMax(int x,int y,int a,int b,int l,int r,int rt)
{
    if(rt==0)return 0;
    if(x<=l&&y>=r)
        return subgetMax(rt,a,b,1,N,1);
    int M = 0;
    int mid = (l+r)>>1;
    if(x<=mid)
        M = max(M,getMax(x,y,a,b,l,mid,lson));
    if(y>mid)
        M = max(M,getMax(x,y,a,b,mid+1,r,rson));
    return M;
}
int getMin(int x,int y,int a,int b,int l,int r,int rt)
{
    if(x<=l&&y>=r)
        return subgetMin(rt,a,b,1,N,1);
    int M = 300;
    int mid = (l+r)>>1;
    if(x<=mid)
        M = min(M,getMin(x,y,a,b,l,mid,lson));
    if(y>mid)
        M = min(M,getMin(x,y,a,b,mid+1,r,rson));
    return M;
}
int main()
{
    int i,j,k,a,b;
    while(scanf("%d%d%d",&N,&B,&K)!=EOF)
    {
        build(1,N,1);
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=N;j++)
            {
                scanf("%d",&k);
                update(i,j,k,1,N,1);
            }
        }
        while(K--)
        {
            scanf("%d%d",&a,&b);
            printf("%d\n",getMax(a,a+B-1,b,b+B-1,1,N,1)-getMin(a,a+B-1,b,b+B-1,1,N,1));
        }
    }
}
