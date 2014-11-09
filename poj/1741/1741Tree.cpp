#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int n,k;
const int maxn = 11005;
int head[maxn],tot;
int s[maxn],f[maxn],size,vis[maxn],root;
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
int d[maxn];
void add(int a,int b,int c)
{
    edge[tot].to=b;
    edge[tot].w=c;
    edge[tot].next=head[a];
    head[a]=tot++;
}
void findroot(int u,int fa)
{
    s[u]=1;
    f[u]=0;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(vis[v]==0&&v!=fa)
        {
            findroot(v,u);
            s[u]+=s[v];
            f[u]=max(f[u],s[v]);
        }
    }
    f[u]=max(f[u],size-s[u]);
    if(f[u]<f[root])root=u;
}
int ans;
vector<int>dep;
void getdp(int u,int fa)
{
    dep.push_back(d[u]);
    s[u]=1;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(vis[v]==0&&v!=fa)
        {
            d[v]=d[u]+edge[i].w;
            getdp(v,u);
            s[u]+=s[v];
        }
    }
}
int cal(int u,int w)
{
    d[u]=w;
    dep.clear();
    getdp(u,-1);
    sort(dep.begin(),dep.end());
    int sum=0,i=0,j=dep.size()-1;
    for(i=0;i<j;i++)
        cout<<i<<" "<<dep[i]<<endl;
    i=0;
    while(i<j)
    {
        while(dep[i]+dep[j]>k&&i<j)
            j--;
        //if(u==1)cout<<j<<"()"<<endl;
        if(dep[i]+dep[j]<=k)sum+=j-i;
       // if(u==1)cout<<i<<"!!"<<j<<" "<<sum<<endl;
        i++;
    }


    return sum;
}
void solve(int u)
{
    ans += cal(u,0);
    vis[u]=1;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(vis[v]==0)
        {
            ans -= cal(v,edge[i].w);
            f[0]=size=s[v];
            root=0;
            findroot(v,-1);
            solve(root);
        }
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
        f[0]=size=n;
        root=0;
        findroot(1,-1);
        ans=0;
        solve(root);
        printf("%d\n",ans);
    }
}
