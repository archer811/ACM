#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#define ll long long
using namespace std;
ll a[1000005];

ll sum[1005];
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        sum[0]=0;
        for(i=1; i<=n; i++)
        {
            scanf("%lld",&a[i]);
        }
        //sort(a+1,a+1+n);
        for(i=1; i<=n; i++)
        {
            sum[i]=sum[i-1]+a[i];
        }
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            if(l>r)
            {
                puts("0");continue;
            }
            int mid=(l+r)/2;
            ll key=0;
            ll M=a[mid];
            int numl=mid-l+1,numr=r-mid;
            key+=numl*M-(sum[mid]-sum[l-1])+  (sum[r]-sum[mid])- numr*M;

            printf("%lld\n",key);
        }
    }
    return 0;
}
