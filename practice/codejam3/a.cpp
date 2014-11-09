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
ll gcd(ll a,ll b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
ll Max;
ll g[1000];
int main()
{
    int i,j;
    Max=1;
    for(i=1;i<=12;i++)
        Max=Max*(ll)10;
    g[0]=1;
    for(i=1;i<=40;i++)
    {
        g[i]=g[i-1]*(ll)2;
        //cout<<i<<" "<<g[i]<<endl;
    }
//    freopen("A-large.in","r",stdin);
//    freopen("out.txt","w",stdout);
    int cas=0,t;
    scanf("%d",&t);
    ll a,b;
    while(t--)
    {
        scanf("%lld/%lld",&a,&b);
        printf("Case #%d: ",++cas);
        ll x = gcd(a,b);
        a/=x;b/=x;
        int flag=0;
        if(g[40]%b)
        {
            puts("impossible");continue;
        }
        for(i=0;i<40;i++)
        {
            if(g[i]*a-b>=0)
            {
                ll t1 = g[i]*a-b;
                ll t2 = g[i]*b;
//                ll y = gcd(t1,t2);
//                //cout<<t1<<" "<<t2<<endl;
//                if(t1!=0&&t2%t1)
//                    flag=1;
//                else if(t1==0||t2%t1==0)
                {
                    cout<<i<<endl;
                }break;
            }
        }
    }
    return 0;
}
