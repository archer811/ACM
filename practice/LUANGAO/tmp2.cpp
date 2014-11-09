#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int dir[][2]={0,1,1,0,0,-1,-1,0};
const int maxn=5000+10;
char maze[5000][5000];
bool vis[5000][5000];
int n,m,sx,sy;
inline bool check(int x,int y)
{
    return x>=0&&x<n&&y>=0&&y<m&&vis[x][y]==false&&maze[x][y]!='#';
}
struct array
{
    int x,y;
}tmp;
queue<array>q;
bool bfs()
{
    while(!q.empty())q.pop();
    vis[sx][sy]=true;
    tmp.x=sx;tmp.y=sy;
    q.push(tmp);
    int x,y,dx,dy;
    while(!q.empty())
    {
        array pa=q.front();q.pop();
        x=pa.x;y=pa.y;
        for(int i=0;i<4;i++)
        {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            if(dx>=0&&dy>=0&&dx<n&&dy<m&&maze[dx][dy]!='#'&&vis[dx][dy]==false)
            {
                if(dx==0||dy==0||dx==n-1||dy==m-1) return true;
                vis[dx][dy]=true;
                array tk;
                tk.x=dx;tk.y=dy;
                q.push(tk);
            }
        }
    }
    return false;
}
void cpym()
{
    int i,j;
    int N = n*3,M = m*3;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            maze[i][j+m]=maze[i][j+m*2]=
            maze[i+n][j]=maze[i+n][j+m]=maze[i+n][j+m*2]=
            maze[i+n*2][j]=maze[i+n*2][j+m]=maze[i+n*2][j+m*2]=maze[i][j];
        }
    }

   // sx+=n;sy+=m;
    N = n;M = m;
    return;
//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<m;j++)
//            cout<<maze[i][j];
//        cout<<endl;
//    }
//    cout<<maze[sx][sy]<<endl;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        sx=sy=0;
        for(int i=0;i<n;++i)
        {
            scanf("%s",maze[i]);
            for(int j=0;j<m;++j)
                if(maze[i][j]=='S')
                {sx=i+n;sy=j+m;}
        }
        cpym();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                vis[i][j]=false;
        }
        if(bfs())
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
