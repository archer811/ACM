#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int n,r;
const int maxn = 10005;
const int inf = 0x3fffffff;
int head[maxn],tot;
struct array
{
    int to,next,w;
}edge[maxn*4];
void add(int u,int v,int w)
{
    edge[tot].to=v;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int d[maxn],mark[maxn];
void dfs(int u,int fa)
{
    int i,j;
    bool flag=false;
    int sum=0;
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa)continue;
        flag=true;
        dfs(v,u);
        //if(v==11)cout<<mark[v]<<endl;
        if(mark[v])sum += edge[i].w;
        else
        {
            int tmp = edge[i].w;
            tmp = min(tmp,d[v]);
            sum += tmp;
        }
    }
    //cout<<u<<" * "<<flag<<" "<<sum<<endl;
    if(flag==false)mark[u]=1;
    d[u]=sum;
}
int main()
{
    int i,j,a,b,c;
    while(scanf("%d%d",&n,&r)!=EOF)
    {
        tot=0;
        if(n==0&&r==0)break;
        memset(head,-1,sizeof(head));
        memset(mark,0,sizeof(mark));
        memset(d,0,sizeof(d));
        for(i=1;i<n;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
            add(b,a,c);
        }
        dfs(r,-1);
        cout<<d[r]<<endl;
    }
}
