#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
#define ll __int64
int main()
{
    ll i,j;

    ll n;
    while(cin>>n)
    {
        ll sum=0;
        ll pre=1;
        if(n==0)
        {
            cout<<1<<endl;
            continue;
        }
        for(i=n;i>=1;i--)
        {
            ll tmp = sqrt((n*n)-(i*i));
            if(i==n)sum+=(ll)1;
            else if(tmp-pre==0)sum += 2;
            else
            sum += (ll)(tmp-pre)*2;
            pre=tmp;
           // cout<<sum<<endl;
        }
        cout<<sum*2+2<<endl;

    }
}
