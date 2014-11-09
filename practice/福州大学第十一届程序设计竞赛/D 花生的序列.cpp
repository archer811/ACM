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
char s[60000];
int vis[60000];
#define ll long long
const ll mod = 1000000007;
ll dp[2][3005][2];
ll c[6005][6005];
int main()
{
    int i,j,t;
    for(i=0;i<6005;i++)
    {
        c[i][0]=1;
        if(i<=3000)
            c[i][i]=1;
    }
    for(i=2;i<=6000;i++)
    {
        for(j=1;j<i;j++)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    }
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s",s);
        int x=0,y=0;
        for(i=0;i<2*n;i++)
            if(s[i]=='W')x++;
            else y++;
        if(x!=y||n%2)
        {
            printf("0\n");continue;
        }
        for(i=0;i<n;i++)
            dp[0][i][0]=dp[0][i][1]=-1;
        dp[0][0][1]=1;
        int index=1;
        for(i=0;i<2*n;i++)
        {
            for(j=0;j<=n;j++)
                dp[index][j][0]=dp[index][j][1]=-1;
            for(j=0;j<=n;j++)
            {
                if(s[i]=='W')
                {
                    if(j-1>=0&&dp[index^1][j-1][0]!=-1)
                    {
                        if(dp[index][j][0]==-1)dp[index][j][0]=dp[index^1][j-1][0];
                        else dp[index][j][0]+=dp[index^1][j-1][0];
                    }
                   // if(i==0&&j==1)
                    //    cout<<dp[index^1][j-1][1]<<"*"<<endl;
                    if(j-1>=0&&dp[index^1][j-1][1]!=-1)
                    {
                        if(dp[index][j][0]==-1)dp[index][j][0]=dp[index^1][j-1][1];
                        else dp[index][j][0]+=dp[index^1][j-1][1];
                    }
                   // cout<<i<<" "<<dp[index][1][0]<<endl;
                }
                else
                {
                    if(i==1&&j==1)cout<<dp[index^1][j][0]<<"()"<<endl;
                    if(dp[index^1][j][0]!=-1)
                    {
                        if(dp[index][j][1]==-1)dp[index][j][1]=dp[index^1][j][0];
                        else dp[index][j][1]+=dp[index^1][j][0];
                    }
                    if(j-1>=0&&dp[index^1][j-1][1]!=-1)
                    {
                        if(dp[index][j][1]==-1)dp[index][j][1]=dp[index^1][j-1][1];
                        else dp[index][j][1]+=dp[index^1][j-1][1];
                    }
                }

            }
            cout<<i<<"*"<<endl;
            for(j=0;j<=n;j++)
                    cout<<dp[index][j][0]<<" "<<dp[index][j][1]<<endl;
            index^=1;
        }
        index^=1;
        ll ans = dp[index][n][1];
        if(ans==-1)
        {
            printf("0\n");continue;
        }
        ans = ans*c[n][n/2]%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
