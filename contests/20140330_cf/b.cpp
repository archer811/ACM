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
#define ll __int64
const ll mod = 1000000007;
#define N 1005
ll dp[N][2];
ll a[N];
ll n;
int main()
{
    ll i, j, k, u, v;
    while(cin>>n)
    {
        memset(dp, 0, sizeof(dp));
        for(i=1; i<=n; i++)
            cin>>a[i];
        dp[1][0] = 1;
        dp[1][1] = 2;
        for(i=2; i<=n; i++)
        {
            ll ans = 0;
            for(j = a[i]; j<i; j++)
                (ans+= dp[j][1])%=mod;
            ans+=(ll)2;
            dp[i][1] = ans%mod;
        }
        ll sum = 0;
        for(i=1; i<=n; i++)
           (sum += dp[i][1])%=mod;
        cout<<sum<<endl;
    }
    return 0;
}
