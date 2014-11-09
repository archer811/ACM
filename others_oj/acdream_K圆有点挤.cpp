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
const double eps = 1e-8;
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        double a,b,r1,r2;
        scanf("%lf%lf%lf%lf",&a,&b,&r1,&r2);
        double tmp,tmp2;
        if(a>b)swap(a,b);
        int flag=0;

        tmp = b-r1-r2;
        tmp2 = a-r1-r2;
        if(tmp>=0&&tmp2>=0&&tmp*tmp+tmp2*tmp2>=(r1+r2)*(r1+r2))
        {
            flag=1;
        }


        if(a<2*max(r1,r2))flag=0;

        if(flag)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
