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
const int N= 1005;
#define ll __int64
ll a[N][N],b[N][N],c[N][N],cn[N],dn[N],en[N];
int main()
{
    int i,j;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                scanf("%I64d",&a[i][j]);
        }
        for(i=1;i<=n;i++)
        {
            ll sum=0;
            for(j=1;j<=n;j++)
            {
                scanf("%I64d",&b[i][j]);
                sum += (ll)j*(b[i][j]);
            }
            cn[i]=sum;
            //cout<<cn[i]<<endl;
        }
        for(i=1;i<=n;i++)
        {
            ll sum=0;
            for(j=1;j<=n;j++)
            {
                scanf("%I64d",&c[i][j]);
                sum += (ll)j*c[i][j];
            }
            dn[i]=sum;
            //cout<<dn[i]<<endl;
        }
        for(i=1;i<=n;i++)
        {
            ll sum=0;
            for(j=1;j<=n;j++)
            {
                sum += a[i][j]*cn[j];
            }
            en[i]=sum;
            //cout<<en[i]<<endl;
        }
        int flag=0;
        for(i=1;i<=n;i++)
            if(dn[i]!=en[i])flag=1;
        if(flag)puts("NO");
        else puts("YES");
    }
    return 0;
}
