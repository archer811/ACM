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
const int maxn = 21000;
struct array
{
    int to,next;
}edge[maxn*2];
int head[maxn],tot;
void add(int u,int v)
{
    edge[tot].to=y;
    edge[tot].next=head[x];
    head[x]=tot++;
}
int num[maxn],M[maxn];
void dfs(int u,int fa)
{
    int i,j;
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa)continue;
        num[v]=num[u]+1;
        dfs(v,u);
        M[u]=max(M[v]+1,M[u]);
    }
}
int main()
{
    int i,j,n,q;
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        memset(head,-1,sizeof(head));
        tot=0;
        int a,b;
        for(i=1;i<=n-1;i++)
        {
            scanf("%d%d",&a,&b);
            add(a,b);
            add(b,a);
        }
        num[1]=0;
        dfs(1,-1);
        while(q--)
        {
            int u,d;
            scanf("%d%d",&u,&d);
            if(d<=num[u])
            {

            }
            else
        }
    }
    return 0;
}
