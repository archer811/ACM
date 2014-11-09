#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;
struct Point
{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
}g[4006];
double d[4006];
const double eps = 1e-8;
int dcmp(double x)
{
    if(fabs(x)<eps)return 0;
    return x<0?-1:1;
}
typedef Point Vector;
double dis(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%lf%lf",&g[i].x,&g[i].y);
        memset(d,0,sizeof(d));
        for(i=1;i<n;i++)
        {
            d[i]=d[i-1]+dis(g[i],g[i-1]);
        }
        double ans = d[n-1];
        for(i=3;i<n;i++)
        {
            for(j=i-2;j>=1;j--)
            {
                int flag=0;
                if(g[i].x==g[i-1].x&&g[j].y==g[j-1].y)
                {

                    double x1 = max(g[j].x,g[j-1].x);
                    double x2 = min(g[j].x,g[j-1].x);
                    double yl = max(g[i].y,g[i-1].y);
                    double y2 = min(g[i].y,g[i-1].y);
                    //cout<<x1<<" "<<x2<<" "<<yl<<" "<<y2<<"  "<<g[i].x<<" "<<g[j].y<<endl;
                    if(g[i].x>=x2&&g[i].x<=x1&&g[j].y>=y2&&g[j].y<=yl)
                    {
                        Point c;
                        c.x = g[i].x;
                        c.y = g[j].y;
//                        cout<<"a"<<i<<" "<<j<<endl;
//                        cout<<c.x<<"*"<<c.y<<endl;
                        double tmp = (d[i]-dis(g[i],c))-(d[j]-dis(g[j],c));
                        ans = min(ans,tmp);
                    }
                }
                if(g[i].y==g[i-1].y&&g[j].x==g[j-1].x)
                {

                    double x1 = max(g[i].x,g[i-1].x);
                    double x2 = min(g[i].x,g[i-1].x);
                    double yl = max(g[j].y,g[j-1].y);
                    double y2 = min(g[j].y,g[j-1].y);
                    if(g[i].y>=y2&&g[i].y<=yl&&g[j].x>=x2&&g[j].x<=x1)
                    {
                        Point c;
                        c.x = g[j].x;
                        c.y = g[i].y;
//                        cout<<"b"<<" "<<i<<" "<<j<<endl;
//                        cout<<c.x<<" "<<c.y<<endl;
                        double tmp = (d[i]-dis(g[i],c))-(d[j]-dis(g[j],c));
//                        cout<<tmp<<endl;
                        ans = min(ans,tmp);
                    }
                }
            }
        }
        printf("%.0f\n",ans);
    }
    return 0;
}
