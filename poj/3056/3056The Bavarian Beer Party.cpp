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
int a[10005];
int n;
int dp[1005][1005];
int dfs(int x,int y)
{
    if((y-x+1)%2)return dp[x][y]=0;
    if(y<x)return dp[x][y]=0;
    if(x==y-1)return dp[x][y]=(a[x]==a[y]);
    if(dp[x][y]!=-1)return dp[x][y];
    int sum=0;
    //if(x==1&&y==n)sum=max(sum,dfs(x+1,y-1)+1);
    if(a[x]==a[y])sum=max(sum,dfs(x+1,y-1)+1);
    else sum = max(sum,dfs(x+1,y-1));
    for(int i=x+1;i<y;i+=2)
    {
        int tmp=0;
        if(a[x]==a[i])tmp=1;
        if(tmp+dfs(x+1,i-1)+dfs(i+1,y)>sum)
            sum=tmp+dfs(x+1,i-1)+dfs(i+1,y);
    }
    return dp[x][y]=sum;
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        memset(dp,-1,sizeof(dp));
        dfs(1,n);
       // cout<<dp[7][12]<<"()"<<endl;
        printf("%d\n",max(0,dp[1][n]));
    }
    return 0;
}
