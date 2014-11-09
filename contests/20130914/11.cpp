#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int change(int n){
	int t=1;
	int tmp,ans=0;
	while(n){
		tmp=n%10;
		ans+=t*tmp;
		t<<=1;
		n/=10;
	}
	return ans;
}
int main()
{
    int i,j,k;
    while(cin>>i)
        cout<<change(i)<<endl;
}
