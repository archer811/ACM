#include <cstdio>
#include <cstring>
double dt[105],store[105];
int main()
{
       int t,c=1;
	   int n,i,j;
	   double tmp;
	   for(scanf("%d",&t);t--;)
	   {
	           scanf("%d",&n);
			   memset(dt,0,sizeof(dt));
			   for(i=n-1;i>=0;i--)
			   {
				   scanf("%lf",&store[i]);
			       dt[i]=store[i];
			   }
			   for(i=1;i<=6;i++)
			   {
				   tmp=0;
				   for(j=0;j<i;j++)
					   tmp=tmp+(dt[j]/i);
				   dt[i]+=tmp;
			   }
			   if(n<=7)
			   {
				   printf("Case %d: %.7lf\n",c++,dt[n-1]);
			       continue;
			   }
			   for(;i<n;i++)
                   dt[i]=dt[i-1]-store[i-1]+store[i]+(dt[i-1]-dt[i-7])/6;
			   printf("Case %d: %.6lf\n",c++,dt[n-1]);
	   }return 0;
}
