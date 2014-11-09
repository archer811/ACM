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
int a,b,n;
#define ll __int64
const ll mod = 1000000007;
int judge(int x)
{
    while(x)
    {
        int tmp = x%10;
        if(tmp!=a&&tmp!=b)return 0;
        x/=10;
    }
    return 1;
}
ll o[1000006];
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;y=0;
        return a;
    }
    ll tmp = exgcd(b,a%b,x,y);
    ll g = x;
    x = y;
    y = g-(a/b)*y;
    return tmp;
}
int main()
{
    int i,j;
    o[0]=1;
    for(i=1;i<=1000000;i++)
        o[i]=o[i-1]*i%mod;
    while(scanf("%d%d%d",&a,&b,&n)!=EOF)
    {
        ll ans=0;
        for(i=0;i<=n;i++)
        {
            if(judge(i*a+(n-i)*b))
            {
                cout<<i<<endl;
                ll x=-1,y=-1;
                ll tmp = exgcd(o[i]*o[n-i]%mod,mod,x,y);
                cout<<x<<" "<<y<<endl;
                ll bb = o[n];
                ll x0 = x*(bb/tmp)%mod;
                cout<<x0<<endl;
                while(x0<0)
                {
                    x0+=bb/tmp;
                }
                ans += x0;
                ans %= mod;
            }
        }
        cout<<ans<<endl;
    }
}
