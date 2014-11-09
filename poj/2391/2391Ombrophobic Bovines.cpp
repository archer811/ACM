#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define ll __int64
int f,p;
const ll _inf = (ll)(1000000000)*(ll)(1000);
const int N = 205;
ll d[N][N];
int a[N],b[N];
void init()
{
    for(int i=1; i<=f; i++)
    {
        d[i][i]=0;
        for(int j=i+1; j<=f; j++)
        {
            d[i][j]=d[j][i]=_inf;
        }
    }
}
ll _min(ll a,ll b)
{
    if(a>b)return b;
    return a;
}
ll _max(ll a,ll b)
{
    if(a>b)return a;
    return b;
}
#define vm 100005
#define em 300000
const int inf = 0x3fffffff;
struct E
{
    int to,next,cap;
} edge[em];
int head[vm],gap[vm],dist[vm],cur[vm],pre[vm];
int e;
void _init()
{
    e=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int c)
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
void build(ll mid)
{
    _init();
    int i,j;
    for(i=1; i<=f; i++)
    {
        addedge(0,i,a[i]);
        addedge(i+f,f*2+1,b[i]);
        for(j=1; j<=f; j++)
        {
            if(mid>=d[i][j])
            {
                addedge(i,j+f,inf);
            }

        }
    }
}
ll g[N*N+1];
int main()
{
    int i,j,k,_a,_b;
    ll c;
    while(scanf("%d%d",&f,&p)!=EOF)
    {
        init();
        int sum=0;
        for(i=1; i<=f; i++)
            scanf("%d%d",&a[i],&b[i]),sum+=a[i];
        for(i=1; i<=p; i++)
        {
            scanf("%d%d%I64d",&_a,&_b,&c);
            d[_a][_b]=_min(d[_a][_b],c);
            d[_b][_a]=d[_a][_b];
        }
//       for(i=1;i<=f;i++)
//       {
//           for(j=1;j<=f;j++)
//            cout<<d[i][j]<< " ";
//           cout<<endl;
//       }
        for(k=1; k<=f; k++)
        {
            for(i=1; i<=f; i++)
            {
               // if(i==j||d[i][j]==_inf)continue;
                for(j=1; j<=f; j++)
                {
                    d[i][j]=_min(d[i][k]+d[k][j],d[i][j]);
                }
            }
        }
        int t=0;
        for(i=1; i<=f; i++)
        {
            for(j=1; j<=f; j++)
            {
                if(d[i][j]<_inf)
                    g[t++]=d[i][j];
            }
        }

//       for(i=1;i<=f;i++)
//       {
//           for(j=1;j<=f;j++)
//            cout<<d[i][j]<< " ";
//           cout<<endl;
//       }g+

         sort(g,g+t);
         t = unique(g,g+t)-g;
//         for(i=0;i<t;i++)
//            cout<<g[i]<<endl;
        int l =0,r = t-1;
        ll ant=-1 ;
        while(l<=r)
        {
            int mid = (l+r)/2;
            build(g[mid]);
            int tmp = sap(0,f*2+1,f*2+2);
//           cout<<g[mid]<<" "<<tmp<<endl;
            if(tmp==sum)
                r = mid-1,ant = g[mid];
            else l = mid+1;
        }
            printf("%I64d\n",ant);
    }
}
