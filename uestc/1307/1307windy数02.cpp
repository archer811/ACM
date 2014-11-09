#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
ll dp[20][20],num[20];
ll dfs(ll pos,ll st,ll pre,bool flag)
{
       if(pos==0)return st==1;
       if(flag&&st&&dp[pos][pre]!=-1)return dp[pos][pre];
       ll ans=0;
       ll u=flag?9:num[pos];
       for(ll d=0;d<=u;d++)
       {
              if(!st||abs(pre-d)>=2)
              ans+=dfs(pos-1,st||d>0,d,flag||d<u);
       }
       if(flag&&st)dp[pos][pre]=ans;
       return ans;
}
ll solve(ll x)
{
       ll len=0;
       while(x)
       {
              num[++len]=x%10;
              x/=10;
       }
       return dfs(len,0,11,0);
}
int main()
{
       ll i,j,k,m,n;
       memset(dp,-1,sizeof(dp));
       while(~scanf("%lld%lld",&m,&n))
       {
              printf("%lld\n",solve(n)-solve(m-1));
       }
       return 0;
}
