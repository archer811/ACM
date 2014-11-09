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
} edge[maxn*maxn*2];
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
    int yanse,num,t;
} now,next;
queue<xy>q;
int spfa()
{
    int i,j;
    // d[1][3]=0;
    while(!q.empty())q.pop();
    now.num=1;
    now.yanse=0;
    now.t=0;
    q.push(now);
    //d[1][0]=d[1][2]=d[1][1]=0;
    while(!q.empty())
    {
        now = q.front();
        q.pop();
        int u = now.num;
        int yanse=now.yanse;
        int t = now.t;
        for(i=head[u]; i!=-1; i=edge[i].next)
        {
            int v = edge[i].to;
            int w = edge[i].w;
            if(w==yanse)continue;//&&u!=1

            if(d[v][w]==0)
            {
                if(v==n)return t+1;
                d[v][w]=1;
                next.num=v;
                next.yanse=w;
                next.t=t+1;
                q.push(next);
            }
        }
    }
    return -1;
}
int main()
{
    int i,j,k;
    int x,y,c;
    cin>>n>>m;

    memset(head,-1,sizeof(head));
    tot=0;
    memset(d,0,sizeof(d));
    for(i=0; i<m; i++)
    {
        scanf("%d%d%d",&x,&y,&c);
        add(x,y,c);
        //add(y,x,c);
    }

    int ans = spfa();;
    printf("%d\n",ans);
}
