#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;
#ifdef __int64
typedef __int64 ll;
#else
typedef long long ll;
#endif
/*
const int maxn = 400005;
int head[maxn],tot;
struct Edge
{
    int to,next;
}edge[maxn];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}*/
const int maxn = 1000006;
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
const ll mod = 1000000007;
ll euler(ll x) // 就是公式
{
    ll i, res=x;
    ll max= (ll)sqrt(x * 1.0) + 1;
    for (i = 2; i <max; i++)
        if(x%i==0)
        {
            res = res / i * (i - 1);
            while (x % i == 0) x /= i; // 保证i一定是素数
        }
    if (x > 1) res = res / x * (x - 1);
    return res;
}

ll f(ll n,ll k)
{
    if(k==n)return 1;
    return euler(n/k);
}
int main()
{
    ll i,j;
    ll k,n;
    while(scanf("%I64d%I64d",&n,&k)!=EOF)
    {
        if(n==1)
        {
            puts("1");
        }
        else if(k>2)puts("0");
        else if(k==2)
            puts("1");
        else
        {
            ll ans=0;
            for(i=1; i<=sqrt(n); i++)
            {
                if(n%i==0)
                {
                    ll x = i;
                    ll y = n/i;
                    ll tmp = f(n,i)*f(n,y)%mod;
                   // cout<<x<<"  "<<y<<"  "<<f(n,i)<<"  "<<f(n,y)<<endl;
                    if(x==y)ans += tmp;
                    else ans += tmp*2%mod;
                    ans %= mod;
                }
            }
            printf("%I64d\n",ans);
        }
    }
    return 0;
}
