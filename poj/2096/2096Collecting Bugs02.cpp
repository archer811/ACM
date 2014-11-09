#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;
double e[1005][1005];
int main()
{
    int n,s;
    while(~scanf("%d%d",&n,&s))
    {
        memset(e,0,sizeof(e));
        for(int i=n; i>=0; i--)
        {
            for(int j=s; j>=0; j--)
            {
                if(i==n&&j==s) continue;
                double te=n*s*(1.0);
                e[i][j]=(1+e[i][j+1]*i*(s-j)/te+e[i+1][j]*(n-i)*j/te+e[i+1][j+1]*(n-i)*(s-j)/te)/(1-i*j/te);
            }
        }
        printf("%.4lf\n",e[0][0]);
    }
}
