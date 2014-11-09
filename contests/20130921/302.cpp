#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define ll __int64
const int maxn = 10005;
const int maxm = 500005;
struct array
{
    int u,v,w;
}ans[maxm];
int fa[maxn],s[maxn];
ll sum[maxm];
int a[maxm],n,m;
int cmp(array x,array y)
{
    return x.w<y.w;
}
int find(int x)
{
    if(x==fa[x])return x;
    return fa[x]=find(fa[x]);
}
int main()
{
    int i,j,k,q,t;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<n;i++)
            fa[i]=i,s[i]=1;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&ans[i].u,&ans[i].v,&ans[i].w);
        }
        sort(ans,ans+m,cmp);
        a[0]=-2;
        int tot=1;
        ll ss=0;
        for(i=0;i<m;i++)
        {
            int u = find(ans[i].u),v = find(ans[i].v);
            if(u==v)continue;
            if(u>v)swap(u,v);
            fa[v]=u;
            a[tot]=ans[i].w;
            ss = ss-(ll)s[u]*(s[u]-1)+(ll)(s[u]+s[v])*(s[u]+s[v]-1)-(ll)s[v]*(s[v]-1);
            sum[tot++]=ss;
            s[u]+=s[v];
        }
        scanf("%d",&q);
        //cout<<tot<<"*"<<endl;
        tot--;
//        for(i=0;i<=tot+1;i++)
//            cout<<i<<" "<<a[i]<<"&&"<<endl;
        while(q--)
        {
            scanf("%d",&t);
            int tmp = upper_bound(a,a+tot+1,t-1)-a-1;
            if(tmp>=tot)tmp = tot;
//            cout<<t-1<<" "<<a[1]<<" "<<tmp<<" "<<sum[tot]<<" "<<sum[tmp]<<endl;
            printf("%I64d\n",sum[tot]-sum[tmp]);
        }
    }
}

