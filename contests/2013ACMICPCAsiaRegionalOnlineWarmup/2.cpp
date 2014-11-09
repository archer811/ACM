#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <stack>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define E exp(double(1))
#define maxn 110000
#define eps 1e-5
using namespace std;
int a[20][20];
int b[1000];

int main()
{
    int i,j,k,n;
    while(scanf("%d",&n)&&n)
    {
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
               scanf("%d",&a[i][j]);
        int sum=0, ps =0;
        int Min = 0,p = inf;
        k =0 ;
        for(int g=1;g<=n/2;g++)
        {
            k=0;
            Min = 0;
            for(i=g;i<=n+1-g;i++)
                b[k++]=a[g][i];
            for(i=g+1;i<=n+1-g;i++)
                b[k++]=a[i][n+1-g];
            for(i=n+1-g-1;i>=g;i--)
                b[k++]=a[n+1-g][i];
            for(i=n-g;i>g;i--)
                b[k++]=a[i][g];
//            for(j=0;j<k;j++)
//                cout<<b[j];
//            cout<<endl;
            int d = n+1-2*g;
            for(i=0;i<k;i++)
            {
                int s = i,ss=0;
                for(j=1;j<=4;j++)
                {
                    //cout<<b[s];
                    ss += b[s];
                    s = (s+d)%k;
                }
                if(Min<ss)
                {
                    Min = ss;
                    p = i;
                }
                else if(Min==ss)
                {
                    if(p>i)p=i;
                }
                //cout<<endl;
            }


            k=0;
            for(i=g;i<=n+1-g;i++)
                b[k++]=a[i][g];
            for(i=g+1;i<=n+1-g;i++)
                b[k++]=a[n+1-g][i];
            for(i=n+1-g-1;i>=g;i--)
                b[k++]=a[i][n+1-g];
            for(i=n-g;i>g;i--)
                b[k++]=a[g][i];
//            for(j=0;j<k;j++)
//                cout<<b[j];
//            cout<<endl;
            d = n+1-2*g;
            for(i=0;i<k;i++)
            {
                int s = i,ss=0;
                for(j=1;j<=4;j++)
                {
                    //cout<<b[s];
                    ss += b[s];
                    s = (s+d)%k;
                }
                if(Min<ss)
                {
                    Min = ss;
                    p = i;
                }else if(Min==ss)
                {
                    if(p>i)p=i;
                }
                //cout<<endl;
            }
            //cout<<Min<<" "<<p<<endl;
            sum += Min;
            ps += p;
        }
        cout<<sum+a[(n+1)/2][(n+1)/2]<<" "<<ps<<endl;
    }
}
