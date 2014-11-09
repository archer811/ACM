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
    double x;
    int index;
}s[100005];
int cmp(array a,array b)
{
    return a.x<b.x;
}
double dis(double xl,double yl,double x2,double y2)
{
    return sqrt((xl-x2)*(xl-x2)+(yl-y2)*(yl-y2));
}
int g2(int x)
{
    if(x<0)return -x;
    return x;
}
int main()
{
    int i,j,n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        double xn1,yn1;
        for(i=1;i<=n;i++)
        {
            scanf("%lf",&s[i].x);
            s[i].index=i;
        }
        scanf("%lf%lf",&xn1,&yn1);
        sort(s+1,s+1+n,cmp);
        int now=-1;
        for(i=1;i<=n;i++)
        {
            //cout<<s[i].index<<" "<<s[i].x<<" "<<k<<endl;
            if(s[i].index==k){now=i;break;}
        }
        double ans=-1;
        if(k>=1&&k<=n)
        {
            double sum = s[n].x-s[1].x;
            sum *= 2;
            for(i=1;i<=n;i++)
            {
                double tmp1 = 2*(s[i].x-s[1].x)+s[n].x-s[i].x;
                double tmp2 = 2*(s[n].x-s[i].x)+s[i].x-s[1].x;
                if(tmp1>tmp2)tmp1=tmp2;
                double tmp = tmp1+2*dis(s[i].x,0,xn1,yn1);
                if(ans==-1||tmp<ans)ans=tmp;
            }
            //cout<<ans<<endl;
            for(i=1;i<n;i++)
            {
                double tmp1 = g2(s[now].x-s[i].x)+2*(s[i].x-s[1].x)+
                    s[n].x-s[i+1].x;
                double tmp2 = g2(s[now].x-s[i+1].x)+2*(s[n].x-s[i+1].x)+
                    s[i].x-s[1].x;
                if(tmp1>tmp2)tmp1=tmp2;
                double tmp = tmp1+dis(s[i].x,0,xn1,yn1)+dis(s[i+1].x,0,xn1,yn1);
               // cout<<ans<<"*"<<tmp2<<"()"<<tmp<<" "<<tmp1<<"  "<<dis(s[i].x,0,xn1,yn1)+dis(s[i+1].x,0,xn1,yn1)<<endl;
                if(ans==-1||tmp<ans)ans=tmp;
            }
            //cout<<ans<<endl;


            if(now>1&&now<n)
            {
                if(xn1>=s[now-1].x&&xn1<=s[now+1].x)
                {
                    double tmp = 2*(s[now].x-s[1].x)-(s[now].x-s[now-1].x)+
                    dis(s[now-1].x,0,xn1,yn1)+dis(s[now+1].x,0,xn1,yn1)+s[n].x-s[now+1].x;
                    if(ans==-1||tmp<ans)ans=tmp;
//cout<<tmp<<endl;

                    tmp = 2*(s[n].x-s[now].x)-(s[now+1].x-s[now].x)+
                    dis(s[now-1].x,0,xn1,yn1)+dis(s[now+1].x,0,xn1,yn1)+s[now-1].x-s[1].x;
                    if(ans==-1||tmp<ans)ans=tmp;

                    //cout<<tmp<<endl;
                }
            }

        }
        else
        {
            for(i=1;i<=n;i++)
            {
                double tmp1=s[i].x-s[1].x;
                double tmp2 = s[n].x-s[i].x;
                if(tmp1>tmp2)tmp1=tmp2;
                double tmp = s[n].x-s[1].x+tmp1+dis(s[i].x,0,xn1,yn1);
                if(ans==-1||tmp<ans)ans=tmp;
            }
        }
        printf("%.6f\n",ans);
    }
    return 0;
}
