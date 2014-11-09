#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int n,m,w;
double dp[1005][105];
int pre[1005][105];
double a[105][105],b[105][105];
int we[1005];
int flag=0;
const double inf = 99999999;
const double eps = 1e-15;
int main()
{
    int i,j,k,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&w);
        for(i=1; i<=n; i++)
            scanf("%d",&we[i]);
        for(i=0; i<=n; i++)
        {
            for(j=0; j<m; j++)
                dp[i][j]=pre[i][j]=0;
        }
        for(i=0; i<m; i++)
        {
            for(j=0; j<m; j++)
                scanf("%lf",&a[i][j]);
        }
        for(i=0; i<m; i++)
        {
            for(j=0; j<w; j++)
                scanf("%lf",&b[i][j]);
        }

        dp[0][0]=1;

        for(k = 1; k<=n; k++)
        {
            for(j=0; j<m; j++)
            {
                double tmp = -inf;
                for(i=0;i<m;i++)
                {
                    double temp = dp[k-1][i]*a[i][j]*b[j][we[k]];
                    if(temp>tmp)
                    {
                        tmp = temp;
                    }
                }
                for(i=0;i<m;i++)
                {
                    double temp = dp[k-1][i]*a[i][j]*b[j][we[k]];
                    if(fabs(temp-tmp)<eps)
                    {
                        pre[k][j]=i;
                    }
                }
                dp[k][j]=tmp;
            }
        }
        double M =-inf;
        int from;
        for(i=0; i<m; i++)
        {
            if(dp[n][i]>M)
            {
                M=dp[n][i];
            }
        }
        for(i=0; i<m; i++)
        {
            int tt = pre[n][i];
            if(fabs(dp[n][i]-M)<eps)
            {

                pre[n][i]=0;

            }
                pre[n][i]=1;
        }
        for(k=n-1; k>0; k--)
        {
            for(i=0; i<m; i++)
            {
                if(pre[k+1][i]==0)continue;
                for(j=0;j<m;j++)
                {
                    if(fabs((dp[k][j]*a[j][i]*b[i][we[k+1]])-dp[k+1][i])<eps)
                    {
                        pre[k][j]=1;
                    }
                }
            }
        }
        flag =0;
        int Pre = 0;
//        for(i=0;i<=n;i++)
//        {
//            for(j=0;j<m;j++)
//                cout<<pre[i][j]<<" ";
//            cout<<endl;
//        }
        for(i=1; i<=n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(pre[i][j])
                {
                    if(fabs(dp[i-1][Pre]*a[Pre][j]*b[j][we[i]]-dp[i][j])<eps)
                    {
                        if(flag==0)printf("%d",j);
                        else printf(" %d",j);
                        flag=1;
                        Pre = j;
                        break;
                    }
                }
            }
        }
        puts("");
    }
}
