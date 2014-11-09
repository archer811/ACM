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
    int i,j,t;
//    freopen("B-large.in","r",stdin);
//    freopen("out.txt","w",stdout);
    scanf("%d",&t);
    double c,f,x;
    int cas=0;
    while(t--)
    {
        scanf("%lf%lf%lf",&c,&f,&x);
        double rate = 2.0;
        double tim=0;
        double tim1 = x/2.0;

        {
            while((x/(rate+f)+c/rate)<x/rate)
            {
                tim+=c/rate;
                rate+=f;
                //cout<<tim<<endl;
            }
            tim += x/rate;
        }
        printf("Case #%d: ",++cas);
        printf("%.6f\n",tim);
        //cout<<tim<<endl;
    }
}
