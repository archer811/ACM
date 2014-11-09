#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
#define ll long long
int a[2000005]={0};
ll prime[2000006];
int num;
ll ans[1000005];
ll anum[1000005];
int sz;
void f(ll n)
{
    sz = 0;
    ll nn = n;
    for(int i=0;i<num;i++)
    {
        if(prime[i]*prime[i]>nn)break;
        if(n%prime[i]==0)
        {
            anum[sz]=1;
            while(n%prime[i]==0)
            {
                anum[sz]*=prime[i];
                n/=prime[i];
            }
            ans[sz++]=prime[i];
        }
    }
    if(n!=1&&n!=0)
    {
        ans[sz]=n;
        anum[sz++]=n;
    }
}
int main()
{
    int i,j;
    num=0;
    for(i=2;i<=1000000;i++)
    {
        if(a[i]==0)
        {
            for(j=i+i;j<=1000000;j+=i)
                a[j]=1;
            prime[num++]=i;
        }
    }
    ll k;
    int n;
    scanf("%d",&n);
    int cas=0;
    while(n--)
    {
        scanf("%lld",&k);
        f(k);
        if(k<=1||sz==1)
        {
            printf("Case %d: Impossible\n",++cas);
            continue;
        }
        ll x = -1,y = -1;
        ll dis = 0;

        for(i=0;i<sz;i++)
        {
            ll tmp = anum[i];
            ll tmp2 = k/ans[i];
            //cout<<tmp2<<" "<<tmp<<" "<<x<<" "<<y<<"  "<<dis<<endl;
            if(tmp2>tmp&&tmp2<k)
            {
                if(x==-1||dis<tmp2-tmp)
                {
                    dis=tmp2-tmp;
                    x=tmp2;y=tmp;
                }
                else if(tmp2-tmp==dis)
                {
                    if(tmp2>x)
                    {
                        x=tmp2;y=tmp;
                    }
                }
            }
        }
        printf("Case %d: %lld %lld\n",++cas,x,y);
    }
}
