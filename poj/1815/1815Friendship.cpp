#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int n,s,t;
const int N = 205;
int v[N][N];
#define vm 600
#define em 300000
const int inf = 0x3fffffff;
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
int mp[N][N];
void build()
{
    init();
    for(int i=1; i<=n; i++)
    {
        if(i==s||i==t)
            addedge(i,i+n,inf);
        else
            addedge(i,i+n,1);
        for(int j=i+1; j<=n; j++)
        {
            if(v[i][j])
            {
                addedge(j+n,i,inf);
                addedge(i+n,j,inf);
            }
        }
    }
}
void change(int k)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            mp[i][j]=v[i][j];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==k||j==k)
                v[i][j]=0;
        }
    }
}
void back()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            v[i][j]=mp[i][j];
    }
}
int ans[N];
int main()
{
    int i,j,k;
    while(scanf("%d%d%d",&n,&s,&t)!=EOF)
    {

        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
                scanf("%d",&v[i][j]);
        }
        if(v[s][t])
        {
            puts("NO ANSWER!");
            continue;
        }
        build();
        int tmp = sap(s,n+t,n*2);
        printf("%d\n",tmp);
        if(tmp==0)continue;
        j=0;
        for(i=1; i<=n; i++)
        {
            if(i==s||i==t)continue;
            change(i);
            build();
            int f = sap(s,n+t,n*2);
            //cout<<i<<" "<<f<<endl;
            if(f<tmp)
            {
                tmp--;
                ans[j++]=i;
            }
            else back();
        }
        for(i=0;i<j;i++)
        {
            if(i==0)printf("%d",ans[i]);
            else printf(" %d",ans[i]);
        }puts("");
    }
}
