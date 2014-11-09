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
#define ll __int64
const int maxn = 200005;
set<ll>s;
ll l;
ll x,y;
int judge(ll a)
{
    if(a>=0&&a<=l&&(s.find(a-y)!=s.end()||s.find(a+y)!=s.end()))return 1;
    return 0;
}
ll a[maxn];
int n;
int main()
{
    int i,j;

    while(cin>>n>>l>>x>>y)
    {
        s.clear();
        for(i=1; i<=n; i++)
            scanf("%I64d",&a[i]),s.insert(a[i]);
        int flag1=0,flag2=0;
        for(i=1;i<=n;i++)
        {
            if(s.find(a[i]-x)!=s.end()||s.find(a[i]+x)!=s.end())
            {
                flag1=1;
            }

            if(s.find(a[i]-y)!=s.end()||s.find(a[i]+y)!=s.end())
            {
                flag2=1;
            }
        }
        if(flag1&&flag2)
        {
            puts("0");continue;
        }
        if(flag1)
        {
            cout<<1<<" "<<y<<endl;continue;
        }
        if(flag2)
        {
            cout<<1<<" "<<x<<endl;continue;
        }
        int f=0;
        for(i=1;i<=n;i++)
        {
            if(judge(a[i]+x))
            {
                cout<<1<<" "<<a[i]+x<<endl;
                f=1;
                break;
            }
            if(judge(a[i]-x))
            {
                cout<<1<<" "<<a[i]-x<<endl;
                f=1;
                break;
            }
        }
        if(f==0)
        {
            cout<<2<<" "<<x<<" "<<y<<endl;
        }
    }
    return 0;
}

