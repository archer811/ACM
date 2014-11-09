#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int t,n;
double f[105],a[105],ans[105];
int main()
{
    int i,j,k;
    int cas=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        memset(ans,0,sizeof(ans));
        a[0]=1;
        for(i=0;i<n;i++)
        {
            scanf("%lf",&f[i]);
        }
        ans[0]=f[0];
        for(i=0;i<n;i++)
        {
            for(j=i-1;j>=max(0,i-6);j--)
            {
                a[i]+=a[j];
                ans[i]+=(ans[j]+f[i]);
            }



        }
        printf("Case %d: ",++cas);
        printf("%.6f\n",ans[n-1]*1.0/a[n-1]);
    }
}
