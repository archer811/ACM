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
const ll mod = 1000000007;
int n,k,d;
ll dp[105][105][2];
int main()
{
    int i,j;
    while(scanf("%d%d%d",&n,&k,&d)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        dp[0][0][0]=1;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=k;j++)
            {
                for(int t=0;t<=n;t++)
                {
                    if(t+j<=n)
                    {
                        if(j>=d)
                        {
                            dp[i][t+j][1]+=(dp[i-1][t][0]+dp[i-1][t][1])%mod;
                        }
                        else
                        {
                            dp[i][t+j][0]+=dp[i-1][t][0]%mod;
                            dp[i][t+j][1]+=dp[i-1][t][1]%mod;
                        }


//                       cout<<i<<" "<<j<<" "<<t<<" "<<
//                       " "<<dp[i][t+j][1]<<" "<<dp[i][t+j][0]<<endl;
                    }
                }
            }
        }
        ll sum=0;
        for(i=1;i<=n;i++)
        {
            (sum += dp[i][n][1])%=mod;
        }
        cout<<sum<<endl;
    }
    return 0;
}
