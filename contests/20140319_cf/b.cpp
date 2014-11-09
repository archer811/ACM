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
double a;
void output(int start,double x)
{
    //cout<<start<<" ** "<<x<<endl;
    if(start==0)
    {
        printf("%.4f %.4f\n",x,0.0);
    }
    if(start==1)
    {
        printf("%.4f %.4f\n",a,x);
    }
    if(start==2)
    {
        printf("%.4f %.4f\n",a-x,a);
    }
    if(start==3)
    {
        printf("%.4f %.4f\n",0.0,a-x);
    }
}
int main()
{
    int i,j;
    double d;
    int n;
    while(cin>>a>>d>>n)
    {
        int start=0;
        double last=a;
        for(i=0;i<n;i++)
        {
            if(d<=last)
            {
                output(start,a-last+d);
                last = last-d;
            }
            else
            {
                int tmp = (d-last)/a;
                start = (start+tmp+1)%4;
                //cout<<d<<"  "<<last<<" "<<start<<endl;
                double last2 = d-last-a*tmp;
                last = a-last2;
               // cout<<last2<<endl;
                output(start,last2);
            }
        }
    }
}
