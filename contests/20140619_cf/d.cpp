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
double w[105];
int n;
struct array
{
    double x,y;
} b[105][105],s[105][105];
const double inf = 0x3fffffff;
int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1; i<=n; i++)
            scanf("%lf",&w[i]);

        sort(w+1,w+1+n);
        double ans=w[n];
        double sum=1-w[1],x=w[1];
        double tmp = x*(1-w[n])+sum*w[n];
        if(w[n]>=0.5)
        {
            sum=1-w[1];x=w[1];
            tmp = x*(1-w[n])+sum*w[n];
            if(n>=2&&tmp>ans)ans=tmp;
            for(i=2; i<n; i++)
            {
                //cout<<x<<"()"<<w[i]<<" "<<1-w[1]<<" "<<sum<<endl;
                x = x*(1-w[i])+sum*w[i];

                sum = sum*(1-w[i]);
                tmp = x*(1-w[n])+sum*w[n];
                //cout<<x<<" "<<sum<<" "<<tmp<<endl;
                if(ans<tmp)ans=tmp;
            }
        }
        else
        {
            if(n>=2)
            {
                sum=1-w[n-1];x=w[n-1];
                tmp = x*(1-w[n])+sum*w[n];
                if(tmp>ans)ans=tmp;
            }
            for(i=n-2;i>=1;i--)
            {
                //cout<<x<<"()"<<w[i]<<" "<<1-w[1]<<" "<<sum<<endl;
                x = x*(1-w[i])+sum*w[i];

                sum = sum*(1-w[i]);
                tmp = x*(1-w[n])+sum*w[n];
                //cout<<x<<" "<<sum<<" "<<tmp<<endl;
                if(ans<tmp)ans=tmp;
            }
        }

        printf("%.9f\n",ans);
    }
    return 0;
}
