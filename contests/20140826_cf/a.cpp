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
ll ans=0;
ll a[3000005],sum[300006];
int main()
{
    int i,j;
    int n;
    while(cin>>n)
    {
        for(i=1;i<=n;i++)
            scanf("%I64d",&a[i]);
        sort(a+1,a+1+n);
        sum[n+1]=0;
        ans=0;
        for(i=n;i>=1;i--)
        {
            sum[i] = sum[i+1]+a[i];
            ans += a[i];
            if(i<n)
            ans += sum[i];
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
