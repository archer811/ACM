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
#define ll int
ll sum[1005][1005],a[1005][1005];
const ll inf = 0x3fffffff;
const int N = 1005;
const int M = 1005;
ll arr[N];
ll find_max(int n,int m)
{
    if(n==0||m==0) return 0;
    int i,j,up,down;
    ll ret=-inf;
    memset(sum,0,sizeof(sum));
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            sum[i][j]=sum[i-1][j]+a[i][j];
    arr[0]=0;
    for(up=1; up<=n; up++)
        for(down=up; down<=n; down++)
        {
            for(i=1; i<=m; i++)
                arr[i]=arr[i-1]+sum[down][i]-sum[up-1][i];
            ll mini=0;
            for(i=1; i<=m; i++)
            {
                ret=max(ret,arr[i]-mini);
                mini=min(mini,arr[i]);
            }
        }
    return ret;
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        printf("%d\n",find_max(n,m));
    }
    return 0;
}
