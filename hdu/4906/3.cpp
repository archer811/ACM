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
#define ll  long long
ll d[(1<<20)+10];
const ll mod = 1e9+7;
void add(ll &x,ll b)
{
    x = x+b;
    if(x>=mod)x-=mod;
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        int l;
        scanf("%d%d%d",&n,&k,&l);
        memset(d,0,sizeof(d));
        ll extra=l-k;
        int M= 1<<k;
        d[0]=1;
        for(i=1;i<=n;i++)
        {
            for(j=M-1;j>=0;j--)
            {
                ll c = d[j];
                if(c==0)continue;
                for(int s=1;s<=k;s++)
                {
                   // if(j&(1<<(s-1)))continue;
                    int tmp = j|((j<<s)&(M-1))|(1<<(s-1));
                    add(d[tmp],c);
                }
                add(d[j],extra*c%mod);
            }
        }
        ll ans=0;
        for(i=0;i<M;i++)
        {
            if(i&(1<<(k-1)))
                add(ans,d[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
