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
ll a[maxn];
ll sum[maxn];
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        sum[0]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%I64d",&a[i]);
            sum[i] = sum[i-1]+a[i];
        }
        if(sum[n]%3)
        {
            puts("0");
        }
        else
        {
            ll ans=0;
            ll x = sum[n]/3;
            ll N=0;
            for(j=n;j>=1;j--)
            {
                if(sum[j]==x)
                {
                    ans += N;
                    //cout<<j<<" "<<N<<endl;
                }
                if(j<n&&sum[j]==x*2)
                    N++;
            }
            printf("%I64d\n",ans);
        }
    }
    return 0;
}
