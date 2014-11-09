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
ll x[505],y[505],z[505];
int a[100000];
int prime[32000];
int ans[32000],num[32000];
int vis[505];
int w[505][505];
int now[505];
int c;
int judge(int a,int b)
{
    ll n = z[a]^z[b];
    for(int i=0;i<c;i++)
    {
        if(n%ans[i]==0)return 1;
    }
    return 0;
}
ll sum;
void dfs(int start,int h)
{
    for(int i=start;i<=n;i++)
    {




    }
}
int n;
int main()
{
    int i,j;
    ll p;
    int g=0;
    for(i=2;i<100000;i++)
    {
        if(a[i]==0)
        {
            prime[g++]=i;
            for(j=i+i;j<100000;j+=i)
                a[j]=1;
        }
    }
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%lld",&p);
        for(i=1;i<=n;i++)
        {
            scanf("%lld%lld",&x[i],&y[i]);
            z[i]=x[i]^y[i];
        }
        ll p2 = p;
        c=0;
        for(i=0;i<g;i++)
        {
            if(p2%prime[i]==0)
            {
                num[c]=0;ans[c]=prime[i];
                while(p2%prime[i]==0)
                {
                    p2/=prime[i];
                    num[c]++;
                }
                c++;
            }
        }
        if(p2>1)
        {
            num[c]=1;ans[c]=p2;c++;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(i==j)w[i][j]=0;
                else w[i][j]=judge(i,j);
            }
        }
        sum=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                vis[j]=0;
            dfs(i,0);
        }
        printf("%lld\n",sum);
    }
}
