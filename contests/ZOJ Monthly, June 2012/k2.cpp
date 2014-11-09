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
int a[100],num;
#define ll long long
ll prime[100];

char s[1000];
ll f(char c)
{
    if(c>='0'&&c<='9')return c-'0';
    else if(c>='A'&&c<='Z')return 10+c-'A';
    else return 36+c-'a';
}
ll cnt(ll n,ll y)
{
    ll cn=0;
    ll tmp = y;
    while(n>=tmp)
    {
        //cout<<n<<" "<<tmp<<endl;
        cn += n/tmp;
        tmp *= (ll)y;
    }
    return cn;
}
ll nb[100],nk[100];
ll mul(ll a,ll n)
{
    ll b=a;
    while(n)
    {
        if(n&1)b=b*a;
        a=a*a;
        n/=2;
    }
    return b;
}
int main()
{
    int i,j;
    num=0;
    for(i=2;i<100;i++)
    {
        if(a[i]==0)
        {
            prime[num++]=i;
            for(j=i+i;j<100;j+=i)
                a[j]=1;
        }
    }
//    for(i=0;i<num;i++)
//        cout<<prime[i]<<endl;
    ll x,k;
    while(scanf("%s%lld",s,&k)!=EOF)
    {
        x=0;
        int len = strlen(s);
        for(i=0;i<len;i++)
        {
            x = x*k+f(s[i]);
        }
        for(i=0;i<100;i++)
        {
            nb[i]=nk[i]=0;
        }
        //cout<<x<<endl;
        int flag=0;
        ll ans=1;
        ll kk=k;
        for(i=0;i<num&&prime[i]<=k;i++)
        {
            if(k%prime[i]==0)
            {
                //cout<<"***"<<endl;
                while(k%prime[i]==0)
                {
                    nk[i]++;k/=prime[i];
                }

                nb[i]=cnt(x,prime[i]);
                if(nk[i]==0)continue;
                cout<<prime[i]<<" "<<nb[i]<<" "<<nk[i]<<endl;
                ll g = nb[i]/nk[i];
                if(flag==0)
                {
                    ans=g;
                }
                else ans = min(ans,g);
                flag=1;

                //ans = ans*mul(prime[i],nb[i]-nk[i]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
