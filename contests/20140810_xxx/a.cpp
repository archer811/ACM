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
ll mod;
ll fun(ll a,int n)
{
    ll y=1;
    while(n)
    {
        if(n&1)y=y*a%mod;
        a=a*a%mod;

        //if(n&1)y=y*a;
        //a=a*a;
        n/=2;
    }
    return y;
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&mod);
        int a,b;
        int cas=0;
        while(scanf("%d%d",&a,&b)!=EOF)
        {
            if(a==0&&b==0)break;
            if(a==1)
            {
                printf("Case %d: %lld\n",++cas,(ll)2*b%mod);
            }
            else if(b==1)
            {
                printf("Case %d: %lld\n",++cas,2%mod);
            }
            else
            {
                if(b==2)
                {
                    printf("Case %d: %lld\n",++cas,4%mod);
                }
                else
                {
                    ll x  = fun(2,a-1);
                    ll y = fun(x,b-2);
                    printf("Case %d: %lld\n",++cas,4*y%mod);
                    //cout<<4*y<<endl;
                }

                //
                //2*(2^(m-1))^(n-1)
            }
        }
    }
    return 0;
}
