#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int inf= 0x3fffffff;
int n,m;
struct array
{
    int x,y,num;
}a[150],b[150];
const int S  =0;
int flat[300][300],way[150][150];
queue<int>que;
int pre[300],cnt[300],vis[300],dis[300];
void spfa()
{
    int i,j,k;
    while(!que.empty())que.pop();
    memset(pre,-1,sizeof(pre));
    memset(cnt,0,sizeof(cnt));
    memset(vis,0,sizeof(vis));
    for(i=0;i<=n+m;i++)
        dis[i]=inf;
    dis[0]=0;vis[0]=1;
    int mark=false;
    que.push(0);
    int u;
    /*
    while(!q.empty())
    {
        u = q.front();q.pop();vis[u]=0;
        for(i=0;i<=n+m;i++)
        {
            if(flag[u][i]==-1)continue;
            if(dis[i]>dis[u]+flag[u][i])
            {
                dis[i]=dis[u]+flag[u][i];
                pre[i]=u;
                if(vis[i]==0)
                {
                    vis[i]=1;cnt[i]++;q.push(i);
                }
                if(cnt[i]>n+m+1)
                {
                    mark=true;break;
                }
            }
        }
    }
    if(mark==false)
    {
        puts("OPTIMAL");
    }
    else
    {
        memset(vis,0,sizeof(vis));
        u = i;
        while(1)
        {
            if(vis[u]==0)
            {
                vis[u]=1;u=pre[u];
            }
            else {i=u;break;}
        }
        u=i;
        j=i;
        while(pre[j]!=i)
        {
            k=pre[j];
            if(k<j&&k!=0){g[j-n][k]--;}
            else if(k>j&&j!=0){g[k-n][j]++;}
            j=pre[j];
        }
        if(i<j&&i!=0){g[j-n][i]--;}
        else if(i>j&&j!=0){g[i-n][j]++;}
        printf("SUBOPTIMAL\n");
        for(i = 1; i <= n; i++)
            for(j = 1; j <= m; j++)
            {
                printf("%d",g[i][j]);
                if(j == m) printf("\n"); else printf(" ");
            }
    }*/
    bool flag = true;
    while(!que.empty() && flag)
    {
        i = que.front(); que.pop(); vis[i] = false;
        for(j = 0; j <= m+n; j++)
            if(flat[i][j] != inf && dis[i] + flat[i][j] < dis[j])
            {
                dis[j] = dis[i] + flat[i][j];
                pre[j] = i;
                if(!vis[j]) {vis[j] = true; que.push(j); cnt[j]++;}
                if(cnt[j] > n+m+1) {flag = false; break;}
            }
    }
    if(flag) printf("OPTIMAL\n");
    else
    {
        memset(vis,0,sizeof(vis));
        i = j;
        while(1)
        {
            if(!vis[i]) {vis[i] = true; i = pre[i];}
            else {j = i; break;}
        }
          i = j;
        while(pre[j] != i)
        {
            k = pre[j];
            if(k < j && k != S) way[j-m][k]--;
            else if(k > j && j != S) way[k-m][j]++;
            j = pre[j];
        }
        if(i < j && i != S) way[j-m][i]--;
        else if(i > j && j != S) way[i-m][j]++;
        printf("SUBOPTIMAL\n");
        for(i = 1; i <= n; i++)
            for(j = 1; j <= m; j++)
            {
                printf("%d",way[i][j]);
                if(j == m) printf("\n"); else printf(" ");
            }
    }
}
int main()
{
    int i,j,k;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].num);
        for(i=1;i<=m;i++)
            scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].num);
        for(i=1;i<=m;i++)way[i][0]=0;
         for(i = S; i <= n+m; i++)
        for(j = S; j <= n+m; j++)
            flat[i][j] = inf;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                scanf("%d",&way[i][j]);
                way[j][0]+=way[i][j];
            }
        }
        for(i=1;i<=m;i++)
        {
            if(way[i][0])flat[0][i]=0;
            if(b[i].num-way[i][0]>0)flat[i][0]=0;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                flat[i+m][j]=abs(a[i].x-b[j].x)+abs(a[i].y-b[j].y)+1;
                if(way[i][j])flat[j][i+m]=-flat[i+m][j];
            }
        }
        spfa();
    }
}
