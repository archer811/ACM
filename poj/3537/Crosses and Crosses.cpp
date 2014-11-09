#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<memory.h>
using namespace std;
int sg[3002];
int dfs(int n)
{
    if(n<0)return 0;
    if(sg[n]>=0)return sg[n];
    int g[2001]={0};
    for(int i=1;i<=n;i++)
    {
        int t = dfs(i-3)^dfs(n-i-2);
        g[t]=1;
    }
    for(int i=0;;i++)
        if(g[i]==0)return sg[n]=i;
}
int main()
{
    memset(sg,-1,sizeof(sg));
    int i,j,k,n;
    while(scanf("%d",&n)!=EOF)
    {
        if(dfs(n))puts("1");
        else puts("2");
    }
}
