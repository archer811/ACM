#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int a[1000006],b[1000006];
int main()
{
    int i,j,k,t,n;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]),b[i]=a[i];
        sort(a+1,a+1+n);
        printf("Case %d: %d %d\n",++cas,a[n]-a[1],b[n]-b[1]+1);
    }
}
