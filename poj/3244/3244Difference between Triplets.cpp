#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define ll __int64
const int maxn = 201000;
int a[maxn],b[maxn],c[maxn],d[maxn];
int main()
{
    int i,j,k,n;
    while(scanf("%d",&n)&&n)
    {
        for(i=1;i<=n;i++)
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
        ll ans =0;
        for(i=1;i<=n;i++)
            d[i]=a[i]-b[i];
        sort(d+1,d+1+n);
        for(i=1;i<n;i++)
        {
            ans += (ll)i*(n-i)*(d[i+1]-d[i]);
        }
        for(i=1;i<=n;i++)
            d[i]=b[i]-c[i];
        sort(d+1,d+1+n);
        for(i=1;i<n;i++)
        {
            ans += (ll)i*(n-i)*(d[i+1]-d[i]);
        }
        for(i=1;i<=n;i++)
            d[i]=c[i]-a[i];
        sort(d+1,d+1+n);
        for(i=1;i<n;i++)
        {
            ans += (ll)i*(n-i)*(d[i+1]-d[i]);
        }
        printf("%I64d\n",ans/2);
    }
}
