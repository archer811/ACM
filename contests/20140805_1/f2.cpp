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
#define ll unsigned long long
const ll mod = ((ll)1<<60);
void find(ll d,ll &X,ll &Y)
{
    ll p0=1,p1=0,p;
    ll q0=0,q1=1,q;
    ll a0=sqrt((double)d),a=a0;
    ll g0=0,h0=1,g,h;
    while(true)
    {
        g=-g0+a*h0;
        h=(d-g*g)/h0;
        p=a*p0+p1;
        q=a*q0+q1;
        a=(g+a0)/h;
        if(p*p-d*q*q==1)
        {
            X=p;Y=q;
            return;
        }
        p1=p0;
        p0=p;
        q1=q0;q0=q;
        g0=g;h0=h;
    }
}
ll solve(ll N)
{
    ll x1,y1;
    find(N,x1,y1);
    return x1;
}
int main()
{
    ll k;
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    while(scanf("%lld",&k)!=EOF)
    {
        ll g=sqrt(k);
        if(g*g==k)
        {
            puts("no solution");
            continue;
        }
        ll ans = solve(k);
        if(ans>=mod)
        {
            puts("no solution");
            continue;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
