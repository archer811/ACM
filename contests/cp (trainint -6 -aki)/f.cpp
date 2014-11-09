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
ll d[55][505];
int x[55];
ll gcd(ll a,ll b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    int i,j,n,m,a,b;
    while(scanf("%d%d%d%d",&n,&m,&a,&b)!=EOF)
    {
        a+=50;
        b+=50;
        memset(d,0,sizeof(d));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&x[i]);
            x[i]+=50;
        }
        d[0][0]=1;
        for(i=1;i<=n;i++)
        {
            for(j=a;j<=b;j++)
            {
                int tmp = x[i]-j;
                if(tmp<0)tmp=-tmp;
                for(int k=0;k<=m+1;k++)
                {
                    int g = k+tmp;
                    if(g>=m+1)g=m+1;
                    //if(i==1&&k==0)cout<<g<<"()"<<endl;
                    d[i][g]+=d[i-1][k];
                }
            }
        }
        ll sum1=0,sum2=0;
        for(i=0;i<=m+1;i++)
        {
            if(i<=m)sum1+=d[n][i];
            sum2+=d[n][i];
        }
        ll g2 = gcd(sum1,sum2);
        if(g2)
        {
            sum1/=g2;sum2/=g2;
        }
        printf("%lld/%lld\n",sum1,sum2);
    }
    return 0;
}
