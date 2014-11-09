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
#pragma comment(linker, "/STACK:1024000000,1024000000")
//int g[5005][5005];
#define ll __int64
const ll mod = 100000007;
set<pair<int,int> >s;
ll getans(ll a,ll b)
{
    ll x = (ll)a;
    ll y = (ll)1;
    //cout<<a<<" "<<b<<endl;
    while(b)
    {
        if(b&1)y=x*y%mod;
        x=x*x%mod;
        b>>=1;
        //cout<<x<<" "<<y<<endl;
    }

    return y;
}
int main()
{
    int i,j,n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        ll l = n/2;
        if(n&1)l++;
        s.clear();
        for(i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x++;y++;
            if(x<=l&&y<=l)
            {
                if(y>=x)
                s.insert(make_pair(x,y));
            }
            int x2 = n+1-x,y2=y;

            if(x2<=l&&y2<=l)
            {
                if(y2>=x2)
                s.insert(make_pair(x2,y2));
            }

            x2=x;y2 = n+1-y;
            if(x2<=l&&y2<=l)
            {
                if(y2>=x2)
                s.insert(make_pair(x2,y2));
            }

            x2 = n+1-x;y2 = n+1-y;
            if(x2<=l&&y2<=l)
            {
                if(y2>=x2)
                s.insert(make_pair(x2,y2));
            }




            swap(x,y);
            if(x<=l&&y<=l)
            {
                if(y>=x)
                s.insert(make_pair(x,y));
            }
            x2 = n+1-x;y2=y;

            if(x2<=l&&y2<=l)
            {
                if(y2>=x2)
                s.insert(make_pair(x2,y2));
            }

            x2=x;y2 = n+1-y;
            if(x2<=l&&y2<=l)
            {
                if(y2>=x2)
                s.insert(make_pair(x2,y2));
            }

            x2 = n+1-x;y2 = n+1-y;
            if(x2<=l&&y2<=l)
            {
                if(y2>=x2)
                s.insert(make_pair(x2,y2));
            }
        }
        ll sum=(ll)(l+1)*(ll)l/2;
        //cout<<sum<< "   "<<s.size()<<endl;
        sum = sum-s.size();

        //cout<<sum<<endl;
        printf("%I64d\n",getans((ll)k,sum));
    }
    return 0;
}
