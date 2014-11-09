#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 50005;
int f[maxn];
const int mod  =  1000000007;
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(f,0,sizeof(f));
        f[0]=1;
        for(i=1;i<=n;i++)
        {
            for(j=n;j>=i;j--)
            {
                f[j] = (f[j]+f[j-i])%mod;
            }
        }
        printf("%d\n",f[n]);
    }
}
