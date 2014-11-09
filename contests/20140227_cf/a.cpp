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
int a[1000005];
ll prime[1000006];
int g;
int num[1000006];
ll c[500*32+505][505];
const int mod = 1000000007 ;
void f(ll n)
{
    for(int i=0;i<g;i++)
    {
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                num[i]++;
                n/=prime[i];
            }
        }
    }
    if(n!=1)
    {
        num[g]=1;
        prime[g++]=n;
    }
}
int main()
{
    int i,j,n;
    g=0;
    for(i=2;i<=1000000;i++)
    {
        if(a[i]==0)
        {
            prime[g++]=i;
            for(j=i+i;j<=1000000;j+=i)
                a[j]=1;
        }
    }
    for(i=0;i<500*32+505;i++)
        c[i][0]=1;
    for(i=0;i<=500;i++)
        c[i][i]=1;
    for(i=2;i<500*32+505;i++)
    {
        for(j=1;j<=500;j++)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    }
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<=1000000;i++)
            num[i]=0;
        for(i=1;i<=n;i++)
        {
            ll x;
            scanf("%I64d",&x);
            f(x);
        }
        ll ans=1;
        for(i=0;i<g;i++)
        {
            int tmp = num[i];
            ans *= c[tmp+n-1][n-1];
            ans %= mod;
        }
        cout<<ans<<endl;
    }
}
