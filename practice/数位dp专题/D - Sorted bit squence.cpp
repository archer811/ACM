#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define ll long long
ll n,m;
ll oo = ((ll)1)<<31;
int k;
ll f[33][33];
void init()
{
    f[0][0]=1;
    for(int i=1; i<=32; i++)
    {
        f[i][0]=f[i-1][0];
        for(int j=1; j<=i; j++)
            f[i][j]=f[i-1][j-1]+f[i-1][j];
    }
}
int calc(ll x,int k)
{
    if(x<0)return 0;
    int tot =0,ans=0;
    for(int i=31; i>0; i--)
    {
        ll tmp  = ((ll)1)<<i;
        if(x&(tmp))
        {
            ++tot;
            if(tot>k)break;
            x=x^tmp;
        }
        if((1<<(i-1))<=x)
            ans += f[i-1][k-tot];
    }
    if(tot+x==k)++ans;
    return ans;
}
int main()
{
    int i,j,T;
    scanf("%d",&T);
    init();
    while(T--)
    {
        scanf("%lld%lld%d",&n,&m,&k);
        int f=0;
        if(m==0)
        {
            if(k==1)
            {
                puts("0");
                continue;
            }
            m--;
            k--;
        }
        if(n<0)
        {
            n = oo+n;
            m = oo+m;
            f = 1;
        }
        ll sum =0,ant=0;
        for(i=0; i<=32; i++)
        {
            ant = sum;
            sum += calc(m,i)-calc(n-1,i);
            if(sum>=k)break;
        }
        ll ans;

        k = k-ant;
        ll low = n;
        ll high = m;    //cout<<n<<"fds"<<m<<" "<<k<<endl;

        while(low < high)
        {

            ll mid = low + (high-low)/2;

            if(calc(mid,i)-calc(n-1,i) >= k) high = mid;

            else   low = mid + 1;

        }
        ans = low;
        //cout<<ans<<endl;
        if(f)ans = -oo+ans;
        cout<<ans<<endl;
    }
}
