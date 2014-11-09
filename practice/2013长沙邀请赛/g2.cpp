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
const int inf = 999999;
int c[maxn],s[maxn];
struct array
{
    int index,t,val;
} now,next;
queue<array>q;
int dp[maxn][305];
int n,m,T;
int dis[maxn][maxn];
int head[maxn],tot;
struct oo
{
    int to,next,d;
} edge[100005*2];
void add(int u,int v,int d)
{
   // cout<<u<<" * "<<v<<" "<<d<<endl;
    edge[tot].to=v;
    edge[tot].d=d;
    edge[tot].next=head[u];
    head[u]=tot++;
}
void bfs()
{
    while(!q.empty())q.pop();
    now.index = n;
    now.t=0;
    now.val=0;
    dp[now.index][now.t]=now.val;
    q.push(now);
    while(!q.empty())
    {
        now = q.front();
        q.pop();
        int u = now.index;
        for(int i=head[u]; i!=-1; i=edge[i].next)
        {
            int v = edge[i].to;
            if(now.t+edge[i].d<=T)
            {
                next.index = v;
                next.t = now.t+edge[i].d;
                next.val=now.val+s[v];
                //cout<<u<<" & "<<v<<" "<<next.t<<" "<<next.val<<endl;
                if(dp[next.index][next.t]<next.val)
                {
                    dp[next.index][next.t]=next.val;
                    q.push(next);
                }
            }
        }
    }
}
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
        memset(head,-1,sizeof(head));
        tot=0;
        for(i=0; i<n; i++)
            scanf("%d",&c[i]);
        for(i=0; i<n; i++)
            scanf("%d",&s[i]);
        s[n]=s[n+1]=0;
        memset(dp,-1,sizeof(dp));
        int u,v,d;
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d",&u,&v,&d);
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
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(i!=j&&dis[i][j]<inf&&s[i]<s[j])
                {
                    add(i,j,dis[i][j]+c[j]);
                    //cout<<i<<" "<<j<<"  "<<dis[i][j]+s[j]<<endl;
                }

            }
        }
        for(i=0; i<n; i++)
        {
            add(n,i,dis[st][i]+c[i]);
        }
        for(i=0; i<n; i++)
        {
            add(i,n+1,dis[i][e]);
        }
        bfs();
       // cout<<"--"<<endl;
        int ans=0;
        for(i=0; i<=T; i++)
        {
            if(ans<dp[n+1][i])
            {
                ans=dp[n+1][i];
               // cout<<i<<"#"<<dp[n+1][i]<<endl;
            }

        }
        printf("Case #%d:\n%d\n",++cas,ans);
    }
    return 0;
}
