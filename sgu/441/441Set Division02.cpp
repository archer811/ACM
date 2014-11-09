#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
#define LL __int64
#define inf 2007

LL Cal(LL x,LL y)
{
	LL ans=1,t=y;
	while(t--)
	{
		ans*=x,x--;
		while((ans%y==0)&&y>1)
			ans/=y,y--;
	}
	return ans;
}

LL mul_mod(LL a,LL b,LL m)  //(a*b)%m
{
	LL ans=0;
	LL d=a%m;
	while(b)
	{
		if(b&1)ans=ans+d;
		if(ans>=m)ans-=m;
		d<<=1;
		if(d>=m)d-=m;
		b>>=1;
	}
	return ans;
}

LL pow_mod(LL a,LL r,LL m)
{
	LL d=1,t=a%m;
	while(r)
	{
		if(r%2)
			d=mul_mod(d,t,m);   //(d*t)%m; ,d*t在m=10!*2007的情况下已经跃出long long
		r/=2;
		t=mul_mod(t,t,m)%m;
	}
	return d%m;
}

int main()
{
	LL n,k,i,j;
	while(~scanf("%I64d%I64d",&n,&k))
	{
		LL t=1,m=1,flag=1;
		for(i=1;i<=k;i++)
			t*=i;
		m=t*inf;    //(a/b)%m=(a%(b*m))/b。
		LL sum=0;
		for(i=0;i<=k-1;i++)
		{
			sum+=flag*Cal(k,i)*pow_mod(k-i,n,m);
			sum=(sum%m+m)%m;
			flag=-flag;
		}
		cout<<sum<<endl;
		sum=sum%m/t;
		printf("%I64d\n",sum);
	}
	return 0;
}
