#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
#define ll __int64
ll n,m;

ll ans[1005];
struct array
{
    ll d,x,y;
    ll p;
} s[1005];
const ll N = 700;
ll prime[N+10];
ll a[N+10]= {0};
ll cnt=0;
ll gcd(ll a,ll b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
void init()
{
    ll i,j;
    for(i=2; i<=700; i++)
    {
        if(a[i]==0)
        {
            prime[cnt++]=i;
            for(j=i+i; j<=700; j+=i)
                a[j]=1;
        }
    }
}
ll b[707];
ll num;
ll ant;
void rc(ll index,ll y,ll lim,ll k)
{

    lim = lim*b[index];
    if(lim>y)return;
    ll tmp = y/lim;
    if(k&1)
        ant += lim*(ll)(tmp*(tmp+1)/2);
    else
        ant -= lim*(ll)(tmp*(tmp+1)/2);
    for(ll i=index+1; i<num; i++)
        rc(i,y,lim,k+1);
}
ll cal(ll x,ll y)//1-x coprime with y
{
    ll i,j;
    num=0;
    ll sum = (ll)(x*(x+1))/2;
    for(i=0; i<cnt; i++)
    {
        if(y==1)break;
        if(y%prime[i]==0)
        {
            b[num++]=prime[i];
            while(y%prime[i]==0)
            {
                y/=prime[i];
            }
        }
    }
    if(y!=1)
        b[num++]=y;
    ant = 0;
    for(i=0; i<num; i++)
        rc(i,x,1,1);
    return sum-ant;
}
map<ll,ll>mp;
map<ll,ll>::iterator it;
int main()
{
    ll i,j,t;
    init();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d%I64d",&n,&m);
        mp.clear();
        ll d,x,y;
        ll p;
        for(i=0; i<m; i++)
        {
            scanf("%I64d",&s[i].d);
            if(s[i].d==1)
            {
                scanf("%I64d%I64d%I64d",&s[i].x,&s[i].y,&s[i].p);
                ans[i]=cal(s[i].y,s[i].p)-cal(s[i].x-1,s[i].p);

                for(it=mp.begin(); it!=mp.end(); it++)
                {
                    if((*it).first==(*it).second)continue;
                    if((*it).first<s[i].x||(*it).first>s[i].y)continue;
                    int tmp = gcd((*it).first,s[i].p);

                    if(tmp==1)
                    {
                        ans[i]-=(*it).first;
                    }

                    tmp = gcd((*it).second,s[i].p);
                    if(tmp==1)
                    {
                        ans[i]+=(*it).second;
                    }
                }
            }
            else
            {
                scanf("%I64d%I64d",&s[i].x,&s[i].y);
                mp[s[i].x]=s[i].y;
            }
        }
        for(i=0; i<m; i++)
        {
            if(s[i].d==1)printf("%I64d\n",ans[i]);
        }
    }
    return 0;
}
