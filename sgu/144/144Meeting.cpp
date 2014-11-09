#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
    double x,y,z;
    while(scanf("%lf%lf%lf",&x,&y,&z)!=EOF)
    {
        x*=60;
        y*=60;
        double s = (y-x)*(y-x);
        double f = (y-x)*(y-x)*0.5-(y-x-z)*(y-x-z)*0.5;
        printf("%.7f\n",2.0*f*1.0/s);
    }
}
