#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
using namespace std;
#define ll long long
int main()
{
    int n;
    double pi = atan(1.0) * 4.0;
    cin >> n;
    if (n == 1)
        printf("1.0\n");
    else
    {
        double ans = 1.0 / sin(pi / n) + 1.0;
        printf("%.10lf\n", ans);
    }
    return 0;
}
