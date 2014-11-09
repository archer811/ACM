#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;
#ifdef __int64
typedef __int64 ll;
#else
typedef long long ll;
#endif
const int maxn = 200005;
ll w[maxn<<2],lazy[maxn<<2];
#define lson rt<<1
#define rson rt<<1|1
void down(int l,int r,int mid,int rt)
{
    if(lazy[rt])
    {
        lazy[lson]+=lazy[rt];
        lazy[rson]+=lazy[rt];
        w[lson]+=(lazy[rt]*(mid-l));
        w[rson]+=(lazy[rt]*(r-mid+1));
        lazy[rt]=0;
    }
}
void update(int x,ll g,int l,int r,int rt)
{
    if(l==r)
    {
        lazy[rt]+=g;
        w[rt]+=g*(ll)(r-l+1);
        return;
    }
    int mid = (l+r)>>1;
    down(l,r,mid,rt);
    if(x<=mid)
        update(x,g,l,mid,lson);
    if(x>mid)
        update(x,g,mid+1,r,rson);
    w[rt]=w[lson]+w[rson];
}
void update(int x,int y,ll g,int l,int r,int rt)
{
    if(x<=l&&y>=r)
    {
        lazy[rt]+=g;
        w[rt]+=g*(ll)(r-l+1);
        return;
    }
    int mid = (l+r)>>1;
    down(l,r,mid,rt);
    if(x<=mid)
        update(x,y,g,l,mid,lson);
    if(y>mid)
        update(x,y,g,mid+1,r,rson);
    w[rt]=w[lson]+w[rson];
}
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(w,0,sizeof(w));
        memset(lazy,0,sizeof(lazy));
        int t;
        ll a,x;
        int num=1;
        int nn=n;
        while(nn--)
        {
            scanf("%d",&t);
            if(t==1)
            {
                scanf("%I64d%I64d",&a,&x);
                update(1,a,x,1,n,1);
            }
            else if(t==2)
            {
                scanf("%I64d",&x);
                ++num;
                //cout<<num<<"()"<<num<<endl;
                update(num,x,1,n,1);
            }
            else
            {
                update(num,0,1,n,1);
                num--;
            }
            ll sum=  w[1];
            cout<<sum<<" * "<<num<<endl;
            printf("%.6f\n",sum*1.0/num);
        }
    }
    return 0;
}
