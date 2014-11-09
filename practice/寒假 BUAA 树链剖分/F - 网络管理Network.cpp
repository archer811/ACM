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
const int maxn = 11005;
int val[maxn],fa[maxn],siz[maxn],top[maxn],head[8008];
int tree[100][maxn],son[maxn],w[maxn],dep[maxn];
struct Edge
{
    int to,next;
}edge[8008*2+10];
int tot;
int size;
int num;
int mark[maxn];
int lowbit(int x)
{
    return ~x&x+1;
}
void add(int index,int x,int b)
{
    while(x<maxn)
    {
        tree[index][x]+= b;
        x += lowbit(x);
    }
}
int getsum(int index,int x)
{
    int sum=0;
    while(x>=0)
    {
        sum += tree[index][x];
        x -= lowbit(x);
    }
    return sum;
}
void add(int a,int b)
{
    edge[tot].to=b;
    edge[tot].next=head[a];
    head[a]=tot++;
}
int Q[3005][3];
int s[maxn];
void dfs(int u,int _fa,int deep)
{
    siz[u]=1;
    dep[u]=deep;
    son[u]=0;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==_fa)continue;
        dfs(v,u,deep+1);
        siz[u]+=siz[v];
        fa[v]=u;
        if(siz[son[u]]<siz[v])
            son[u]=v;
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
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa)continue;
        if(v==son[u])continue;
        top[v]=v;
        w[v]=size++;
        mark[v]=size-1;
        dfs1(v,u);
    }
}
int g;
int find(int x)
{
    int l = 0,r = g-1;
    while(l<=r)
    {
        int mid = (l+r)>>1;
        if(s[mid]==x)return mid;
        if(s[mid]<x)l=mid+1;
        else r=mid-1;
    }
}
int getans(int x,int y)
{
    int sum=0;
//    cout<<top[x]<<" "<<top[y]<<endl;
    while(top[x]!=top[y])
    {
        int g1 = dep[top[x]];
        int g2 = dep[top[y]];
        if(g1>g2)swap(x,y);
//        cout<<x<<"$$"<<y<<" "<<fa[top[y]]<<endl;
        sum += w[y]-w[top[y]]+1;
        y = fa[top[y]];
//        cout<<x<<"~~~"<<y<<endl;
    }
    int left = w[x];
    int right = w[y];
    if(left>right)swap(left,right);
    sum += right-left+1;
    return sum;
}
int main()
{
    int i,j;
    int n,q;
    int a,b;
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        tot=0;
        memset(head,-1,sizeof(head));
        memset(mark,0,sizeof(mark));
        g=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&val[i]);
            s[g++]=val[i];
        }
        for(i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            add(a,b);
            add(b,a);
        }
        for(i=0;i<q;i++)
        {
            scanf("%d%d%d",&Q[i][0],&Q[i][1],&Q[i][2]);
            if(Q[i][0]==0)
                s[g++]=Q[i][2];
        }
        sort(s,s+g);
        g = unique(s,s+g)-s;
        memset(tree,0,sizeof(tree));
        dfs(1,-1,1);
        top[1]=1;
        size=1;
        num=1;
        mark[1]=1;
        w[1]=size++;
        dfs1(1,-1);
        for(i=1;i<=n;i++)
        {
            j = mark[top[i]];
            int k = find(val[i]);
            add(j,k,1);
        }
//        for(i=1;i<=n;i++)
//            cout<<i<<"!"<<top[i]<<endl;
        for(i=0;i<q;i++)
        {
            if(Q[i][0]==0)
            {
                int k = find(Q[i][2]);
                add(mark[top[Q[i][1]]],val[Q[i][1]],-1);
                add(mark[top[Q[i][1]]],k,1);
                val[Q[i][1]]=k;
            }
            else
            {
                int sum = getans(Q[i][1],Q[i][2]);
                if(sum<k)puts("invalid request!");
                else
                {

                }
            }
        }
    }
}
