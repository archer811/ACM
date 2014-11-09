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
ll k,n;
ll g[3];
int f(ll d1, ll d2)
{
    if((k - 2 * d2 - d1) % 3)return 0;
    ll z = (k - 2 * d2 - d1) / 3;
    ll y = d2 + z;
    ll x = d1 + y;
    if(x<0 || y<0 || z<0 ) return 0;
    g[0]=x;g[1]=y;g[2]=z;
    sort(g,g+3);
    x=g[0];y=g[1];z=g[2];
    ll s = z-x+z-y;
    //cout<<x<<" "<<y<<" "<<z<<"  "<<n-k<<endl;
    if(s<=n-k&&(n-k-s)%3==0)return 1;
    return 0;
}
int main()
{
    int i,j;

    int t;
    cin>>t;
    while(t--)
    {
        ll d1,d2;
        cin>>n>>k>>d1>>d2;
        int flag=0;
        flag |= f(d1, d2);
        flag |= f(-d1, d2);
        flag |= f(d1, -d2);
        flag |= f(-d1, -d2);
        if(flag)puts("yes");
        else puts("no");
    }
    return 0;
}
