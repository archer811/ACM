#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 2000;
const int maxm = 200;
#define lson rt<<1
#define rson rt<<1|1
struct array
{
   int big[maxn<<2];
}tree[maxm<<2];
void subbuild(int num,int l,int r,int rt)
{
    tree[num].big[rt]=-1;
    if(l!=r)
    {
        int mid= (l+r)>>1;
        subbuild(num,l,mid,lson);
        subbuild(num,mid+1,r,rson);
    }
}
void build(int l,int r,int rt)
{
    subbuild(rt,0,1000,1);
    if(l!=r)
    {
        int mid = (l+r)>>1;
        build(l,mid,lson);
        build(mid+1,r,rson);
    }
}
void pushup(int num,int l,int r,int rt)
{
    tree[num].big[rt]=max(tree[num].big[lson],tree[num].big[rson]);
}
void subupdate(int num,int A,int yf,int l,int r,int rt)
{
    if(l==r)
    {
        if(tree[num].big[rt]<yf)
            tree[num].big[rt]=yf;
        return;
    }
    int mid = (l+r)>>1;
    if(A<=mid)subupdate(num,A,yf,l,mid,lson);
    else subupdate(num,A,yf,mid+1,r,rson);
    pushup(num,l,r,rt);
}
void update(int h,int A,int yf,int l,int r,int rt)
{
    subupdate(rt,A,yf,0,1000,1);
    if(l!=r)
    {
        int mid = (l+r)>>1;
        if(h<=mid)
            update(h,A,yf,l,mid,lson);
        else update(h,A,yf,mid+1,r,rson);
    }
}
int subquery(int num,int a1,int a2,int l,int r,int rt)
{
    if(a1<=l&&a2>=r)
        return tree[num].big[rt];
    int mid = (l+r)>>1;
    int ans = -1;
    if(a1<=mid)
        ans = max(ans,subquery(num,a1,a2,l,mid,lson));
    if(a2>mid)
        ans = max(ans,subquery(num,a1,a2,mid+1,r,rson));
    return ans;
}
int query(int x,int y,int a1,int a2,int l,int r,int rt)
{
    if(x<=l&&y>=r)
    {
        return subquery(rt,a1,a2,0,1000,1);
    }
    int mid = (l+r)>>1;
    int ans = -1;
    if(x<=mid)
        ans = max(ans,query(x,y,a1,a2,l,mid,lson));
    if(y>mid)
        ans = max(ans,query(x,y,a1,a2,mid+1,r,rson));
    return ans;
}
char op[2];
int main()
{
    int i,j,k,T,h,h1,h2;
    double a,l,a1,a2;
    while(scanf("%d",&T)&&T)
    {
        build(100,200,1);
        while(T--)
        {
            scanf("%s",op);
            if(op[0]=='I')
            {
                scanf("%d%lf%lf",&h,&a,&l);
                a *= 10.0;
                l *= 10.0;
                int A = (int)a;
                update(h,A,(int)l,100,200,1);
            }
            else
            {
                scanf("%d%d%lf%lf",&h1,&h2,&a1,&a2);
                if(h1>h2)swap(h1,h2);
                if(a1>a2)swap(a1,a2);
                a1 *= 10.0;
                a2 *= 10.0;
                int A = (int)a1,B = (int)a2;
                int ans = query(h1,h2,A,B,100,200,1);
                if(ans<0)
                    puts("-1");
                else
                printf("%.1f\n",ans*1.0/10);
            }
        }
    }
}
