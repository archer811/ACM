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
int d[maxn][3][3];
struct array
{
    int to,next,w;
} edge[maxn*2];
int e;
void add(int u,int v,int w)
{
    edge[e].to=v;
    edge[e].w=w;
    edge[e].next=head[u];
    head[u]=e++;
}
int min(int a,int b,int c)
{
    if(a>b)a=b;
    if(a>c)a=c;
    return a;
}
int dfs(int u,int fa)
{
    int i,j;
    for(i=head[u]; i!=-1; i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa)continue;
        dfs(v,u);
        int a20=d[u][2][0],a21=d[u][2][1],a10=d[u][1][0],a11=d[u][1][1];
        int a22=d[u][2][2];

        if(i==head[u])
        {
            d[u][2][0]=a22+min(d[v][2][0],d[v][2][1],d[v][2][2])+2*edge[i].w;
            d[u][2][1]=a22+min(d[v][1][0],d[v][1][1])+edge[i].w;
            d[u][2][2]=a22+2*edge[i].w+d[v][2][2];
            d[u][1][0]=a11+min(d[v][1][0],d[v][1][1])+edge[i].w;
            d[u][1][1]=a11+d[v][1][1]+2*edge[i].w;

        }
        else
        {
            d[u][2][0]=min(a21+min(d[v][1][0],d[v][1][1])+edge[i].w,
                           a22+min(d[v][2][0],d[v][2][1],d[v][2][2])+2*edge[i].w);
            d[u][2][1]=min(a22+min(d[v][1][0],d[v][1][1])+edge[i].w,
                           a21+d[v][1][1]+2*edge[i].w);


            d[u][2][2]=a22+2*edge[i].w+d[v][2][2];
            d[u][1][0]=a11+min(d[v][1][0],d[v][1][1])+edge[i].w;
            d[u][1][1]=a11+d[v][1][1]+2*edge[i].w;
        }




        cout<<u<<" "<<v<<" "<<"()()()))))))))))))))))))))"<<
            a22<<" "<<a21<<" "<<a20<<" "<<
            a11<<" "<<a10<<endl;
        cout<<u<<" "<<v<<" "<<d[u][2][0]<<" "<<d[u][2][1]<<" "<<
            " "<<d[u][2][2]<<" "<<d[u][1][0]<<" "<<d[u][1][1]<<endl;
    }
    return min(d[u][2][0],d[u][1][0]);
}
int main()
{
    int i,j,k,a,b,c;
    while(scanf("%d%d",&n,&s)!=EOF)
    {
        memset(d,0,sizeof(d));
        e=0;
        memset(head,-1,sizeof(head));
        for(i=0; i<n-1; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
            add(b,a,c);
        }
        cout<<dfs(s,-1)<<endl;
    }
}
