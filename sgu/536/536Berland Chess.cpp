#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 33000;
const int inf = 0x3fffffff;
char s[16][16];
int n,m;
int go[][2]={-1,0,1,0,0,-1,0,1,-1,-1,-1,1,1,-1,1,1};
int nm[][2]={-1,2,-1,-2,1,2,1,-2,2,-1,2,1,-2,-1,-2,1};
int ans,sx,sy;
int is[16][16];
int head[maxn];
struct ll
{
    int to,next,w;
}edge[500000];
struct array
{
    int x,y;
}g[16];
int k;
int tot;
void add(int u,int v,int w)
{
    edge[tot].to=v;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot++;
}
struct xx
{
    int x,y,t;
    friend bool operator < (xx a,xx b)
    {
         return a.t>b.t;
    }
}tmp,next;
priority_queue<xx>q;
int vis[16][16];
int cal(int start,int end,int startn)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
           is[i][j]=vis[i][j]=0;
    for(i=0;i<k;i++)
    {
        int x = g[i].x;
        int y = g[i].y;
        if(s[x][y]=='K')
        {
            for(j=0;j<8;j++)
            {
                int xx = x+nm[j][0];
                int yy = y+nm[j][1];
                if(xx<0||yy<0||xx>=n||yy>=m)continue;
                is[xx][yy]=1;
            }
        }
        else if(s[x][y]=='B')
        {
            for(j=4;j<8;j++)
            {
                int xx = x+go[j][0];
                int yy = y+go[j][1];
                while(xx>=0&&yy>=0&&xx<n&&yy<m)
                {
                    is[xx][yy]=1;
                    xx += go[j][0];
                    yy += go[j][1];
                }
            }
        }
        else if(s[x][y]=='R')
        {
            for(j=0;j<4;j++)
            {
                int xx = x+go[j][0];
                int yy = y+go[j][1];
                while(xx>=0&&yy>=0&&xx<n&&yy<m)
                {
                    is[xx][yy]=1;
                    xx += go[j][0];
                    yy += go[j][1];
                }
            }
        }
    }
    is[g[end].x][g[end].y]=0;
//    if(start==-1)
//    {
//        for(i=0;i<n;i++)
//        {
//            for(j=0;j<m;j++)
//                cout<<is[i][j]<<" ";
//            cout<<endl;
//        }
//    }
    while(!q.empty())q.pop();
    if(start==-1)
        tmp.x = sx,tmp.y = sy,tmp.t=0;
    else
        tmp.x = g[start].x,tmp.y = g[start].y,tmp.t=0;
    q.push(tmp);
    vis[tmp.x][tmp.y]=1;
    while(!q.empty())
    {
        tmp = q.top();q.pop();
        if(tmp.x==g[end].x&&tmp.y==g[end].y)return tmp.t;
        for(i=0;i<8;i++)
        {
            int x = tmp.x + go[i][0];
            int y = tmp.y + go[i][1];
            if(x==g[end].x&&y==g[end].y)return tmp.t+1;
            if(x>=0&&x<n&&y>=0&&y<m&&is[x][y]==0&&vis[x][y]==0)
            {
                vis[x][y]=1;
                next.x=x;next.y=y;next.t=tmp.t+1;
                q.push(next);
            }
        }
    }
    return inf;
}
int gg=1;
void f(int start,int end,int startn,int endn)
{
    int i,j;
    for(i=0;i<k;i++)
    {
        if((1<<i)&startn)
        {
            int w = cal(start,end,startn);
            //if(startn==7)
            cout<<gg<<" "<<start<<" "<<end<<" "<<startn<<" "<<endn<<" "<<w<<endl;
            gg++;
            if(w<inf)
               add(startn,endn,w);
            for(j=0;j<k;j++)
            {
                if((1<<j)&endn)
                {
                    f(end,j,endn,endn-(1<<j));
                }
            }
        }
    }
}
queue<int>h;
int v[maxn],d[maxn];
int spfa()
{
    while(!h.empty())h.pop();
    int i,j;
    int start = (1<<k)-1,end = 0;
    for(i=0;i<=start;i++)
        d[i]=inf,v[i]=0;
    v[start]=1;d[start]=0;
    h.push(start);
    while(!h.empty())
    {
        int u = h.front();h.pop();
        for(i=head[u];i!=-1;i=edge[i].next)
        {
            int vv = edge[i].to;
            if(d[vv]>d[u]+edge[i].w)
            {
                d[vv]=d[u]+edge[i].w;
                if(v[vv]==0)
                {
                    v[vv]=1;
                    h.push(vv);
                }
            }
        }
    }
    return d[end];
}
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int gg=0;
        k =0;
        tot=0;
        memset(head,-1,sizeof(head));
        for(i=0;i<n;i++)
        {
            scanf("%s",s[i]);
            for(j=0;j<m;j++)
            {
                if(s[i][j]=='K'||s[i][j]=='B'||s[i][j]=='R')
                {
                    g[k].x=i;g[k++].y=j;gg=1;
                }
                if(s[i][j]=='*')sx=i,sy=j;
            }
        }
        if(gg==0)
        {
            puts("0");
            continue;
        }
        ans = -1;
        int mm = (1<<k)-1;
        for(i=0;i<k;i++)
            f(-1,i,mm,mm-(1<<i));
            //cout<<"$$"<<endl;
        ans = spfa();
        if(ans>=inf)puts("-1");
        else printf("%d\n",ans);
    }
}
