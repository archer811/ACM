#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
const int N = 200;
double w[N][N],a[N][N],b[N][N];
int main()
{
    int i,j,n;
    while(cin>>n)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                cin>>w[i][j];
        }
        for(i=1;i<=n ;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(i==j)a[i][j]=w[i][j];
                else
                {
                    a[i][j]=(w[i][j]+w[j][i])/2;
                }
            }
        }

        for(i=1;i<=n ;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(i==j)b[i][j]=0;
                else
                {
                    b[i][j]=(w[i][j]-w[j][i])/2;
                }
            }
        }

        for(i=1;i<=n ;i++)
        {
            for(j=1;j<=n;j++)
            {
                printf("%.6f ",a[i][j]);
            }
            cout<<endl;
        }

        for(i=1;i<=n ;i++)
        {
            for(j=1;j<=n;j++)
            {
                printf("%.6f ",b[i][j]);
            }
            cout<<endl;
        }
    }
}
