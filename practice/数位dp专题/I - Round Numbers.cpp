#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
#define ll __int64
ll dp[40][40][40][2];
int a[40];
ll dfs(int pos,int s1,int s2,int limit,int have)
{
    if(pos==-1)
    {
        if(s1>=s2)return 1;
        return 0;
    }
    if(!limit&&dp[pos][s1][s2][have]!=-1)
        return dp[pos][s1][s2][have];
    ll sum=0;
    int end = limit?a[pos]:1;
    for(int i=0;i<=end;i++)
    {
        if(have==0&&i==0)
        {
            sum += dfs(pos-1,s1,s2,limit&&(i==end),0);
        }
        else if(have==0&&i==1)
            sum += dfs(pos-1,s1,s2+1,limit&&(i==end),1);
        else if(i==0)sum += dfs(pos-1,s1+1,s2,limit&&(i==end),1);
        else sum += dfs(pos-1,s1,s2+1,limit&&(i==end),1);
    }
    if(!limit)
        return dp[pos][s1][s2][have]=sum;
    return sum;
}
ll f(ll n)
{
    int i,j=0;
    while(n)
    {
        a[j++]=n%2;n/=2;
    }
    memset(dp,-1,sizeof(dp));
    return dfs(j-1,0,0,1,0);
}
int main()
{
    int i,j;
    ll x,y;
    while(scanf("%I64d%I64d",&x,&y)!=EOF)
    {
        printf("%I64d\n",f(y)-f(x-1));
    }
}
