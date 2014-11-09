#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;
double dp[1005][1005];

int main()
{
    int n, s, ns;

    cin >> n >> s;
    ns = n*s;
    memset(dp,0,sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i<=n; i++)
        for (int j = 1; j<=s; j++)
        {
            //if ( i == 1 && j == 1 ) continue;
            double a = (n-(i-1))*(s-(j-1))*1.0/ns;
            double b = (n-(i-1))*(j-1)*1.0/ns;
            double c = (i-1)*(s-(j-1))*1.0/ns;
            double d2 = 1.0-a-b-c;
            cout<<a<<" "<<b<<" "<<c<<" "<<d2<<endl;
            dp[i][j] = (1.0+a*dp[i-1][j-1]+b*dp[i-1][j]+c*dp[i][j-1])/(1-d2);
        }
    printf("%.4lf\n", dp[n][s]);

    return 0;
}
