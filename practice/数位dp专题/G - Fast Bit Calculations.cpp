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
int a[33];
ll dp[33][2][33][2];
ll dfs(int pos,int pre,int limit,int sum)
{
    if(pos==-1)return sum;
    if(dp[pos][pre][sum][limit]!=-1)
        return dp[pos][pre][sum][limit];
    int end = limit?a[pos]:1;
    ll s=0;
    for(int i=0;i<=end;i++)
    {
        if(pre==1&&i==1)
           s += dfs(pos-1,i,limit&&(i==end),sum+1);
        else s += dfs(pos-1,i,limit&&(i==end),sum);
    }
    return dp[pos][pre][sum][limit]=s;
}
ll f(ll n)
{
    int i,j=0;
    while(n)
    {
        a[j++]=n%2;
        n/=2;
    }
    memset(dp,-1,sizeof(dp));
    return dfs(j-1,0,1,0);
}
int main()
{
    int i,j,t;
    ll n;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        scanf("%lld",&n);
        printf("Case %d: %lld\n",++cas,f(n));
    }
}
