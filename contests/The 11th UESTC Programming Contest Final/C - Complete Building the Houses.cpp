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
const int maxn = 100010;
int d[maxn],a[maxn],d2[maxn];
const int inf  = 0x3fffffff;
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int ans=-1;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(i==1)ans=a[i];
            else if(i<=m)ans=max(ans,a[i]);
            if(i<=m)
                d[i]=ans;
            else
                d[i]=inf;
        }
        if(n>m)
        {
            d[m]=d2[m]=ans;
            for(i=m+1;i<=n;i++)
            {

            }
        }
    }
    return 0;
}
