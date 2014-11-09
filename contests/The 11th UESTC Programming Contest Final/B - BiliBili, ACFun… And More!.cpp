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
const double eps = 1e-10;
int main()
{
    int i,j,t;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        double x,y,t,s;
        scanf("%lf%lf%lf%lf",&x,&y,&t,&s);
        double ans=0,ls = s,running = s;
        if(x<=y)
        {
            ans = s/x;
        }
        else
        {
            if(y*t>s+eps)
            {
                ls = 0;
            }
            else
            {
                ls = ls- y*t;
            }
            while(running>eps)
            {
                double t1 = ls/y;
                double t2 = running/x;
                double t = (running-ls)/(x-y);
                if(t1<t2)
                {
                    ans += t2;

                    break;
                }
                ans += t;
                ls = ls-y*t;
                running = s;
            }
        }
        printf("Case #%d: %.3f\n",++cas,ans);
    }
    return 0;
}
