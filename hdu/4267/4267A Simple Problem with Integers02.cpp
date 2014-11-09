#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N=50005;
int org[N];
struct BIT
{
	int valu[N];
	int lowbit(int x){return x&(-x);}
	void clear(){memset(valu,0,sizeof(valu));}
	void updata(int st,int ed,int c)
	{
		for(int i=ed;i>=1;i-=lowbit(i))
			valu[i]+=c;
		for(int i=st-1;i>=1;i-=lowbit(i))
			valu[i]-=c;
	}
	int getvalu(int pos)
	{
		int sum=0;
		for(int i=pos;i<N;i+=lowbit(i))
			sum+=valu[i];
		return sum;
	}
}bit[11][11];
int main()
{
	int n,m;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<=10;i++)
			for(int j=0;j<=10;j++) bit[i][j].clear();
		for(int i=1;i<=n;i++) scanf("%d",&org[i]);

		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			int a,b,k,c,op;
			scanf("%d",&op);
			if(op==1)
			{
				scanf("%d%d%d%d",&a,&b,&k,&c);
				int st=a/k;
				int ed=a/k+(b-a)/k;
				bit[k][a%k].updata(st+1,ed+1,c);
			}
			else
			{
				int sum=0;
				scanf("%d",&a);
				for(int i=1;i<=10;i++)
					sum+=bit[i][a%i].getvalu(a/i+1);
				printf("%d\n",sum+org[a]);
			}
		}
	}
	return 0;
}
