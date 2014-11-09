#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define FOR(i,l,r) for(int i=l;i<=r;++i)
#define REP(i,r) for(int i=0;i<r;++i)
#define db double
#define PI acos(-1.0)

db getlens(db r,int n)
{
    return 2 * r * tan(PI / n)*n;
}

int main()
{
    int R,r,H,F,S;
    while(~scanf("%d%d%d%d%d",&R,&r,&H,&F,&S))
    {
        db r1,l1;
        db ans = 0;
        double h1 = H * 1.0 / F;
        double res = (R-r)/(double )(F);
        REP(i,F)
        {
            r1 =  i * res + r;
            int left = 3,right = 1e9;
            while(left <= right)
            {
                int mid = (left+right) >> 1;
                l1 = getlens(r1,mid);
                if(l1 * h1 - S < 0)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            int mid = (left+right) >> 1;
            l1 = getlens(r1,mid);
            ans += l1 * h1 ;
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}
