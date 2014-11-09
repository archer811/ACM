#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 205;
const int inf = 0x3fffffff;
int c[maxn],s[maxn];
struct array
{
    int index,t,val;
} now,next;
queue<array>q;
int head[maxn];
struct oo
{
    int to,next,d;
} edge[100005*2];
int tot;
int dp[maxn][305];
void add(int u,int v,int d)
{
    edge[tot].to=v;
    edge[tot].d=d;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int n,m,T;
struct preedge
{
    int u,v,w;
} ee[1005];
void bfs(int st,int ed)
{
    while(!q.empty())q.pop();
    now.index=st;
    now.t=0;
    now.val=0;
    q.push(now);
    dp[st][now.t]=0;
    now.t=c[st];
    now.val=s[st]-1;
    q.push(now);
    dp[st][now.t]=now.val;
    while(!q.empty())
    {
        now = q.front();
        q.pop();
        int u = now.index;
        int t = now.t;
        for(int i=head[u]; i!=-1; i=edge[i].next)
        {
            int v = edge[i].to;
            if(t+c[v]+edge[i].d<=T)
            {
                next.index = v;
                next.t = t+c[v]+edge[i].d;
                next.val=now.val+s[v]-1;
                if(dp[v][next.t]<next.val)
                {
                    q.push(next);
                    dp[v][next.t]=next.val;
                }
            }

            if(t+edge[i].d<=T)
            {
                next.index=v;
                next.t = t+edge[i].d;
                next.val=now.val;
                if(dp[v][next.t]<now.val)
                {
                    q.push(next);
                    //cout<<"OO"<<next.index<<" "<<next.Max
                    // <<" "<<next.t<<" "<<next.val<<endl;
                    dp[v][next.t]=now.val;
                }
            }
        }
    }
}
int dis[maxn][maxn];
int main()
{
    int i,j,t,st,e;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        scanf("%d%d%d%d%d",&n,&m,&T,&st,&e);
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(i==j)dis[i][j]=0;
                else dis[i][j]=inf;
            }
        }
        for(i=0; i<n; i++)
            scanf("%d",&c[i]);
        for(i=0; i<n; i++)
            scanf("%d",&s[i]),s[i]++;
        memset(head,-1,sizeof(head));
        tot=0;
        memset(dp,-1,sizeof(dp));
        int u,v,d;
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d",&u,&v,&d);
            ee[i].u=u;
            ee[i].v=v;
            ee[i].w=d;
            if(dis[u][v]>d)
                dis[u][v]=dis[v][u]=d;
        }

        for(int k=0; k<n; k++)
        {
            for(i=0; i<n; i++)
            {
                for(j=0; j<n; j++)
                {
                    if(dis[i][j]>dis[i][k]+dis[k][j])
                    {
                        dis[i][j]=dis[i][k]+dis[k][j];
                    }
                }
            }
        }
        for(i=0; i<m; i++)
        {
            if(ee[i].w==dis[ee[i].u][ee[i].v]&&s[ee[i].u]<s[ee[i].v])
            {
                add(ee[i].u,ee[i].v,ee[i].w);
                cout<<ee[i].u<<" "<<ee[i].v<<endl;
            }

        }
        bfs(st,e);
        int ans=0;
        for(j=0; j<=T; j++)
        {
            if(ans<dp[e][j])
                ans=dp[e][j];
        }
        printf("Case #%d:\n%d\n",++cas,ans);
    }
    return 0;
}
