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
int a[42];
ll dp[42][11][42][2];
ll dfs(int pos,int status,int have,int limit,int xx,int sum)
{
    if(pos==-1)
    {
//        if(sum)
//        cout<<xx<<" "<<sum<<endl;
       return (ll)sum;
    }
    if(dp[pos][status][sum][limit]!=-1)return dp[pos][status][sum][limit];
    int end = limit?a[pos]:9;
    ll s=0;
    //cout<<pos<<" "<<end<<endl;
    for(int i=0;i<=end;i++)
    {
        if(i!=0)
        {
            s += dfs(pos-1,i,1,limit&&(i==end),xx*10+i,sum);
        }
        if(i==0)
        {
            if(have==0)
                s += dfs(pos-1,i,0,limit&&(i==end),xx*10+i,sum);
            else
            //cout<<pos<<" "<<xx<<" "<<endl;
            s += dfs(pos-1,i,1,limit&&(i==end),xx*10+i,sum+1);
        }
    }
    return dp[pos][status][sum][limit]=s;
    //cout<<pos<<" "<<xx<<")_"<<sum<<endl;
    return s;
}
ll f(ll n)
{
    if(n<0)return 0;
    int len=0;
    while(n)
    {
        a[len++]=n%10;n/=10;
    }
    memset(dp,-1,sizeof(dp));
    return dfs(len-1,0,0,1,0,0)+1;
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    ll x,y;
    int cas=0;
    while(t--)
    {
        scanf("%lld%lld",&x,&y);
        //cout<<f(y)<<endl;
        //f(x);
        printf("Case %d: %lld\n",++cas,f(y)-f(x-1));
    }
}
