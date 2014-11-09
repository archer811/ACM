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
const int maxn = 1000004;
int now[maxn],goal[maxn];
int head[maxn],tot;
struct array
{
    int to,next;
}edge[maxn*3];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int start[maxn],end[maxn];
int pos;
int g[maxn];
void dfs(int u,int fa)
{
    int i,j;
    start[u]=pos++;
    g[pos-1]=u;
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa)continue;
        dfs(v,u);
    }
    end[u]=pos-1;
}
int tree[maxn<<2];
vector<int>ans;
int lazy[maxn<<2];
#define lson rt<<1
#define rson rt<<1|1
int x[maxn];
void build(int l,int r,int rt)
{
    lazy[rt]=0;
    if(l==r)
    {
        tree[rt]=x[l];return;
    }
    int mid = (l+r)>>1;
    build(l,mid,lson);
    build(mid+1,r,rson);
}
void pushdown(int l,int r,int mid,int rt)
{
    if(lazy[rt])
    {
        lazy[lson]^=1;
        lazy[rson]^=1;
        if(lazy[lson])
            tree[lson]^=1;
        if(lazy[rson])
            tree[rson]^=1;
        lazy[rt]=0;
    }
}
void change(int x,int y,int l,int r,int rt)
{
    if(x<=l&&y>=r)
    {
        lazy[rt]^=1;
        if(lazy[rt])
            tree[rt]^=1;
        return;
    }
    int mid = (l+r)/2;
    pushdown(l,r,mid,rt);
    if(x<=mid)
        change(x,y,l,mid,lson);
    if(y>mid)
        change(x,y,mid+1,r,rson);
}
int get(int x,int l,int r,int rt)
{
    if(l==r)
    {
        return tree[rt];
    }
    int mid = (l+r)/2;
    pushdown(l,r,mid,rt);
    if(x<=mid)return get(x,l,mid,lson);
    return get(x,mid+1,r,rson);
}
int n;
void dfs2(int u,int fa)
{
    int i,j;
    int tmp = get(start[u],1,n,1);
    //cout<<u<<" "<<start[u]<<" "<<tmp<<" "<<goal[u]<<endl;
    if(tmp!=goal[u])
    {
        ans.push_back(u);
        change(start[u],end[u],1,n,1);
    }
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa)continue;
        dfs2(v,u);
    }
}
int main()
{
    int i,j;
    while(cin>>n)
    {
        int a,b;
        memset(head,-1,sizeof(head));
        tot=0;
        for(i=2;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            add(a,b);
            add(b,a);
        }
        pos=1;
        dfs(1,-1);
        for(i=1;i<=n;i++)
            scanf("%d",&now[i]);
        for(i=1;i<=n;i++)
        {
            x[start[i]]=now[i];
        }
        for(i=1;i<=n;i++)
            scanf("%d",&goal[i]);
        ans.clear();
        build(1,n,1);
//        for(i=1;i<=n;i++)
//        {
//            cout<<get(start[i],1,n,1)<<" ";
//        }
//        cout<<endl;
        dfs2(1,-1);
        printf("%d\n",ans.size());
        sort(ans.begin(),ans.end());
        for(i=0;i<ans.size();i++)
            cout<<ans[i]<<endl;
    }
    return 0;
}
