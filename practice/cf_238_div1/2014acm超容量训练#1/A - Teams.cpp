#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
#define ll long long
const ll mod = 1000000007;
ll mul(ll a,ll n)
{
    ll b=1;
    while(n)
    {
        if(n%2)b=b*a%mod;
        a = a*a%mod;
        n/=2;
    }
    return b;
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        ll n;
        scanf("%lld",&n);
        ll tmp = mul(2,n-1);
        tmp *= n;
        tmp %= mod;
        printf("Case #%d: %lld\n",++cas,tmp);
    }
}
