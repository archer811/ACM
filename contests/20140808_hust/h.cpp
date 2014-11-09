#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
using namespace std;
#define ll  __int64
int main()
{
    ll i,j;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll aa,bb,a,b,A,B;
    while(scanf("%I64d%I64d%I64d%I64d",&aa,&bb,&A,&B)!=EOF)
    {
        ll sum1=0,sum2=0;a=aa,b=bb;
        while(aa<A)
        {
            sum1++;aa*=2;
        }
        while(bb<B)
        {
            sum1++;bb*=2;
        }


        while(b<A)
        {
            sum2++;b*=2;
        }
        while(a<B)
        {
            sum2++;a*=2;
        }
        printf("%I64d\n",min(sum1,sum2));
    }
    return 0;
}
