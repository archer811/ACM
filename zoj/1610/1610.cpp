#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=8003*2;
int n;
const int N = 8000*2;
//8000*2;
#define lson rt<<1
#define rson rt<<1|1
int tree[maxn<<2],lazy[maxn<<2];
int ans[maxn],kind[maxn<<2];
void pushdown(int l,int r,int mid,int rt)
{
    if(lazy[rt]!=-1)
    {
        lazy[lson]=lazy[rt];
        lazy[rson]=lazy[rt];
        tree[lson]=lazy[rt];
        tree[rson]=lazy[rt];
        lazy[rt]=-1;
    }
}
void add(int x,int y,int c,int l,int r,int rt)
{
    if(x<=l&&y>=r)
    {
//        cout<<rt<<endl;
        tree[rt]=lazy[rt]=c;return;
    }
    int mid = (l+r)>>1;
    pushdown(l,r,mid,rt);
    if(x<=mid)
        add(x,y,c,l,mid,lson);
    if(y>mid)
        add(x,y,c,mid+1,r,rson);
}
void output(int l,int r,int rt)
{
    if(l==r)
    {
//        if(tree[rt]!=-1)
//        cout<<l<<" "<<tree[rt]<<endl;
        kind[l]=tree[rt];return;
    }
    int mid = (l+r)>>1;
    pushdown(l,r,mid,rt);
    output(l,mid,lson);
    output(mid+1,r,rson);
}
int main()
{
    int i,j;
    int a,b,c;
    while(scanf("%d",&n)!=EOF)
    {
        memset(tree,-1,sizeof(tree));
        memset(lazy,-1,sizeof(lazy));
        memset(ans,0,sizeof(ans));
        while(n--)
        {
            scanf("%d%d%d",&a,&b,&c);
            a*=2;b*=2;
            add(a,b,c,0,N,1);

        }
        output(0,N,1);
        for(i=1;i<=N+1;i++)
        {

            if(kind[i-1]!=-1&&i==N+1)
            {
                ans[kind[i-1]]++;
            }
            else if(kind[i-1]!=-1&&kind[i]!=kind[i-1])
            {
                ans[kind[i-1]]++;
            }
        }
        for(i=0;i<=8000;i++)
        {
            if(ans[i])
            {
                printf("%d %d\n",i,ans[i]);
            }
        }
        puts("");
    }
    return 0;
}

