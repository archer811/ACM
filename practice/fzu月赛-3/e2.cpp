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
#define ll long long
#define mod 1000000007
#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define Mid(x,y) ((x+y)>>1)
#define N 10005
using namespace std;
ll n,x,y,a,b;
ll dp[N];
ll work(ll l, ll r)
{
    for(ll i = l; i <= r; i++)
    {
        if(i-x>=0)
            dp[i] = dp[i-x];
        if(i-y>=0)
            dp[i] += dp[i-y];
        dp[i]%=mod;
    }
    return dp[r];
}
int main()
{
    ll i;
    while(~scanf("%lld %lld %lld %lld %lld",&n,&x,&y,&a,&b))
    {
        if(a>b)swap(a,b);
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        ll u = work(1, a);
        memset(dp, 0, sizeof(dp));
        dp[a] = u;
        u = work(a+1,b);
        memset(dp, 0, sizeof(dp));
        dp[b] = u;
        printf("%lld\n", work(b+1,n));
    }
    return 0;
}
