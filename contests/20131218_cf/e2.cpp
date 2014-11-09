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
int vis[1004][1004],in[1004][1004];
int ans;
int n,m;
char str[]="DIMA";
int go[][2]= {-1,0,1,0,0,1,0,-1};
int judge;
struct array
{
    int x,y;
    bool friend operator < (const array &a,const array &b)
    {
        return in[a.x][a.y]>in[b.x][b.y];
    }
}a;
priority_queue<array>q;
int ff(int i,int j)
{
    for(int k=0;k<4;k++)
    {
        if(str[k]==s[i][j])return k;
    }
}
int f(int i,int j)
{
    int t = ff(i,j);
    return (t-1+4)%4;
}
void run()
{
    int i,j;
    while(!q.empty())
    {
         a = q.top();q.pop();
         cout<<a.x<<" "<<a.y<<endl;

         if(in[a.x][a.y])
         {
             while(!q.empty())
             {
                 array now = q.top();q.pop();
                 cout<<now.x<<" ()() "<<now.y<<" "<<in[now.x][now.y]<<endl;
             }
         }
         if(vis[a.x][a.y]==-1)vis[a.x][a.y]=0;
         int t = ff(a.x,a.y);
         for(i=0;i<4;i++)
         {
             int x = go[i][0]+a.x;
             int y = go[i][1]+a.y;
             if(x<0||y<0||x>=n||y>=m)continue;
             int g = f(x,y);
             if(t==g)
             {

                 vis[x][y]=max(vis[x][y],vis[a.x][a.y]+1);
                 in[x][y]--;
                 //cout<<x<<"*"<<y<<" "<<in[x][y]<<endl;
             }
         }
    }
}
void run_now(int i,int j)
{
    if(s[i][j]=='D')ans= max(ans,vis[i][j]/4);
    if(s[i][j]=='I')ans= max(ans,(vis[i][j]-1)/4);
    if(s[i][j]=='M')ans= max(ans,(vis[i][j]-2)/4);
    if(s[i][j]=='A')ans= max(ans,(vis[i][j]-3)/4);
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
        memset(vis,-1,sizeof(vis));
        memset(in,0,sizeof(in));
        judge=0;
        while(!q.empty())q.pop();
        //cout<<"dd"<<endl;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                int t = f(i,j);
                for(int k=0;k<4;k++)
                {
                    int x = go[k][0]+i;
                    int y = go[k][1]+j;
                    if(x<0||y<0||x>=n||y>=m)continue;
                    int g = ff(x,y);
                    //cout<<i<<" "<<j<<" "<<x<<" "<<y<<" "<<
                    //ff(x,y)<<" "<<t<<"dd"<<g<<endl;
                    if(t==g)in[i][j]++;
                }
                //cout<<i<<" "<<j<<" "<<in[i][j]<<endl;
                a.x=i;a.y=j;
                q.push(a);
            }
        }
        //cout<<"d"<<endl;
        run();
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(vis[i][j]==-1)
                {
                    judge=1;
                }
                run_now(i,j);
                cout<<vis[i][j]<<" ";
            }
            cout<<endl;
        }
        if(judge)puts("Poor Inna!");
        else if(ans==0)puts("Poor Dima!");
        else printf("%d\n",ans);
    }
}
