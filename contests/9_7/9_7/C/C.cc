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
int const maxn = 52;
int const mod = 10003;
int dp[maxn][maxn][maxn];
inline int add(int &a, int const &b)
{
    a = (a + b) % mod;
}
int main()
{
#ifndef ONLINE_JUDGE
//        freopen("C.in", "r", stdin);
//        freopen("C.out", "w", stdout);
#endif
    int n, m, t;
    while (cin >> n >> m >> t)
    {
        memset(dp, 0, sizeof dp);
        dp[0][m][0] = 1;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j <= m; ++j)
            {
                for (int k = 0; k <= m; ++k)
                {
                    if (dp[i][j][k] == 0) continue;
                    // +0
                    add(dp[i + 1][j][k], dp[i][j][k]);
                    // +1
                    if (j > 0) add(dp[i + 1][j - 1][k + 1], j * dp[i][j][k]);
                    if (k > 0) add(dp[i + 1][j][k - 1], k * dp[i][j][k]);
                    // +2
                    if (j > 1) add(dp[i + 1][j - 2][k + 2], j * (j - 1) / 2 * dp[i][j][k]);
                    if (k > 1) add(dp[i + 1][j][k - 2], k * (k - 1) / 2 * dp[i][j][k]);
                    if (j > 0 && k > 0) add(dp[i + 1][j - 1][k], j * k * dp[i][j][k]);
                }
            }
        }
        int ret = 0;
        for (int i = 0; i <= m; ++i)
        {
            for (int j = 0; i + j <= m; ++j)
            {
                if (j + 2 * (m - i - j) == t) add(ret, dp[n][i][j]);
            }
        }
        cout << ret << endl;
    }
    return 0;
}

