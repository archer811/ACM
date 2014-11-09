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
double v[505];
double a[250006];
int main()
{
    int i,j,n,m;
    while(cin>>n>>m)
    {
        for(i=1;i<=n;i++)
            cin>>v[i];
        for(i=0;i<m;i++)
        {
            int x,y;
            double c;
            cin>>x>>y>>c;
            a[i]=(double)v[x]/c+(double)v[y]/c;

        }
        sort(a,a+m);
        printf("%.9f\n",a[m-1]);
    }
    return 0;
}
