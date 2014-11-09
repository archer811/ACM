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
	freopen("E.in", "w" , stdout);
	puts("1\n2\n3\n5\n100");
	puts("1000000");
	for (int i = 0; i < 19; ++i) printf("%d\n", rand() % 1000000 + 1);
	return 0;
}

