#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <stack>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define E exp(double(1))
#define maxn 110000
using namespace std;
typedef __int64 LL;

struct point
{
    double x,y;
} p1,p2,p3,p4,rr;

point f_t_i(point u1,point u2,point v1,point v2)
{
    point ans = u1;
    double t=((u1.x - v1.x)*(v1.y - v2.y)-(u1.y - v1.y)*(v1.x - v2.x))/((u1.x - u2.x)*(v1.y - v2.y)-(u1.y - u2.y)*(v1.x - v2.x));
    ans.x += (u2.x - u1.x)*t;
    ans.y += (u2.y - u1.y)*t;
    return ans;
}

point f_c_c(point a,point b,point c)
{
    point ua,ub,va,vb;
    ua.x = ( a.x + b.x )/2;
    ua.y = ( a.y + b.y )/2;
    ub.x = ua.x - a.y + b.y;
    ub.y = ua.y + a.x - b.x;
    va.x = ( a.x + c.x )/2;
    va.y = ( a.y + c.y )/2;
    vb.x = va.x - a.y + c.y;
    vb.y = va.y + a.x - c.x;
    return f_t_i(ua,ub,va,vb);
}

double dis(point p1,point p2)
{
    return sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
}

int main()
{
    int cas=1,_;
    cin>>_;
    while(_--)
    {
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y,&p4.x,&p4.y);
        rr = f_c_c(p1,p2,p3);
        double r=dis(rr,p1);
        double tmp=dis(rr,p4);
        printf("%lf,%lf   r = %lf    tmp = %lf\n",rr.x,rr.y,r,tmp);
        //cout<<dis(rr,p1)<<"**"<<
        //dis(rr,p2)<<" "<<
        //dis(rr,p3)<<endl;
        printf("Case #%d: ",cas++);
        if(tmp<=r)
        {
            puts("Danger");
        }
        else
        {
            puts("Safe");
        }
    }
    return 0;
}
