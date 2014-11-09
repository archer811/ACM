#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
double dp[1005][1005];
int main()
{
    int i,j,k,n,s;
    while(scanf("%d%d",&n,&s)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        for(i=n;i>=0;i--)
        {
            for(j=s;j>=0;j--)
            {
                if(i==n&&j==s)continue;
                double a = dp[i][j+1]*i*1.0/n*1.0*(s-j)/s;
                double b = dp[i+1][j]*1.0*(n-i)/n*j*1.0/s;
                double c = dp[i+1][j+1]*1.0*(n-i)/n*1.0*(s-j)/s;
                double sum=0;
                sum=a+b+c;
                sum = (sum+1)*1.0/(1-i*j*1.0/n/s);
                //cout<<i<< " "<<j<<" "<<sum<<endl;
                dp[i][j]=sum;
            }
        }
        printf("%4f\n",dp[0][0]);
    }
}
