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
const int maxn = 105;
int dp[maxn][maxn][3];
int n,d;
int a[maxn],b[maxn],c[maxn];
const int inf = 0x3fffffff;
int dis[maxn][maxn];
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&d)!=EOF)
    {
        memset(dp,-1,sizeof(dp));
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
                dis[i][j]=inf;
            //dis[i][i]=0;
        }
        for(i=0; i<n; i++)
        {
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
            scanf("%d",&j);
            while(j--)
            {
                int num,bf;
                scanf("%d%d",&num,&bf);
                dis[i][num]=min(dis[i][num],bf);
            }
        }
        for(int k=0; k<n; k++)
        {
            for(i=0; i<n; i++)
            {
                for(j=0; j<n; j++)
                {
                    if(dis[i][k]<inf&&dis[k][j]<inf)
                    {
                        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                    }
                }
            }
        }
//        for(i=0;i<n;i++)
//        {
//            for(j=0;j<n;j++)
//            {
//                cout<<i<<" "<<j<<" "<<dis[i][j]<<endl;
//            }
//        }
        dp[1][0][0]=0;
        for(i=2; i<=d; i++)
        {
            for(j=0; j<n; j++)
            {
                for(int k=2;k>=0;k--)
                {
                    if(dp[i-1][j][k]==-1)continue;
                    int tmp=0;
                    if(k==0)tmp=a[j];
                    else if(k==1)tmp=b[j];
                    else tmp=c[j];

                    int t2=min(2,k+1);
                    dp[i][j][t2]=max(dp[i][j][t2],dp[i-1][j][k]+tmp);
                    for(int t=0; t<n; t++)
                    {
                        int bg=dis[j][t];
                        if(dp[i][j][k]+tmp-bg<0)continue;
                        dp[i][t][0]=max(dp[i][t][0],dp[i-1][j][k]+tmp-bg);
                    }
                }
            }
        }
        int ans=0;
        for(i=0; i<n; i++)
        {
            for(j=0; j<=2; j++)
            {
                if(dp[d][i][j]>ans)ans=dp[d][i][j];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
