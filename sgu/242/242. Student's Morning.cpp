#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
#define vm 300
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
int n,k;
int f[205][205];
int mark[205][205],num[205];
int main()
{
    int i,j,g;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        init();
        memset(f,-1,sizeof(f));
        int s=0,t = n+k+1;
        int ss=n+k+2,tt=n+k+3;
        for(i=1; i<=k; i++)
            num[i]=0;
        for (int i = 1; i <= n; i++)
            addedge(s, i, 1);
        for (int i = n+1; i <= n+k; i++)
        {
            addedge(i, tt, 2);
            addedge(ss, t, 2);
            addedge(i, t, inf);
        }
        addedge(t,s,inf);
        int tmp;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &j);
            while (j--)
            {
                scanf("%d", &tmp);
                f[i][tmp]=e;
                addedge(i, n+tmp, 1);
            }
        }
        tmp = sap(ss,tt,n+k+4);
        if(tmp<k*2)
            puts("NO");
        else
        {
            puts("YES");
            for(i=1; i<=n; i++)
            {
                for(j=1; j<=k; j++)
                {
                    //cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
                    if(f[i][j]!=-1)
                    {

                        int tmp = edge[f[i][j]^1].cap;
                        //cout<<(f[i][j]^1)<<"*"<<tmp<<endl;
                        int gg = edge[f[i][j]].to-n;
                        // cout<<gg<<endl;
                        if(tmp)mark[gg][num[gg]++]=i;
                    }
                }
            }
            for(i=1; i<=k; i++)
            {
                printf("%d",num[i]);
                for(j=0; j<num[i]; j++)
                {
                      printf(" %d",mark[i][j]);
                }
                puts("");
            }
        }
    }
}
