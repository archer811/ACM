#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define ll __int64
const int maxn = 100005;
ll tree[maxn<<2];
const ll inf = -(0xfffffff);
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
int num[100005];
int h[100005];
ll dp[100005];
ll _max(ll a,ll b)
{
    if(a>b)return a;
    return b;
}
int cmp(int x,int y)
{
    if(h[x]==h[y])return x>y;
    return h[x]<h[y];
}
void build(int l,int r,int rt)
{
    tree[rt]=inf;
    if(l!=r)
    {
        int mid = (l+r)>>1;
        build(lson);
        build(rson);
    }
}
void pushup(int rt)
{
    tree[rt]=_max(tree[rt<<1],tree[rt<<1|1]);
}
void update(int x,ll y,int l,int r,int rt)
{
    if(l==r)
    {
        tree[rt]=y;
        return;
    }
    int mid = (l+r)>>1;
    if(x<=mid)update(x,y,lson);
    else update(x,y,rson);
    pushup(rt);
}
ll query(int x,int y,int l,int r,int rt)
{
    if(x<=l&&y>=r)
    {
        return tree[rt];
    }
    int mid = (l+r)>>1;
    ll ans = inf;
    if(x<=mid)
        ans = _max(ans,query(x,y,lson));
    if(y>mid)
        ans = _max(ans,query(x,y,rson));
    return ans;
}
int main()
{
    int i,j,T,n,L;
    scanf("%d",&T);
    int cas=0;
    while(T--)
    {
        scanf("%d%d",&n,&L);
        h[0]=0;
        num[0]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&h[i]);
            num[i]=i;
        }
        printf("Case #%d: ",++cas);
        sort(num+1,num+1+n,cmp);
       // for(i=1;i<=n;i++)
        //    cout<<i<<" "<<h[num[i]]<<" "<<num[i]<<endl;
        build(1,n,1);
        for(i=1;i<=n;i++)
        {
            int o = num[i];
            int a = max(1,num[i]-L);
            int b = num[i]-1;
            ll tmp;
            if(num[i]<L+1)dp[o]=0;
            else dp[o]=inf;
            if(a>b)
               tmp = inf;
            else
            {
                tmp = query(a,b,1,n,1);
                //if(tmp==inf)
                 //  tmp=0;
            }
            dp[o]=_max(dp[o],tmp);
            if(dp[o]!=inf)
            {
                dp[o]=dp[o]+(ll)h[num[i]]*(ll)h[num[i]]-(ll)h[num[i]];
                update(num[i],dp[o],1,n,1);
            }
            else update(num[i],inf,1,n,1);
            //if(i>L)update(ans[i-L].num,inf,1,100000,1);

            //cout<<i<<" "<<dp[o]<<" "<<tmp<<" "<<num[i]<<endl;
        }
        if(dp[n]==inf)puts("No solution");
        else printf("%I64d\n",dp[n]+h[n]);
    }
}
