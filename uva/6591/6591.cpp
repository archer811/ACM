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
#define ll long long
ll a[33];
int main()
{
    int i,j,n,k;
    a[1]=1;
    for(i=2; i<=30; i++)
        a[i]=a[i-1]*2+1;
    scanf("%d",&n);
    {
        while(n--)
        {
            scanf("%d",&k);
            printf("%lld\n",a[k]);
        }

    }
    return 0;
}
