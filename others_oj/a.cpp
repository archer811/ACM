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
const int maxn = 11001;
int siz[maxn],son[maxn],fa[maxn],dep[maxn];
int top[maxn],w[maxn];
int cost[maxn];
#define lson rt<<1
#define rson rt<<1|1
struct array
{
    int to,next,index;
} edge[maxn*2+10];
int tot;
int head[maxn];
int size;
int tree[maxn*4];
void add(int a,int b,int c,int num)
{
    edge[tot].to=b;
    edge[tot].next=head[a];
    edge[tot].index=num;
    head[a]=tot++;
}
void dfs(int u,int _fa,int deep)
{
    siz[u]=1;
    dep[u]=deep;
    int M=-1;
    son[u]=0;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==_fa)continue;
        fa[v]=u;
        dfs(v,u,deep+1);
        siz[u]+=siz[v];
        if(siz[v]>M)
        {
            M=siz[v];
            son[u]=v;
        }
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
        if(son[u]!=v)
        {
            top[v]=v;
            // cout<<edge[i].index<<"@@"<<size<<endl;
            w[v]=size++;
            dfs1(v,u);
        }
    }
}
char s[10];
void update(int a,int b,int l,int r,int rt)
{
    if(l==r)
    {
        tree[rt]=b;
        return;
    }
    int mid = (l+r)>>1;
    if(a<=mid)
        update(a,b,l,mid,rt<<1);
    else update(a,b,mid+1,r,rt<<1|1);
    tree[rt]=max(tree[lson],tree[rson]);
}
int query(int x,int y,int l,int r,int rt)
{
    if(x<=l&&y>=r)
    {
        return tree[rt];
    }
    int s=0;
    int mid = (l+r)>>1;
    if(x<=mid)
        s = max(s,query(x,y,l,mid,rt<<1));
    if(y>mid)
        s = max(s,query(x,y,mid+1,r,rt<<1|1));
    return s;
}
int d[maxn][3];
int main()
{
    int i,j,n;
    int a,b,c,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        tot=0;
        size = 1;
        memset(w,0,sizeof(w));
        memset(head,-1,sizeof(head));
        memset(top,0,sizeof(top));
        memset(fa,0,sizeof(fa));
        for(i=1; i<n; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            cost[i]=c;
            add(a,b,c,i);
            add(b,a,c,i);
            d[i][0]=a;
            d[i][1]=b;
            d[i][2]=c;
        }
        dfs(1,-1,1);
        top[1]=1;
        dfs1(1,-1);
        memset(tree,0,sizeof(tree));
        for(i=1; i<n; i++)
        {
            if(dep[d[i][0]]>dep[d[i][1]])
                swap(d[i][0],d[i][1]);
            update(w[d[i][1]],d[i][2],1,size-1,1);
        }
//        for(i=1;i<=n;i++)
//            cout<<i<<" "<<w[i]<<endl;


        while(scanf("%s",s)!=EOF)
        {
            if(s[0]=='D')break;
            scanf("%d%d",&a,&b);
            if(s[0]=='C')
            {
                update(w[d[a][1]],b,1,size-1,1);
            }
            else
            {
                int ans=0;
                while(top[a]!=top[b])
                {
                    int dep1 = dep[top[a]];
                    int dep2 = dep[top[b]];
                    if(dep1>dep2)swap(a,b);
                    int left = w[b];
                    int right = w[top[b]];
                    //cout<<left<<" "<<right<<endl;
                    if(left>right)swap(left,right);
                    ans = max(ans,query(left,right,1,size-1,1));
                    b = fa[top[b]];
                }
                if(a!=b)
                {
                    int dep1 = dep[a];
                    int dep2 = dep[b];
                    if(dep1>dep2)swap(a,b);
                    int left = w[b];
                    int right = w[son[a]];
                    //cout<<left<<" "<<right<<endl;
                    if(left>right)swap(left,right);
                    ans = max(ans,query(left,right,1,size-1,1));
                }
                printf("%d\n",ans);
            }
        }
    }
}

