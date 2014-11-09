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

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define N 15
using namespace std;
typedef __int64 ll;
ll fac[N];
ll c[N][N];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
	#endif
    for (int i = 0; i <= 10; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			c[i][j] = c[i-1][j] + c[i-1][j-1];
		}
	}
    fac[0] = 1;
    for (int i = 1; i <= 10; ++i) fac[i] = fac[i - 1] * i;
    int n, k;

    while (~scanf("%d%d", &n, &k)) {
        if(k > n) puts("0");
        else printf("%I64d\n", fac[n] / fac[n - k] * c[n][k]);
    }
    return 0;
}

