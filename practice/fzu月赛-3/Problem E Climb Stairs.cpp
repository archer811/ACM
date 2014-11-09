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
const ll mod = 1000000007;
ll n,x,y,a,b;
ll dp[10005];
void work(ll l, ll r)
{
    for(ll i = l; i <= r; i++)
    {
        if(i-x>=0)
            dp[i] = dp[i-x];
        if(i-y>=0)
            dp[i] += dp[i-y];
        dp[i]%=mod;
    }
}
int main()
{
    int i;
    while(scanf("%lld %lld %lld %lld %lld",&n,&x,&y,&a,&b)!=EOF)
    {
        if(a>b)swap(a,b);
        memset(dp, 0, sizeof(dp));
        dp[0]=1;
        work(1,10000);
//        for(i=1;i<=10;i++)
//            cout<<dp[i]<<endl;
        ll ans =1;
        ans = dp[a];
        ans = ans*dp[b-a]%mod;
        ans= ans*dp[n-b]%mod;
        printf("%lld\n", ans);
    }
    return 0;
}
