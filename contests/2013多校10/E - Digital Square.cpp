#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;

#define ll long long
const ll mod = 1000000000;
map<ll,int>M;
int a[20];
void f(ll x,int ans)
{
    int i,j=0;
    while(x)
    {
       a[j++]=x%10;x/=10;
    }
    ll sum=0,y=1;
    for(i=0;i<j;i++)
    {
        sum = sum+a[i]*y;
        y = y*(ll)10;
        //cout<<sum<<" "<<ans<<endl;
        if(M[sum]==0)
            M[sum]=ans;
    }
}
int main()
{
    int i,j,t;
    //freopen("out.txt","w",stdout);
    M.clear();
    for(i=1;i<=100000;i++)
    {
        ll tmp = (ll)i*(ll)i;
        f(tmp,i);
    }
    scanf("%d",&t);
    while(t--)
    {
        ll n;
        scanf("%lld",&n);
        if(n==0)
        {
            cout<<0<<endl;continue;
        }
        else if(M[n]==0)
        {
            cout<<"None"<<endl;continue;
        }
        printf("%d\n",M[n]);
    }
    return 0;
}
