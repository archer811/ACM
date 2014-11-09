#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
double Rm,R,r,sx,sy,vx,vy;
#define eps 1e-8
#define DB double
#define cpoint array
struct array
{
    double x,y;

} o,start,end;
array operator-(cpoint a,cpoint b)
{
    array c;
    c.x=a.x-b.x;
    c.y=a.y-b.y;
    return c;
}
double dot(array a,array b,array p)
{
    return (a.x-p.x)*(b.x-p.x) + (a.y-p.y)*(b.y-p.y);
}
DB x_mult(cpoint a,cpoint b,cpoint p)
{
    return (a.x-p.x)*(b.y-p.y) - (a.y-p.y)*(b.x-p.x);
}
DB length(array t)
{
    return sqrt(t.x*t.x+t.y*t.y);
}
int main()
{
    int i,j,k;
    while(scanf("%lf%lf%lf%lf%lf%lf%lf",&Rm,&R,&r,&sx,&sy,&vx,&vy)!=EOF)
    {
        double dm = -sx*vy*1.0+vx*sy*1.0;
        if(dm<0)dm=-dm;
        dm = dm*1.0/sqrt(vx*vx*1.0+vy*vy*1.0);
        start.x=sx;
        start.y=sy;
        o.x=o.y=0;
        end.x=sx+100*vx;
        end.y=sy+100*vy;
        double d1 = sqrt((R+r)*(R+r)*1.0-dm*dm*1.0+eps);
        d1 /= sqrt(vx*vx*1.0+vy*vy*1.0);
        double d2 = sqrt((Rm+r)*(Rm+r)*1.0-dm*dm*1.0+eps);
        d2 /= sqrt(vx*vx*1.0+vy*vy*1.0);
        if(dot(end,o,start)<=0)
        {
            printf("0.000\n");
            continue;
        }
        if(dm>(R+r))
        {
            printf("%.3lf\n",0.0);
            continue;
        }
        if(dm>(Rm+r))
        {

            printf("%.3lf\n",d1*2);
            continue;
        }
        else
        {

            //double dd = *1.0;
            printf("%.3lf\n",(d1 - d2)*2);
        }
    }
}
