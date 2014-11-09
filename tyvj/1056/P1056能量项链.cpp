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
#define ll long long
ll a[515];
struct array
{
    int x,y;
}b[515];
ll dp[515][515];
ll dfs(int x,int y)
{
    if(y-x==0)return 0;
   // if(y-x==1)return b[x].x*b[y].y*b[x].y;
    //cout<<x<<" "<<y<<endl;
    if(dp[x][y]!=-1)return dp[x][y];
    int i,j;
    ll sum=0;
    for(i=x;i<y;i++)
    {
        //cout<<b[x]<<"*"<<b[y]<<"*"<<b[i]<<endl;
        if(dfs(x,i)+dfs(i+1,y)+b[x].x*b[y].y*b[i].y>sum)
            sum=dfs(x,i)+dfs(i+1,y)+b[x].x*b[y].y*b[i].y;
    }
    return dp[x][y]=sum;
}
int main()
{
    int i,j,n;
    scanf("%d",&n);
    {
        ll ans=0;
        for(i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        for(i=1;i<=n;i++)
        {
            int g=1;
            for(j=i;j<n;j++)
            {
                b[g].x=a[j];
                b[g++].y=a[j+1];
            }
            b[g].x=a[n];
            b[g++].y=a[1];
            for(j=1;j<=i;j++)
            {
                b[g].x=a[j];
                b[g++].y=a[j+1];
            }
            for(j=1;j<=n+1;j++)
            {
                for(int k=1;k<=n+1;k++)
                    dp[j][k]=-1;
            }
//            for(j=1;j<=n;j++)
//                cout<<b[j].x<<" "<<b[j].y<<endl;
//            cout<<endl;
            dfs(1,n);
//            cout<<dp[1][n+1]<<endl;
            if(dp[1][n]>ans)
                ans=dp[1][n];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
