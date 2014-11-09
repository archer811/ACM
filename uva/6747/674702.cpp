#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn = 3005;
int a[maxn];
int sum[maxn];
int num[maxn];
int l[maxn],r[maxn];
int vis[maxn];
int dp[maxn][maxn][2];
int _min(int a,int b)
{
    if(a<b)return a;
    return b;
}
int main()
{
    int i,j;
    int n;
    int p,L;
    while(scanf("%d%d%d",&n,&p,&L)!=EOF)
    {
        if(n==0&&p==0&&L==0)break;
        sum[0]=0;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
            vis[i]=0;
        }
        memset(dp,-1,sizeof(dp));
        for(i=1; i<=n; i++)
        {
            int l2,rr;
            if(sum[i-1]%p==0)
                l2 = sum[i-1]/p;
            else l2 = sum[i-1]/p;
            if(sum[i]%p==0)
                rr = sum[i]/p;
            else rr = sum[i]/p+1;
            num[i]=(rr-l2)*p;
            l[i]=l2;
            r[i]=rr;
            //cout<<l2<<" "<<rr<<" * "<<i<<" "<<num[i]<<" "<<(rr-l2)*p<<endl;
        }
        int x = sum[n]/p;
        if(sum[n]%p)
        {
            x = sum[n]-x*p;
            num[n]=num[n]-p+x;
        }
//        for(i=1;i<=n;i++)
//        {
//            cout<<i<<" "<<num[i]<<" "<<l[i]<<" "<<r[i]<<endl;
//        }
        dp[0][0][1]=0;
        for(i=1; i<=n; i++)
        {
            for(j=0; j<i; j++)
            {
                int tmp=0;
                if(sum[i-1]%p)tmp=p;
                int x=dp[i][j+1][1];
                if(dp[i-1][j][0]!=-1)
                {
                    if(x==-1||dp[i-1][j][0]+num[i]<x)
                        x=dp[i-1][j][0]+num[i];
                }
                if(dp[i-1][j][1]!=-1)
                {
                    if(x==-1||dp[i-1][j][1]+num[i]-tmp<x)
                        x=dp[i-1][j][1]+num[i]-tmp;
                }
                dp[i][j+1][1]=x;
                //cout<<i<<" "<<j+1<<"*"<<x<<"   "<<dp[i-1][j][1]<<" "<<sum[i]<<" "<<tmp<<endl;

                x = dp[i][j][0];
                if(dp[i-1][j][0]!=-1)
                {
                    if(x==-1||dp[i-1][j][0]<x)
                        x=dp[i-1][j][0];
                }
                if(dp[i-1][j][1]!=-1)
                {
                    if(x==-1||dp[i-1][j][1]<x)
                        x=dp[i-1][j][1];
                }
                dp[i][j][0]=x;
                //cout<<i<<" "<<j<<" "<<"()"<<x<<endl;
            }
        }
        int sum=0;
        for(i=0; i<=n; i++)
        {
            if(dp[n][i][0]!=-1)
            {
                if(dp[n][i][0]<=L)
                    sum=i;
            }
            if(dp[n][i][1]!=-1)
            {
                if(dp[n][i][1]<=L)
                    sum=i;
            }
            //cout<<dp[n][i][0]<<" "<<dp[n][i][1]<<endl;
        }
        cout<<sum<<endl;
    }
    return 0;
}