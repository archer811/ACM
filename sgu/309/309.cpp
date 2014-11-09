#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;
struct O
{
    int x,y;
} g[20005];
const int inf = 0x3fffffff;
int n;
bool vis[20005];
inline void func(int i,int j,int &a,int &b,int xl,int xr,int yl,int yr)
{
    if(i==0)
    {
        a=g[j].x-xl;
        b=g[j].y-yl;
    }
    else if(i==1)
    {
        a=g[j].x-xl;
        b=yr-g[j].y;
    }
    else if(i==2)
    {
        a=xr-g[j].x;
        b=g[j].y-yl;
    }
    else
    {
        a=xr-g[j].x;
        b=yr-g[j].y;
    }
}
inline int check(int mid,int XL,int XR,int YL,int YR)
{
    for(int i=0; i<4; i++)
    {
        int xl=inf,xr=-inf,yl=inf,yr=-inf;
        int sum1=0;
        for(int j=1; j<=n; j++)
            vis[j]=0;
        for(int j=1; j<=n; j++)
        {
            int a=-1,b=-1;
            func(i,j,a,b,XL,XR,YL,YR);
            if(a>=0&&b>=0&&a<=mid&&b<=mid)
            {
                sum1++;
                vis[j]=1;
                continue;
            }
            xl=min(g[j].x,xl);
            xr=max(g[j].x,xr);
            yl=min(g[j].y,yl);
            yr=max(g[j].y,yr);
        }
        if(sum1>=n)return 1;
        int x1=inf,x2=-inf,yleft=inf,y2=-inf;
        int sum2;
        for(int tp=0; tp<4; tp++)
        {
            sum2=sum1;
            x1=inf;
            x2=-inf;
            yleft=inf;
            y2=-inf;
            for(int j=1; j<=n; j++)
            {
                if(vis[j])continue;
                int a=-1,b=-1;
                func(tp,j,a,b,xl,xr,yl,yr);
                if(a>=0&&b>=0&&a<=mid&&b<=mid)
                {
                    sum2++;
                    continue;
                }
                x1=min(g[j].x,x1);
                x2=max(g[j].x,x2);
                yleft=min(g[j].y,yleft);
                y2=max(g[j].y,y2);
            }
            if(sum2>=n)return 1;
            if(x2-x1<=mid&&y2-yleft<=mid)return 1;
        }
    }
    return 0;
}
template <class T>
inline bool rd(T &ret)
{
    char c;
    int sgn;
    if(c=getchar(),c==EOF) return 0;
    while(c!='-'&&(c<'0'||c>'9')) c=getchar();
    sgn=(c=='-')?-1:1;
    ret=(c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
    ret*=sgn;
    return 1;
}
int main()
{
    int i,j;
    int xl,xr,yl,yr;
    rd(n);
    {
        xl=inf;
        xr=-inf;
        yl=inf;
        yr=-inf;
        for(i=1; i<=n; i++)
        {
            rd(g[i].x);
            rd(g[i].y);
            xl=min(g[i].x,xl);
            xr=max(g[i].x,xr);
            yl=min(g[i].y,yl);
            yr=max(g[i].y,yr);
        }
        int l=0,r=max(xr-xl,yr-yl);
        while(l<r)
        {
            int mid = (l+r)>>1;
            if(check(mid,xl,xr,yl,yr))r=mid;
            else l=mid+1;
        }
        printf("%d\n",l);
    }
    return 0;
}
