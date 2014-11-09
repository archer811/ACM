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
    int i,j,t,g;
    scanf("%d",&t);
    while(t--)
    {
        double a,b,f,d;
        scanf("%d%lf%lf%lf%lf",&g,&d,&a,&b,&f);
        double x=0,y=d;
        double sum=0;
        double now=0;
        int flag=0;
        while(x+eps<y)
        {
            double t2=0;
            if(flag==0)
            {
                t2=(y-now)/(f+b);
                sum += t2*f;
                //cout<<t2<<" "<<f<<endl;
                y = y - b*t2;
                x = x + a*t2;
                now = y;
            }
            else
            {
                t2 = (now-x)/(a+f);
                sum += t2*f;
                //cout<<t2<<"*"<<f<<endl;
                y = y-b*t2;
                x = x+a*t2;
                now = x;
            }
            flag = 1-flag;
        }
        printf("%d %.2f\n",g,sum);
    }
    return 0;
}
