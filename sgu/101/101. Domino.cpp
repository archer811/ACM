#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int head[10],vis[10],tot;
struct array
{
    int to,next,vis;
}edge[500];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next = head[u];
    edge[tot].vis=0;
    head[u]=tot++;
}
int ans[500],g;
bool ok;
int mark[10];
void dfs(int u)
{
    int i,j;
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        if(!edge[i].vis)
        {
            edge[i].vis=1;
            edge[i^1].vis=1;

            dfs(edge[i].to);
            ans[g++]=i;
        }
    }
}
void Dfs(int u)
{
    vis[u]=1;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int j = edge[i].to;
        if(vis[j])continue;
        vis[j]=1;
        Dfs(j);
    }
}
int main()
{
    int i,j,n,a,b;
    while(scanf("%d",&n)!=EOF)
    {
        memset(head,-1,sizeof(head));
       // memset(mark,0,sizeof(mark));
        tot =0;
        for(i=0;i<10;i++)
            vis[i]=0,mark[i]=0;
        for(i=0;i<n;i++)
        {
           scanf("%d%d",&a,&b);
           add(a,b);
           add(b,a);
           vis[a]++;vis[b]++;
           mark[a]=1;mark[b]=1;
        }
        int count =0,flag=-1;
        for(i=0;i<10;i++)
        {
           if(vis[i]%2)count++,flag=i;
        }
        if(count>2)
        {
            printf("No solution\n");
            continue;
        }
        if(flag==-1)
        {
            for(i=0;i<10;i++)
            {
                if(vis[i]){flag=i;break;}
            }
        }
        for(i=0;i<=7;i++)
            vis[i]=0;
        Dfs(flag);
        for(i=0;i<7;i++)
        {
            if(mark[i]&&vis[i]==0)
                break;
        }
        if(i<7)
        {
            printf("No solution\n");
            continue;
        }
        g=0;
        dfs(flag);
        for(i=g-1;i>=0;i--)
        {
            if(ans[i]%2)printf("%d -\n",ans[i]/2+1);
            else printf("%d +\n",ans[i]/2+1);
        }
    }
}
