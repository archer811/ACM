#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int n;
const int maxn = 100005;
int head[maxn],tot;
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
void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
}

vector<int>ans;
int d[maxn];
void dfs(int u,int fa,int mark)
{
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa)continue;
        int t=0;
        if(edge[i].w)
        {
            t=1;
            d[u]++;
        }
        dfs(v,u,t);
        d[u]+=d[v];
    }
   // cout<<u<<" "<<d[u]<<" "<<mark<<endl;
    if(d[u]==0&&mark)ans.push_back(u);
}
int main()
{
    int i,j,k;
    int a,b,c;
    while(scanf("%d",&n)!=EOF)
    {
        init();
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(c==2)
                add(a,b,1),add(b,a,1);
            else add(a,b,0),add(b,a,0);
        }
        memset(d,0,sizeof(d));
        ans.clear();
        dfs(1,-1,0);
        cout<<ans.size()<<endl;
        for(i=0;i<ans.size();i++)
           cout<<ans[i]<<" ";
    }
}
