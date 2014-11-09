#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define num 100
double dp[num];
void init()
{
	int i,j,cnt;
	double sum;
	dp[1]=0;
    for(i=2;i<num;i++)
	{
		sum=0;
		cnt=0;
        for(j=1;j<=sqrt(i);j++)
			if(i%j==0)
			{
				sum+=dp[j];
				//if(i==2)cout<<"dpdpdpdpd"<<dp[j]<<endl;
				cnt++;
				if(j!=i/j)
				{
					sum+=dp[i/j];
					//if(i==2)cout<<"dpdpdpdpd"<<dp[i/j]<<endl;
					cnt++;
				}
			}
		sum+=cnt;
		cout<<i<<" "<<sum<< " "<<cnt<<endl;
		dp[i]=sum/(cnt-1);
	}
}
int main()
{
	init();
	int t,n,Case=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("Case %d: %lf\n",Case++,dp[n]);
	}
	return 0;
}
