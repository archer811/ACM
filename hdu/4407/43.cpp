#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>
#define EPS 1e-3
#define MAXN 210
#define INF 1000000009
using namespace std;
int sum[MAXN],per[MAXN];
int len[MAXN];
int dp[110][100];
int main()
{
    //freopen("C:\\Documents and Settings\\k99\\My Documents\\input.txt","r",stdin);
    int t,n,m,p,s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&p);
        for(int i=0;i<n-1;++i)
            scanf("%d",&len[i]);
        for(int i=n-2;i>=0;--i)
            len[i]+=len[i+1];
        for(int i=1;i<=p;++i)
            scanf("%d%d",&s,&per[i]),per[i]+=len[s-1];
        for(int i=0;i<=p;++i)
            for(int j=0;j<=m;++j)
                dp[i][j]=INF;
        sort(per+1,per+p+1);
        sum[0]=0;
        for(int i =1;i<=p;++i)
            sum[i]=sum[i-1]+per[i];
        dp[0][0]=0;
        for(int i=1;i<=p;++i)
            for(int j=1;j<=m;++j)
                for(int ii=0;ii<i;++ii)
                    dp[i][j]=min((long long)dp[i][j],dp[ii][j-1]+(long long)(i-ii)*per[i]-sum[i]+sum[ii]);
        printf("%d\n",dp[p][m]);
    }
    return 0;
}
