#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 300005;
int a[maxn],n;
const int N = 1000005;
int prime[N],b[N],g;
void init()
{
    int i,j;
    g=0;
    for(i=2;i<N;i++)
    {
        if(b[i]==0)
        {
            prime[g++]=i;
            for(j=i+i;j<N;j+=i)
                b[j]=1;
        }
    }
}
vector<int>G[maxn];
int main()
{
    int i,j,k;
    init();
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]),G[i].clear(0);
        for(i=1;i<=n;i++)
        {
            for(j=0;j<g&&prime[j]<a[i];j++)
            {
                if(a[i]%prime[j]==0)
                {
                    int num=0;
                    while(a[i]%prime[j]==0)
                }
            }
        }
    }
}
