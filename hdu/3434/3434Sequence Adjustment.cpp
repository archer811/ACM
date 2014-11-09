#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define ll __int64
ll b[1000006];
int main()
{
    int i,j,k,t,n;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%I64d",&b[i]);
        ll x=0,y=0;
        for(i=2;i<=n;i++)
        {
            if(b[i]-b[i-1]>0)x+=b[i]-b[i-1];
            else y+=b[i-1]-b[i];
        }
        printf("Case %d: %I64d %I64d\n",++cas,max(x,y),b[n]-b[1]+1);
    }
}
