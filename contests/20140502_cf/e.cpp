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
#define ll __int64
int n,m;
ll x[1000005];
ll sum[1000006];
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%I64d",&x[i]);
        sort(x+1,x+1+n);
        sum[0]=0;
        x[0]=0;
        for(i=1;i<=n;i++)
            sum[i]=sum[i-1]+(x[i]-x[i-1]);
        for(i=1;i<=n;i++)
            cout<<sum[i]<<endl;
    }
    return 0;
}
