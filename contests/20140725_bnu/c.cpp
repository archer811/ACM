#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
struct point
{
    double x,y;
}R[5];
double dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
    while(cin>>R[0].x>>R[0].y)
    {
        cin>>R[1].x>>R[1].y;
        cin>>R[2].x>>R[2].y;
        cin>>R[3].x>>R[3].y;
        double a1=dis(R[0],R[1]);
        double a2=dis(R[2],R[3]);
        double b1=dis(R[0],R[2]);
        double b2=dis(R[1],R[3]);
        double c1=dis(R[0],R[3]);
        double c2=dis(R[1],R[2]);
        double ans=min(min(a1+a2,b1+b2),c1+c2);
        printf("%.8lf\n",ans);
    }
    return 0;
}
