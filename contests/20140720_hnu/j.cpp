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
typedef long long LL;
LL x,y,d;
LL n1,f1,d1,n2,f2,d2;
LL gcd(LL a,LL b)
{
    if (!b) return a;
    return gcd(b,a%b);
}
void exgcd(LL a,LL b,LL &d,LL &x,LL &y)
{
    if (!b)
    {
        x=1 ;y=0 ;d=a ;
        return ;
    }
    else
    {
        exgcd(b,a%b,d,x,y);
        LL temp=x;
        x=y;
        y=temp-(a/b)*y;
    }
}
void f(LL a,LL b,LL m)
{
    exgcd(a,m,d,x,y);
    //if (b%d) return -1;
    x=x*(b/d)%m;
    LL count=0;
    for (LL i=1 ;i<=d ;i++)
    {
        LL xx=(x+(i-1)*m/d)%m;
        LL yy=(y-(i-1)*a/d)%a;
        //if (xx>0 && xx<=n1 && yy>0 &&yy<=n2)
            count ++ ;
    }
    printf("%I64d\n",count);
}
int main()
{
    LL t;
    //LL n1,f1,d1,n2,f2,d2;
    scanf("%I64d",&t);
    while (t--)
    {
        scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&n1,&f1,&d1,&n2,&f2,&d2);
        LL a=d1 ;
        LL m=-d2;
        LL b=d1-d2+f2-f1;
        f(a,b,m);
    }
    return 0;
}
