#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 100005;
int n,s;
int head[maxn];
int d[maxn][3];
struct array
{
    int to,next,w;
}edge[maxn*2];
int e;
void add(int u,int v,int w)
{
    edge[e].to=v;
    edge[e].w=w;
    edge[e].next=head[u];
    head[u]=e++;
}
int dfs(int u,int fa)
{
    int i,j;
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa)continue;
        dfs(v,u);
        int a0=d[u][0],a1=d[u][1],a2=d[u][2];
        if(u==2)cout<<a0<<"*"<<a1<<"&"<<a2<<" "<<v<<
            "+++++++++++++++"<<d[v][0]<<
            " "<<d[v][1]<<" "<<d[v][2]<<endl;

        d[u][0]=min(a1+d[v][0]+edge[i].w,a2+d[v][0]+2*edge[i].w);
        if(u==2&&v==1)cout<<a1+d[v][0]+edge[i].w<<"))))))))))))))"<<endl;
        d[u][1]=min(a1+d[v][1]+2*edge[i].w,a2+d[v][1]+3*edge[i].w);
        d[u][2]=a2+2*edge[i].w+d[v][1];
        cout<<u<<" "<<d[u][0]<<" "<<d[u][1]<<" "<<d[u][2]<<endl;
    }
    return d[u][0];
}
int main()
{
    int i,j,k,a,b,c;
    while(scanf("%d%d",&n,&s)!=EOF)
    {
        memset(d,0,sizeof(d));
        e=0;
        memset(head,-1,sizeof(head));
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
            add(b,a,c);
        }
        cout<<dfs(s,-1)<<endl;
    }
}
