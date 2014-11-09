#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 10000000;
#define ll long long
const ll inf = 999999999;
ll sum[maxn];
int cn1[maxn],cn2[maxn];
bool tprime[maxn];
ll prime[maxn];
int pn,n;
ll x,y;
void init()
{
    int i,j;
    memset(tprime,0,sizeof(tprime));
    pn = 0;
    for(i=2;i<=maxn;i++)
    {
        if(!tprime[i])
        {
            pn++;
            prime[pn]=i;
            cn1[i]=1;cn2[i]=0;
        }
        for(j=1;j<=pn;j++)
        {
            if(i*prime[j]>maxn)break;
            tprime[prime[j]*i]=true;
            if(i%prime[j]==0)
            {
                if(i/prime[j]%prime[j]==0)
                {
                    cn2[i*prime[j]]=2;
                    cn1[i*prime[j]]=cn1[i];
                }
                else
                {
                    cn1[i*prime[j]]=cn1[i];
                    cn2[i*prime[j]]=cn2[i]+1;
                }
                break;
            }
            cn1[i*prime[j]]=cn1[i]+1;
            cn2[i*prime[j]]=cn2[i];
        }
    }
    prime[1]=0;
    for(i=2;i<=maxn;i++)
    {
        if(cn2[i]==1)
        {
            prime[i]=-((cn1[i]&1)<<1)+1;
        }
        else if(cn2[i]==0)
        {
            prime[i]=cn1[i]*(((cn1[i]&1)<<1)-1);
        }
        else prime[i]=0;
    }
    for(i=1;i<=maxn;i++)
        sum[i]=sum[i-1]+prime[i];
}
ll _min(ll a,ll b)
{
    if(a<b)return a;
    return b;
}
int main()
{
    ll i,j,k;
    ll ans,now;
    init();
    cin>>n;
    while(n--)
    {
        cin>>x>>y;
        ans =0;
        i = 1;
        while(i<=x||i<=y)
        {
            now = inf;
            if(i<=x)now = _min(now,x/(x/i));
            if(i<=y)now = _min(now,y/(y/i));
            //cout<<now<<endl;
            ans = ans + (x/now)*(y/now)*(sum[now]-sum[i-1]);
            i=now+1;
        }
        cout<<ans<<endl;
    }
}

