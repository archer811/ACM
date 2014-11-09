#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

#define LL long long
#define DB double
#define SI(a) scanf("%d",&a)
#define SD(a) scanf("%lf",&a)
#define SS(a) scanf("%s",a)
#define PF printf
#define MM(a,b) memset(a,b,sizeof(a))
#define REP(i,a,b) for(int i=a;i<b;i++)
#define REPD(i,a,b) for(int i=a;i>b;i--)
#define INF 0x3f3f3f3f
#define EPS 1e-8
#define bug puts("bug")
using namespace std;
#define N 100
struct cpoint
{
    DB x,y;
    void get()
    {
        SD(x);
        SD(y);
    }
} o,coin,tmp;
struct cvector
{
    DB x,y;
    cvector(DB a,DB b)
    {
        x = a;
        y = b;
    }
    cvector() {}
};
cvector operator-(cpoint a,cpoint b)
{
    return cvector(a.x-b.x,a.y-b.y);
}
cpoint operator+(cpoint a,cvector b)
{
    a.x+=b.x;
    a.y+=b.y;
    return a;
}
DB dot(cpoint a,cpoint b,cpoint p)
{
    return (a.x-p.x)*(b.x-p.x) + (a.y-p.y)*(b.y-p.y);
}
DB x_mult(cpoint a,cpoint b,cpoint p)
{
    return (a.x-p.x)*(b.y-p.y) - (a.y-p.y)*(b.x-p.x);
}
DB Rm,R,r,vx,vy;
DB length(cvector t)
{
    return sqrt(t.x*t.x+t.y*t.y);
}

int main()
{

    o.x = 0;
    o.y = 0;
    while(~SD(Rm))
    {
        SD(R);
        SD(r);
        coin.get();
        SD(vx);
        SD(vy);
        cvector t;
        t.x = vx*100;
        t.y = vy*100;
        tmp = coin + t;
        printf("%lf %lf\n%lf %lf\n%lf %lf\n",tmp.x,tmp.y,o.x,o.y,coin.x,coin.y);
        if(dot(tmp,o,coin)<=0)
        {
            printf("0.00000\n");
            continue;
        }
        DB cc = x_mult(o,tmp,coin);
        DB d = fabs(cc/length(tmp-coin));
        DB x = sqrt((R+r)*(R+r)-d*d+EPS);
        DB x1 = sqrt((Rm+r)*(Rm+r)-d*d+EPS);
        if(d>(R+r))
        {
            PF("0.00000\n");
            continue;
        }
        if(d>(Rm+r))
        {
            PF("%.5lf\n",2*x/sqrt(vx*vx+vy*vy));
        }
        else
        {
            PF("%.5lf\n",2*(x-x1)/sqrt(vx*vx+vy*vy));
        }
    }
    return 0;
}
