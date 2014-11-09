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
const double eps = 1e-8;
int main()
{
    int i,j,t;
    double a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf",&a,&b,&c);
        double x,y,z;
        x = b*c;y=a*c;z=a*b;
        double sum=x+y+z;
        if((a*x-sum)>eps&&(b*y-sum)>eps&&(c*z-sum)>eps)
            puts("Aha");
        else
            puts("No way");
    }
    return 0;
}
