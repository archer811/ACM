#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 50010;
int n,m;
#define ll long long
int a[maxn];
int b[maxn];
struct array
{
    int l,r,no;
    friend bool operator <(array x,array y)
    {
        return (int)(x.l/sqrt(n))<(int)(y.l/sqrt(n))||
        ((int)(x.l/sqrt(n))==(int)(y.l/sqrt(n))&&x.r<y.r);
    }
}p1[maxn],p2[maxn];
ll ant[maxn];
ll gcd(ll a,ll b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    int i,j,k;
    scanf("%d%d",&n,&m);
    {
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&p1[i].l,&p1[i].r);
            p1[i].no = i;
        }
        memcpy(p2,p1,sizeof(p1));
        sort(p2+1,p2+1+m);
        p2[0].l=1;p2[0].r=0;
        ll ans =0;
        for(i=1;i<=m;i++)
        {
            if(p2[i-1].l<p2[i].l)
            {
                for(j=p2[i-1].l;j<=p2[i].l-1;j++)
                {
                    ans -= (ll)b[a[j]]*(ll)b[a[j]];
                    b[a[j]]--;
                    ans += (ll)b[a[j]]*(ll)b[a[j]];
                }
            }
            if(p2[i-1].l>p2[i].l)
            {
                for(j=p2[i].l;j<=p2[i-1].l-1;j++)
                {
                    ans -= (ll)b[a[j]]*(ll)b[a[j]];
                    b[a[j]]++;
                    ans += (ll)b[a[j]]*(ll)b[a[j]];
                }
            }
            if(p2[i-1].r<p2[i].r)
            {
                for(j=p2[i-1].r+1;j<=p2[i].r;j++)
                {
                    ans -= (ll)b[a[j]]*(ll)b[a[j]];
                    b[a[j]]++;
                    ans += (ll)b[a[j]]*(ll)b[a[j]];
                }
            }
            if(p2[i-1].r>p2[i].r)
            {
                for(j=p2[i].r+1;j<=p2[i-1].r;j++)
                {
                    ans -= (ll)b[a[j]]*(ll)b[a[j]];
                    b[a[j]]--;
                    ans += (ll)b[a[j]]*(ll)b[a[j]];
                }
            }
            ant[p2[i].no]=ans;
        }
        for(i=1;i<=m;i++)
        {
            ll _a,_b;
            ll len = p1[i].r-p1[i].l+1;
            ll tmp = ant[i]-len;
            if(tmp==0)
            {
                puts("0/1");continue;
            }
            ll kk  = gcd(tmp,len*(len-1));
            printf("%lld/%lld\n",tmp/kk,len*(len-1)/kk);
        }
    }
}
