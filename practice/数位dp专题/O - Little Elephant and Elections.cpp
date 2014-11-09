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
ll ans[11];
int d[11];
ll dp[11][11][11][11];
const ll mod = 1000000007;
ll dfs(int pos,int status,int limit,int sum,int aim)
{
    int i,j;
    if(pos==-1)
    {
        return sum==aim;
    }
    if(!limit&&dp[pos][status][sum][aim]!=-1)
        return dp[pos][status][sum][aim];
    int end = limit?d[pos]:9;
    ll ans1=0;
    for(i=0;i<=end;i++)
    {
        if(i==4||i==7)
            ans1 += dfs(pos-1,i,limit&&(i==end),sum+1,aim);
        else
            ans1 += dfs(pos-1,i,limit&&(i==end),sum,aim);
        ans1 %= mod;
    }
    if(!limit)return dp[pos][status][sum][aim]=ans1;
    return ans1;
}
int len;
ll Ans;
void f(ll m)
{
    int i,j=0;
    while(m)
    {
        d[j++]=m%10;
        m/=10;
    }
    len = j;
    memset(dp,-1,sizeof(dp));
    for(i=0;i<=j;i++)
    {
        ans[i]=dfs(j-1,0,1,0,i);


    }
    ans[0]--;
}
ll y[11];
int s[11];
void getans(int last,int start,int now)
{
    if(now==6)
    {
        ll tmp=1;
        for(int i=0;i<=len;i++)
        {
            y[i]=ans[i];
        }
//        for(int i=0;i<6;i++)
//            cout<<s[i]<<" ";
//        cout<<endl;
        int error=0;
        for(int i=0;i<6;i++)
        {
            int g = s[i];
            if(y[g]>=1)
            {
                tmp = tmp*y[g]%mod;
                y[g]--;
            }
            else
            {
                error=1;
            }
        }
        if(error)return;
//        cout<<tmp*ans[last]<<endl;
        Ans += tmp*ans[last]%mod;
        Ans %= mod;
        return;
    }
    for(int i=start;i>=0;i--)
    {
        s[now]=i;
        getans(last,start-i,now+1);
    }
}
int main()
{
    int i,j;
    ll m;
    while(scanf("%I64d",&m)!=EOF)
    {
        for(i=0;i<11;i++)
            ans[i]=0;
        f(m);
        Ans =0;
        for(i=1;i<=len;i++)
        {
            getans(i,i-1,0);
        }
        cout<<Ans<<endl;
    }
}
