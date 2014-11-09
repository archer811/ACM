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

#define ll __int64
const ll mod = 1e9+7;
ll d[22][405][2];
ll c[22][22];
ll f(ll x,int n)
{
    ll y = 1;
    while(n)
    {
        if(n&1)y=y*x%mod;
        x=x*x%mod;
        n/=2;
    }
    return y;
}
int main()
{
    int i,j,t;
//    freopen("1010.in","r",stdin);
//    freopen("out.txt","w",stdout);
    for(i=0;i<22;i++)
        c[i][i]=c[i][0]=1;
    for(i=1;i<22;i++)
    {
        for(j=1;j<i;j++)
        {
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
    }
    scanf("%d",&t);
    while(t--)
    {
        int n,k,l;
        scanf("%d%d%d",&n,&k,&l);
        if(k==0)
        {
            printf("1\n");
            continue;
        }
        memset(d,0,sizeof(d));
        d[0][0][0]=1;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<k;j++)
            {
                for(int s=400-j;s>=0;s--)
                {
                    (d[i][s+j][1]+=d[i-1][s][1])%=mod;
                    if(s+j==k)
                    {
                        (d[i][s+j][1]+=d[i-1][s][0])%=mod;
                    }
                    else
                        (d[i][s+j][0]+=d[i-1][s][0])%=mod;
                }
            }
        }
        ll sum=0;
        for(i=0;i<=n;i++)
        {
            ll s=0;
            for(j=0;j<=400;j++)
            {
                if(j!=k&&d[i][j][0])
                {
                    s+=d[i][j][0];
                    if(i==3)
                    cout<<j<<" "<<d[i][j][0]<<endl;
                    s %= mod;
                }
            }

            cout<<c[n][i]<<"*"<<f(l-k,n-i)<<" "<<s<<endl;
            sum += c[n][i]*f(l-k,n-i)%mod*s%mod;
            sum %= mod;
        }
        ll sum2 = f(l+1,n);
        sum2 = ((sum2-sum)%mod+mod)%mod;
        printf("%I64d\n",sum2);
    }
    return 0;
}
