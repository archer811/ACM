#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<functional>
#include<bitset>
#include<ctime>

using namespace std;

#pragma comment(linker, "/STACK:1024000000,1024000000")
#define PB push_back
#define MP make_pair

const double pi=acos(-1.0),eps=1e-8;
const int maxn=1100,maxm=110000,inf=0x3f3f3f3f;
#define ll long long
//const ll linf=1122334455667788990;

struct node
{
	int a,b,x,y;
}s[maxm];
bool cmp(node a,node b)
{
	return a.b<b.b;
}

int par[maxm];
int n,m;
int getroot(int x)
{
	if(par[x]<0)return x;
	else return par[x]=getroot(par[x]);
}

void u(int x,int y)
{
	x=getroot(x);
	y=getroot(y);
	if(x==y)return ;
	par[x]=y;
}
int cal(int x)
{
	memset(par,-1,sizeof(par));
	int i;
	for(i=0;i<m;i++)
	{
		if(s[i].a<=x)
		{
			u(s[i].x,s[i].y);
			if(getroot(1)==getroot(n))
			{
				return x+s[i].b;
			}
		}
	}
	return inf;
}
int main()
{
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int Maxa,i,j,ans,low,high,ml,mr,xl,xr;
	while(scanf("%d%d",&n,&m)==2)
	{
		Maxa=0;
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d%d",&s[i].x,&s[i].y,&s[i].a,&s[i].b);
			Maxa=max(Maxa,s[i].a);
		}
		sort(s,s+m,cmp);
		ans=cal(Maxa);
		if(ans==inf)
		{
			ans=-1;
		}
		else if(Maxa<=10)
		{
			for(i=0;i<=Maxa;i++)
			{
				ans=max(ans,cal(i));
			}
		}
		else
		{
			low=0;
			high=Maxa;
			while(low+10<high)
			{
				ml=low+(high-low)/3;
				mr=high-(high-low)/3;
				xl=cal(ml);
				xr=cal(mr);
				if(xl>xr||xl==inf)
				{
					low=ml;
				}
				else
				{
					high=mr;
				}
			}
			for(i=low;i<=high;i++)
			{
				ans=min(ans,cal(i));
			}
		}
		printf("%d\n",ans);
	}

    return 0;
}


