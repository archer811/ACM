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
	freopen("A.in", "w", stdout);
	srand(time(0));
	puts("abc");
	puts("aab");
	puts("a");
	for (int i = 0; i < 100; ++i) {
		int len = rand() % 1000 + 1;
		for (int j = 0; j < len; ++j) {
			int c = rand() % 26;
			putchar(c + 'a');
		}
		puts("");
	}
	return 0;
}

