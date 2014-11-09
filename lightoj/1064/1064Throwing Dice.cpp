#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define ll unsigned long long
ll a[25][150];
int n,m;
ll g[25];
ll gcd(ll a,ll b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
     int i,j,k,t;
     scanf("%d",&t);
     int cas = 0;
     g[1]=6;
     for(i=2;i<25;i++)
        g[i]=g[i-1]*6;
     while(t--)
     {
         memset(a,0,sizeof(a));
         scanf("%d%d",&n,&m);
         for(i=1;i<=6;i++)
            a[1][i]=1;
         for(i=2;i<=n;i++)
         {
             for(j=0;j<=n*6;j++)
             {
                 if(a[i-1][j])
                 {
                     for(k=1;k<=6;k++)
                     {
                         if(j+k>n*6)break;
                         a[i][j+k]+=a[i-1][j];
                     }
                 }
             }
         }
         ll sum=0;
         for(i=m;i<=n*6;i++)
            sum += a[n][i];
         ll ans = g[n];
         printf("Case %d: ",++cas);
         if(sum%ans==0)
            printf("%llu\n",sum/ans);
         else
         {
             ll _gcd=gcd(sum,ans);
             sum/=_gcd;
             ans/=_gcd;
             printf("%llu",sum);
             printf("/");
             printf("%llu\n",ans);
         }
     }
}
