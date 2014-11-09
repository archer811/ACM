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
#define ll __int64
int main()
{
    int i,j,t,a,b;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        scanf("%d%d",&a,&b);
        ll sum=0;
        for(i=a;i<=b;i++)
        {
            ll tmp = (ll)i*(ll)i*(ll)i;
            sum += tmp;
        }
        printf("Case #%d: %I64d\n",++cas,sum);
    }
    return 0;
}
