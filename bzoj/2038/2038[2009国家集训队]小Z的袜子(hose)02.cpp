#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cctype>
#include<ctime>
using namespace std;
#define MAXN (50000+10)
#define MAXM MAXN
int n,m,a[MAXN];
int b[MAXN]= {0};
long long Ti2=0;
struct commend
{
    int l,r,no;
    friend bool operator<(commend a,commend b)
    {
        return int(a.l/sqrt(n))<int(b.l/sqrt(n))||(int(a.l/sqrt(n))==int(b.l/sqrt(n)))&&a.r<b.r;
    }
} p1[MAXM],p2[MAXM];
long long ans[MAXN];
long long gcd(long long a,long long b)
{
    if (!b) return a;
    return gcd(b,a%b);
}
int main()
{
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(i=1; i<=m; i++)
        scanf("%d%d",&p1[i].l,&p1[i].r),p1[i].no=i;
    memcpy(p2,p1,sizeof(p1));
    sort(p2+1,p2+1+m);
    p2[0].l=1,p2[0].r=0;
    for(i=1; i<=m; i++)
    {
        if (p2[i-1].l<p2[i].l)
        {
            for(j=p2[i-1].l;j<=p2[i].l-1;j++)
            {
                Ti2-=(long long)b[a[j]]*b[a[j]];
                b[a[j]]--;
                Ti2+=(long long)b[a[j]]*b[a[j]];
            }
        }
        if (p2[i].l<p2[i-1].l)
        {
            for(j=p2[i].l;j<=p2[i-1].l-1;j++)
            {
                Ti2-=(long long)b[a[j]]*b[a[j]];
                b[a[j]]++;
                Ti2+=(long long)b[a[j]]*b[a[j]];
            }
        }
        if (p2[i-1].r<p2[i].r)
        {
            for(j=p2[i-1].r+1;j<=p2[i].r;j++)
            {
                Ti2-=(long long)b[a[j]]*b[a[j]];
                b[a[j]]++;
                Ti2+=(long long)b[a[j]]*b[a[j]];
            }
        }
        if (p2[i].r<p2[i-1].r)
        {
            for(j=p2[i].r+1;j<=p2[i-1].r;j++)
            {
                Ti2-=(long long)b[a[j]]*b[a[j]];
                b[a[j]]--;
                Ti2+=(long long)b[a[j]]*b[a[j]];
            }
        }
        ans[p2[i].no]=Ti2;
    }
    for(i=1; i<=m; i++)
    {
        long long len=p1[i].r-p1[i].l+1;
        long long g1=ans[i]-len,g2=len*(len-1);
        if (g1==0) puts("0/1");
        else
        {
            long long d=gcd(g1,g2);
            printf("%lld/%lld\n",g1/d,g2/d);
        }
    }
    return 0;
}
