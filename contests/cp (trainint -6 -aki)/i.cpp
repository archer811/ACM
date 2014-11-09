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
const double eps = 1e-10;
struct array
{
    double x,y;
}s[1005];
double dis(double a,double b,double c,double d)
{
    return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
vector<array>v;
int main()
{
    int i,j,n,m;
    int cas=0;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        double sum=0;
        v.clear();
        n++;
        s[1].x=s[1].y=0.0;
        for(i=2;i<=n;i++)
        {
            scanf("%lf%lf",&s[i].x,&s[i].y);
            if(i>1)
            {
                sum += dis(s[i].x,s[i].y,s[i-1].x,s[i-1].y);
            }
        }
        sum /= (m+1);
        double now=sum;
        for(i=2;i<=n;i++)
        {
            double tmp = dis(s[i].x,s[i].y,s[i-1].x,s[i-1].y);
            double tmp2 = tmp;
            double th =0;
            while(tmp>eps)
            {
                if(now<tmp)
                {
                    array next;
                    th += now;
                    //cout<<now<<"&&&&"<<th<<endl;
                    next.x=s[i-1].x+th*1.0/tmp2*(s[i].x-s[i-1].x);
                    next.y=s[i-1].y+th*1.0/tmp2*(s[i].y-s[i-1].y);
                    if(v.size()<m)
                    v.push_back(next);
                    //cout<<i<<"()"<<now<<" "<<tmp<<endl;
                    tmp -= now;

                    now=sum;
                }
                else if(now==tmp)
                {
                    array next;
                    th += now;
                    next.x=s[i].x;next.y=s[i].y;
                    if(v.size()<m)
                    v.push_back(next);
                    tmp=0;
                }
                else
                {
                    now-=tmp;
                    th += tmp;
                    tmp=0;
                }
            }
        }
        printf("Route %d\n",++cas);
        for(i=0;i<v.size();i++)
        {
            printf("CP%d: (%.3f, %.3f)\n",i+1,v[i].x,v[i].y);
        }
    }
    return 0;
}
