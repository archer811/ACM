#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include <iostream>
#include <iomanip>
using namespace std;
double a[6],b[6];
const double inf = 0x3fffffff*1.0;
double dis(int x,int y)
{
    return sqrt((a[x]-a[y])*(a[x]-a[y])+(b[x]-b[y])*(b[x]-b[y]));
}
double r1[6],r2[6];
int g[6],vis[6];
double d[6][6];
double f(double mid)
{
    r1[1]=mid;r1[2]=r1[3]=r1[4]=0;
    int num=0;
    g[num++]=1;
    for(int i=1;i<=4;i++)
        vis[i]=0;
    vis[1]=1;
    double sum=mid;
    for(int k=0;k<3;k++)
    {
        for(int i=1;i<=4;i++)
            r2[i]=inf;
        for(int i=1;i<=4;i++)
        {
            if(vis[i])continue;
            for(int j=1;j<=4;j++)
            {
                if(j==i)continue;
                r2[i]=min(r2[i],d[i][j]-r1[j]);
                //cout<<i<<" "<<j<<"  "<<d[i][j]<<" "<<r1[j]<<endl;
            }
        }
//        cout<<k<<endl;
//        for(int i=1;i<=4;i++)
//            cout<<r2[i]<<" ";
//        cout<<endl;
        double tmp;
        int flag=-1;
        for(int i=1;i<=4;i++)
        {
            if(vis[i])continue;
            if(flag==-1)
            {
                flag=i;tmp=r2[i];
            }
            else if(r2[i]<tmp)
            {
                tmp=r2[i];flag=i;
            }
        }
        if(flag!=-1)
        {
            r1[flag]=tmp;
            vis[flag]=1;
            //cout<<k<<" "<<flag<<"   "<<tmp<<endl;
            sum+=tmp;
            //cout<<sum<<"****"<<endl;
            g[num++]=flag;
        }
    }
    return sum;
}
const double eps = 1e-7;
int main()
{
    int i,j;
    while(~scanf("%lf%lf",&a[1],&b[1]))
    {

        for(i=2;i<=4;i++) scanf("%lf%lf",&a[i],&b[i]);
        double len=-1;
        for(i=1;i<=4;i++)
        {
            for(j=i+1;j<=4;j++)
            {
                double tmp = dis(i,j);
                d[i][j]=d[j][i]=tmp;
                if(len<0||tmp<len)len=tmp;
            }
        }
        double l = 0,r = len;
        double t1,t2;
        while(l+eps<r)
        {
            double mid = (l+r)/2,mid2=(mid+r)/2;
            t1 = f(mid);t2 = f(mid2);
            if(t1>t2)r=mid2;
            else l=mid;
        }
        double ans = f(l);
        printf("%.6f\n",ans);
    }
    return 0;
}
