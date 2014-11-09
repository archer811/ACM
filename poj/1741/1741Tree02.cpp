#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 10005;
int n,k;
int head[maxn],tot;
int f[maxn],s[maxn],size,ans=0,root;
int vis[maxn];
vector<int>dep;
void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
}
struct array
{
    int to,next,w;
}edge[maxn*2];
void add(int a,int b,int c)
{
    edge[tot].to=b;
    edge[tot].w=c;
    edge[tot].next=head[a];
    head[a]=tot++;
}
void find_root(int u,int fa)
{
    f[u]=0;
    s[u]=1;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa)continue;
        if(vis[v])continue;
        find_root(v,u);
        s[u]+=s[v];
        f[u]=max(f[u],s[v]);
    }
    f[u]=max(f[u],size-s[u]);
    //if(u==4)cout<<"#####"<<f[u]<<" "<<f[root]<<endl;
    if(f[u]<f[root])root=u;
}
int d[maxn];
void dfs(int u,int fa)
{
    dep.push_back(d[u]);
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(vis[v])continue;
        if(v==fa)continue;
        d[v]=d[u]+edge[i].w;
        //cout<<v<<"!!@@!@!@"<<d[u]<<" "<<edge[i].w<<endl;

        dfs(v,u);
    }
}

int getans(int u,int fa)
{
    d[u]=fa;
    dep.clear();
    dfs(u,-1);
    sort(dep.begin(),dep.end());
    int i=0,j = dep.size()-1;
    int sum=0;
//    for(i=0;i<j;i++)
//        cout<<i<<" "<<dep[i]<<endl;
    i=0;
    while(i<j)
    {
        while(i<j&&dep[i]+dep[j]>k)j--;
        if(i<j&&dep[i]+dep[j]<=k)
          sum += j-i;
        i++;
    }
    //cout<<u<<" "<<sum<<"&"<<endl;
    return sum;
}
void solve(int u,int fa)
{
    ans += getans(u,0);
    //cout<<u<<"!"<<ans<<endl;
    vis[u]=1;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(vis[v])continue;

        ans -= getans(v,edge[i].w);
        f[0]=size=s[v];
        //cout<<s[v]<<"@@@#!@#!#@!@#!@#"<<endl;
        root=0;
        find_root(v,-1);
        //cout<<root<<"@"<<endl;
        solve(root,-1);
    }
}
int main()
{
    int i,j;
    int a,b,c;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        if(n==0&&k==0)break;
        init();
        for(i=1;i<n;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
            add(b,a,c);
        }
        ans=0;
        f[0]=size=n;
        root=0;
        find_root(1,-1);
//        for(i=1;i<=n;i++)
//            cout<<i<<"GG"<<s[i]<<endl;
        solve(root,-1);
        cout<<ans<<endl;
    }
}
