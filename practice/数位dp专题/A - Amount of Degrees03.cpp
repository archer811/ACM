#include <cstdio>
#include<iostream>
using namespace std;
typedef unsigned UI;

int f[32][32], t[44], k, b;

inline void change(UI &x) {
    t[0] = 0;
    for (; x; x /= b)
        t[++t[0]] = x % b;
    bool f = false;
    for (int i = t[0]; i; --i) {
        if (t[i] > 1)
            f = true;
        if (f)
            t[i] = 1;
    }
    for (int i = t[0]; i; --i)
        (x <<= 1) += t[i];
    cout<<x<<endl;
}

inline int calc(UI x) {
    int ret = 0;
    for (int i = 31, c = 0; i >= 0; --i)
        if (x & (1U << i)) {
            ret += f[i][k - c];
            if (++c == k)
                break;
            x ^= 1U << i;
        }
    return ret;
}

int main() {
    f[0][0] = 1;
    for (int i = 1; i < 32; ++i) {
        f[i][0] = f[i - 1][0];
        for (int j = 1; j <= i; ++j)
            f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
    }
    UI x, y;
    scanf("%u%u%d%d", &x, &y, &k, &b);
    change(x);
    change(y);
    //cout<<x<<" "<<y<<endl;
    printf("%d\n", calc(y + 1) - calc(x));
    return 0;
}
