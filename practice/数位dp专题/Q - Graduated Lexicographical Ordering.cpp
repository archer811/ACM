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
ll dp[20][11][163][163];
int d[20];
ll ans[163];
int len;
int a[20],b[20];
int M;
ll dfs(int pos,int status,int limit,int sum,int aim,int x)
{
    if(pos==-1)
    {
        return sum==aim;
    }
    if(!limit&&dp[pos][status][sum][aim]!=-1)
        return dp[pos][status][sum][aim];
    int end = limit?a[pos]:9;
    ll s=0;
    for(int i=0;i<=end;i++)
    {
        s += dfs(pos-1,i,limit&&(i==end),sum+i,aim,x*10+i);
    }
    if(!limit)return dp[pos][status][sum][aim]=s;
    return s;
}
int rsum;
void f(ll n)
{
    int i,j=0;
    while(n)
    {
        a[j++]=n%10;
        n/=10;
    }
    len =j;
    for(i=0;i<=len*9;i++)
    {
        ans[i]=dfs(j-1,0,1,0,i,0);
    }
    ans[0]--;
}
ll ans1,ans2;
int len2;
void ff(ll n)
{
    int i,j=0;
    while(n)
    {
        a[j++]=n%10;
        rsum += a[j-1];
        n/=10;
    }
    len2=j;
}
int main()
{
    int i,j;
    ll n,k;
    memset(dp,-1,sizeof(dp));
    while(scanf("%I64d%I64d",&n,&k)!=EOF)
    {
        if(n==0&&k==0)break;
        M=0;
        f(n);
        ans1=0;
        rsum=0;
        ff(k);
        for(i=0;i<rsum;i++)
            ans1 += ans[i];
        M=1;
        ans1 += dfs(len2-1,0,1,0,rsum,0);
        cout<<ans1<<"*"<<endl;
        ans2 =0;
        ll mysum=ans[0];
        for(i=1;i<=len*9;i++)
        {
            if(mysum+ans[i]>k)
            {
                i--;
                break;
            }
            mysum += ans[i];
        }
        int mark=1;
        for(j=len-2;j>=0;j--)
        {
            for(int t=)
        }
    }
}
