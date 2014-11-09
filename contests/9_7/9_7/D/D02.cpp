#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
using namespace std;
typedef long long ll;
ll const mod = 1000000007LL;
char s[1111];
int a[1111], b[1111];
int getBinary(char *s)
{
    int n = strlen(s), m = 0;
    for (int i = 0; i < n; ++i) a[i] = s[n - i - 1] - '0';
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    while (true)
    {
        bool flag = true;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] != 0)
            {
                flag = false;
                break;
            }
        }
        if (flag) break;
        b[++m] = a[0] & 1;
        int p = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            a[i] += p * 10;
            p = a[i] & 1;
            a[i] >>= 1;
        }
    }
    return m;
}
ll dp[1111][4];

int main()
{
    int i,j;
    while (~scanf("%s", s))
    {
        if(s[0]=='0')
        {
            puts("1");
            continue;
        }
        int n = getBinary(s);
//        for (i = n; i >= 1;i--)
//            printf("%d", b[i]);puts("");
        memset(dp, 0, sizeof dp);
        dp[n][1]=1;
        for(i=n-1;i>=1;i--)
        {
            if(b[i]==0)
            {
                dp[i][1]=0;
                dp[i][3]=0;
                dp[i][0]=(dp[i+1][0]+dp[i+1][1]+dp[i+1][2])%mod;
                dp[i][2]=(dp[i+1][1]+dp[i+1][3]+dp[i+1][2])%mod;
            }
            else
            {
                dp[i][0]=dp[i][2]=0;
                dp[i][1]=(dp[i+1][0]+dp[i+1][1]+dp[i+1][2])%mod;
                dp[i][3]=(dp[i+1][2]+dp[i+1][1]+dp[i+1][3])%mod;
            }
            //cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<" "<<dp[i][3]<<endl;
        }
        printf("%I64d\n",(dp[1][0]+dp[1][1]+dp[1][2])%mod);
        //cout<<<<endl;
    }
    return 0;
}
