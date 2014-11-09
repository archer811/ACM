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
const ll mod = 1000000007;
ll defun(ll n)
{
    ll res=1;
    for(ll i=2,t; i*i<=n; i+=2)
    {
        if(!(n%i))
        {
            for(t=i*i,n/=i; !(n%i); t*=i,n/=i);
                res*=(t-1)/(i-1);
        }
        if(i==2)
        {
            i--;
        }
    }
    if(n>1)
    {
        res *= (n+1);
    }
    return res;
}
ll ans[5000005];
int main()
{
    int i,j;
    ll M=-1;
    freopen("out.txt","w",stdout);
    int sum=0;
    for(i=1;i<=5000000;i++)
    {
        ans[i]=defun(i)-i;
    }
    for(i=1;i<=5000000;i++)
    {
        ll tmp = ans[i];
        if(tmp==i)continue;
        if(tmp>=1&&tmp<=5000000)
        {
            if(ans[tmp]==i)
            {

                cout<<"g["<<sum<<"].x="<<i<<";";
                cout<<"g["<<sum<<"].y="<<ans[i]<<";";
                cout<<endl;
                sum++;
            }
        }
    }
    cout<<"**"<<endl;
    /*
    cout<<M<<endl;

    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        int sum=0;
        for(i=a;i<=b;i++)
        {
            ll tmp = ans[i];
            if(tmp>=a&&tmp<=b)sum++;
        }
        printf("%d\n",sum);
    }*/
    return 0;
}
