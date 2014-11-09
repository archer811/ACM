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
	freopen("D.in", "w", stdout);
	puts("0");
	puts("10");
	putchar('1'); for (int i = 0; i <100; ++i) putchar('0'); putchar(10);
	for (int i = 0; i < 100; ++i) {
		int len = rand() % 98 + 1;
		int h = rand() % 9 + 1;
		printf("%d", h);
		for (int j = 0; j < len; ++j) {
			printf("%d", rand() % 10);
		}
		puts("");
	}
	return 0;
}

