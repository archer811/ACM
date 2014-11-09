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
#define ll long long
ll exgcd(ll a,ll b,ll & x,ll & y)
{
    if(b==0)
    {
        x=1;y=0;
        return a;
    }
    ll tmp = exgcd(b,a%b,x,y);
    ll tmp2 = x;
    x = y;
    y = tmp2-a/b*y;
    return tmp;
}
int main()
{
    int i,j;
    ll a,b,c;
    ll k;
    while(scanf("%lld%lld%lld%lld",&a,&b,&c,&k)!=EOF)
    {
        if(a==0&&b==0&&c==0&&k==0)break;
        k = ((ll)1)<<k;
        b = (b-a+k)%k;
        ll x,y;
        ll ans = exgcd(c,k,x,y);
        if(b%ans)puts("FOREVER");
        else
        {
            //cout<<ans<<" "<<x<<" "<<y<<endl;
            x = (x*b/ans)%k;
            while(x>0)
                x-=k/ans;
            //cout<<b<<" "<<x<<endl;
            //x=((x+k)%k+k)%k;
            while(x<0)
                x+=k/ans;
            printf("%lld\n",x);
        }
    }
}
