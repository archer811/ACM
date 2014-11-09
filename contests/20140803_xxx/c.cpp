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
struct o
{
    ll x,v;
}g[1000005];
ll cmp(o a,o b)
{
    if(a.x==b.x)return a.v<b.v;
    return a.x<b.x;
}
ll num;
ll a[1000006],b[1000005];
void msort(ll s,ll t)
{
    ll mid = (t+s)/2;
    ll qb=1,bn=t-s+1;
    ll i,j;
    if(s>=t)return;
    msort(s,mid);
    msort(mid+1,t);
    for(i=s,j=mid+1;i<=mid&&j<=t;)
    {
        if(a[i]<=a[j])
        {
            b[qb]=a[i];
            i++;
        }
        else
        {
            b[qb]=a[j];
            num+=(ll)(mid-i+1);
            j++;
        }qb++;
    }
    while(j<=t)
    {
        b[qb]=a[j];qb++;j++;
    }
    while(i<=mid)
    {
        b[qb]=a[i];
        qb++;
        i++;
    }
    for(i=1,j=s;i<qb;i++,j++)
    {
        a[j]=b[i];
    }
}
int main()
{
    ll i,j,n;
    while(scanf("%lld",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%lld%lld",&g[i].x,&g[i].v);
        }
        sort(g+1,g+1+n,cmp);
        for(i=1;i<=n;i++)
            a[i]=g[i].v;
//        for(i=1;i<=n;i++)
//            cout<<a[i]<<" ";
//        cout<<endl;
        num=0;
        msort(1,n);
        j=1;
        ll sum=0;
        //cout<<num<<endl;
        for(i=1;i<=n;i++)
        {
            if(i==1||(!(g[i].x==g[i-1].x)))
            {
                num += sum; sum=0;
            }
            else sum=1;
            //cout<<i<<" "<<sum<<endl;
        }
        num += sum;
        printf("%lld\n",num);
    }
    return 0;
}
