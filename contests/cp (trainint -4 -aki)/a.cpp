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
ll f2(ll n)
{
    ll x=1;
    ll n2=n;
    while(n)
    {
        n/=10;
        x*=10;
    }
    return x%n2==0;
}
ll f(ll n)
{
    ll x=1,y=1;
    int i,j;
    ll sum=0;
    for(i=0;i<=32;i++)
    {
        y = 1;
        for(j=0;j<=32;j++)
        {
            if(x*y<=n&&f2(x*y))sum++;
            y = y*(ll)5;
        }
        x = x*(ll)2;
    }
    return sum;
}
int main()
{
    ll n,m;
    while(scanf("%lld%lld",&n,&m)!=EOF)
    {
        printf("%lld\n",f(m)-f(n-1));
    }
    return 0;
}
