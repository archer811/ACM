#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int a[20];
int dp[20][12][2][14][2];
int dfs(int pos,int pre,int have,int limit,int mod)
{
    if(pos==-1)return have==1&&mod==0;
    if(dp[pos][pre][have][mod][limit]!=-1)return dp[pos][pre][have][mod][limit];
    int end = limit?a[pos]:9;
    int sum=0;
    for(int i=0;i<=end;i++)
    {
        if(pre==1&&i==3)
            sum += dfs(pos-1,i,1,limit&&(i==end),(mod*10+i)%13);
        else sum += dfs(pos-1,i,have,limit&&(i==end),(mod*10+i)%13);
    }
    //if(!limit)
       return dp[pos][pre][have][mod][limit]=sum;
    //else return sum;
}
int f(int n)
{
    int i,j=0;
    while(n)
    {
        a[j++]=n%10;
        n/=10;
    }
    memset(dp,-1,sizeof(dp));
    return dfs(j-1,0,0,1,0);
}
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        cout<<f(n)<<endl;
    }

}
