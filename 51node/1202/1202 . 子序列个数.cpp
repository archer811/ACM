#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 100005;
int a[maxn],f[maxn];
const int mod = 1000000007;
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        int sum=0;
        memset(f,0,sizeof(f));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            int g = sum-f[a[i]]+mod;
            g %= mod;
            f[a[i]] = sum+1;
            f[a[i]] %= mod;
            sum = f[a[i]]+g ;
            sum %= mod;
//            for(j=1;j<=3;j++)
//                cout<<j<<" "<<f[j]<<endl;
//            cout<<sum<<endl;
        }
        int ans=0;
        for(i=0;i<=100000;i++)
        {
            ans += f[i];
            ans %= mod;
        }
        cout<<ans<<endl;
    }
}
