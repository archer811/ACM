#include<stdio.h>
#include<string.h>

int m,t,n;
double dp[1001][35][35],s[1001][35],p[1001][35];
int main()
{
    while(scanf("%d%d%d",&m,&t,&n) && (m+t+n))
    {
        memset(dp,0,sizeof(dp));
        memset(s,0,sizeof(s));
        for(int i=1; i<=t; i++)
            for(int j=1; j<=m; j++)
                scanf("%lf",&p[i][j]);
        for(int i=1; i<=t; i++)   dp[i][0][0]=1.0;
        for(int i=1; i<=t; i++)
        {
            for(int j=1; j<=m; j++)
                dp[i][j][0]=dp[i][j-1][0]*(1-p[i][j]);
            for(int j=1; j<=m; j++)
                for(int k=1; k<=j; k++)
                    dp[i][j][k]=dp[i][j-1][k-1]*p[i][j]+dp[i][j-1][k]*(1-p[i][j]);
            s[i][0]=dp[i][m][0];
            for(int k=1; k<=m; k++)
                s[i][k]=s[i][k-1]+dp[i][m][k];
        }
        double p1=1.0;
        for(int i=1; i<=t; i++)
            p1*=(s[i][m]-s[i][0]);
        double p2=1.0;
        for(int i=1; i<=t; i++)
            p2*=(s[i][n-1]-s[i][0]);
        printf("%.3lf\n",p1-p2);
    }
    return 0;
}
