#include<cstdio>
#include<cstring>
#include<queue>
#define inf 100000000
using namespace std;
int n,m,s,t;
int head[1200],e,head1[1200];
bool vis[1200],ok[1200];
int dis[1200],mon[1200],times[1200];
struct array
{
    int to,w,d,next;
} edge[22000];
void addedge(int u,int v,int w,int d)
{
    if(head[u]!=-1 && edge[head[u]].w<w)
        return;
    if(head[u]!=-1 && edge[head[u]].w>w)
        head[u]=-1;
    edge[e].to=v;
    edge[e].d=d;
    edge[e].w=w;
    edge[e].next=head[u];
    head[u]=e++;
}
int SPFA(int u)
{
    int i,j;
    memset(vis,0,sizeof(vis));
    memset(times,0,sizeof(times));
    for(i=0; i<n; i++)
    {
        dis[i]=mon[i]=inf;
    }
    queue<int>que;
    que.push(u);
    vis[u]=1;
    dis[u]=mon[u]=0;
    times[u]++;
    while(!que.empty())
    {
        int tem=que.front();
        que.pop();
        vis[tem]=0;                   //把这句移到这里可以把负的自环判断出来
        if(times[tem]>n)
            return 1;
        for(i=head[tem]; i!=-1; i=edge[i].next)
        {
            int v=edge[i].to;
            if(!ok[v])
                continue;
            if(mon[v]>mon[tem]+edge[i].w || (mon[v] == mon[tem]+edge[i].w && dis[v]>dis[tem]+edge[i].d))
            {
                mon[v]=mon[tem]+edge[i].w;
                dis[v]=dis[tem]+edge[i].d;
                if(!vis[v])
                {
                    que.push(v);
                    vis[v]=1;
                    times[v]++;
                }
            }
        }
    }
    return 0;
}
void dfs(int a)
{
    int i,yes=0;
    ok[a]=1;
    for(i=head1[a]; i!=-1; i=edge[i].next)
    {
        if(!ok[edge[i].to])
            dfs(edge[i].to);
    }
}
char str[1000];
int main()
{
    int i,j;
    while(scanf("%d %d %d %d",&n,&m,&s,&t)==4)
    {
        memset(head,-1,sizeof(head));
        e=0;
        for(i=1; i<=m; i++)
        {
            int u,v,f1,l,f2;
            scanf("%s",str);
            sscanf(str,"(%d,%d,%d[%d]%d)",&u,&v,&f1,&l,&f2);
            addedge(u,v,f1,l);
            addedge(v,u,f2,l);
        }
        memset(ok,0,sizeof(ok));
        memset(head1,-1,sizeof(head1));
        for(i=0; i<n; i++)                               //建立反图
        {
            for(j=head[i]; j!=-1; j=edge[j].next)
            {
                edge[e].to=i;
                edge[e].next=head1[edge[j].to];
                head1[edge[j].to]=e++;
            }
        }
        dfs(t);                                         //搜索所有能够到达t的点并标记
        int kk=SPFA(s);
        if(mon[t]==inf)
            printf("VOID\n");
        else if(kk==0)
            printf("%d %d\n",mon[t],dis[t]);
        else
            printf("UNBOUND\n");
    }
    return 0;
}
