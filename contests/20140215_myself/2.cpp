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
ll gcd(ll a,ll b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    int i,j;
    ll a,b;
    int cas=0;
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%lld%lld",&a,&b);
        ll c = gcd(a,b);
       // cout<<a+b<<" "<<c<<endl;
        printf("Case %d: %lld\n",++cas,(a+b)/gcd(a,b));
    }
}
