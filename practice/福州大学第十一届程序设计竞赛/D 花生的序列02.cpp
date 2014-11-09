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
char s[3000];
#pragma comment(linker, "/STACK:36777216")
#define ll long long
const ll mod = 1000000007;
ll dp[1005][1005];
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s",s+1);
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            {
                int k = i+j+1;
                if(s[k]=='W')
                {
                    if(i%2==0)
                        (dp[i+1][j]+=dp[i][j])%=mod;
                    if(j%2==0)
                        (dp[i][j+1]+=dp[i][j])%=mod;
                }
                else
                {
                    if(i%2)
                        (dp[i+1][j]+=dp[i][j])%=mod;
                    if(j%2)
                        (dp[i][j+1]+=dp[i][j])%=mod;
                }
            }
        }
        printf("%lld\n",dp[n][n]);
    }
    return 0;
}
