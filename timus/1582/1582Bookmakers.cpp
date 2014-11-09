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
    int i,j,k;
    double k1,k2,k3;
    while(scanf("%lf%lf%lf",&k1,&k2,&k3)!=EOF)
    {
        double ans = 1000*k1*k2*k3/(k1*k2+k1*k3+k2*k3);
        printf("%.0f\n",ans);
    }
}
