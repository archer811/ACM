#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;
#define ll __int64
ll a[5005];
ll sum[5005];
ll d[5005][5005];
int main()
{
    int i,j,n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%I64d",&a[i]);
        sum[0]=0;
        for(i=1;i<=n;i++)
        {
            sum[i] = sum[i-1]+a[i];
        }
        memset(d,-1,sizeof(d));
        for(i=0;i<=n;i++)
            d[0][i]=0;
        for(i=1;i<=k;i++)
        {
            ll M=-1;
            for(j=1;j<=n;j++)
            {
                if(j-m>=0&&d[i-1][j-m]!=-1)
                {
                    //cout<<i<<"()"<<j<<"  "<<j-m<<" "<<sum[j]<<" "<<sum[j-m]<<endl;
                    ll tmp = d[i-1][j-m]+sum[j]-sum[j-m];
                    M = max(M,tmp);
                }
                d[i][j] = M;
            }
//            for(j=1;j<=n;j++)
//                cout<<d[i][j]<<" ";
//            cout<<endl;
        }
        ll M=0;
        for(i=1;i<=n;i++)
        {
            if(M<d[k][i])
                M=d[k][i];
        }
        printf("%I64d\n",M);
    }
    return 0;
}
