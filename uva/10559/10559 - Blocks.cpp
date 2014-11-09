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
const int maxn = 205;
struct array
{
    int index,num;
}s[maxn];
int a[maxn];
int tot=1;
int dp[maxn][maxn][maxn];
int dfs(int l,int r,int k)
{
    if(dp[l][r][k]!=-1)return dp[l][r][k];
    //if(l==r)return s[l].num*s[l].num;
    int i,j;
    if(r<l)return 0;
    int sum=0;
    sum = max(sum,dfs(l,r-1,0)+(s[r].num+k)*(s[r].num+k));
    for(i=l;i<r;i++)
    {
        if(s[i].index==s[r].index)
        {
            sum = max(sum,dfs(l,i,k+s[r].num)+dfs(i+1,r-1,0));
        }
    }
    return dp[l][r][k]=sum;
}
int main()
{
    int i,j,t,n;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        tot=1;
        int num=1;
        a[n+1]=-1;
        for(i=2;i<=n+1;i++)
        {
            if(a[i]!=a[i-1])
            {
                s[tot].index=a[i-1];
                s[tot++].num=num;
                num=1;
            }
            else num++;
        }
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n",++cas,dfs(1,tot-1,0));
    }
}
