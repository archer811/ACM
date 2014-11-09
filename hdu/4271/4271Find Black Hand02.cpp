#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
char s[10],t[10];
int main()
{
    int dp[10][10];
    int i,j,k;
    while(cin>>s>>t)
    {
        int len = strlen(s);
        int len1 = strlen(t);
        for(i=len-1;i>=0;i--)
            s[i+1]=s[i];
        for(i=len1-1;i>=0;i--)
            t[i+1]=t[i];
        dp[0][0]=0;
        for(i=1;i<=len;i++)
        {
            for(j=1;j<=len1;j++)
            {
                if(s[i]==t[j])
                    dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        cout<<dp[len][len1]<<endl;
    }
}
