#include<cstdio>
#include<cmath>
double f[400005];
double logC(int m,int n)
{
    return f[m]-f[n]-f[m-n];
}
int main()
{
    f[0]=0;
    for(int i=1; i<=400002; i++) f[i]=f[i-1]+log(i*1.0);
    for(int i=1;i<=10;i++)
        printf("%.3f\n",f[i]);
    int apple=1,n;
    double p,q;
    while(~scanf("%d",&n))
    {
        scanf("%lf",&p);
        q=1-p;
        double ans=0;
        for(int k=0; k<=n; k++)
        {
            ans+=(n-k)*(exp(logC(n+k,k)+(n+1)*log(q*1.0)+k*log(p*1.0))+exp(logC(n+k,k)+(n+1)*log(p*1.0)+k*log(q*1.0)));
        }
        printf("Case %d: %.6f\n",apple++,ans);
    }
    return 0;
}
