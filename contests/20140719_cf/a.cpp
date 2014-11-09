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
#define ll __int64
int main()
{
    ll i,j;
    ll n,m,k;
    while(cin>>n>>m>>k)
    {
        if(n+m-2<k)
        {
            puts("-1");continue;
        }
        if(n>m)swap(n,m);
        ll ans=-1;
        if(k<=n-1)
        {
            ans = max(ans,(n)/(k+1)*m);
        }
        else ans = max(ans,m/(k-(n-1)+1));
        if(k<=m-1)
            ans = max(ans,(m)/(k+1)*n);
        else
            ans = max(ans,n/(k-(m-1)+1));

        cout<<ans<<endl;
    }
    return 0;
}
