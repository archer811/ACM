#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<functional>
#include<bitset>
#include<ctime>

using namespace std;

#pragma comment(linker, "/STACK:1024000000,1024000000")
#define PB push_back
#define MP make_pair

const double pi=acos(-1.0),eps=1e-8;
const int maxn=2100,maxm=26000000,inf=0x3f3f3f3f;
#define ll long long
//const ll linf=1122334455667788990;

ll f[maxn],s[maxn],p[maxn],q[maxn],l[maxn],dp[maxn];
ll dpf(int u);
ll dfs(int i,int u,ll dist);

ll dfs(int i,int u,ll dist)
{
    ll ans=dpf(u)+dist*p[i]+q[i];
    if(u!=1&&s[u]+dist<=l[i])
        ans=min(ans,dfs(i,f[u],dist+s[u]));
    return ans;
}

ll dpf(int u)
{
    if(~dp[u])
        return dp[u];
    return dp[u]=dfs(u,f[u],s[u]);
}

int main()
{
    freopen("ticket.in","r",stdin);
    freopen("ticket.out","w",stdout);
    int n,t;
    while(~scanf("%d%d",&n,&t))
    {
        memset(dp,-1,sizeof(dp));
        dp[1]=0;
        for(int i=2;i<=n;i++)
        {
            cin>>f[i]>>s[i]>>p[i]>>q[i]>>l[i];
        }
        for(int i=2;i<=n;i++)
            dpf(i);
        for(int i=2;i<=n;i++)
            cout<<dp[i]<<endl;
    }
    return 0;
}
