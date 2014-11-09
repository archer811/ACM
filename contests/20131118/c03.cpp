#include <iostream>
using namespace std;
int main()
{
	long long t1, t2, x1, x2, t0, i, y1, y2, y;
	double t=1000001, k;
	cin>>t1>>t2>>x1>>x2>>t0;
	if(t1==t2)
	{
		cout<<x1<<" "<<x2;
		return 0;
	}
	if(t0==t1)
	{
		cout<<x1<<" 0";
		return 0;
	}
	for(i=1; i<=x2; i++)
	{
		y=i*(t2-t0)/(t0-t1);
		cout<<i<<" "<<y<<endl;
		if(y>x1)
			y=x1;
		k=(double)(t1*y+t2*i)/(y+i);
		if(t>=k)
			t=k, y1=y, y2=i;
	}
	cout<<y1<<" "<<y2;
	return 0;
}
