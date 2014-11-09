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
const double eps = 1e-8;
struct Point
{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
};
typedef Point Vector;
Vector operator + (Vector A,Vector B)
{
    return Vector(A.x+B.x,A.y+B.y);
}
Vector operator - (Vector A,Vector B)
{
    return Vector(A.x-B.x,A.y-B.y);
}
Vector operator *(Vector A,double p)
{
    return Vector(A.x*p,A.y*p);
}
Vector operator /(Vector A,double p)
{
    return Vector(A.x/p,A.y/p);
}
bool operator < (const Point &a,const Point &b)
{
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
int dcmp(double x)
{
    if(fabs(x)<eps)return 0;
    return x<0?-1:1;
}
bool operator == (const Point &a,const Point &b)
{
    return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
}
double Cross(Vector A,Vector B)
{
    return A.x*B.y-A.y*B.x;
}
int ConvexHull(Point* p,int n,Point* ch)
{
    sort(p,p+n);
    int m = 0;
    for(int i=0;i<n;i++)
    {
        while(m>1&& Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0)m--;
        ch[m++] = p[i];
    }
    int k=m;
    for(int i=n-2;i >= 0;i--)
    {
        while(m>k&& Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0)m--;
        ch[m++] = p[i];
    }
    if(n>1)m--;
    return m;
}
Point p[3005],ans[3005];
double PolygonArea(Point* p,int n)
{
    double area =0;
    for(int i=1;i<n-1;i++)
       area += Cross(p[i]-p[0],p[i+1]-p[0]);
    return area/2;
}

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        int m = ConvexHull(p,n,ans);
        double ansarea = PolygonArea(ans,m);
        cout<<ansarea<<endl;
    }
    return 0;
}
