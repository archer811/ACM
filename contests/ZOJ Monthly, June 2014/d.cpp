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
char s1[maxn],s2[maxn];
#define ll long long
const ll mod = 1000000009;
ll dp[105][105];
ll c[maxn][maxn];
int main()
{
    int i,j,n,k,m;
    memset(c,0,sizeof(c));


    for(i=0;i<maxn;i++)
        c[i][i]=c[i][0]=1;
    for(i=1;i<maxn;i++)
    {
        for(j=1;j<i;j++)
        {
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
    }



//    for(i=0;i<10;i++)
//    {
//        for(j=0;j<10;j++)
//        {
//            if(i==4&&j==4)cout<<"* ";
//            else cout<<c[i][j]<<" ";
//        }
//
//        cout<<endl;
//    }
//        cout<<c[4][4]<<endl;
    while(scanf("%d%d%d",&n,&k,&m)!=EOF)
    {
        scanf("%s%s",s1,s2);
        int sum=0;
        for(i=0;i<n;i++)
        {
            if(s1[i]!=s2[i])sum++;
        }
        memset(dp,0,sizeof(dp));
        dp[0][sum]=1;
        for(i=1;i<=k;i++)
        {
            for(j=0;j<=n;j++)
            {
                for(int t=max(0,j-m);t<=j&&m+t<=n&&m-j+t+t<=n;t++)
                {

                    if(m-j+t+t<0)continue;

                    (dp[i][m-j+t+t]+=dp[i-1][j]*c[j][t]%mod*c[n-j][n-m-t]%mod)%=mod;
//                    if(dp[i-1][j]>0)
//                    cout<<i<<" "<<j<<" "<<t<<" "<<m-j+t+t<<"  "<<dp[i][m-j+t+t]<<
//                    "    "<<c[j][t]<<" ** "<<n-j<<" "<<n-m-t<<"  "<<c[n-j][n-m-t]<<endl;
                }
            }
        }
        printf("%lld\n",dp[k][0]);
    }
    return 0;
}
