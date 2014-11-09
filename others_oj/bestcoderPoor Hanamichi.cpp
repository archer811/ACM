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
int f(int x)
{
    int flag=0;
    int s1=0,s2=0;
    while(x)
    {
        if(flag&1)s2+=x%10;
        else s1+=x%10;
        x/=10;
        flag++;
    }
    int ans=0;
    if(flag&1)ans=s1-s2;
    else ans=s2-s1;
    cout<<flag<<" "<<s1<<" "<<s2<<endl;
    if(ans!=3)return 0;
    return 1;
}
int main()
{
    int i,j;
    ll l,r;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d%I64d",&l,&r);
        ll x = l/11;
        x = x*11+3;
        //cout<<x<<endl;
        while(x<l)
            x+=11;
        while(x<=r&&f(x))
        {
            x+=11;
        }
        if(x<=r&&f(x)==0)printf("%I64d\n",x);
        else puts("-1");
    }
    return 0;
}
