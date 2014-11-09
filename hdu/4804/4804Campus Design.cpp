#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<cmath>
#define mod  1000000007
using namespace std;

int N,M,C,D;
__int64 dp[4][3000][22];
char map[105][22];

void dfs( int sta,int lev,int stu,int n,int k,__int64 num )
{
    if( sta >= M || k > D)return;
    dfs( sta+1,lev,stu,n,k,num );
    if( map[lev][sta] == '1' && (stu&(1<<sta)) == 0 )
    {
        int t = stu+(1<<sta);
        dp[n][t][k+1]+=num;
        dp[n][t][k+1] %= mod;
        dfs(sta+1,lev,t,n,k+1,num);
    }
    if( sta + 1 < M && map[lev][sta] == '1' && map[lev][sta+1] == '1' )
        if( (stu&(1<<sta)) == 0 && (stu&(1<<(sta+1))) == 0  )
        {
            int t = stu+(1<<sta);
            t = t+(1<<(sta+1));
            dp[n][t][k]+=num;
            dp[n][t][k] %= mod;
            dfs(sta+2,lev,t,n,k,num);
        }
}
void work( )
{
    int i,j,k,s,t=1,num = (1<<M);
    memset( dp,0,sizeof(dp) );
    dp[t][num-1][0] = 1;
    for( i = 1; i <= N; i++ )
    {
        s = t^1;
        for( j = 0; j < num; j++ )
            for( k = 0; k <= D;  k++ )
            {
                if( dp[t][j][k] == 0 )continue;
                __int64 stu = 0;
                bool fell = false;
                for( int x = 0; x < M; x++ )
                    if( map[i-1][x] != '0' && (j&(1<<x)) == 0 )
                    {
                        if( map[i][x] == '0' ) fell = true;
                        else stu += (1<<x);
                    }
                if( fell )continue;
                dp[s][stu][k] = dp[t][j][k];
                dfs( 0,i,stu,s,k,dp[t][j][k] );
            }
        for( j = 0; j < num; j++ )
            for( k = 0; k <= D;  k++ )
                dp[t][j][k] = 0;
        t = s;
    }
    __int64 res = 0;
    int now = 0;
    for( j = 0; j < M; j++ )
        if( map[N][j] != '0' ) now +=(1<<j);
    for( j = C; j <= D;  j++ )
    res += dp[t][now][j],res %= mod;
    printf("%I64d\n",res);
}
int main( )
{
    while( scanf("%d%d%d%d",&N,&M,&C,&D) != EOF )
    {
        memset(map,'0',sizeof(map));
        for( int i = 1; i <= N; i++ )
            scanf("%s",map[i]);
        work( );
    }
    return 0;
}
