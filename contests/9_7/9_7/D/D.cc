#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
using namespace std;
typedef long long ll;
ll const mod = 1000000007LL;
char s[1111];
int a[1111], b[1111];
int getBinary(char *s) {
	int n = strlen(s), m = 0;
	for (int i = 0; i < n; ++i) a[i] = s[n - i - 1] - '0';
	while (true) {
		bool flag = true;
		for (int i = 0; i < n; ++i) { if (a[i] != 0) { flag = false; break; } }
		if (flag) break;
		b[++m] = a[0] & 1;
		int p = 0;
		for (int i = n - 1; i >= 0; --i) {
			a[i] += p * 10;
			p = a[i] & 1;
			a[i] >>= 1;
		}
	}
	return m;
}
ll dp[1111][2];

int main() {
//	#ifndef ONLINE_JUDGE
//		freopen("D.in", "r", stdin);
//		freopen("D.out", "w", stdout);
//	#endif
	while (~scanf("%s", s)) {
		int n = getBinary(s);
		//for (int i = n; i >= 1; --i) printf("%d", b[i]);puts("");
		memset(dp, 0, sizeof dp);
		dp[0][0] = 1;
		for (int i = 1; i <= n; ++i) {
			if (b[i] == 0) {
				dp[i][0] += dp[i - 1][0];
				dp[i][1] += dp[i - 1][1] + dp[i - 1][0];
			}
			else {
				dp[i][0] += dp[i - 1][0] + dp[i - 1][1];
				dp[i][1] += dp[i - 1][1];
			}
			dp[i][0] %= mod;
			dp[i][1] %= mod;
		}
		printf("%I64d\n", dp[n][0]);
	}
	return 0;
}


