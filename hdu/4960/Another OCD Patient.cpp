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
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int maxn = 5006;
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
ll v[maxn];
ll a[maxn];
int d[maxn][maxn];
int dfs(int l,int r)
{
    if(l>=r)return 0;
    if(d[l][r]!=-1)return d[l][r];
    ll ans = v[r-l+1];
    int i=l,j=r;
    ll s1=0,s2=0;
    while(i<=j)
    {
        if(s1<=s2)
        {
            s1 += a[i];
            i++;
        }
        else
        {
            s2 += a[j];
            j--;
        }
        if(s1==s2&&s1!=0)
        {
            ll tmp = v[i-(l)]+v[(r)-j];
//            cout<<tmp<<"*"<<i-(l)<<" "<<r-j<<endl;
            if(tmp<ans)
            {
                tmp += dfs(i,j);
                if(tmp<ans)ans=tmp;
            }
        }
    }
    return d[l][r]=ans;
}
int main()
{
    int i,j;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        memset(d,-1,sizeof(d));
        for(i=1; i<=n; i++)
            scanf("%lld",&a[i]);
        for(i=1; i<=n; i++)
            scanf("%lld",&v[i]);
        ll ans = dfs(1,n);
        printf("%lld\n",ans);
    }
    return 0;
}
