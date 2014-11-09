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
char s[20][20];
int v[20][20][20];
int n,m;
int go[][2]= {-1,0,1,0,0,-1,0,1,-1,-1,-1,1,1,-1,1,1};
int nm[][2]= {-1,2,-1,-2,1,2,1,-2,2,-1,2,1,-2,-1,-2,1};
int ans,sx,sy;
struct array
{
    int x,y;
} g[20];
int k;
int index[20][20];
void pre(int kk,int x,int y)
{
    int i,j;
    if(s[x][y]=='K')
    {
        for(j=0; j<8; j++)
        {
            int xx = x+nm[j][0];
            int yy = y+nm[j][1];
            if(xx<0||yy<0||xx>=n||yy>=m)continue;
            v[kk][xx][yy]=1;
        }
    }
    else if(s[x][y]=='B')
    {
        for(j=4; j<8; j++)
        {
            int xx = x+go[j][0];
            int yy = y+go[j][1];
            while(xx>=0&&yy>=0&&xx<n&&yy<m)
            {
                v[kk][xx][yy]=1;
                if(s[xx][yy]=='K'||s[xx][yy]=='B'||s[xx][yy]=='R')
                {
                        break;
                }
                xx += go[j][0];
                yy += go[j][1];
            }
        }
    }
    else if(s[x][y]=='R')
    {
        for(j=0; j<4; j++)
        {
            int xx = x+go[j][0];
            int yy = y+go[j][1];
            while(xx>=0&&yy>=0&&xx<n&&yy<m)
            {
                v[kk][xx][yy]=1;
                if(s[xx][yy]=='K'||s[xx][yy]=='B'||s[xx][yy]=='R')
                {
                        break;
                }
                xx += go[j][0];
                yy += go[j][1];
            }
        }
    }
}
struct xx
{
    int x,y,state;
}now,next;
queue<xx>q;
int vis[17][17][33000],dis[17][17][33000];
int judge(int x,int y)
{
    if(x>=0&&y>=0&&x<n&&y<m)return 1;
    return 0;
}
void make()
{
    int i,j;
    memset(v,0,sizeof(v));
    for(i=0;i<k;i++)
    {
        pre(i,g[i].x,g[i].y);
    }
}
void spfa()
{
    int i,j;
    while(!q.empty())q.pop();
    memset(vis,0,sizeof(vis));
    memset(dis,0x0f,sizeof(dis));
    now.x=sx;now.y=sy;now.state=(1<<k)-1;
    q.push(now);
    //cout<<k<<endl;
    dis[sx][sy][(1<<k)-1]=0;
    vis[sx][sy][(1<<k)-1]=1;
    while(!q.empty())
    {
        now = q.front();q.pop();
        //cout<<now.x<<" " <<now.y<<endl;
        vis[now.x][now.y][now.state]=0;
        if(now.state==0)
        {
            if(ans==-1)ans=dis[now.x][now.y][0];
            else ans = min(ans,dis[now.x][now.y][0]);
            continue;
        }
        for(i=0;i<8;i++)
        {
            int xx = now.x+go[i][0];
            int yy = now.y+go[i][1];

            if(judge(xx,yy)==0)continue;
            bool flag = false;
            for(j=0;j<k;j++)
            {
                if(((1<<j)&now.state)&&v[j][xx][yy])
                {
                    flag=true;break;
                }
            }
            if(flag)continue;

            int state = now.state;
            if(s[xx][yy]=='K'||s[xx][yy]=='B'||s[xx][yy]=='R')
            {
                if(now.state&(1<<index[xx][yy]))
                    state = now.state - (1<<(index[xx][yy]));
            }
//            if(now.x==4&&now.y==1&&xx==3&&yy==2)
//                cout<<"&"<<state<<endl;
            if(dis[xx][yy][state]>dis[now.x][now.y][now.state]+1)
            {
                dis[xx][yy][state]=dis[now.x][now.y][now.state]+1;
                if(vis[xx][yy][state]==0)
                {
//                    if(now.x==3&&now.y==6)
//                        cout<<xx<<" "<<yy<<"**"<<" "<<dis[xx][yy][state]<<endl;
                    vis[xx][yy][state]=1;
                    next.x=xx;next.y=yy;next.state=state;
                    q.push(next);
                }
            }
        }
    }
}
int main()
{
    int i,j;
    scanf("%d%d",&n,&m);
    {
        int gg=0;
        k =0;
        memset(index,-1,sizeof(index));

        for(i=0; i<n; i++)
        {
            scanf("%s",s[i]);
            for(j=0; j<m; j++)
            {
                if(s[i][j]=='K'||s[i][j]=='B'||s[i][j]=='R')
                {
                    g[k].x=i;
                    g[k++].y=j;
                    index[i][j]=k-1;
                }
                if(s[i][j]=='*')sx=i,sy=j;
            }
        }
        make();
        ans = -1;
        spfa();
        printf("%d\n",ans);
    }
}
