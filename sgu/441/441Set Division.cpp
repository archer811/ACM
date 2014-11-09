#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
#define ll __int64
ll c[11][11];
ll cs[12];
ll mod = 2007;
ll mul_mod(ll a,ll b)  //(a*b)%m
{
    ll ans=0;
    ll d=a%mod;
    while(b)
    {
        if(b&1)ans=ans+d;
        if(ans>=mod)ans-=mod;
        d<<=1;
        if(d>=mod)d-=mod;
        b>>=1;
    }
    return ans;
}
ll powMod(ll a,ll n)
{
    ll res = (ll)1;
    while(n)
    {
        if(n&1)res = mul_mod(res,a);
        a =mul_mod(a,a);
        n/=2;
    }
    return res;
}
int main()
{
    int n,k,i,j;
    for(i=0;i<11;i++)
        c[i][i]=1,c[i][0]=1;
    for(i=1;i<11;i++)
    {
        for(j=1;j<i;j++)
        {
            c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }
    cs[1]=1;
    cs[0]=1;
    for(i=2;i<=10;i++)
        cs[i]=cs[i-1]*i;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        ll sum=0;
        mod = cs[k]*(ll)2007;
         for(i=0;i<=k-1;i++)
         {
             ll ans;
             if(i%2)ans =-1;else ans=1;
             ans *= c[k][i];
             ans = (ans*powMod(k-i,n));
             sum += ans;
             sum = (sum%mod+mod)%mod;
         }
         //cout<<sum<<endl;
         sum = (sum+mod)%mod;
         //cout<<sum<<endl;
         printf("%I64d\n",sum/cs[k]);
    }
    return 0;
}
