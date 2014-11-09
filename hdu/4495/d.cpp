#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
#include<vector>
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define eps 1e-9
#define pi acos(-1.0)
using namespace std;
char s[101];
int dp[101][101];
int dfs(int l,int r)
{
    if(l==r)return 1;
    if(dp[l][r]!=-1)return dp[l][r];
    if(l==r-1)
    {
        if(s[l]=='('&&s[r]==')')return 0;
        if(s[l]=='['&&s[r]==']')return 0;
        return 2;
    }
    int sum=-1;
    for(int i=l;i<r;i++)
    {
        int tmp = dfs(l,i)+dfs(i+1,r);
        if(sum==-1||tmp<sum)
            sum=tmp;
    }
    if(r-l>=2&&s[l]=='('&&s[r]==')')
        sum = min(sum,dfs(l+1,r-1));
    if(r-l>=2&&s[l]=='['&&s[r]==']')
        sum = min(sum,dfs(l+1,r-1));
    return dp[l][r]=sum;
}
int main()
{
    int i,j;
    int n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",s);
        memset(dp,-1,sizeof(dp));
        int len= strlen(s);
        printf("%d\n",dfs(0,len-1));
    }
    return 0;
}
