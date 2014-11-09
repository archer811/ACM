#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int n,m;
char s[1005][1005];
int go[][2]={-1,0,1,0,0,1,0,-1,-1,-1,-1,1,1,1,1,-1};
int num=0;
void dfs(int x,int y)
{
    int i,j;
    s[x][y]='.';
    num++;
    for(i=0;i<8;i++)
    {
        int _x = x+go[i][0];
        int _y = y+go[i][1];
        if(_x>=0&&_y>=0&&_x<n&&_y<m&&s[_x][_y]=='P')
        {
            //cout<<_x<<" "<<_y<<" "<<s[_x][_y]<<endl;
            s[_x][_y]='.';
            dfs(_x,_y);
        }
    }
}
bool flag=false;
int vis[1005][1005];
int f(int x,int y)
{
    int i,j;
    //cout<<x<<" "<<y<<endl;
    for(i=0;i<4;i++)
    {
        int _x = x+go[i][0];
        int _y = y+go[i][1];
        if(_x>=0&&_y>=0&&_x<n&&_y<m&&s[_x][_y]=='.'&&vis[_x][_y]==0)
        {
            //cout<<_x<<" "<<_y<<" "<<s[_x][_y]<<endl;
            vis[_x][_y]=1;
            f(_x,_y);
        }
        else if(_x>=0&&_y>=0&&_x<n&&_y<m&&s[_x][_y]=='P'&&vis[_x][_y]==0)
        {
            vis[_x][_y]=1;
        }
    }
    return 0;
}
int main()
{
    int i,j,k;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%s",s[i]);
        memset(vis,0,sizeof(vis));
        for(i=0;i<m;i++)
        {
            if(vis[0][i]==0)
            {
                vis[0][i]=1;
                if(s[0][i]=='.')
                   f(0,i);
            }
            if(vis[n-1][i]==0)
            {
                vis[n-1][i]=1;
                if(s[n-1][i]=='.')
                   f(n-1,i);
            }
        }
        for(i=0;i<n;i++)
        {
            if(vis[i][0]==0)
            {
                vis[i][0]=1;
                if(s[i][0]=='.')
                  f(i,0);
            }
            if(vis[i][m-1]==0)
            {
                vis[i][m-1]=1;
                if(s[i][m-1]=='.')
                  f(i,m-1);
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(vis[i][j]==0)s[i][j]='G';
            }
            //cout<<s[i]<<endl;
        }
        int ans=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(s[i][j]=='P')
                {
                    num=0;
                    dfs(i,j);
                    if(num>ans)ans=num;
                }
            }
        }
        printf("%d\n",ans);
    }
}
