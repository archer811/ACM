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
#define ll long long
const ll mod = 1000000007;
const int N = 100005;
char s[N];
ll p;
ll g[4][N<<2];
#define lson rt<<1
#define rson rt<<1|1
void up(int l,int r,int mid,int rt)
{
    for(int i=0; i<4; i++)
        g[i][rt]=g[i][lson]+g[i][rson];
}
void build(int l,int r,int rt)
{
    for(int i=0; i<4; i++)
        g[i][rt]=0;
    if(l==r)
    {
        if(l&1)
        {
            g[1][rt]=s[l]-'0';
            g[3][rt]=(ll)(s[l]-'0')*(ll)(p-l)%mod;
        }
        else
        {
            g[0][rt]=s[l]-'0';
            g[2][rt]=(ll)(s[l]-'0')*(ll)(p-l)%mod;
        }
        return;
    }
    int mid = (l+r)>>1;
    build(l,mid,lson);
    build(mid+1,r,rson);
    up(l,r,mid,rt);
}
ll query(int x,int y,int l,int r,int rt,int d)
{
    if(x<=l&&y>=r)return g[d][rt];
    int mid = (l+r)>>1;
    ll sum=0;
    if(x<=mid)
        (sum += query(x,y,l,mid,lson,d) )%= mod;
    if(y>mid)
        (sum += query(x,y,mid+1,r,rson,d) )%= mod;
    return sum;
}
void update(int x,ll y,int l,int r,int rt)
{
    if(l==r)
    {
        if(l&1)
        {
            g[1][rt]=y;
            g[3][rt]=(ll)(y)*(ll)(p-l)%mod;
        }
        else
        {
            g[0][rt]=y;
            g[2][rt]=(ll)(y)*(ll)(p-l)%mod;
        }
        return;
    }
    int mid = (l+r)>>1;
    if(x<=mid)update(x,y,l,mid,lson);
    else update(x,y,mid+1,r,rson);
    up(l,r,mid,rt);
}
ll f1(ll len)
{
    if(len&1)
    {
        ll a = len-1+2;
        ll b = len/2;
        if((a&1)==0)a/=2;
        else b/=2;
        return a%mod*(b%mod)%mod;
    }
    else
    {
        ll a = len-1+1;
        ll b = len/2;
        if((a&1)==0)a/=2;
        else b/=2;
        return a%mod*(b%mod)%mod;
    }
}
ll f2(ll len)
{
    return f1(len-1);
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        p = strlen(s);
        build(0,p-1,1);
        ll l,r;
        int q,kind;
        scanf("%d",&q);
        ll x,y;
        while(q--)
        {
            scanf("%d%lld%lld",&kind,&x,&y);
            if(kind==1)
            {
                x--;
                update(x,y,0,p-1,1);
            }
            else
            {
                x--;y--;
                l = x%p;
                r = y%p;

                ll len = y-x+1;
                if(l!=0)len -= (p-1-l+1);
                if(r!=p-1)len -= (r-0+1);
                len = len/p;
                ll sum=0;

                ll ff = l+len*p+1;

                if(r>=l&&y-x+1<p)
                {
                    int d1,d2;
                    if(l&1)
                    {
                        d1=1;
                        d2=3;
                    }
                    else
                    {
                        d1=0;
                        d2=2;
                    }
                    ll tmp = query(l,r,0,p-1,1,d2)-query(l,r,0,p-1,1,d1)*(ll)(p-1-r)%mod;
                    tmp = (tmp%mod + mod)%mod;
                    sum = (sum + tmp)%mod;
                }
                else
                {
                    if(l!=0)
                    {
                        if(l&1) sum += (query(l,p-1,0,p-1,1,1)*((ll)(y-(p-1))%mod)%mod+
                                            query(l,p-1,0,p-1,1,3))%mod;
                        else sum += (query(l,p-1,0,p-1,1,0)*((ll)(y-(p-1))%mod)%mod+
                                         query(l,p-1,0,p-1,1,2))%mod;
                        sum %= mod;
                    }
                    if(len>=1)
                    {
                        int d1,d2;
                        if(l==0)
                        {
                            d1=0;
                            d2=2;
                        }
                        else
                        {
                            if(((p-l)&1)==0)
                                d1=0,d2=2;
                            else
                                d1=1,d2=3;
                        }


                        ll tmp = 0;
                        if( (p&1)==0 )
                        {

                            len %= mod;
                            ll g =  (len*(len-1)/2)%mod*((ll)(p)%mod)%mod;
                            if(r!=p-1)g+=(ll)(r+1)*len%mod;

                            tmp = query(0,p-1,0,p-1,1,d2)*len%mod+
                                  query(0,p-1,0,p-1,1,d1)*(g%mod)%mod;
                        }
                        else
                        {

                            ll l1 = len/2;
                            if(len&1)l1++;
                            ll l2 = len-l1;
                            l1 %= mod;
                            l2 %= mod;



                            ll s1 = f1(len)%mod*(p%mod)%mod;
                            ll s2 = f2(len)%mod*(p%mod)%mod;
                            len %= mod;

                            if(r!=p-1)
                            {
                                (s1 += (ll)(r+1)%mod*l1%mod)%=mod;
                                (s2 += (ll)(r+1)%mod*l2%mod)%=mod;
                            }

                            tmp = query(0,p-1,0,p-1,1,d2)*l1%mod;
                            tmp = tmp + query(0,p-1,0,p-1,1,5-d2)*l2%mod;
                            tmp %= mod;
                            tmp = tmp + query(0,p-1,0,p-1,1,d1)*s1%mod;
                            tmp %= mod;
                            tmp = tmp + query(0,p-1,0,p-1,1,1-d1)*s2%mod;
                            tmp %= mod;

                        }

                        sum = (sum+tmp)%mod;
                    }
                    if(r!=p-1)
                    {
                        int d1,d2;
                        if( (ff)&1 )
                        {
                           d1=1;
                            d2=3;
                        }
                        else
                        {

                            d1=0;
                            d2=2;
                        }
                        ll tmp = query(0,r,0,p-1,1,d2)-query(0,r,0,p-1,1,d1)*(p-1-r)%mod;
                        tmp = (tmp%mod + mod)%mod;
                        sum = (sum + tmp)%mod;
                    }
                }
                printf("%lld\n",sum%mod);
            }
        }
    }
    return 0;
}
