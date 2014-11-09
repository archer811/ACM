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
#ifdef __int64
typedef __int64 ll;
#else
typedef long long ll;
#endif
/*
const int maxn = 400005;
int head[maxn],tot;
struct Edge
{
    int to,next;
}edge[maxn];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}*/
const int maxn = 1000006;
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
vector<ll>o;
ll f(ll x)
{
    ll su=0;
    while(x)
    {
        su+=x%10;
        x/=10;
    }
    return su;
}
int main()
{
    ll i,j;
    ll x,y;
    ll a,b,c;
    while(cin>>a>>b>>c)
    {
        o.clear();
        for(i=0;i<=100;i++)
        {
            ll x = 1;
            ll y = i;
            for(j=1;j<=a;j++)
                x = x*y;
            ll ans = x*b+c;
            if(f(ans)==i)
            {
                //cout<<i<<" "<<x<<" "<<ans<<"  "<<f(ans)<<endl;
                if(ans>0&&ans<1000000000)
                    o.push_back(ans);
            }

        }
        sort(o.begin(),o.end());
        cout<<o.size()<<endl;
        for(int i=0;i<o.size();i++)
            cout<<o[i]<<endl;
    }
    return 0;
}
