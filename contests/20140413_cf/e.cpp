#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<vector>
#include<queue>
#include<set>
using namespace std;
#define N 13
#define ll int
ll n, m;
ll dp[2][1<<N][510];
ll mp[N][N];
ll Jie[20];
vector<ll>G[13];
ll GCD(ll x,ll y)
{
    if(y==0)return x;
    return GCD(y,x%y);
}
void init(ll x)
{
    memset(dp[x], 0, sizeof dp[x]);
}
int siz[1<<N];
int main()
{
    int T;
    scanf("%d",&T);
    ll i, j;
    Jie[0] = 1;
    for(i = 1; i <=12; i++)Jie[i] = Jie[i-1]*i;
    for(i = 0; i <=12; i++)G[i].clear();
    siz[0]=0;
    for(i=1; i<(1<<12); i++)
    {
        if(i&1)
            siz[i]=siz[i/2]+1;
        else
            siz[i]=siz[i/2];
        G[siz[i]].push_back(i);
    }
    while(T--)
    {
        scanf("%d %d", &n, &m);
        for(i = 0; i < n; i++)	for(j = 0; j < n; j++)	scanf("%d",&mp[i][j]);
        init(0);
        ll cur = 0, top = 0;
        dp[cur][0][0] = 1;
        int M = 1<<n;
        for(i = 0; i < n; i++)
        {
            cur ^= 1;
            init(cur);
            for(j = 0; j < G[i].size(); j++)
            {
                ll now = G[i][j];
                // if(now>=M)break;
                for(ll z = 0; z < n; z++)
                    if((now & (1<<z)) ==0)
                    {
                        if(dp[cur^1][now][s]==-1)continue;
                        int dd = min(m+1,s+p[i][k]);

                        if(dp[cur][now|(1<<(z))][dd]==-1)
                            dp[cur][now|(1<<(z))][dd]=dp[cur^1][now][s];
                        else
                            dp[cur][now|(1<<(z))][dd]+=dp[cur^1][now][s];
                    }
            }
        }
//        if(dp[cur][(1<<n)-1][m]==0)puts("No solution");
//        else
//        {
//            ll gcd = GCD(dp[cur][(1<<n)-1][m], Jie[n]);
//            printf("%d/%d\n",Jie[n]/gcd, dp[cur][(1<<n)-1][m]/gcd);
//        }
        ll sum=0,sum2=0;
        for(j=0; j<=m+1; j++)
        {
            if(dp[cur][M-1][j]!=-1)
                sum += dp[cur][M-1][j];
            if(dp[cur][M-1][j]!=-1&&j>=m)
                sum2 += dp[cur][M-1][j];
        }
        if(sum2==0)puts("No solution");
        else
        {
            ll x = GCD(sum,sum2);
            printf("%lld/%lld\n",sum/x,sum2/x);
        }
    }
    return 0;
}
