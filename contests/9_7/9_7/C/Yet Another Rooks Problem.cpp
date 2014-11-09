#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define ll long long
const ll mod = 10003;
ll dp[105][55][55],a[55];
int main()
{
    int i,j,k,n,m,s,t;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        if(n>m)swap(n,m);
        if(k>2*n)
        {
            puts("0");
            continue;
        }
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
                dp[1][i][j]=1;
        }
        for(i=2;i<=k;i++)
        {
            for(s=1;s<=n;s++)
            {
                ll sum = 0,sum2=0;
                for(t=1;t<=m;t++)
                    (sum += dp[i-1][s-1][t])%=mod;
                a[0]=0;
                for(t=1;t<=m;t++)
                    a[t]=(a[t-1]+dp[i-1][s][t])%mod;
                for(t=1;t<=m;t++)
                {
                    dp[i][s][t]=(a[t-1]+sum)%mod;
                }
            }
        }
        ll ans =0 ;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
                (ans += dp[k][i][j])%=mod;
        }
        printf("%lld\n",ans);
        //cout<<ans<<endl;
    }
}
