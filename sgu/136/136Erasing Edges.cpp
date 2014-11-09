#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n;
double x[10010] , y[10010];
double a[10010] , b[10010];
int main()
{
    int i,j;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		scanf("%lf%lf",&x[i],&y[i]);
	}
	if(n%2)
    {
        double sumx=0,sumy=0;
        int f=1;
        for(i=0;i<n;i++)
        {
            sumx += f*x[i];
            sumy += f*y[i];
            f = -f;
        }
        a[0]=sumx;
        b[0]=sumy;
        for(i=1;i<n;i++)
        {
            sumx = -sumx+2*x[i-1];
            sumy = -sumy+2*y[i-1];
            a[i]=sumx;
            b[i]=sumy;
        }
    }
    else
    {
        a[0]=-1;b[0]=1;
        for(i=1;i<=n;i++)
        {
            a[i]=2*x[i-1]-a[i-1];
            b[i]=2*y[i-1]-b[i-1];
        }
        if(a[0]!=a[n]||b[0]!=b[n])
        {
            puts("NO");return 0;
        }
    }
    puts("YES");
    for(i=0;i<n;i++)
        printf("%.3lf %.3lf\n",a[i],b[i]);
}
