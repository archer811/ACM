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
    int i,j;
    double a,b,c;
    while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF)
    {
        if(a==0)
        {
            if(b==0)
            {
                if(c!=0)puts("0");
                else
                    puts("-1");
            }
            else
            {
               puts("1");
               printf("%.5f\n",-c*1.0/b);
            }
            continue;
        }
        double delta = b*b-4.0*a*c;
        //cout<<delta<<"dd"<<fabs(delta)<<endl;
        if(fabs(delta)<eps)
        {
            puts("1");
            double ans=-b/2.0/a;
            printf("%.5f\n",ans);
        }
        else if(delta<0)
        {
            puts("0");
        }
        else
        {
            //cout<<delta<<"*"<<endl;
            double ans1=(-b-sqrt(delta))/2/a;
            double ans2=(-b+sqrt(delta))/2/a;
            puts("2");
            if(ans1>ans2)swap(ans1,ans2);
            printf("%.5f\n%.5f\n",ans1,ans2);
        }
    }
    return 0;
}
