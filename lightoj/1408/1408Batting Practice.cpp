#include <cstdio>
#include <cmath>

const double STD=1e-10;

int main ()
{
	int T,k1,k2;
	double p,q;
	scanf("%d",&T);
	for (int Cas=1;Cas<=T;Cas++)
	{
		scanf("%lf%d%d",&p,&k1,&k2);
		q=1-p;
		if (p>1-STD)
		{
			printf("Case %d: %lf\n",Cas,1.0*k2);
			continue;
		}
		if (p<STD)
		{
			printf("Case %d: %lf\n",Cas,1.0*k1);
			continue;
		}
		double a=1-pow(q,k1-1);
        double b=1-pow(p,k2-1);
        double x=(a*b/q+a/p)/(1-a*b),y=b*x+b/q;
        printf("Case %d: %lf\n",Cas,p*y+q*x+1);
	}
	return 0;
}
