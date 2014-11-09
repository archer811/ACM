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
int a[20];
ll dp[20][20][6000][2];
int len;
ll dfs(int pos,int zhong,int status,int limit,int now,int sum,int xx)
{
    if(pos==-1)
    {
        //if(zhong!=len&&now==3000)
        //   cout<<xx<<endl;
        return now==3000;
    }

    if(dp[pos][zhong][now][limit]!=-1)
    {
       // cout<<pos<<" "<<zhong<<" "<<now<<" "<<dp[pos][zhong][now]<<endl;
        return dp[pos][zhong][now][limit];
    }
    ll s=0;
    int end = limit?a[pos]:9;
    //cout<<end<<"&"<<endl;
    for(int i=0;i<=end;i++)
    {
        s += dfs(pos-1,zhong,i,limit&&(i==end),now+i*(zhong-pos),0,xx*10+i);
//        if(pos<zhong)
//            s += dfs(pos-1,zhong,i,limit&&(i==end),now+sum+i,sum+i,xx*10+i);
//        else if(pos==zhong)
//        {
//            s += dfs(pos-1,zhong,i,limit&&(i==end),now,1,xx*10+i);
//           // s += dfs(pos-1,len,i,limit&&(i==end),now+sum+i,sum+i,xx*10+i);
//        }
//        else if(pos>zhong)
//            s += dfs(pos-1,zhong,i,limit&&(i==end),now-i*sum,sum+1,xx*10+i);
    }
    return dp[pos][zhong][now][limit]=s;
    return s;
}
ll f(ll n)
{
    if(n<0)return 0;
    len=0;
    while(n)
    {
        a[len++]=n%10;
        n/=10;
    }
    memset(dp,-1,sizeof(dp));
    ll sum=0;
    for(int i=len-1;i>=0;i--)
        sum += dfs(len-1,i,0,1,3000,0,0);
    return sum-len+1;
}
int main()
{
    int i,j,t;
    ll x,y;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&x,&y);
        ll tmp = f(y)-f(x-1);
        printf("%lld\n",tmp);
//cout<<f(y)<<" "<<f(x-1)<<endl;
    }
}
