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
struct array
{
    double x,y,t,p;
}s[1005];
int cmp(array a,array b)
{
    return a.t<b.t;
}
double ans[10005];
const double eps = 1e-9;
int f(int a,int b)
{
    if(a==0)return 1;
    double t = s[b].t-s[a].t;
    double dis = sqrt((s[a].x-s[b].x)*(s[a].x-s[b].x)+(s[a].y-s[b].y)*(s[a].y-s[b].y));
    //cout<<t<<"*"<<dis<<endl;
    if(t+eps>dis)return 1;
    return 0;
}
double _max(double a,double b)
{
    if(a>b)return a;
    return b;
}
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%lf%lf%lf%lf",&s[i].x,&s[i].y,&s[i].t,&s[i].p);
        }
        sort(s+1,s+1+n,cmp);
        memset(ans,0,sizeof(ans));
        for(i=1;i<=n;i++)
        {
            for(j=0;j<i;j++)
            {
                if(f(j,i))
                {
                    //cout<<i<<"()"<<j<<ans[j]<<" "<<s[i].p<<endl;
                    ans[i]=_max(ans[i],ans[j]+s[i].p);
                }
            }
        }
        double t=0;
        for(i=1;i<=n;i++)
        {
            if(ans[i]>t)t=ans[i];
        }
        printf("%.6f\n",t);
    }
    return 0;
}
