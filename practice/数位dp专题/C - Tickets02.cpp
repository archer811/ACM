#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define ll __int64
ll getsum1(int n,int k)
{
     ll B  = 1;
     for(int i=0;i<n;i++)B*=k;
     return B*n*(k-1)/2;
}
ll getsum2(int prefixsum,int n,int k)
{
    ll B = getsum1(n,k);
    ll C = prefixsum;
    for(int i=0;i<n;i++)
        C*=k;
    return B+C;
}
ll getsum3(int prefixsum,ll n,int k)
{
    if(n<k)
    {
        ll ret =0;
        for(int i=0;i<=n;i++)
            ret += prefixsum+i;
        return ret;
    }
    ll t = 1,tn = n;
    int d =0;
    while(tn>=k)
    {
        tn/=k;
        t*=k;
        d++;
    }
    ll ret  =0;
    for(int i=0;i<tn;i++)
        ret += getsum2(prefixsum+i,d,k);
    ret += getsum3(prefixsum+tn,n-t*tn,k);
    return ret;
}
int main()
{
    int i,j;
    ll l,r,k;
    while(scanf("%I64d%I64d%I64d",&l,&r,&k)!=EOF)
    {
        ll sum=0;
        for(ll s = l;s <= r;s++)
        {
            ll  t = s;
            while(t)
            {
                sum += t%10;
                t/=10;
            }
        }
        cout<<sum<<endl;
    }
}
