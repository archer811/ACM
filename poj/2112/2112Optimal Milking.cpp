#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int k,c,m;
int d[350][350];
int a[250*250];
#define vm 300
#define em 300000
const int inf = 0x3fffffff;
struct E
{
    int to,next,cap;
}edge[em];
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
        for(int &i=cur[u];i!=-1;i=edge[i].next)
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
                    for(u=pre[u];v!=s;v=u,u=pre[u])
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
        for(int i=head[u];i!=-1;i=edge[i].next)
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
int f(int mid)
{
    init();
    int i,j;
    for(i=1;i<=k;i++)
    {
        for(j=k+1;j<=k+c;j++)
        {
            if(d[i][j]<=mid)
                addedge(i,j,inf);
        }
    }
    for(i=1;i<=k;i++)
        addedge(0,i,m);
    for(i=k+1;i<=k+c;i++)
        addedge(i,k+c+1,1);
    if(sap(0,k+c+1,k+c+2)==c)return 1;
    return 0;
}
int main()
{
    int i,j,t;
    while(scanf("%d%d%d",&k,&c,&m)!=EOF)
    {
        t  =k +c;
        for(i=1;i<=t;i++)
        {
            for(j=1;j<=t;j++)
            {
                scanf("%d",&d[i][j]);
                if(d[i][j]==0&&i!=j)d[i][j]=inf;
            }
        }
        for(int g=1;g<=t;g++)
        {
            for(i=1;i<=t;i++)
            {
                for(j=1;j<=t;j++)
                {
                    if(d[i][j]>d[i][g]+d[g][j])
                        d[i][j]=d[i][g]+d[g][j];
                }
            }
        }
        int g=0;
        for(i=1;i<=t;i++)
        {
            for(j=1;j<=t;j++)
            {
                a[g++]=d[i][j];
            }
        }
        sort(a,a+g);
        g = unique(a,a+g)-a;
        int l =0,r = g-1;
        int ans=-1;
//        for(i=0;i<g;i++)
//            cout<<i<< " "<<a[i]<<endl;

        while(l<=r)
        {
            int mid = (l+r)>>1;
            int tmp = f(a[mid]);
            //cout<<a[mid]<<"&&"<<tmp<<endl;
            if(tmp)
            {
                r=mid-1;ans=a[mid];
            }
            else l=mid+1;
        }
        printf("%d\n",ans);
    }
}
