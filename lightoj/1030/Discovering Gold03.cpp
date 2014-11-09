#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int t,n;
double f[105],ans[105];
int main()
{
    int i,j,k;
    int cas=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(ans,0,sizeof(ans));
        for(i=0;i<n;i++)
        {
            scanf("%lf",&f[i]);
        }
        ans[n-1]=f[n-1];
        for(i=n-2;i>=0;i--)
        {
            ans[i]=f[i];
            int t = min(i+6,n-1);
            for(j=i+1;j<=t;j++)
            {
                ans[i]+=ans[j]/(t-i);
            }
        }
        printf("Case %d: ",++cas);
        printf("%.6f\n",ans[0]);
    }
}
