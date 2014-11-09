#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

int T;

int F(int A) {
    int n = 0;
    int a[20];
    while (A)
        a[n++] = A % 10, A /= 10;
    int ret = 0;
    for (int i = n - 1; i >= 0; --i) {
        ret += a[i] << i;
    }
    return ret;
}

const int MAX_V = 20000 + 10;
int dp[20][MAX_V]; //len,weight sum

int main() {
    dp[0][0] = 1;
    cin >> T;
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < MAX_V; ++j) {
            int c = dp[i][j];
            if (c == 0)
                continue;
            for (int d = 0; d < 10; ++d) {
                dp[i + 1][j + (1 << i) * d] += c;
            }
        }

    }

    for (int i = 0; i < 12; ++i) {
        for (int j = 1; j < MAX_V; ++j) {
            dp[i][j] += dp[i][j - 1];
        }
    }

    for (int iter = 1; iter <= T; ++iter) {
        printf("Case #%d: ", iter);
        int A, B;
        cin >> A >> B;

        int b[20], n = 0;
        ++B;
        while (B)
            b[n++] = B % 10, B /= 10;

        int a = F(A);
        int sum = 0;
        int ret = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int d = 0; d < b[i]; ++d) {
                int csum = sum + d * (1 << i);
                if (a >= csum) {
                    ret += dp[i][a - csum];
                }
            }
            sum += b[i] << i;
        }

        cout << ret << endl;
    }
}
