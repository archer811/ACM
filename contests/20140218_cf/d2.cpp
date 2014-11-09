#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
#define ll __int64
ll dp[42][4][4];
ll s[4][4];
ll _min(ll a,ll b)
{
    if(a>b)return b;
    return a;
}
ll dfs(int n,int x,int y,int z)
{
    if(n==0)return 0;
    if(dp[n][x][y]!=-1)
        return dp[n][x][y];
    ll sum=0;
    sum += dfs(n-1,x,z,y);
//    if(n==3&&x==1&&y==3)
//        cout<<sum<<endl;
    sum += s[x][y];
//    if(n==3&&x==1&&y==3)
//        cout<<sum<<endl;
    sum += dfs(n-1,z,y,x);
//    if(n==3&&x==1&&y==3)
//        cout<<sum<<endl;

    ll sum2=0;
    sum2 += dfs(n-1,x,y,z);
    sum2 += s[x][z];
    sum2 += dfs(n-1,y,x,z);
    sum2 += s[z][y];
    sum2 += dfs(n-1,x,y,z);
    return dp[n][x][y]=_min(sum,sum2);
}

int main()
{
    int i,j;
    memset(dp,-1,sizeof(dp));
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
            scanf("%I64d",&s[i][j]);
    }
//    for(i=1;i<=3;i++)
//    {
//        for(j=1;j<=3;j++)
//            cout<<s[i][j]<<" ";
//        cout<<endl;
//    }
    int n;
    scanf("%d",&n);
    printf("%I64d\n",dfs(n,1,3,2));
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=3;j++)
        {
//            for(int k=1;k<=3;k++)
//                cout<<i<< " "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
        }
    }
}
