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
const int maxn = 1<<15;
int a[maxn];
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int m= (n+1)/2;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            a[i]%=m;
        }
    }
    return 0;
}
