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
#define ll long long
const int maxn = 30100;
int val[maxn],w[maxn],son[maxn],siz[maxn];
int tree[maxn*4];
ll sum[maxn*4];
int top[maxn];
int fa[maxn];
int dep[maxn];
struct array
{
    int to,next;
} edge[maxn*2+11];
int tot,size;
int head[maxn];
const ll inf = ((ll)1)<<20;
#define lson rt<<1
#define rson rt<<1|1
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
void dfs(int u,int _fa,int deep)
{
    siz[u]=1;
    son[u]=0;
    dep[u]=deep;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==_fa)continue;
        fa[v]=u;
        dfs(v,u,deep+1);
        if(siz[son[u]]<siz[v])
            son[u]=v;
        siz[u]+=siz[v];
    }
}
void dfs1(int u,int fa)
{
    if(son[u])
    {
        top[son[u]]=top[u];
        w[son[u]]=size++;
        dfs1(son[u],u);
    }
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa)continue;
        if(v!=son[u])
        {
            top[v]=v;
            w[v]=size++;
            dfs1(v,u);
        }
    }
}
void update(int a,int b,int l,int r,int rt)
{
    if(l==r)
    {
        tree[rt]=b;
        sum[rt]=(ll)b;
        //cout<<rt<<"!!"<<sum[rt]<<endl;
        return;
    }
    int mid = (l+r)>>1;
    if(a<=mid)
        update(a,b,l,mid,lson);
    else update(a,b,mid+1,r,rson);
    tree[rt]=max(tree[lson],tree[rson]);
    sum[rt]=sum[lson]+sum[rson];
    //cout<<rt<<" ***** "<<sum[rt]<<endl;
}
ll querymax(int x,int y,int l,int r,int rt)
{
    if(x<=l&&y>=r)
        return tree[rt];
    int mid = (l+r)>>1;
    ll ans=-inf;
    if(x<=mid)
        ans = max(ans,querymax(x,y,l,mid,lson));
    if(y>mid)
        ans = max(ans,querymax(x,y,mid+1,r,rson));
    return ans;
}
ll querysum(int x,int y,int l,int r,int rt)
{
    if(x<=l&&y>=r)
        return sum[rt];
    int mid = (l+r)>>1;
    ll ans=0;
    if(x<=mid)
        ans += (ll)querysum(x,y,l,mid,lson);
    if(y>mid)
        ans += (ll)querysum(x,y,mid+1,r,rson);
    return ans;
}
char s[10];
int main()
{
    int i,j,n,m;
    int a,b;
    while(scanf("%d",&n)==1)
    {
        tot=0;
        memset(head,-1,sizeof(head));
        memset(siz,0,sizeof(siz));
        size=1;
        for(i=1; i<n; i++)
        {
            scanf("%d%d",&a,&b);
            add(a,b);
            add(b,a);
        }
        for(i=1; i<=n; i++)
        {
            scanf("%d",&val[i]);
        }
        dfs(1,-1,1);
        top[1]=1;
        w[1]=size++;
        dfs1(1,-1);
        for(i=1; i<=n; i++)
        {
//            cout<<w[i]<<"*"<<val[i]<<endl;
            update(w[i],val[i],1,size-1,1);
        }
//        cout<<querysum(1,3,1,size-1,1)<<endl;
        scanf("%d",&m);
//        for(i=1; i<=n; i++)
//        {
//            cout<<i<<" "<<w[i]<<endl;
//        }
        while(m--)
        {
            scanf("%s%d%d",s,&a,&b);
            if(s[0]=='C')
            {
                val[a]=b;
                update(w[a],b,1,size-1,1);
            }
            else if(s[1]=='M')
            {
                ll ans=-3000000;
                //cout<<top[a]<<"SSS"<<top[b]<<endl;
                while(top[a]!=top[b])
                {
                    int x = top[a];
                    int y = top[b];
                    if(dep[x]>dep[y])swap(a,b);
                    int left=w[b];
                    int right=w[top[b]];
                    if(left>right)swap(left,right);
                    //cout<<left<<" "<<right<<endl;
                    //cout<<ans<<endl;
                    ans = max(ans,querymax(left,right,1,size-1,1));

                    b = fa[top[b]];
                }

                int left = w[a];
                int right = w[b];
                if(left>right)swap(left,right);
                ans = max(ans,querymax(left,right,1,size-1,1));

                printf("%lld\n",ans);
            }
            else if(s[1]=='S')
            {
                ll ans=0;

                while(top[a]!=top[b])
                {
                    int x = top[a];
                    int y = top[b];
                    if(dep[x]>dep[y])swap(a,b);
                    int left=w[b];
                    int right=w[top[b]];
                    if(left>right)swap(left,right);

                    ans += querysum(left,right,1,size-1,1);

                    b = fa[top[b]];
                }

                int left = w[a];
                int right = w[b];
                if(left>right)swap(left,right);
//                cout<<ans<<"          "<<querysum(1,3,1,size-1,1)<<endl;
                ans += querysum(left,right,1,size-1,1);
//                cout<<a<<" "<<b<<" "<<w[a]<<" "<<w[b]<<" "<<left<<" "<<right<<" "<<ans<<endl;

                printf("%lld\n",ans);
            }


        }
    }
}
