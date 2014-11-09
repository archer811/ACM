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
#define N 3005
#define mod 1000000007
char s[N*2];
ll x[N];
int  n;//x[i]=1表示是w
ll dp[N][N][4]; //前i个中有j个是第一序列，两个序列的结尾有4种状态4
void init(ll y)
{
    memset(dp[y], 0, sizeof dp[y]);
}
int main()
{
    int i, j, T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%s",s);
        memset(dp,0,sizeof(dp));
        if(s[0]!='W')
        {
            printf("0\n");continue;
        }
        dp[0][0][0]=1;
        dp[0][1][2]=1;
        for(i=1;i<2*n;i++)
        {
            for(j=0;j<=i/2;j++)
            {
                cout<<i<<":"<<j<<endl;
                if(s[i]=='W')
                {
                    (dp[i][j][2]+=dp[i-1][j][0]+dp[i-1][j-1][3]+dp[i-1][j][1])%=mod;
                    cout<<dp[i][j][2]<<endl;
                    (dp[i][j][0]+=dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j][3])%=mod;
                }
                else
                {
                    (dp[i][j][3]+=dp[i-1][j][2]+dp[i-1][j][0]+dp[i-1][j][1])%=mod;
                    (dp[i][j][1]+=dp[i-1][j][0]+dp[i-1][j][2]+dp[i-1][j][3])%=mod;
                    cout<<j<<" "<<dp[i][j][1]<<"("<<dp[i-1][j][0]<<" "<<dp[i-1][j][2]<<" "
                    <<dp[i-1][j][3]<<endl;
                }

            }
        }
        cout<<dp[n][n/2][1]+dp[n][n/2][3]<<endl;
    }
    return 0;
}
