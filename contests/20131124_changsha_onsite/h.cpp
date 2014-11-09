#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
const double PI = acos(-1.0);
double R,r,h,f,s;
double F(int mid,double r1)
{
    return tan(PI/mid)*r1*2;
}
int main()
{
    int i,j,k;

    while(scanf("%lf%lf%lf%lf%lf",&R,&r,&h,&f,&s)!=EOF)
    {
        double res = (R-r)/(double)(f);
        double area=0;
        double l1 = h/(double)f;
        for(i=0; i<f; i++)
        {
            double r1 = r+i*res;
            int Left, Right;
            int mid;
            double mid_area;
            Left = 3;
            Right = 1e9;
            while (Left <= Right)
            {
                mid = (Left + Right) / 2;
                mid_area = F(mid,r1);
                if(mid_area*l1-s<0)Right = mid-1;
                else Left = mid+1;
            }
            mid = (Left+Right)/2;
            double ll = F(mid,r1);
            area += ll*l1*mid;
        }
        printf("%.3f\n",area);
        //cout<<area<<endl;
    }
}
