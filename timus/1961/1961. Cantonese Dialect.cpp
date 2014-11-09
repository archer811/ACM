#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
#define ll __int64
int main()
{
    int i,j,k;
    ll n,m,N,M;
    while(scanf("%I64d%I64d%I64d",&n,&m,&N)!=EOF)
    {
        double tmp = m*N*1.0/n;
        ll a = tmp;
        //printf("%.5f %I64d\n",tmp,a);
        if(tmp-a>0.0)
        {
            a++;
        }
        printf("%I64d\n",min(N,a));
    }
}
