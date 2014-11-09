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
const int maxn = 220;
#define vm 220
#define em 1880000
const int inf = 0x7f7f7f7f;
struct E
{
    int to,next,cap;
}edge[em];
int head[vm],gap[vm],dist[vm],cur[vm],pre[vm];
int e;
void init()
{
    e=0;
    memset(head,-1,sizeof(head));
}
void add(int u,int v,int c)
{
    edge[e].cap=c;
    edge[e].next=head[u];
    edge[e].to=v;
    head[u]=e++;
    edge[e].cap=0;
    edge[e].next=head[v];
    edge[e].to=u;
    head[v]=e++;
}
int sap(int s,int t,int n)
{
    memset(dist,0,sizeof(dist));
    memset(gap,0,sizeof(gap));
    memcpy(cur,head,sizeof(head));
    int res = 0;
    int u=pre[s]=s;
    int aug = inf;
    gap[0]=n;
    while(dist[s]< n)
    {
        loop:
        for(int &i=cur[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            if(edge[i].cap&&dist[u]==dist[v]+1)
            {
                aug=min(aug,edge[i].cap);
                pre[v]=u;
                u=v;
                if(v==t)
                {
                    res+=aug;
                    for(u=pre[u];v!=s;v=u,u=pre[u])
                    {
                        edge[cur[u]].cap-=aug;
                        edge[cur[u]^1].cap+=aug;
                    }
                    aug=inf;
                }
                goto loop;
            }
        }
        int mindist = n;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            if(edge[i].cap&&mindist>dist[v])
            {
                cur[u]=i;
                mindist=dist[v];
            }
        }
        if((--gap[dist[u]])==0)
          break;
        dist[u]=mindist+1;
        gap[dist[u]]++;
        u=pre[u];
    }
    return res;
}
int w[maxn][maxn];
int go[][2]={-1,0,1,0,0,1,0,-1};
int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        int sum=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
                scanf("%d",&w[i][j]),sum+=w[i][j];
        }
        memset(head,-1,sizeof(head));
        e=0;
        int s=0,t=n*m+1;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                int tmp = (i-1)*m+j;
                if((i+j)&1)
                {
                    add(tmp,t,w[i][j]);continue;
                }
                else
                    add(s,tmp,w[i][j]);
                for(int k=0;k<4;k++)
                {
                    int x = go[k][0]+i;
                    int y = go[k][1]+j;
                    if(x>=1&&y>=1&&x<=n&&y<=m)
                    {
                        add(tmp,(x-1)*m+y,inf);
                    }
                }
            }
        }
        int tmp = sap(s,t,n*m+2);
        printf("%d\n",sum-tmp);
    }
    return 0;
}
