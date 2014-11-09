#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<ctime>
#include<set>
#define int_max 0x7fffffff
#define ll_max 0x7fffffffffffffffLL
#define fr first
#define se second
typedef long long ll;
typedef unsigned long long llu;
using namespace std;
int a[100],b[100],del[100];
int dp[1<<21],sum[1<<21],n,sa=0,sb=0;
int main()
{
    sa=sb=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sa+=a[i];
    }
    for(int j=0;j<n;j++)
    {
        scanf("%d",&b[j]);
        del[j]=b[j]-a[j];
        sb+=b[j];
    }
    if(sa^sb)puts("-1");
    else
    {
        int tot=1<<n;
        for(int i=0;i<tot;i++)
        {
            sum[i]=0;
            for(int j=0;j<n;j++)
            if(i&(1<<j))
            sum[i]+=del[j];
        }
        dp[0]=0;
        for(int i=1;i<tot;i++)
        {
            dp[i]=12345678;
            for(int j=0;j<n;j++)
            if(i&(1<<j))
            {
                int nima=dp[i^(1<<j)];
                cout<<i<<" "<<sum[i]<<" "<<j<<" "<<del[j]<<endl;
                if(sum[i]^del[j])++nima;
                dp[i]=min(dp[i],nima);
            }
        }
        printf("%d\n",dp[--tot]);
    }
}
