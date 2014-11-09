#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
double s;
int n;
int f(double len)
{
    int a=0,g=0;
//    if(len>3&&len<4)g=1,cout<<len<<endl;
    int ff=1;
    while(ff)
    {
        len -= 1;
        double d = asin(1.0/len);
        d = d*360/PI;
        if(d==0||360/d<1)
        {
            ff=0;
            break;
        }
        a += 360/d;
//
//        if(g)
//            cout<<360/d<<"                       "<<len<<endl;
        if(a>=n)break;
        len -= 1;
    }
    //if(g)cout<<a<<"*"<<(a>=n)<<endl;
    if(a>=n)return 1;
    return 0;
}
int main()
{
    s = sqrt(3.0);
    s = 3*(s-1)/(2*s);
    //cout<<s<<endl;
    int gg[]= {0,0,0,6,8,10,12,12,14,16,17};
    int gk=0;
    while(scanf("%d",&n)!=EOF)
    {
        double d = 180/n;
        d = sin(d*PI/180); //cout<<d<<endl;
        d = 1/d;

        printf("%.6f\n",d+1);
    }
}
