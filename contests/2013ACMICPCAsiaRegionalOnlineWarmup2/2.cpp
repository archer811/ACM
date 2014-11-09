#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;

#define N 305
int ca , n;
double X[N] , Y[N] , vx[N] , vy[N];
#define sqr(x) ((x)*(x))
double _max(double a,double b)
{
    if(a>b)return a;
    return b;
}
double cal(double t)
{
    int i , j;
    double ans = 0;
    for (i = 0 ; i < n ; i++)
        for (j = i + 1 ; j < n ; j++)
        {
            ans = _max(ans , sqr(X[i]-X[j]+(vx[i]-vx[j])*t) + sqr(Y[i]-Y[j]+(vy[i]-vy[j])*t));
        }

    return ans;
}

void work()
{

    scanf("%d",&n);
    for (int i = 0 ; i < n ; i++)
        scanf("%lf%lf%lf%lf",&X[i],&Y[i],&vx[i],&vy[i]);
    double top = 0 , bot = 10000000.0  , mid1 , mid2;
    while (bot - top >= 1e-4)
    {
        mid1 = (top + top + bot) / 3.0;
        mid2 = (top + bot + bot) / 3.0;
        if (cal(mid1) > cal(mid2))
            top = mid1;
        else bot = mid2;
    }
    printf("Case #%d: " , ++ ca);
    printf("%.2f %.2f\n" , top , sqrt(cal(top)) );
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
        work();
    return 0;
}
