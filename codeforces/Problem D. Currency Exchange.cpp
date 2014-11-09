#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<map>
using namespace std;

#define ll __int64
int digit[22];
ll dp[20][59100];
int o[]= {1,3,9,27,81,243,729,2187,6561,19683};
int judge(int x,int num)
{
    int y = (x/o[num])%3;
    return y;
}
int now=0;
ll dfs(int pos,int status,int limit,int st,int x)
{
    if(pos==-1)
    {
        return 1;
    }
    if(!limit&&dp[pos][st]!=-1)
        return dp[pos][st];
    int end = limit?digit[pos]:9;
    ll sum=0;
    for(int i=0; i<=end; i++)
    {
        if(x==0&&i==0)
        {
            sum += dfs(pos-1,i,limit&&(i==end),st,x);
            continue;
        }
        int g = judge(st,i);
        int oo=x;
        if(i>0)oo=1;
        if(g<=1)
            sum += dfs(pos-1,i,limit&&(i==end),st+o[i],oo);
    }
    if(!limit)
        return dp[pos][st]=sum;
    else return sum;
}
ll f(ll x)
{
    int i,j;
    j=0;
    while(x)
    {
        digit[j++]=x%10;
        x/=10;
    }
    ll ans = dfs(j-1,0,1,0,0);
    //cout<<ans<<endl;
    return ans;
}
int main()
{
    freopen("exchange.in","r",stdin);
    freopen("exchange.out","w",stdout);
    ll l,r;
    int i,j;
    for(i=0;i<=18;i++)
    {
        //for(j=0;j<=9;j++)
        {
            for(int k=0;k<59100;k++)
              dp[i][k]=-1;
        }
    }
    while(scanf("%I64d%I64d",&l,&r)!=EOF)
    {
        ll ans = f(r)-f(l-1);
        printf("%I64d\n",ans);
    }
    return 0;
}
