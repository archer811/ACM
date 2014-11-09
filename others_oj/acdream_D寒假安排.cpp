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
const int maxn = 100004;
ll prime[maxn],ans[maxn];
int a[maxn],num,num2;
ll haha[maxn];
void init()
{
    int i,j;
    num=0;
    memset(a,0,sizeof(a));
    for(i=2; i<maxn; i++)
    {
        if(a[i]==0)
        {
            prime[num++]=i;
            for(j=i+i; j<maxn; j+=i)
                a[j]=1;
        }
    }
}
const ll inf = ((ll)1)<<32;
ll cnt(ll n,ll y)
{
    ll cn=0;
    if(n<=0)return 0;
    ll tmp=y;
    while(n>=tmp)
    {
        cn+=n/tmp;
        tmp*=y;
    }
    return cn;
}
int main()
{
    int i,j,t;
    init();
    scanf("%d",&t);
    ll n,m,k;
    while(t--)
    {
        scanf("%lld%lld%lld",&n,&m,&k);
        num2=0;
        for(i=0; i<num&&k>=prime[i]; i++)
        {
            if(k%prime[i]==0)
            {
                haha[num2]=0;
                ans[num2]=prime[i];
                while(k%prime[i]==0)
                {
                    k/=prime[i];
                    haha[num2]++;
                }
                num2++;
            }
        }
        if(k>1)
            ans[num2]=k,haha[num2++]=1;
        ll M=inf;
        m=n-m;
        //cout<<n<<"@@"<<m<<endl;

        for(i=0; i<num2; i++)
        {
            ll tmp1 = cnt(m,ans[i]);
            ll tmp2 = cnt(n,ans[i]);

            //cout<<i<<" "<<ans[i]<<" "<<tmp1<<" "<<tmp2<<endl;
            M=min(M,(tmp2-tmp1)/haha[i]);
        }
        printf("%lld\n",M);
    }
    return 0;
}
