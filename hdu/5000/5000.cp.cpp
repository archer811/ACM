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
#define ll long long
const ll mod = 1000000007;
const int N = 2005;
int a[N];
ll d[N][N];
int main()
{
    int i,j,t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        memset(d,0,sizeof(d));
        int sum=0;
        d[0][0]=1;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<=sum;j++)
            {
                for(int k=a[i];k>=0;k--)
                {
                    d[i][j+k]=(d[i][j+k]+d[i-1][j])%mod;
                }
            }
            sum += a[i];
        }
        printf("%lld\n",d[n][sum/2]);
    }
    return 0;
}
