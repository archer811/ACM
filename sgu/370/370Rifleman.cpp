#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define ll __int64
#define N 1000005
vector<int>g[N];
int a[N];
void EulerPrime()
{
    int i,j;
    for(i=2;i<N;i++)
    {
        if(a[i]==0)
        {
            for(j=i;j<N;j+=i)
            {
                g[j].push_back(i);
                a[j]=1;
            }
        }
    }
}
ll dfs(int index,int res,int cur)
{
    ll ret =0;
    int i;
    for(i=index;i<g[cur].size();i++)
    {
        ret += ret/g[cur][i]-dfs(index+1,res,cur);
    }
}
ll dfs(int index,int res,int cur)//计算小于等于res的数中，与cur不互质的个数
{
    ll ret=0;
    int i;
    for(i=index;i<g[cur].size();i++)
    {
        ret+=res/g[cur][i]-dfs(i+1,res/g[cur][i],cur);
    }
    return ret;
}
int main()
{
     int n,m,i,j;
     EulerPrime();
     while(scanf("%d%d",&n,&m)!=EOF)
     {
         if(n<m)swap(n,m);
         ll sum=0,t;
         if(n>1&&m>1)sum+=3;
         else if(n>1&&m==1)sum+=1;
         else if(n==1&&m>1)sum+=1;
         n--;m--;
         for(i=2;i<=n;i++)
         {
             int g= m;
             g = min(g,i-1);
            // cout<<g<<"*"<<i<<endl;
             t = g-dfs(0,g,i);
            // cout<<t<<endl;
             if(i<=m)sum+=t*2;
             else sum+=t;
         }
         printf("%I64d\n",sum);
     }
}
