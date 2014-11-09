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
const int maxn = 205;
const int maxm = 1000006;
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
int head[maxn],tot,d[maxn],s,t;
void add(int u,int v,int cap)
{
    edge[tot]=Edge(v,cap,head[u]);
    head[u]=tot++;
    edge[tot]=Edge(u,0,head[v]);
    head[v]=tot++;
}
bool bfs()
{
    queue<int>q;
    q.push(s);
    memset(d,-1,sizeof(d));
    d[s]=0;
    while(!q.empty())
    {
        int u = q.front();q.pop();
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].to;
            if(d[v]==-1&&edge[i].cap>0)
            {
                q.push(v);
                d[v]=d[u]+1;
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
char S[1000];
int main()
{
    int i,j,n,np,nc,m;
    while(scanf("%d%d%d%d",&n,&np,&nc,&m)!=EOF)
    {
        memset(head,-1,sizeof(head));
        tot=0;
        s=0;t=n+1;
        int u,v,z;
        for(i=1;i<=m;i++)
        {
            scanf("%s",S);
            int len = strlen(S);
            u=0;v=0;z=0;
            int flag1=0,flag2=0;
            for(j=0;j<len;j++)
            {
                if(S[j]>='0'&&S[j]<='9')
                {
                    if(flag1==0)u=u*10+S[j]-'0';
                    else if(flag1&&flag2==0)v=v*10+S[j]-'0';
                    else if(flag1&&flag2)z=z*10+S[j]-'0';
                }
                else if(S[j]==',')flag1=1;
                else if(S[j]==')')flag2=1;
            }
            u++;v++;
            //cout<<i<<" "<<u<<" "<<v<<" "<<z<<endl;
            add(u,v,z);
        }
        for(i=1;i<=np;i++)
        {
            scanf("%s",S);
            int len = strlen(S);
            u=0;z=0;
            int flag1=0;
            for(j=0;j<len;j++)
            {
                if(S[j]>='0'&&S[j]<='9')
                {
                    if(flag1==0)u=u*10+S[j]-'0';
                    else if(flag1)z=z*10+S[j]-'0';
                }
                else if(S[j]==')')flag1=1;
            }
            u++;
            add(s,u,z);
        }
        for(i=1;i<=nc;i++)
        {
            scanf("%s",S);
            int len = strlen(S);
            u=0;z=0;
            int flag1=0;
            for(j=0;j<len;j++)
            {
                if(S[j]>='0'&&S[j]<='9')
                {
                    if(flag1==0)u=u*10+S[j]-'0';
                    else if(flag1)z=z*10+S[j]-'0';
                }
                else if(S[j]==')')flag1=1;
            }
            u++;
            add(u,t,z);
        }
        printf("%d\n",maxflow());
    }
    return 0;
}
