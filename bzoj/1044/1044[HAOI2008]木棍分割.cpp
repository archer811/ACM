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
const int maxn = 50006;
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
int n,m;
int a[50005];
int ff(int mid)
{
    int i,j=0,s=0;
    for(i=1;i<=n;i++)
    {
        if(j+a[i]>mid)
        {
            s++;
            j=a[i];
        }
        else j+=a[i];
    }
    if(j)s++;
    return s<=m;
}
int p[500005],sum[500005];
int g[maxn],f[maxn],preg[maxn],pref[maxn];
const ll mod = 10007;
ll ok(ll x)
{
    if(x<0)
    {
        x = (x%mod+mod)%mod;
    }
    else
        x = x%mod;
    return x;
}
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        sum[0]=0;
        m = m+1;
        int M=-1;
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i],M=max(M,a[i]);
        int l = M,r = sum[n];
        while(l<r)
        {
            int mid = (l+r)/2;
            if(ff(mid))r=mid;
            else l=mid+1;
        }

        printf("%d\n",l);
        int k=0;
        for(i=1;i<=n;i++)
        {
            while(k<=i&&sum[i]-sum[k]>l)k++;
            p[i]=k;
        }
        ll ans=0;
        memset(preg,0,sizeof(preg));
        memset(pref,0,sizeof(pref));
        pref[0]=1;
        for(i=1;i<=n;i++)
            preg[i]=1;
        for(i=1;i<=m;i++)
        {
            g[0]=0;
            for(j=1;j<=n;j++)
            {
                f[j] = ok(preg[j-1]-preg[p[j]]);
                g[j] = ok(g[j-1]+f[j]);
                cout<<i<<" "<<j<<" "<<f[j]<<" "<<g[j]<<endl;
            }
            ans = ok(ans+f[n]);
            for(j=1;j<=n;j++)
            {
                preg[j]=g[j];
                pref[j]=f[j];
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
