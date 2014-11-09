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
int g[15];
const int maxn = 19682+10;
int e[15],f[15];
struct Edge
{
    int next,to,z,d;
} edge[10005];
int head[105],tot;
void add(int u,int v,int z,int d)
{
    edge[tot].to=v;
    edge[tot].z=z;
    edge[tot].d=d;
    edge[tot].next=head[u];
    head[u]=tot++;
}
const int inf = 0x3fffffff;
int d[105][maxn],d2[105][maxn];
int mark[105];
int n,m;
struct o
{
    int dit,v,ans;
    bool friend operator <(o x,o y)
    {
        return x.ans>y.ans;
    }
} now,next;
int vis[105];
int sum=0;
void bfs()
{
    int i,j;
    priority_queue<o>q;
    now.dit=0;
    now.v=0;
    now.ans=0;
    q.push(now);
    while(!q.empty())
    {
        now = q.top();
        q.pop();
        sum++;
        int u = now.dit;
        int val = now.v;
        //cout<<u<<"*"<<val<<endl;
        for(i=head[u]; i!=-1; i=edge[i].next)
        {
            int v=edge[i].to;
            j = edge[i].z;

            int tmp =(val%g[j+1])/g[j];
            int next_cost=0;
            int next_val=val;
            if(tmp==0)
            {
                next_cost+=0;
                next_val+=g[j];
            }
            else if(tmp==1)
            {
                next_cost+=e[j];
                next_val+=g[j];
            }
            else if(tmp>=2)
            {
                next_cost+=f[j];
            }
            next.dit=v;
            next.v=next_val;
            if(d[v][next_val]==-1||d[v][next_val]>next_cost+d[u][val])
            {
                cout<<v<<"*"<<next_val<<"  "<<next_cost<<endl;
                //cout<<next_val%g[j+1]<<endl;
                d[v][next_val]=next_cost+d[u][val];
                next.ans=next_cost+d[u][val];
                //if(vis[v][next_val]==0)
                {
                   // cout<<v<<"()"<<next_val<<"  "<<next_cost+d[u][val]<<endl;
                   // vis[v][next_val]=1;
                    q.push(next);
                }

            }
        }
    }
}
void bfs1()
{
    queue<int>q;
    q.push(0);
    memset(d2,0,sizeof(d2));
    memset(vis,0,sizeof(vis));
    vis[0]=1;
    d2[0][0]=0;
    while(!q.empty())
    {
        int u = q.front();q.pop();
        vis[u]=0;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            if(d2[v][0]==-1||d2[v][0]>d2[u][0]+edge[i].d)
            {
                d2[v][0]=d2[u][0]+edge[i].d;
                if(vis[v]==0)
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<maxn;j++)
        {
            if(d[i][j]>0)
            {
                cout<<i<<"()"<<j<<"  "<<d[i][j]<<endl;
            }
        }
    }
}
int main()
{
    int i,j;
//    freopen("test0 (1).in","r",stdin);
//    freopen("outs.txt","w",stdout);
    j=1;
    //int sum=0;
    for(i=0; i<=9; i++)
    {
        g[i]=j;
        //sum+=2*g[i];
        j*=3;
    }
    //cout<<sum<<endl;
    int q;
    while(scanf("%d%d%d",&n,&m,&q)!=EOF)
    {
        memset(d,-1,sizeof(d));
        for(i=0; i<m; i++)
            scanf("%d",&e[i]);
        for(i=0; i<m; i++)
            scanf("%d",&f[i]);
        memset(head,-1,sizeof(head));
        tot=0;
        for(i=0; i<q; i++)
        {
            int x,y,z,d;
            scanf("%d%d%d%d",&x,&y,&z,&d);
            add(x,y,z,d);
        }
        bfs1();
        bfs();
        int M=-1;
        for(i=0; i<maxn; i++)
        {
            if(d[n-1][i]==-1)continue;
            if(M==-1||d[n-1][i]<M)
            {
                //cout<<d[n-1][i]<<endl;
                M=d[n-1][i];
            }
        }
        printf("%d\n",M);
        //cout<<sum<<"*"<<endl;
    }
    return 0;
}
