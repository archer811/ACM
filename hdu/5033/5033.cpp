#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <fstream>
using namespace std;
const double PI = acos(-1.0);
const int maxn = 1000005;
struct O
{
    double x,h;
    int id;
    int mark;
} g[maxn*2],l[maxn],r[maxn];
int cmp(O a,O b)
{
    return a.x<b.x;
}
int a[maxn];
double f(int a,int b,int c)
{
    double by = fabs(g[a].h-g[b].h);
    double bx = fabs(g[b].x-g[a].x);
    double cy = fabs(g[c].h-g[a].h);
    double cx = fabs(g[c].x-g[a].x);
    return cy*bx>by*cx;
}
struct Point
{
    double x,y;
};
double re(Point a,Point b,Point c)
{
    double h1 = b.y;
    double a1 = fabs(a.x-b.x);
    double arc1 = atan2(h1,a1);

    h1 = c.y;
    a1 = fabs(c.x-a.x);
    double arc2 = atan2(h1,a1);
    //cout<<arc1<<" "<<arc2<<endl;
    //printf("%.10f %.10f(()))\n",arc1,arc2);
    return (PI-arc1-arc2)/PI*180;
}
double ans[maxn];
int main()
{
    int i,j,t;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int k=0;
        for(i=1; i<=n; i++)
        {
            scanf("%lf%lf",&g[k].x,&g[k].h);
            g[k].id=i;
            g[k++].mark=0;
        }
        int q;
        scanf("%d",&q);
        for(i=1; i<=q; i++)
        {
            scanf("%lf",&g[k].x);
            g[k].h=0;
            g[k].id=i;
            g[k++].mark=1;
        }
        sort(g,g+k,cmp);
        int end=0;
        for(i=0; i<k; i++)
        {
            if(g[i].mark)
            {
                while(end>1 && f(i,a[end-1],a[end-2]))
                    end--;
                if(end==0)
                {
                    O tmp;
                    tmp.x=g[i].x-0.5;
                    tmp.h=0;
                    l[i]=tmp;
                }
                else
                    l[i] = g[a[end-1]];
            }
            else
            {
                while( end && g[a[end-1]].h< g[i].h)
                    end--;
                while(end>1 && f(i,a[end-1],a[end-2]))
                    end--;
                a[end++]=i;
            }
        }
        end = 0;
        for(i=k-1; i>=0; i--)
        {
            if(g[i].mark)
            {
                while(end>1 && f(i,a[end-1],a[end-2]))
                    end--;
                if(end==0)
                {
                    O tmp;
                    tmp.x=g[i].x+0.5;
                    tmp.h=0;
                    r[i]=tmp;
                }
                else
                    r[i] = g[a[end-1]];
            }
            else
            {
                while( end && g[a[end-1]].h <= g[i].h)
                    end--;
                while(end>1 && f(i,a[end-1],a[end-2]))
                    end--;
                a[end++]=i;
            }
        }
        for(i=0; i<k; i++)
        {
            if(g[i].mark==1)
            {
                Point a,b,c;
                a.x=g[i].x;a.y=0;
                b.x=l[i].x;b.y=l[i].h;
                c.x=r[i].x;c.y=r[i].h;
                ans[g[i].id]=re(a,b,c);
                //printf("%.10f %.10f %.10f %.10f\n",
                //    l[i].x,l[i].h ,r[i].x ,r[i].h );
            }
        }
        printf("Case #%d:\n",++cas);
        for(i=1;i<=q;i++)
        {
            printf("%.10f\n",ans[i]);
        }
    }
    return 0;
}
