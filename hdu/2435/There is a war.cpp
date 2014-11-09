#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#define eps 1e-9
#define pi acos(-1.0)
using namespace std;
#define vm 300
#define em 300000
const int inf = 0x3fffffff;
int val[em];
struct E
{
    int to,next,cap;
} edge[em];
int head[vm],gap[vm],dist[vm],cur[vm],pre[vm];
int e;
void init()
{
    e=0;
    memset(head,-1,sizeof(head));
}
int mark[105][105];
int vis[105];
void addedge(int u,int v,int c)
{
    edge[e].cap=c;
    edge[e].next=head[u];
    edge[e].to=v;
    mark[u][v]=e;
    head[u]=e++;
    edge[e].cap=0;
    edge[e].next=head[v];
    edge[e].to=u;
    head[v]=e++;
}
int n,m;
int ff[105][105];
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
        for(int &i=cur[u]; i!=-1; i=edge[i].next)
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
                    for(u=pre[u]; v!=s; v=u,u=pre[u])
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
        for(int i=head[u]; i!=-1; i=edge[i].next)
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
queue<int>q;
vector<int>ct;
void bfs()
{
    while(!q.empty())q.pop();
    q.push(1);
    vis[1]=1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=head[u]; i!=-1; i=edge[i].next)
        {
            int v = edge[i].to;
            if(vis[v]==0&&edge[i].cap)
            {
                vis[v]=1;
                q.push(v);
            }
        }
    }
    for(int i= 2; i<n; i++)
    {
        if(vis[i]==0)continue;
        for(int j=head[i]; j!=-1; j=edge[j].next)
        {
            int v = edge[j].to;
            if(vis[v])continue;
            if(v==1||v==n)continue;
            if(ff[i][v]==0&&vis[v]!=vis[i]&&edge[j].cap==0)
            {
                ct.push_back(j);
                ff[i][v]=1;
                //cout<<"&&&&&"<<i<<" "<<v<<endl;
            }
        }
    }
    for(int i=2;i<n;i++)
    {
        if(vis[i]==0)continue;
        for(int j=2;j<n;j++)
        {
            if(vis[j])continue;
            if(i==j)continue;
            if(mark[i][j]!=-1)continue;
            ct.push_back(e);
            addedge(i,j,0);
        }
    }
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    int u,v,d;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        init();
        memset(mark,-1,sizeof(mark));
        memset(val,0,sizeof(val));
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&d);
            addedge(u,v,d);
        }
        for(i=0; i<e; i++)
            val[i]=edge[i].cap;
        int ans = sap(1,n,n);
        memset(vis,0,sizeof(vis));
        ct.clear();
        bfs();
        int tmp = ans;
        for(i=0; i<ct.size(); i++)
        {
            for(j=0; j<e; j++)
                edge[j].cap=val[j];
            edge[ct[i]].cap=inf;
            ans = max(ans,sap(1,n,n));
        }
        printf("%d\n",ans);
    }
    return 0;
}
