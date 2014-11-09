#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
struct array
{
    int index,num;
}a[10005];
int cmp(array x,array y)
{
    return x.num<y.num;
}
int main()
{
    int i,j,k,n;
    bool flag=false;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%d",&a[i].num),a[i].index=i;
        sort(a+1,a+1+n,cmp);
        if(flag)puts("");
        flag=true;
        for(i=1;i<=n;i+=2)
        {
            printf("%d %d\n",a[i].index,a[i+1].index);
        }
    }
}
