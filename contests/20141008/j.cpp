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
#ifdef __int64
typedef __int64 ll;
#else
typedef long long ll;
#endif
const ll mod = 1000000007;
ll f[1000006];
int main()
{
    int i,j,t;
    f[1]=1;
    f[2]=1;
    f[3]=3;
    for(i=4;i<=1000000;i++)
    {
        f[i]=(f[i-1]*(ll)(i-1)%mod+(f[i-2]*(ll)(i-2))%mod)%mod;
    }
    scanf("%d",&t);
    int cas=0,n;
    while(t--)
    {
        scanf("%d",&n);
        printf("Case %d: %lld\n",++cas,f[n]);
    }
    return 0;
}
