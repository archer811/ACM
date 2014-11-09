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
const int maxm = 400005;
int head[maxn],tot;
struct Edge
{
    int to,next;
}edge[maxm];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}*/
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#define ll __int64
const ll mod = 1000000007;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    ll d=exgcd(b,a%b,x,y);
    ll t=x;
    x=y;
    y=t-a/b*y;
    return d;
}
ll div_mod(ll a,ll b,ll c)
{
    ll x,y;
    exgcd(b,c,x,y);
    return ((a%c)*(x%c))%c;
}
int main()
{
    ll i,j,a,b;
    while(scanf("%I64d%I64d",&a,&b)!=EOF)
    {
        ll sum=0;
        for(i=1; i<b; i++)
        {
            ll st = i*b%mod+i;
            ll ed = a*i%mod*b%mod+i;
            ll ct = a;
            ll g1 = a;
            ll g2 = a+1;
            if((g1&1)==0)g1/=2;
            else g2/=2;
            g1  = g1*g2%mod;
            //cout<<g1<<endl;
            ll y = i;
            ll tmp = a*y%mod+y*b%mod*g1%mod;
            sum += tmp;
            sum %= mod;
        }
        cout<<sum<<endl;
    }
    return 0;
}
