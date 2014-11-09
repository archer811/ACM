#include<cstdio>
#include<cstring>

#define MV 108
int dp[MV][MV];
int a,b,c;
int dfs(int x,int y)
{
    if(dp[x][y]!=-1) return dp[x][y];
    int t1;
    if(x==0&&y==0) return dp[x][y]=1;
    if(x==0)
    {
        if(y==b) t1=0;
        else t1=1;
        return dp[x][y]=t1;
    }
    if(y==0)
    {
        if(x==b) t1=0;
        else t1=1;
        return dp[x][y]=t1;
    }
    int tmax=0;
    for(int i=1; i<=x; i++)
    {
        int t1=!dfs(x-i,y);
        if(t1>tmax ) tmax=t1;
    }
    for(int i=1; i<=y; i++)
    {
        int t1=!dfs(x,y-i);
        if(t1>tmax ) tmax=t1;
    }
    return dp[x][y]=tmax;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=100;i++)
    {
        for(int j=1;j<=100;j++)
        {
            for(int k=1;k<=100;k++)
            {
                cout<<i<<" "<<j<<" "<<k<<" "<<dfs(i,k)<<endl;
            }
        }
    }
}
