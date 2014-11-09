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
ll n;
int m;
ll dp[263000][105];
int digit[11];
int len;
ll dfs(int pos,int status,int mod,int state)
{
    cout<<pos<<" "<<status<<" "<<mod<<" "<<state<<endl;
    if(pos==0)
    {
        return mod==0;
    }
    if(dp[state][mod]!=-1)
        return dp[state][mod];
    ll sum=0;
    int start=0;
    if(pos==len)start=1;
    for(int i=start;i<=9;i++)
    {
        if(digit[i]==0)continue;
        digit[i]--;
        sum += dfs(pos-1,i,(mod*10+i)%m,state|(1<<(pos-1)));
        digit[i]++;
    }
    return dp[state][mod]=sum;
}
int main()
{
    int i,j;
    while(cin>>n>>m)
    {
        memset(dp,-1,sizeof(dp));
        for(i=0;i<=9;i++)
            digit[i]=0;
        ll _n=n;len=0;
        while(_n)
        {
            len++;
            int tmp = _n%10;
            _n/=10;
            digit[tmp]++;
        }
        ll ans = dfs(len,0,0,0);
        cout<<ans<<endl;
    }
}
