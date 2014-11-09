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
#define ll long long
int dp[5006];
int main()
{
    int i,j;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(~scanf("%d",&n))
    {
        memset(dp,0,sizeof(dp));
        dp[n]=1;
        for(int i=n-1;i>=1;i++)
        {
            for(int j=i+2;j<=n;j++)
                dp[i]=dp[i]+dp[j];
        }
        for(int i=1;i<=n;i++) cout<<dp[i];cout<<"\n";
    }
    return 0;
}
