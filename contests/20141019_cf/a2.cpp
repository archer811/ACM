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
ll c[maxn];
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,ll v)
{
    while(x<maxn)
    {
        c[x]+=v;
        x+=lowbit(x);
    }
}
ll sum(int x)
{
    ll su=0;
    while(x>0)
    {
        su+=c[x];
        x-=lowbit(x);
    }
    return su;
}
int n;
ll a[maxn];
int judge(ll x)
{
    for(int i=1;i<=n;i++)
    {
        int l=i,r=n;
        int flag=0;
        ll s=sum(i-1);
        while(l<=r)
        {
            int mid = (l+r)>>1;
            ll tmp = sum(mid)-s;
            if(tmp>x)r=mid-1;
            else if(tmp<x)l=mid+1;
            else if(tmp==x)return 1;
        }
    }
    return 0;
}
int main()
{
    int i,j;
    ll l,x,y;
    while(cin>>n>>l>>x>>y)
    {
        memset(c,0,sizeof(c));
        for(i=1; i<=n; i++)
            scanf("%I64d",&a[i]);
        for(i=1; i<n; i++)
            add(i,a[i+1]-a[i]);
        n--;
        int flag=0;
        int e=-1,f=-1;
       // cout<<x<<"*"<<y<<endl;
        if(!judge(x)&&!judge(l-x)){flag++;e=x;}
        if(!judge(y)&&!judge(l-y))
        {
            flag++;
            if(e==-1)e=y;
            else f=y;
        }
        cout<<flag<<endl;
        if(flag==1)cout<<e<<endl;
        else if(flag==2)cout<<e<<" "<<f<<endl;
    }
    return 0;
}

