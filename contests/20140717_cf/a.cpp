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
const int maxn = 5005;
#define ll __int64
ll a[maxn];

ll b[maxn];
ll d[maxn][2];
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%I64d",&a[i]),b[i]=a[i];
        sort(b+1,b+1+n);
        ll sum=0,ans=-1;
        for(j=1;j<=n;j++)
        {
            if(j==1)sum+=a[j];
            else
            if(a[j]>a[j-1])sum+=a[j]-a[j-1];
        }
        if(ans==-1||ans>sum)ans=sum;
        for(i=n;i>=1;i--)
        {
            ll tmp = b[i];
            sum=0;
            ll sum2=0;
            ll pre=-1;
            for(j=1;j<=n;j++)
            {
                if(a[j]>=tmp){sum++;continue;}
                if(pre==-1)
                {
                    sum2+=a[j];pre=a[j];
                }
                else if(a[j]>pre)
                {
                    sum2+=a[j]-pre;
                    pre=a[j];
                }
            }
            //cout<<i<<" "<<sum2<<" "<<sum<<endl;
            if(ans==-1||sum2+sum<ans)
                ans=sum2+sum;
        }

        cout<<ans<<endl;
    }
    return 0;
}
