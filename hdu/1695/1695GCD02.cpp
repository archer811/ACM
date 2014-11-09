#include<iostream>
#include<time.h>
#include<cstdio>
using namespace std;
typedef __int64 llong;
llong gcd(llong a,llong b)
{
    return b?gcd(b,a%b):a;
}
llong phi[100005];
llong n,m,k;
llong fac[32],len;
bool ss[100005]= {1,1};
llong p[50001],plen=0;
llong limit,ans,mor;
llong Euler(llong n)
{
    llong i,ret=n;
    for(i=2; i*i<=n; ++i)
        if(n%i==0)
        {
            ret-=ret/i;
            while(n%i==0)
                n/=i;
        }
    if(n!=1)ret-=ret/n;
    return ret;
}
void mklist()
{
    llong i,j;
    for(i=2; i*i<=100000; ++i)
        if(!ss[i])
            for(j=i; j*i<=100000; ++j)
                ss[i*j]=true;
    for(i=2; i*i<=100000; ++i)if(!ss[i])p[plen++]=i;
}
void split(llong n)
{
    len=0;
    llong i;
    for(i=0; i<plen&&p[i]<=n; ++i)
    {
        if(n%p[i]==0)
        {
            fac[len]=p[i];
            len++;
            while(n%p[i]==0)n/=p[i];
        }
    }
    if(n!=1)
    {
        fac[len++]=n;
    }
    return;
}
void dfs(llong x,llong dep,llong val)
{
    llong i;
    if(dep==limit)
    {
        ans+=mor/val;
        return;
    }
    for(i=x+1; i<len; ++i)
        dfs(i,dep+1,val*fac[i]);
}
llong solve(llong x)
{
    llong ret=0;
    llong i;
    mor=m/k;
    if(mor<x)swap(mor,x);
    ret+=mor;
    split(x);
//[1,mor];
    for(i=1; i<=len; ++i)
    {
        limit=i;
        ans=0;
        dfs(-1,0,1);
        if(i&0x1)
            ret-=ans;
        else
            ret+=ans;
    }
    mor=x-1;
    ret-=x-1;
    for(i=1; i<=len; ++i)
    {
        limit=i;
        ans=0;
        dfs(-1,0,1);
        if(i&0x1)
            ret+=ans;
        else
            ret-=ans;
    }
    return ret;
}
int main()
{
    llong t;
    llong i,j,idx=0;
    mklist();
    for(t=1; t<=100000; ++t)phi[t]=Euler(t);
    llong ret;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%*d%d%*d%d%d",&n,&m,&k);
        printf("Case %d: ",++idx);
        if(k==0)
        {
            puts("0");
            continue;
        }
        ret=0;
        if(n>m)swap(n,m);
        for(i=1; i<=n; ++i)if(i%k==0)ret+=solve(i/k);
        printf("%I64d\n",ret);
    }
    return 0;
}
