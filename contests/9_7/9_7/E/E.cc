#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL

using namespace std;
typedef __int64 ll;
int const N = 1000000;
ll const mod = 1000000007LL;
ll pow2[N + 10];
ll dp[N + 10];
int n;
int main() {
	#ifndef ONLINE_JUDGE
		freopen("E.in", "r", stdin);
		freopen("E.out", "w", stdout);
	#endif
    pow2[0] = 1;
    for (int i = 1; i <= N; ++i) {
        pow2[i] = pow2[i - 1] << 1;
        if (pow2[i] >= mod) pow2[i] -= mod;
    }
    while (cin >> n) {
        memset(dp, 0, sizeof dp);
        dp[0] = 1LL;
        ll p = 1;
        for (int i = 0; i < n; ++i) {
            dp[i + 1] = (p - dp[i] + mod) % mod;
            if (i) {
                ll t = dp[i - 1] * i % mod * (pow2[n] - i) % mod;
                dp[i + 1] = (dp[i + 1] - t + mod) % mod;
            }
            p = p * (pow2[n] - 1 - i + mod) % mod;
        }
        ll ret = (p - dp[n] + mod) % mod;
        cout << ret << endl;
    }
    return 0;
}

