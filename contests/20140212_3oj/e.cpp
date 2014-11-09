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
ll N;
ll K;
int a[20];
ll dp[20][20][20];
ll dfs(int pos,int status,int limit,int have,int now)
{
    if(pos==-1)
    {
        //cout<<"*("<<endl;
        return (have&&now==K);
    }
    if(!limit&&dp[pos][now][K]!=-1)
        return dp[pos][now][K];
    int end = limit?a[pos]:9;
    ll sum=0;
    for(int i=0;i<=end;i++)
    {
        if(have==0&&i==0)
        {
            sum += dfs(pos-1,0,limit&&(i==end),0,0);
        }
        else if(have==0&&i!=0)
        {
            sum += dfs(pos-1,i,limit&&(i==end),1,i);
        }
        else
        {
            sum += dfs(pos-1,i,limit&&(i==end),have,i^now);
        }
    }
    //cout<<sum<<" "<<now<<" "<<have<<endl;
    if(!limit&&have)
        return dp[pos][now][K]=sum;
    return sum;
}
ll f(ll m)
{
    int i,j=0;
    while(m)
    {
        a[j++]=m%10;m/=10;
    }memset(dp,-1,sizeof(dp));
    return dfs(j-1,0,1,0,0);

}
int main()
{
    int i,j;

    while(scanf("%I64d%I64d",&N,&K)!=EOF)
    {
        if(K>=20)
            printf("0\n");
        else
        printf("%I64d\n",f(N));
    }
}
