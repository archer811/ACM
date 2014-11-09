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
int s,t;
const int maxn = 200;
const int inf = 0x3fffffff;
int head[maxn],d[maxn],tot;
const int maxm = maxn*maxn;
struct Edge
{
    int to,next,cap;
    Edge() {};
    Edge(int tt,int cc,int nx)
    {
        to=tt;
        cap=cc;
        next=nx;
    };
} edge[maxm];
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
        int u = q.front();
        q.pop();
        for(int i=head[u]; i!=-1; i=edge[i].next)
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
    for(int i=head[u]; i!=-1; i=edge[i].next)
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
char S[10000];
int main()
{
    int i,j;
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        s=0;
        t=n+m+1;
        memset(head,-1,sizeof(head));
        tot=0;
        int sum=0;
        getchar();
        for(i=1; i<=n; i++)
        {
            gets(S);
            int len = strlen(S);
            int num=0,f=0,mark=0;
            S[len++]=' ';


            for(j=0; j<len; j++)
            {
                if(S[j]>='0'&&S[j]<='9')
                {
                    num=num*10+S[j]-'0';
                    f=1;
                }
                else
                {
                    if(f)
                    {
                        f=0;
                        if(mark==0)
                        {
                            sum+=num;
                            add(s,i,num);
                            //cout<<s<<"*"<<i<<endl;
                            mark=1;
                        }
                        else
                        {
                            add(i,num+n,inf);
                            //cout<<i<<"()"<<num+n<<endl;
                        }
                        num=0;
                    }
                }
            }
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d",&j);
            add(n+i,t,j);
        }
        int tmp = maxflow();
        printf("%d\n",sum-tmp);
    }
    return 0;
}
