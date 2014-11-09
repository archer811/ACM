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
const int maxn = 5005;
const int maxm=100000+10;
struct array
{
    int to,next,ti;
} edge[maxm<<1];
int head[maxn],tot;
int d[5005][555],in[5005][555];
void add(int u,int v,int val)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    edge[tot].ti=val;
    head[u]=tot++;
}
int s,t,k;
struct oo
{
    int node,v;
} now,next;
void spfa()
{
    queue<oo>q;
    d[s][0]=0;
    now.node=s;
    now.v=0;
    q.push(now);
    memset(in,0,sizeof(in));
    in[s][0]=1;
    while(!q.empty())
    {
        now = q.front();
        q.pop();
        int u = now.node;
        int preval=now.v;
        in[u][preval]=0;
        for(int i=head[u]; i!=-1; i=edge[i].next)
        {
            int v = edge[i].to;
            int val=edge[i].ti;
            int tmp = preval+10;
            if(tmp>=k)tmp=k;
            if(d[v][tmp]==-1||d[v][tmp]>d[u][preval]+val)
            {
                d[v][tmp]=d[u][preval]+val;
                //if(in[v][tmp]==0)
                {
                    in[v][tmp]=1;
                    //cout<<v<<" * "<<tmp<<endl;
                    next.node=v;
                    next.v=tmp;
                    q.push(next);
                }
            }
        }
    }
}
int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(head,-1,sizeof(head));
        tot=0;
        int a,b,c;
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
            add(b,a,c);
        }
        scanf("%d%d%d",&s,&t,&k);
        memset(d,-1,sizeof(d));
        spfa();
        int ans=d[t][k];
        printf("%d\n",ans);
    }
    return 0;
}
