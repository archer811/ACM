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
const ll mod = 1000000007;
ll quickpow(ll m,ll n,ll k)
{
    ll b = 1;
    while (n > 0)
    {
          if (n %2 )
             b = (b*m)%k;
          n = n /2 ;
          m = (m*m)%k;
    }
    return b;
}
const int maxn = 100005;
ll a[maxn],b[maxn];
int main()
{
    int i,j,k;
    ll n,x;
    while(cin>>n>>x)
    {
        ll sum=0;
        for(i=1;i<=n;i++)
            cin>>a[i],sum += a[i];
        for(i=1;i<=n;i++)
        {
            b[i]=sum-a[i];
            //cout<<i<<" "<<b[i]<<endl;
        }
        sort(b+1,b+1+n);
        ll temp = b[0],tmp=b[0];
        ll f=0;
        for(i=1;i<=n;i++)
        {
            b[i]=b[i]-tmp;
            if(b[i]==0)f++;
        }
        tmp=(ll)f;
        ll num=0;
        while(tmp%x==0)
        {
            tmp/=x;
            num++;
        }
        for(i=1;i<=n;i++)
        {
            if(b[i]<num&&b[i]!=0)num=b[i];
        }
        //cout<<f<<" * "<<num<<endl;
        num += temp;//cout<<num<<endl;
        cout<<quickpow(x,num,mod)<<endl;
    }
}
