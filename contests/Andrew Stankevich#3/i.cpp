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
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int g=0;g<n;g++)
        {
            double r1,r2;
            scanf("%lf%lf",&r1,&r2);
            if(r1>r2)swap(r1,r2);
            printf("%.4f\n",16.0/3*r1*r1*r1);
        }
    }
    return 0;
}
