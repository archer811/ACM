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
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        ll n,m;
        scanf("%lld%lld",&n,&m);
        if(m>=n)
        {
            puts("-1");continue;
        }
        if(n-m==1)
        {
            puts("0");continue;
        }
        ll g = n-m;
        ll ans=-1;
        for(ll x=0;x<=sqrt(g);x++)
        {
            ll tmp = x+g;
            if(tmp%(2*x+1)==0)
            {
                ll y = tmp/(2*x+1);
                if(m-x-y>=0&&y>=0&&y<=m&&x<=m)
                {
                    if(ans==-1||m-x-y<ans)
                    ans=m-x-y;
                }

            }
        }
        if(ans<=-1)ans=-1;
        printf("%lld\n",ans);
    }
    return 0;
}
