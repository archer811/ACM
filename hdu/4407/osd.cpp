#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
ll s[1005];
ll dp[1005][155];
ll d[1005];
ll x[1005];
ll f[1005][1005];
const ll inf = 1000000009;
ll dfs(int l,int m)
{
    if(dp[l][m]!=-1)
        return dp[l][m];
    ll sum=-1;
   //cout<<l<<" "<<m<<endl;
    if(l+1<=m)
        return dp[l][m]=0;
    if(m==1)
    {
        return dp[l][m]=f[0][l];
    }
    for(int i=0; i<l; i++)
    {
        ll tmp = dfs(i,m-1)+f[i+1][l];
        if(sum==-1||tmp<sum)
            sum=tmp;
    }
    return dp[l][m]=sum;
}
ll _min(ll a,ll b)
{
    if(a<b)return a;
    return b;
}
int main()
{
    int i,j;
    int t;
    scanf("%d",&t);
    int cas=0;
    int n,m,p;
    while(t--)
    {
        int n;
        scanf("%d%d%d",&n,&m,&p);
        s[0]=s[1]=0;
        for(i=2; i<=n; i++)
        {
            scanf("%lld",&d[i]);
            s[i]=s[i-1]+d[i];
        }
        int num=0;
        int a,b;
        for(i=1; i<=p; i++)
        {
            scanf("%d%d",&a,&b);
            x[num++]=b-s[a];
        }
        sort(x,x+num);
        for(i=0;i<=p;i++)
        {
            for(j=0;j<=m;j++)
            {
                dp[i][j]=inf;
                if(i+1<=j)dp[i][j]=0;
            }
        }
        for(i=p-1;i>=0;i--)
        {
            f[i][i]=0;
            for(j=i-1;j>=0;j--)
            {
                f[j][i]=f[j+1][i]+x[i]-x[j];
            }
        }
        //cout<<f[0][2]<<endl;
        for(i=0;i<p;i++)
        {
            for(j=1;j<=m;j++)
            {
                for(int k=0;k<i;k++)
                {
                    //cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j]<<"*"<<dp[k][j-1]<<" "<<f[k+1][i]<<endl;
                    dp[i][j]=_min(dp[i][j],dp[k][j-1]+f[k+1][i]);
                }
            }
        }
//        for(i=1;i<=m;i++)
//        {
//            for(j=0;j<p;j++)
//            {
//                if(i==1)
//                dp[j][i]=f[0][j];
//                else
//                {
//                    for(int k=0;k<j;k++)
//                    {
//                        //
//                        dp[j][i]=_min(dp[j][i],dp[k][i-1]+f[k+1][j]);
//                    }
//                }
//            }
//        }
        memset(dp,-1,sizeof(dp));
        printf("%lld\n",dfs(p-1,m));
    }
    return 0;
}
