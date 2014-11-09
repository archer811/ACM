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
double a,b,c;
struct ar
{
    double x,y;
}s[33];
double x1,x2,x3,yl,y3,y2;
double dis(double x1,double yl,double x2,double y2)
{
    return sqrt((x2-x1)*(x2-x1)+(y2-yl)*(y2-yl));
}
int f(int i,int j,int k)
{

    if((y2-yl)*(s[j].x-s[i].x)!=(x2-x1)*(s[j].y-s[i].y))return 0;

    if((y3-y2)*(s[k].x-s[j].x)!=(x3-x2)*(s[k].y-s[j].y))return 0;
//    if(s[i].x==0&&s[i].y==0&&s[j].x==0&&s[j].y==2)
//        cout<<"()"<<endl;
    if((y3-yl)*(s[k].x-s[i].x)!=(x3-x1)*(s[k].y-s[i].y))return 0;
    double d1 = dis(x1,yl,x2,y2);
    double d2 = dis(x2,y2,x3,y3);
    double d3 = dis(x1,yl,x3,y3);
    double k1 = dis(s[i].x,s[i].y,s[j].x,s[j].y);
    double k2 = dis(s[j].x,s[j].y,s[k].x,s[k].y);
    double k3 = dis(s[i].x,s[i].y,s[k].x,s[k].y);
    if(d1*k2!=d2*k1)return 0;
    if(d1*k3!=d3*k1)return 0;
    if(d2*k3!=d3*k2)return 0;
}
int judge(int i,int j,int k)
{
    if(f(i,j,k))return 1;
    if(f(i,k,j))return 1;
    if(f(j,i,k))return 1;
    if(f(j,k,i))return 1;
    if(f(k,i,j))return 1;
    if(f(k,j,i))return 1;
    return 0;
}
int main()
{
    int i,j,k,n;

    while(scanf("%d",&n)!=EOF)
    {
        scanf("%lf%lf%lf%lf%lf%lf",&x1,&yl,&x2,&y2,&x3,&y3);
        for(i=0;i<n;i++)
            scanf("%lf%lf",&s[i].x,&s[i].y);
        int sum=0;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                for(k=j+1;k<n;k++)
                {
                    if(judge(i,j,k))sum++;
                }
            }
        }
        cout<<sum<<endl;
    }
}
