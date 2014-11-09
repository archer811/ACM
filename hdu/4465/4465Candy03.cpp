#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

double g[400005];
double f(int n,int m)
{
    return g[n]-g[m]-g[n-m];
}
int main()
{
    int k;
    g[0]=0;
    for(int i=1;i<=400000;i++)
        g[i]=g[i-1]+log(i*1.0);
    int n;
    double p;
    int cas=0;
    while(scanf("%d%lf",&n,&p)!=EOF)
    {
        double sum=0,q=1.0-p;
        for(k=0;k<=n;k++)
        {
            sum += (n-k)*1.0*(exp(f(n+k,k)+(n+1)*log(p*1.0)+(k)*log(q*1.0))+
                          exp(f(n+k,k)+(n+1)*log(q*1.0)+(k)*log(p*1.0)));
//            sum += (n-k)*1.0*(exp(f(n+k,k)+(n+1)*log(q*1.0)+k*log(p*1.0))+
//                        exp(f(n+k,k)+(n+1)*log(p*1.0)+k*log(q*1.0)));
        }
        printf("Case %d: ",++cas);
        printf("%.6f\n",sum);
    }
}
