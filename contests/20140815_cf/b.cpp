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
ll a[200005];

int main()
{
    int i,j,n;
    while(cin>>n)
    {
        for(i=0;i<n;i++)
            scanf("%I64d",&a[i]);
        sort(a,a+n);
        ll l=0,r=0;
        for(i=0;i<n;i++)
        {
            if(a[i]==a[0])l++;
        }
        for(i=n-1;i>=0;i--)
        {
            if(a[i]==a[n-1])r++;
        }
        if(l==n)
        {
            ll ans=  (ll)n*(ll)(n-1)/2;
            cout<<0<<" "<<ans<<endl;
            continue;
        }
        cout<<a[n-1]-a[0]<<" "<<l*r<<endl;
    }
    return 0;
}
