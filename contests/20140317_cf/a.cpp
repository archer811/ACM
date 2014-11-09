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
ll f(ll a,ll b)
{
    ll sum=0;
    ll tmp = a/b;
    sum += tmp;
    a = a-b*tmp;
    ll getans = sqrt(b*b-4*a);
    ll ans1 = (b+getans)/2;
    ll ans2 = (b-getans)/2;
}
int main()
{
    int i,j;
    ll a,b;
    while(cin>>a>>b)
    {
        cout<<f(a,b)<<endl;
    }
}
