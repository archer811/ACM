#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
const int inf = 0x3fffffff;
int n,m;
const int maxn = 205;
int head[maxn];
int d[maxn][4];
struct array
{
    int to,next,w;
}edge[maxn*maxn*2];
int tot=0;
void add(int x,int y,int c)
{
    edge[tot].to=y;
    edge[tot].w=c;
    edge[tot].next=head[x];
    head[x]=tot++;
}
struct xy
{
    int yanse,num;
}now,next;
queue<xy>q;
void spfa()
{
    int i,j;
    d[1][3]=0;
    while(!q.empty())q.pop();
    now.num=1;now.yanse=3;q.push(now);
//    now.yanse=1;q.push(now);
//    now.yanse=2;q.push(now);
    while(!q.empty())
    {
        now = q.front();q.pop();
        int u = now.num;
        for(i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].to;
            int w = edge[i].w;
            if(w==now.yanse)continue;//&&u!=1
            if(d[v][w]>d[u][now.yanse]+1)
            {
                d[v][w]=d[u][now.yanse]+1;
                next.num=v;
                next.yanse=w;
                q.push(next);
            }
        }
    }
}
int main()
{
    int i,j,k;
    int x,y,c;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(head,-1,sizeof(head));
        tot=0;
        for(i=1;i<=n;i++)
            d[i][0]=d[i][1]=d[i][2]=d[i][3]=inf;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&c);
            add(x,y,c-1);
            //add(y,x,c-1);
        }
        spfa();
        int ans = d[n][0];
        ans = min(ans,d[n][1]);
        ans = min(ans,d[n][2]);
        if(ans>=inf)puts("-1");
        else printf("%d\n",ans);
        //cout<<d[n][0]<<" "<<d[n][1]<<" "<<d[n][2]<<endl;
    }
}
