#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int n,A,B,C,k1,k2,k3;
double a[600],b[600],p[600];
int main()
{
    int i,j,k,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d%d%d%d",&n,&k1,&k2,&k3,&A,&B,&C);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(p,0,sizeof(p));
        double po = 1.0/k1/k2/k3;
        for(i=1;i<=k1;i++)
            for(j=1;j<=k2;j++)
               for(k=1;k<=k3;k++)
                 if(i!=A||j!=B||k!=C)
                    p[i+j+k]+=po;
        for(i=n;i>=0;i--)
        {
            a[i]=po;b[i]=1.0;
            for(j=1;j<=k1+k2+k3;j++)
            {
                a[i]+=p[j]*a[i+j];
                b[i]+=p[j]*b[i+j];
            }
        }
        printf("%.8f\n",b[0]/(1.0-a[0]));
        //cout<<<<endl;
    }
}
