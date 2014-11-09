#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 300005;
int tree[maxn<<2],lazy[maxn<<2];
int a[maxn],b[maxn];
#define lson rt<<1
#define rson rt<<1|1
struct array
{
    int x,y,num;
}s[200005];
int cmp(array a,array b)
{
    return a.y-a.x>b.y-b.x;
}
void build(int l,int r,int rt)
{
    tree[rt]=lazy[rt]=0;
    if(l==r)return;
    int mid = (l+r)>>1;
    build(l,mid,lson);
    build(mid+1,r,rson);
}
void pushdown(int mid,int l,int r,int rt)
{
    if(lazy[rt])
    {
        lazy[lson]=lazy[rson]=lazy[rt];
        tree[lson]=tree[rson]=lazy[rt];
        lazy[rt]=0;
    }
}
void update(int x,int y,int c,int l,int r,int rt)
{
    if(x<=l&&y>=r)
    {
        tree[rt]=lazy[rt]=c;
        return;
    }
    int mid = (l+r)>>1;
    pushdown(mid,l,r,rt);
    if(x<=mid)
        update(x,y,c,l,mid,lson);
    if(y>mid)
        update(x,y,c,mid+1,r,rson);
}
int q(int x,int l,int r,int rt)
{
    if(l==r)
        return tree[rt];
    int mid = (l+r)>>1;
    pushdown(mid,l,r,rt);
    if(x<=mid)
       return q(x,l,mid,lson);
    else return q(x,mid+1,r,rson);
}
int main()
{
    int n,m,i,j,k;
    while(scanf("%d",&n)!=EOF)
    {
        k = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&s[i].x,&s[i].y);
            a[k++]=s[i].x;
            a[k++]=s[i].y;
            s[i].num=i+1;
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d",&b[i]);
            a[k++]=b[i];
        }
        sort(s,s+n,cmp);
        sort(a,a+k);
        k = unique(a,a+k)-a;
        build(0,k-1,1);
        for(i=0;i<n;i++)
        {
            int x = lower_bound(a,a+k,s[i].x)-a;
            int y = lower_bound(a,a+k,s[i].y)-a;
            update(x,y,s[i].num,0,k-1,1);
        }
        for(i=0;i<m;i++)
        {
            int x = lower_bound(a,a+k,b[i])-a;
            int ans = q(x,0,k-1,1);
            if(ans==0)ans=-1;
            printf("%d\n",ans);
        }
    }
}
