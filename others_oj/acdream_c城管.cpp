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
const int maxn = 10005;
const int maxm = 110000;
int h[maxn],h2[maxn],tot,tot2;
struct Edge
{
    int to,next,w;
}edge[maxm],edge2[maxm];
void add(int u,int v,int w)
{
    edge[tot].to=v;
    edge[tot].next=h[u];
    edge[tot].w=w;
    h[u]=tot++;
}
void add2(int u,int v,int w)
{
    edge2[tot2].to=v;
    edge2[tot2].next=h2[u];
    edge2[tot2].w=w;
    h2[u]=tot2++;
}
int in[maxn],d[maxn],d2[maxn];
const int inf = 0x3fffffff;
int n,m,dis[maxn];
void tuopo()
{
    int i,j;
    queue<int>q;
    for(i=0;i<n;i++)
    {
        d[i]=d2[i]=inf;
    }
    d[n-1]=0;
    q.push(n-1);
    while(!q.empty())
    {
        int u = q.front();q.pop();
        for(i=h2[u];i!=-1;i=edge2[i].next)
        {
            int v = edge2[i].to;
            int w = edge2[i].w;
            int tmp = d[u]+w;
            int tmp2 = d2[u]+w;
            if(tmp<d[v])
            {
                d2[v]=min(d2[v],d[v]);
                d[v]=tmp;
            }
            else if(tmp>=d[v]&&tmp<d2[v])
            {
                d2[v]=tmp;
            }

            if(tmp2<d[v])
            {
                d2[v]=min(d2[v],d[v]);
                d[v]=tmp2;
            }
            else if(tmp2>=d[v]&&tmp2<d2[v])
            {
                d2[v]=tmp2;
            }


            in[v]--;
            if(in[v]==0)
                q.push(v);
        }
    }
}
int IN[maxn];
void dfs()
{
    queue<int>q;
    int i,j;
    for(i=0;i<n;i++)
        dis[i]=inf;
    dis[0]=0;
    q.push(0);
    while(!q.empty())
    {
        int u = q.front();q.pop();
        for(i=h[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].to;
            if(dis[v]>dis[u]+edge[i].w)
            {
                dis[v]=dis[u]+edge[i].w;
            }
            IN[v]--;
            q.push(v);
        }
    }
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(h,-1,sizeof(h));
        memset(h2,-1,sizeof(h2));
        memset(in,0,sizeof(in));
        memset(IN,0,sizeof(IN));
        tot=0;tot2=0;
        int a,b,c;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
            add2(b,a,c);
            in[a]++;
            IN[b]++;
        }
        tuopo();
        for(i=0;i<n;i++)
        {
            cout<<i<<"()"<<d[i]<<"  "<<d2[i]<<endl;
        }
        dfs();
        int ans=inf;
        for(i=0;i<n;i++)
        {
            if(dis[i]>=inf||d2[i]>=inf)continue;
            if(dis[i]+d2[i]<ans)
                ans=dis[i]+d2[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
