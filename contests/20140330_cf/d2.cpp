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

#define ll __int64
const ll mod = 1000000007;
ll p[1001];
ll dp[1001];
int main()
{
    int i,j;
    int n;
    while(cin>>n)
    {
        for(i=1;i<=n;i++)
            cin>>p[i];
        memset(dp,0,sizeof(dp));
        dp[1]=1;
        for(i=1;i<=n;i++)
        {
            int tmp=1;
            for(j=p[i];j<i;j++)
            {
                tmp = tmp+dp[j];
                tmp%=mod;
                tmp++;
            }
            dp[i]=(tmp)%mod;
            //cout<<i<<" "<<dp[i]<<endl;
        }
        int ans=0;
        for(i=1;i<=n;i++)
        {
            ans = ans+dp[i];
            ans ++;
            ans %=mod;
        }
        cout<<ans<<endl;
    }
}
