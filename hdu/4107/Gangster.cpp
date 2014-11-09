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
int n,m,p;
const int maxn = 201000;
int add[maxn<<2];
int Min[maxn<<2];
int Max[maxn<<2];
#define lson rt<<1
#define rson rt<<1|1
void pushdown(int l,int r,int mid,int rt)
{
    if(add[rt])
    {
        Min[lson]+=add[rt];
        Min[rson]+=add[rt];
        Max[lson]+=add[rt];
        Max[rson]+=add[rt];
        add[lson]+=add[rt];
        add[rson]+=add[rt];
        add[rt]=0;
    }
}
void pushup(int l,int r,int mid,int rt)
{
    Min[rt]=min(Min[lson],Min[rson]);
    Max[rt]=max(Max[lson],Max[rson]);
}
void Add(int x,int y,int c,int l,int r,int rt)
{
    if(l==r)
    {
        if(Min[rt]<p)
        {
            Min[rt]+=c;Max[rt]+=c;
        }
        else
        {
            Min[rt]+=c*2;Max[rt]+=c*2;
        }
        return;
    }
    if(x<=l&&y>=r)
    {
        if(Min[rt]>=p)
        {
            Min[rt]+=c*2;
            Max[rt]+=c*2;
            add[rt]+=c*2;
            return;
        }
        if(Max[rt]<p)
        {
            Max[rt]+=c;
            Min[rt]+=c;
            add[rt]+=c;
            return;
        }
    }

    int mid = (l+r)>>1;
    pushdown(l,r,mid,rt);
    if(x<=mid)
        Add(x,y,c,l,mid,lson);
    if(y>mid)
        Add(x,y,c,mid+1,r,rson);
    pushup(l,r,mid,rt);
}
void output(int l,int r,int rt)
{
    if(l==r)
    {
        if(l==1)printf("%d",Min[rt]);
        else printf(" %d",Min[rt]);
        return;
    }
    int mid = (l+r)>>1;
    pushdown(l,r,mid,rt);
    output(l,mid,lson);
    output(mid+1,r,rson);
}
void build(int l,int r,int rt)
{
    Min[rt]=Max[rt]=add[rt]=0;
    if(l==r)return;
    int mid = (l+r)>>1;
    build(l,mid,lson);
    build(mid+1,r,rson);
}
int main()
{
    int i,j;
    int a,b,c;
    while(scanf("%d%d%d",&n,&m,&p)!=EOF)
    {
        build(1,n,1);
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            Add(a,b,c,1,n,1);
        }
        output(1,n,1);
        printf("\n");
    }
    return 0;
}
