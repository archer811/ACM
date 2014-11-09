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
double a[55];
int cmp(double x,double y)
{
    return x>y;
}
int main()
{
    int i,j,t,n;
    scanf("%d",&t);
    while(t--)
    {
        double sum=0;
        scanf("%d",&n);
        double now= 1.0;
        for(i=1;i<=n;i++)
        {
            scanf("%lf",&a[i]);
        }
        sort(a+1,a+1+n,cmp);
        for(i=1;i<=n;i++)
        {

            sum += now*a[i];
            now *= 0.95;
        }
        printf("%.9f\n",sum);
    }
    return 0;
}
