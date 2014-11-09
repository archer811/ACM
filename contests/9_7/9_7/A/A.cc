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
int const maxn = 1010;
typedef long long ll;
char str[maxn];
int num[128];

int main() {
#ifndef ONLINE_JUDGE
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif
    while (~scanf(" %s", str)) {
        memset(num, 0, sizeof num);
        int len = strlen(str);
        for (int i = 0; i < len; ++i) {
            num[str[i] - 'a']++;
        }
        int ret = 0;
        for (int i = 0; i < 26; ++i) {
            if (num[i] % 2 != 0) ++ret;
        }
        ret = max(0, ret - 1);
        printf("%d\n", ret);
    }
    return 0;
}

