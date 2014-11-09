#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int n,l,r,ql,qr;
const int maxn = 100005;
#define ll long long
const ll inf  = 9999999990;
ll _left[maxn],_right[maxn],w[maxn];
ll min(ll a,ll b)
{
    if(a>b)return b;
    return a;
}
int main()
{
    int i,j,k;
    while(scanf("%d%d%d%d%d",&n,&l,&r,&ql,&qr)!=EOF)
    {
        for(i=1;i<=n;i++)
            cin>>w[i];
        _left[1]=w[1]*l;
        _right[n]=w[n]*r;
        for(i=2;i<=n;i++)
            _left[i]=_left[i-1]+w[i]*l+ql;
        for(i=n-1;i>=1;i--)
            _right[i]=_right[i+1]+w[i]*r+qr;
        ll ans = inf;
        for(i=1;i<n;i++)
        {
            ans = min(ans,_left[i]+_right[i+1]);
        }
        if(n==1)ans = min(_left[1],_right[1]);
        else if(n==2)ans=_left[1]+_right[1];
        cout<<ans<<endl;
    }
}
