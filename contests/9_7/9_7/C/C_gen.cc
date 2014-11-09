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
	freopen("C.in", "w", stdout);
	puts("3 2 3");
	puts("50 50 100");
	int t = 20;
	int n, m, k;
	for (int i = 0; i < t; ++i) {
		n = rand() % 50 + 1, m = rand() % 50 + 1;
		k = rand() % (n * m) + 1;
		printf("%d %d\n", n, m, k);
	}
	return 0;
}

