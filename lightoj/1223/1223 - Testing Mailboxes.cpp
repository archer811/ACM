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
const int N = 105;
int d[N][N][N];
const int inf =0x3fffffff;
int main()
{
    int i,j,t,k,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&k,&m);
        for(i=1;i<=m+1;i++)
        {
            for(j=1;j<=m+1;j++)
            {
                for(int g=0;g<=k;g++)
                    d[g][i][j]=inf;
            }
        }
        int sum=0;
        for(i=1;i<=m+1;i++)
        {
            d[1][i][m+1]=min(d[1][i][m+1],sum);
            //cout<<d[1][i][m+1]<<endl;
            sum+=i;
        }
//        for(int g=0;g<=0;g++)
//        {
//            d[g][1][m]=0;
//        }
        for(int g=2;g<=k;g++)
        {
            for(i=1;i<=m+1;i++)
            {
                for(j=i;j<=m+1;j++)
                {
                    if(d[g-1][i][j]<inf)
                    {
                        for(int g2=i;g2<=j;g2++)
                        {
                            d[g][i][g2-1]=min(d[g][i][g2-1],d[g-1][i][j]+g2);
                        }
                    }
                }
            }
            for(i=1;i<=m+1;i++)
            {
                for(j=i;j<=m+1;j++)
                {
                    if(d[g][i][j]<inf)
                    {
                        for(int g2=i;g2<=j;g2++)
                        {
                            d[g][g2+1][j]=min(d[g][g2+1][j],d[g][i][j]+g2);
                        }
                    }
                }
            }

            for(i=1;i<=m+1;i++)
            {
                for(j=i;j<=m+1;j++)
                {
                    //cout<<i<<" "<<j<<" "<<d[g][i][j]<<endl;
                }
            }
            //cout<<endl;
        }
        int ans=inf;
        for(i=1;i<=m+1;i++)
        {
            ans=min(ans,d[k][i][i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
