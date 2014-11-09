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
int digit[66];
ll dp[66][12][2];
ll dfs(int pos,int status,int limit,int have)
{
    if(pos==-1)return (ll)have;
    if(!limit&&dp[pos][status][have]!=-1)
        return dp[pos][status][have];
    int end=limit?digit[pos]:9;
    ll ans=0;
    for(int i=0;i<=end;i++)
    {
        if(status==4&&i==9)
            ans += dfs(pos-1,i,limit&&(i==end),1);
        else ans+=dfs(pos-1,i,limit&&(i==end),have);
    }
    if(!limit)dp[pos][status][have]=ans;
    return ans;
}
ll f(ll n)
{
    int len=0;
    while(n)
    {
        digit[len++]=n%10;
        n/=10;
    }
    return dfs(len-1,0,1,0);
}
int main()
{
    int i,j,k;
    ll n;
    scanf("%d",&k);
    while(k--)
    {
        cin>>n;
        memset(dp,-1,sizeof(dp));
        cout<<f(n)<<endl;
    }
}
