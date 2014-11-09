#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define ll __int64
const ll inf = 999999999;
bool tp[1000001];
long long prime[1000001],s[1000001],u[1000001];
long long pn,t;
long long ans,now;
void init()
{
    long long i,j;
    pn=0;
    memset(tp,0,sizeof(tp));
    for(i=2; i<=1000000; i++)
    {
        if(!tp[i])
        {
            pn++;
            prime[pn]=i;
            u[i]=-1;
        }
        for(j=1; j<=pn; j++)
        {
            if(i*prime[j]>1000000)break;
            tp[prime[j]*i]=true;
            if(i%prime[j]==0)
            {
                u[i*prime[j]]=0;
                break;
            }
            else
                u[i*prime[j]]=-u[i];
        }
    }
    u[1]=1;
    s[0]=0;
    for(i=1; i<=1000000; i++)
        s[i]=s[i-1]+u[i];
}
ll _min(ll a,ll b)
{
    if(a<b)return a;
    return b;
}
int main()
{
    ll i,j;
    int T;
    init();
    ll a,b,c,d,k;
    scanf("%d",&T);
    int cas=0;
    while(T--)
    {
        scanf("%I64d%I64d%I64d%I64d%I64d",&a,&b,&c,&d,&k);
        if(k==0)
        {
            printf("Case %d: 0\n",++cas);
            continue;
        }
        b/=k;
        d/=k;
        ans =0;
        i = 1;
        ll x = b,y = d,N = _min(x,y);
        while(i<=x||i<=y)
        {
            now = inf;
            if(i<=x)now = _min(now,x/(x/i));
            if(i<=y)now = _min(now,y/(y/i));
            //cout<<now<<endl;
            ans = ans + (x/now)*(y/now)*(s[now]-s[i-1]);
            i=now+1;
        }
        i=1;
        ll sum=0;
        while(i<=N)
        {
            now = N/(N/i);
            sum = sum + (N/now)*(N/now)*(s[now]-s[i-1]);
            i=now+1;
        }
        printf("Case %d: %I64d\n",++cas,ans-(sum-1)/2);
    }
}
