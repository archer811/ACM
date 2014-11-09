#include <iostream>
#include <cstdio>
#include <cmath>
#define M 100007
using namespace std;
int a[M];
int main()
{
    int t,tt,i,j,k;
    int n,m;
    __int64 ans;
    scanf("%d",&t);
    for(tt = 1; tt <= t; tt++)
    {
        ans = 0;
        scanf("%d%d",&n,&m);
        for(i = 0;i < n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i = 0;i < n;i++)
        {
            int temp = 0;
            for(j = i;j < n;j++)
            {
                temp |= a[j];
                if(temp < m)
                {
                    ans++;
                }
                else
                    break;
            }
        }
        printf("Case #%d: %I64d\n",tt,ans);
    }

    return 0;
}
