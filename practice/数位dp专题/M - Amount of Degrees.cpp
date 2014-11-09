#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int x,y;
int K,B;
int a[33];
int dp[33][3][30];
int dfs(int pos,int status,int num,int limit)
{
    if(pos==-1)
    {
        return num==K;
    }
    if(!limit&&dp[pos][status][num]!=-1)
        return dp[pos][status][num];
    int end = limit?a[pos]:1;
    int end2 = end;
    if(end2>1)end2=1;
    int sum=0;
    for(int i=0;i<=end2;i++)
    {
        if(i==1)
        sum += dfs(pos-1,i,num+1,limit&&(i==end));
        else sum += dfs(pos-1,i,num,limit&&(i==end));
    }
    if(!limit)
        return dp[pos][status][num]=sum;
    return sum;
}
int f(int n)
{
    int i,j=0;
    while(n)
    {
        a[j++]=n%B;
        n/=B;
    }
    memset(dp,-1,sizeof(dp));
    return dfs(j-1,0,0,1);
}
int main()
{
    int i,j;
    while(scanf("%d%d",&x,&y)!=EOF)
    {
        scanf("%d%d",&K,&B);
        printf("%d\n",f(y)-f(x-1));
    }
}
