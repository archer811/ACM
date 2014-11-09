#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 210;
const int maxm = 10*maxn*maxn;
int n,m;
struct array
{
    int x,y,l,c;
}s[maxm];
int head[maxn];
struct E
{
    int to,next,cap;
}edge[maxm*2];
const int inf = 0x3fffffff;
int gap[maxn],dist[maxn],cur[maxn],pre[maxn],e;
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
int ans[maxm],g;
int main()
{
    int i,j,k,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(head,-1,sizeof(head));
        e=0;
        int ss=0,tt=n+1;
        int sum=0;
        g=0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d%d",&s[i].x,&s[i].y,&s[i].l,&s[i].c);
            addedge(ss,s[i].y,s[i].l);
            addedge(s[i].x,tt,s[i].l);
            sum += s[i].l;
            ans[g++]=e;
            addedge(s[i].x,s[i].y,s[i].c-s[i].l);
        }
        if(sap(0,n+1,n+2)!=sum)
            puts("NO");
        else
        {
            puts("YES");
            for(i=0;i<g;i++)
            {
                printf("%d\n", s[i].l + edge[ans[i]^1].cap);
            }
        }
    }
}
