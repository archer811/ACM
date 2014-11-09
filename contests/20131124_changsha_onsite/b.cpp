#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int n;
double t[122][122];
double d[10005][122];
int a[10005];
int main()
{
    int i,j,k;
    int m;
    while(scanf("%d",&n)!=EOF)
    {
        n = n*(n-1)*(n-2)/6;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%lf",&t[i][j]);
            }
        }
        memset(d,0,sizeof(d));
        for(i=0;i<n;i++)
            d[0][i]=1;
        scanf("%d",&m);
        for(i=1;i<=m;i++)
            scanf("%d",&a[i]);
        for(i=1;i<=m;i++)
        {
            int tmp = a[i];
            for(j=0;j<n;j++)
            {
                double gg=d[i-1][j]*t[j][tmp];
                d[i][tmp]=max(d[i][tmp],gg);
                //if(i==1&&j==3)cout<<gg<<endl;
                d[i][j]=max(d[i][j],gg);

            }
//            for(j=0;j<n;j++)
//                cout<<d[i][j]<<" ";
//            cout<<endl;
        }
        double ans=0;
        for(i=0;i<n;i++)
            ans = max(d[m][i],ans);
        printf("%.6f\n",ans);
    }
}
