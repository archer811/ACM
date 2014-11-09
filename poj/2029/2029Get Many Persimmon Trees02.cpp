#include <cstdio>
#include <iostream>
#include <algorithm>
#define lson i<<1
#define rson i<<1|1
using namespace std;
const int M = 666;
struct subnode
{
    int lx,rx;
    int val;
};
struct node
{
    int ly,ry;
    subnode st[M<<2];
} tree[M<<2];
void up(int ii,int i)
{
    tree[ii].st[i].val= tree[ii].st[lson].val + tree[ii].st[rson].val;
}
void buildsub(int ii,int i,int l,int r)
{
    tree[ii].st[i].lx = l;
    tree[ii].st[i].rx = r;
    tree[ii].st[i].val = 0;
    if(l==r) return ;
    int mid = (l+r) >>1;
    buildsub(ii,lson,l,mid);
    buildsub(ii,rson,mid+1,r);
}
void build(int i,int l,int r,int ll,int rr)
{
    buildsub(i,1,ll,rr);
    tree[i].ly= l;
    tree[i].ry = r;
    if(l==r) return ;
    int mid = (l+r) >>1;
    build(lson,l,mid,ll,rr);
    build(rson,mid+1,r,ll,rr);
}
void updatesub(int ii,int i,int x)
{
    if(tree[ii].st[i].lx==tree[ii].st[i].rx)
    {
        tree[ii].st[i].val++;
        return ;
    }
    int mid=(tree[ii].st[i].lx+tree[ii].st[i].rx) >>1;
    if(x<=mid) updatesub(ii,lson,x);
    else updatesub(ii,rson,x);
    up(ii,i);
}
void update(int i,int y,int x)
{
    updatesub(i,1,x);
    if(tree[i].ly==tree[i].ry) return ;
    int mid =(tree[i].ly+tree[i].ry) >>1;
    if(y<=mid) update(lson,y,x);
    else update(rson,y,x);
}
int querysub(int ii,int i,int l,int r)
{
    if(tree[ii].st[i].lx>=l&&tree[ii].st[i].rx<=r)
    {
        return tree[ii].st[i].val;
    }
    int mid = (tree[ii].st[i].lx+tree[ii].st[i].rx) >>1;
    if(r<=mid) return querysub(ii,lson,l,r);
    else if(l>mid) return querysub(ii,rson,l,r);
    else return querysub(ii,lson,l,mid)+querysub(ii,rson,mid+1,r);
    up(ii,i);
}
int query(int i,int l,int r,int ll,int rr)
{
    if(tree[i].ly==l&&tree[i].ry==r) return querysub(i,1,ll,rr);
    int mid = (tree[i].ly+tree[i].ry) >>1;
    if(r<=mid) return query(lson,l,r,ll,rr);
    else if(l>mid) return query(rson,l,r,ll,rr);
    else return query(lson,l,mid,ll,rr)+query(rson,mid+1,r,ll,rr);
}
int main()
{
    int n,m,t;
    while(cin>>t,t)
    {
        cin>>n>>m;
        build(1,1,n,1,m);
        while(t--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            update(1,x,y);
        }
        int ans= -34;
        int S,T;
        cin>>S>>T;
        for(int i=1; i<=m-T+1; i++)
        {
            for(int j=1; j<=n-S+1; j++)
            {
                ans=max(ans,query(1,j,j+S-1,i,i+T-1));
            }
        }
        printf("%d\n",ans);
    }
}
