#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
char s[1004][1004];
int vis[1004][1004];
int ans;
int n,m;
char str[]="DIMA";
struct array
{
    int x,y,num,t,have;
} now,next;
queue<array>q;
int go[][2]= {-1,0,1,0,0,1,0,-1};
int judge;
void dfs(int u,int v,int num,int t,int ant)
{
    if(judge)return;
    int i,j;
    int g = (t+1)%4;
    if(ant>ans)ans=ant;
   // cout<<u<<" "<<v<<endl;
    for(i=0; i<4; i++)
    {
        int x = u+go[i][0];
        int y = v+go[i][1];
        if(x<0||y<0||x>=n||y>=m)continue;
//cout<<s[x][y]<<" "<<g<<" "<<str[g]<<endl;
        if(s[x][y]!=str[g])continue;
        if(vis[x][y]==-1)
        {
            vis[x][y]=num+1;
            if(s[x][y]=='A')
                dfs(x,y,num+1,g,ant+1);
            else
                dfs(x,y,num+1,g,ant);
            //vis[x][y] = tmp;
        }
        else if(vis[x][y]>=num+1)
        {
             vis[x][y]=num+1;
        }
        else
        {
            //cout<<u<<" "<<v<<" "<<x<<" "<<y<<endl;
            judge=1;
            return;
        }
    }
}
int main()
{
    int i,j;

    while(scanf("%d%d",&n,&m)!=EOF)
    {
        ans=0;
        for(i=0; i<n; i++)
        {
            scanf("%s",s[i]);
        }
        int g=0;
        memset(vis,-1,sizeof(vis));
        judge=0;
        int in=0;
        for(i=0; i<n&&judge==0; i++)
        {
            for(j=0; j<m&&judge==0; j++)
            {
                bool flag=false;
                if(s[i][j]=='D')
                {
                    for(int k=0; k<4; k++)
                    {
                        int x = go[k][0]+i;
                        int y = go[k][1]+j;
                        if(x<0||y<0||x>=n||y>=m)continue;
                        if(s[x][y]=='A')
                        {
                            flag=true;
                            break;
                        }
                    }
                    if(flag==false)
                    {
                        //in=1;
                        //memset(vis,-1,sizeof(vis));
                        vis[i][j]=0;
                        dfs(i,j,0,0,0);
                       // cout<<"*"<<i<<" "<<j<<" "<<judge<<endl;
                    }
                    else in=1;
                }

            }
        }

        if(judge==0&&ans==0)
        {
            bool flag=false;
            for(i=0;i<n&&judge==0&&flag==false;i++)
            {
                for(j=0;j<m&&judge==0&&flag==false;j++)
                {
                    if(vis[i][j]==-1&&s[i][j]=='D')
                    {
                        dfs(i,j,0,0,0);flag=true;
                    }
                }
            }
        }

        //cout<<ans<<endl;
       // cout<<judge<<" "<<ans<<endl;
        if(judge)puts("Poor Inna!");
        else if(ans==0)puts("Poor Dima!");
        else printf("%d\n",ans);
    }
}
