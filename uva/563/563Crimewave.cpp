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
const int maxn = 10000;
const int maxm = 5000006;
const int inf = 0x3fffffff;
struct Edge
{
    int to,next,cap;
    Edge(){};
    Edge(int tt,int cc,int nx)
    {
        to=tt;cap=cc;next=nx;
    };
}edge[maxm];
int head[maxn],d[maxn],tot,s,t;
void add(int u,int v,int cap)
{
    edge[tot]=Edge(v,cap,head[u]);
    head[u]=tot++;
    edge[tot]=Edge(u,0,head[v]);
    head[v]=tot++;
}
bool bfs()
{
    memset(d,-1,sizeof(d));
    queue<int>q;
    q.push(s);
    d[s]=0;
    int fuck=0;
    while(!q.empty())
    {
        int u = q.front();q.pop();
        fuck++;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].to;
            if(d[v]==-1&&edge[i].cap>0)
            {
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
    return d[t]!=-1;
}
int dfs(int u,int a)
{
    if(u==t||a==0)return a;
    int flow=0,f;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(d[v]==d[u]+1&&(f=dfs(v,min(a,edge[i].cap)))>0)
        {
            edge[i].cap-=f;
            edge[i^1].cap+=f;
            flow+=f;
            a-=f;
            if(a==0)break;
        }
    }
    if(flow==0)
    d[u]=-1;
    return flow;
}
int maxflow()
{
    int flow=0;
    while(bfs())
    {
        flow+=dfs(s,inf);
    }
    return flow;
}
int go[][2]={-1,0,1,0,0,1,0,-1};
int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,num;
        scanf("%d%d%d",&n,&m,&num);
        memset(head,-1,sizeof(head));
        tot=0;
        s=0;t=n*m*2+1;
        int a,b;
        for(i=0;i<num;i++)
        {
            scanf("%d%d",&a,&b);
            add(s,(a-1)*m+b,1);
//            cout<<s<<" "<<(a-1)*m+b<<endl;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                for(int k=0;k<4;k++)
                {
                    int x = go[k][0]+i;
                    int y = go[k][1]+j;
                    if(x>=1&&y>=1&&x<=n&&y<=m)
                    {
                        add(n*m+(x-1)*m+y,(i-1)*m+j,inf);
//                        cout<<n*m+(x-1)*m+y<<" "<<
//                        (i-1)*m+j<<endl;
                    }
                }
                add((i-1)*m+j,(i-1)*m+j+n*m,1);
            }
        }
        for(i=1;i<=m;i++)
        {
            add(n*m+i,t,1);
            add(n*m+(n-1)*m+i,t,1);
            //cout<<n*m+i<<" "<<t<<endl;
            //cout<<n*m+(n-1)*m+i<<" "<<t<<endl;
        }
        for(i=2;i<n;i++)
        {
            add(n*m+(i-1)*m+1,t,1);
            add(n*m+(i-1)*m+m,t,1);
//            cout<<n*m+(i-1)*m+1<<" "<<t<<endl;
//            cout<<n*m+(i-1)*m+m<<" "<<t<<endl;
        }
//        cout<<"o"<<endl;
        int tmp = maxflow();
        if(tmp>=num)puts("possible");
        else puts("not possible");
    }
    return 0;
}
