#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
struct array
{
    double x,y;
}a[204];
double dis(int i,int j)
{
    double p = (a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y);
    p = sqrt(p*1.0);
    return p;
}
int main()
{
    int i,j,k;
    int n;
    while(cin>>n>>k)
    {
        double s =0;
        for(i=1;i<=n;i++)
        {
            scanf("%lf%lf",&a[i].x,&a[i].y);
            if(i>1)
                s += dis(i-1,i);
        }
        printf("%.6f\n",s*k*1.0/50.0);
    }
}
