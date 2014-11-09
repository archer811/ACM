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
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    srand(time(0));
	freopen("B.in", "w", stdout);
	for (int i = 1; i <= 10; ++i) {
		for (int j = 0; j <= i * i; ++j) {
			printf("%d %d\n", i, j);
		}
	}
	return 0;
}

