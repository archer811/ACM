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
#define ll __int64
ll a[22];
const ll mod = 1000000007;
const ll MOD = 1000000007;
long long inv(long long a,long long m)
{
    if(a == 1)return 1;
    return inv(m%a,m)*(m-m/a)%m;
}

long long C(long long n,long long m)
{
	long long ans = 1;
	for(int i = 1;i <= m;i++)
	{
		ans = ans*((n-i+1)%MOD)%MOD;
		ans = ans*(inv(i,MOD)%MOD)%MOD;
	}
	return ans;
}
int main()
{
    int i,j;
    int n;
    ll s;
    while(cin>>n>>s)
    {
        for(i=0; i<n; i++)
            cin>>a[i];
        ll ans=0;
        int M = 1<<n;
        for(i=0; i<M; i++)
        {
            ll s2=s;
            int f=0;
            for(j=0; j<n; j++)
            {
                if(i&(1<<j))
                    s2+=-a[j],f++;
            }
            cout<<i<<" "<<(f%2)<<endl;
            //if(s2<0)continue;
            cout<<C(s2+n-1,n-1)<<endl;
            if(f%2)ans-=C(s2+n-1,n-1);
            else ans+=C(s2+n-1,n-1);
            ans = (ans%mod+mod)%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}
