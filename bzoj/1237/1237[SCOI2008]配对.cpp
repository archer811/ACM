#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define ll long long
ll a[200000],b[200000],f[200000];
const ll inf = ((ll)1)<<60;
ll ab(ll x)
{
    if(x==0)return inf;
    return abs(x);
}
int main()
{
    int i,j,k,n;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%lld%lld",&a[i],&b[i]);
        sort(a+1,a+1+n);
        sort(b+1,b+1+n);
        f[1]=ab(a[1]-b[1]);
        f[2]=f[1]+ab(a[2]-b[2]);
        f[2]=min(f[2],ab(a[1]-b[2])+ab(a[2]-b[1]));
        for(i=3;i<=n;i++)
        {
            f[i]=f[i-1]+ab(a[i]-b[i]);
            f[i]=min(f[i],f[i-2]+ab(a[i]-b[i-1])+ab(a[i-1]-b[i]));
            f[i]=min(f[i],f[i-3]+ab(a[i]-b[i-1])+ab(a[i-1]-b[i-2])+ab(a[i-2]-b[i]));
            f[i]=min(f[i],f[i-3]+ab(a[i]-b[i-2])+ab(a[i-1]-b[i])+ab(a[i-2]-b[i-1]));
        }
        if(f[n]>=inf)puts("-1");
        else
            printf("%lld\n",f[n]);
    }
}
