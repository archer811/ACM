#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int n,m,t;
double f[1005][33];
double sum[1005][33][33];
int main()
{
    int i,j,k;
    while(scanf("%d%d%d",&n,&t,&m)!=EOF)
    {
        if(n==0&&t==0&&m==0)break;
        for(i=1;i<=t;i++)
        {
            for(j=1;j<=n;j++)
                scanf("%lf",&f[i][j]);
        }
        memset(sum,0,sizeof(sum));
        for(i=1;i<=t;i++)
        {
            sum[i][1][1]=f[i][1];
            sum[i][1][0]=1.0-f[i][1];
        }
        for(i=1;i<=t;i++)
        {
            for(j=2;j<=n;j++)
            {
                for(k=0;k<=n;k++)
                {
                    sum[i][j][k+1]+=sum[i][j-1][k]*f[i][j];
                    sum[i][j][k]+=sum[i][j-1][k]*(1.0-f[i][j]);
                }
            }
        }
        double sum1=1,sum2=1;
        for(i=1;i<=t;i++)
        {
            double _sum=0,_sum2=0;
            for(j=1;j<=n;j++)
                _sum+=sum[i][n][j];
            for(j=1;j<m;j++)
                _sum2+=sum[i][n][j];
            sum1 *= _sum;
            sum2 *= _sum2;
        }
        printf("%.3f\n",sum1-sum2);
        //cout<<sum1-sum2<<endl;
    }
}
