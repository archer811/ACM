#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<queue>
#include<map>
using namespace std;
int w[1005],dp[2][1005][205];
vector<int>gra[1005];
int m;
void dfs(int x,int fa)
{
    int i,j,k,t;
    for(i=0;i<=m;i++)
    {
        dp[0][x][i]=dp[1][x][i]=w[x];
        //cout<<w[x]<<endl;
    }
    for(i=0;i<gra[x].size();i++)
    {
        j=gra[x][i];
        if(j==fa)continue;
        dfs(j,x);
        for(k=m;k>=0;k--)
        {
            for(t=0;t<=k;t++)
            {
                dp[0][x][k+2]=max(dp[0][x][k+2],dp[0][x][t]+dp[0][j][k-t]);
                dp[1][x][k+2]=max(dp[1][x][k+2],dp[1][x][t]+dp[0][j][k-t]);
                dp[1][x][k+1]=max(dp[1][x][k+1],dp[0][x][t]+dp[1][j][k-t]);
            }
        }
    }
}
int main()
{
    int n,k,i,j,a,b;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&w[i]);
            gra[i].clear();
        }
        for(i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            gra[a].push_back(b);
            gra[b].push_back(a);
        }
        memset(dp,0,sizeof(dp));
        dfs(1,0);
        cout<<dp[1][1][m]<<endl;
    }
}
