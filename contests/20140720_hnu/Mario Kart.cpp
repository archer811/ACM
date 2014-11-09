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
int a[105];
int d[105][105];
const int inf  = 0x3fffffff;
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,l;
        scanf("%d%d%d",&n,&m,&l);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        int c,v;
        scanf("%d%d",&c,&v);
        cout<<"*"<<endl;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(i==j)d[i][j]=0;
                else d[i][j]=inf;
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                int tmp = a[j]-a[i];
                if(tmp%v==0)
                {
                    int l2 = tmp/v;
                    l2 = l2*c;
                    if(l2<=l)
                        d[i][j]=1;
                    cout<<i<<" "<<j<<" "<<d[i][j]<<endl;
                }
            }
        }
        for(int k=1;k<=n;k++)
        {
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                {
                    if(d[i][k]<inf&&d[k][j]<inf)
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                }
            }
        }
        if(d[1][n]>=inf)d[1][n]=-1;
        printf("%d\n",d[1][n]);
    }
    return 0;
}
