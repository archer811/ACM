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
char s[5005],t[5005];
int dp[5005][5005];
int main()
{
    int i,j;
    while(cin>>s>>t)
    {
        memset(dp,-1,sizeof(dp));
        int len=strlen(s);
        int len2=strlen(t);
        dp[0][0]=0;
        for(i=1;i<=len;i++)
        {
            for(j=1;j<=len2;j++)
            {
                int i2=i-1,j2=j-1;
                if(s[i2]==t[j2])
                {
                    cout<<i<<" "<<j<<endl;
                    if(dp[i][j]==-1&&dp[i-1][j-1]!=-1)
                        dp[i][j]=dp[i-1][j-1]+1;
                    else if(dp[i][j]!=-1&&dp[i-1][j-1]!=-1)
                        dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
                }
                else
                {
                    if(dp[i-1][j]!=-1)
                    {
                        if(dp[i][j]==-1)
                            dp[i][j]=dp[i-1][j];
                        else
                            dp[i][j]=min(dp[i][j],dp[i-1][j]);
                    }
                    else if(dp[i][j-1]!=-1)
                    {
                        if(dp[i][j]==-1)
                            dp[i][j]=dp[i][j-1];
                        else
                            dp[i][j]=min(dp[i][j],dp[i][j-1]);
                    }
                }
            }
        }
        int ans=-1;
        for(i=1;i<=len;i++)
        {
            for(j=1;j<=len2;j++)
            {
                if(ans==-1)
                    ans=dp[i][j];
                else if(ans>dp[i][j])
                    ans=dp[i][j];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
