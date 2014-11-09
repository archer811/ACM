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
int main()
{
    ll i,j;
    ll n,a,b;
    while(cin>>n>>a>>b)
    {
        ll g = 6*n;
        int flag=0;
        if(a>b)swap(a,b),flag=1;
        ll ans=-1;
        ll x,y;
        if(a*b>=g)
        {
            cout<<a*b<<" "<<a<<" "<<b<<endl;
            continue;
        }
//        ll f = i+100000;
        ll g2 = sqrt(g);
//        f = max(f,g2);
        for(i=a; i<=g2; i++)
        {
            ll f2 = g/i;
            if(i>0&&g%i)
            {
                f2++;
            }
            if(f2<b)f2=b;
            if(ans==-1||f2*i<ans)
            {
                ans=f2*i;
                x=i;
                y=f2;
            }
        }
        /*
        for(i=b; i<=g2; i++)
        {
            ll f2 = g/i;
            if(i>0&&g%i)
            {
                f2++;
            }
            if(f2<a)f2=a;
            if(ans==-1||f2*i<ans)
            {
                ans=f2*i;
                x=i;
                y=f2;
            }
        }*/
        for(i=a; i<=a+1000; i++)
        {
            for(j=b; j<=b+1000; j++)
            {
                if(i*j>=g)
                {
                    if(ans==-1||i*j<ans)
                    {
                        ans=i*j;
                        x=i;
                        y=j;
                    }
                }
            }
        }
        if(flag)swap(a,b);
        if(x>=a&&y>=b);
        else swap(x,y);
        cout<<ans<<" "<<x<<"  "<<y<<endl;
    }
    return 0;
}
