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
const int maxn = 300005;
struct array
{
    int t[maxn<<2];
}tree[maxn<<2];
struct ax
{
    int l,r;
}s[maxn];
#define lson rt<<1
#define rson rt<<1|1
int cnt;
void subbuild(int l,int r,int rt,int frt)
{
    tree[frt][rt]=0;
    if(l==r)
    {
        return;
    }
    int mid = (l+r)>>1;
    subbuild(l,mid,lson,frt);
    subbuild(mid+1,r,rson,frt);
}
void build(int l,int r,int rt)
{
    if(l==r)
    {

        subbuild(1,cnt,1,rt);
        return;
    }
    int mid = (l+r)>>1;
    build(l,mid,lson);
    build(mid+1,r,rson);
}
vector<int>x[maxn];
int main()
{
    int i,j;
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%d%d",&s[i].l,&s[i].r);

        build(1,m,1);

    }
    return 0;
}
