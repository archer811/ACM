#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <stack>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define E exp(double(1))
#define maxn 11000
#define eps 1e-7
using namespace std;
typedef long long LL;

char str[][20]={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
char tmp[maxn];

int main(){
	int i,j,k;
	double s;
	double len;
	double time;
	while(scanf("%s%lf%lf",tmp,&len,&s)!=EOF){
		time=len/s;
		int t=(int)time;
		if(time-t>0)t++;
		t%=48;

		for(i=0;i<7;i++){
			if(strcmp(str[i],tmp)==0)break;
		}
		i++;
		cout<<i<<endl;
		cout<<str[i-1]<<endl;
		int now=i;

		while(1){
			if(now>=6){
				t-=4;
			}else{
				t-=8;
			}
			if(t<=0)break;
			now++;
			if(now>7)now=1;
		}

		printf("%s\n",str[now-1]);
	}
	return 0;
}
