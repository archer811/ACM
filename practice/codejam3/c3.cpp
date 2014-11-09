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
const int maxn = 110000;
char s[4][maxn];
int dp[maxn][4];
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<3;i++)
            scanf("%s",s[i]+1);
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
        {
            int tmp=0;
            if(s[2][i]>='0'&&s[2][i]<='9')
                tmp = s[2][i]-'0';
            dp[i][0]=max(dp[i-1][0],dp[i-1][1])+tmp;

            if(s[1][i]>='0'&&s[1][i]<='9')
                tmp = s[1][i]-'0';
            dp[i][1]=max(dp[i-1][0],dp[i-1][2])+tmp;

            if(s[0][i]>='0'&&s[0][i]<='9')
                tmp = s[0][i]-'0';
            dp[i][2]=dp[i-1][1]+tmp;
        }
        printf("%d\n",max(max(dp[n][0],dp[n][1]),dp[n][2]));
    }
    return 0;
}
