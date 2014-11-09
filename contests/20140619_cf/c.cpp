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
        for(i=0; i<=n; i++)
        {
            for(j=0; j<=n; j++)
            {
                b[i][j].x=-inf;
                s[i][j].x=-inf;
            }

        }
b[0][0].x=0;
            b[0][0].y=0;
            //s[0][0].x=0;
            //s[0][0].y=1;
        double ans=0;
        for(i=1; i<=n; i++)
        {
            for(j=0; j<=i; j++)
            {
                if(j>=1)
                {
                    double tmp = b[i-1][j-1].x*(1-w[i])+b[i-1][j-1].y*w[i];
                    //cout<<i<<"   "<<j<< "   "<<tmp<<endl;
                    if(tmp>b[i][j].x)
                    {
                        b[i][j].x=tmp;
                        b[i][j].y=b[i-1][j-1].y+1-w[i];
                    }
                    if(tmp<s[i][j].x)
                    {
                        s[i][j].x=tmp;
                        s[i][j].y=s[i-1][j-1].y+1-w[i];
                    }

                    tmp = s[i-1][j-1].x*(1-w[i])+s[i-1][j-1].y*w[i];
                    if(tmp>b[i][j].x)
                    {
                        b[i][j].x=tmp;
                        b[i][j].y=b[i-1][j-1].y+1-w[i];
                    }
                    if(tmp<s[i][j].x)
                    {
                        s[i][j].x=tmp;
                        s[i][j].y=s[i-1][j-1].y+1-w[i];
                    }
                }
                double tmp = b[i-1][j-1].x;
                if(tmp>b[i][j].x)
                {
                    b[i][j].x=tmp;
                    b[i][j].y=b[i-1][j-1].y;
                }
                if(tmp<s[i][j].x)
                {
                    s[i][j].x=tmp;
                    s[i][j].y=s[i-1][j-1].y;
                }

                tmp = s[i-1][j-1].x;
                if(tmp>b[i][j].x)
                {
                    b[i][j].x=tmp;
                    b[i][j].y=b[i-1][j-1].y;
                }
                if(tmp<s[i][j].x)
                {
                    s[i][j].x=tmp;
                    s[i][j].y=s[i-1][j-1].y;
                }
                cout<<i<<" "<<j<<" "<<b[i][j].x<<" "<<b[i][j].y<<" "<<s[i][j].x<<
                    " "<<s[i][j].y<<endl;
            }
        }
        for(i=1; i<=n; i++)
        {
            for(j=0; j<=i; j++)
            {
                if(b[i][j].x>ans)ans=b[i][j].x;
                if(s[i][j].x>ans)ans=s[i][j].x;
            }
        }
        printf("%.9f\n",ans);
    }
    return 0;
}
