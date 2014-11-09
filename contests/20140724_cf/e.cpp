#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int MOD = 1e9+7;
//��ax = 1( mod m) ��xֵ��������Ԫ(0<a<m)
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
		ans = ans*(n-i+1)%MOD;
		ans = ans*inv(i,MOD)%MOD;
	}
	return ans;
}
long long a[22];
int bit[22];
int bitnum[1<<21];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	long long s;
	int n;
	bit[0] = 1;
	for(int i = 1;i < 22;i++)
		bit[i] = 2*bit[i-1];

	while(scanf("%d%I64d",&n,&s) == 2)
	{
		for(int i = 0;i < n;i++)scanf("%I64d",&a[i]);
		int tot = (1<<n);
		bitnum[0] = 0;
		for(int i = 1;i < tot;i++)
		{
			int j = i&(-i);
			bitnum[i] = bitnum[i^j]+1;
		}
		long long ans = C(s+n-1,n-1);
		for(int i = 1;i < tot;i++)
		{
			long long ss = s;
			for(int j = 0;j < n;j++)
			{
				if(i&bit[j])
					ss -= a[j]+1;
			}
			if(ss < 0)continue;
			if(bitnum[i]&1)ans -= C(ss+n-1,n-1);
			else ans += C(ss+n-1,n-1);
			ans = (ans%MOD + MOD)%MOD;
		}
		ans = (ans%MOD + MOD)%MOD;
		cout<<ans<<endl;
	}
    return 0;
}
