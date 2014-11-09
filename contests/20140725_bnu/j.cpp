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
ll f[100005][2],sum[100005][2];
const ll mod = 1000000007;
int main()
{
    int i,j,n,m;
//    g[0]=1;
//    for(i=1;i<=100000;i++)
//        g[i]=g[i-1]*2%mod;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(f,0,sizeof(f));
        memset(sum,0,sizeof(sum));
        if(n==m)
        {
            printf("1\n");continue;
        }
        if(m==1)
        {
            ll ans=1;
            for(i=1;i<=n;i++)
                ans  = ans*2%mod;
            ans = ((ans-1)%mod+mod)%mod;
            printf("%lld\n",ans);
            continue;
        }
        f[0][0]=1;
        for(i=1;i<=n;i++)
        {
            f[i][1]=f[i-1][1]*2;
            if(i>=m)
                f[i][1]+=f[i-m][0];

            f[i][0]=f[i-1][0]*2;
            if(i>=m)
                f[i][0]+=f[i-m][1];
            cout<<i<<" "<<f[i][0]<<" "<<f[i][1]<<endl;
        }
        printf("%lld\n",f[n][1]);
    }
    return 0;
}
