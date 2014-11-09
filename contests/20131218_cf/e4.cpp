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
int vis[1004][1004],Max[1004][1004];
int sunxu[1004][1004];
int ans;
int n,m;
char str[]="DIMA";
int go[][2]= {-1,0,1,0,0,1,0,-1};
int judge,tot;
int ff(int i,int j)
{
    for(int k=0; k<4; k++)
    {
        if(str[k]==s[i][j])return k;
    }
}
int f(int i,int j)
{
    int t = ff(i,j);
    return (t-1+4)%4;
}
void run_now(int i,int j)
{
    if(s[i][j]=='D')ans= max(ans,Max[i][j]/4);
    if(s[i][j]=='I')ans= max(ans,(Max[i][j]-3)/4);
    if(s[i][j]=='M')ans= max(ans,(Max[i][j]-2)/4);
    if(s[i][j]=='A')ans= max(ans,(Max[i][j]-1)/4);
}
void dfs(int a,int b,int num)
{
    if(judge)return;
    int i,j;
    if(Max[a][b]!=-1)return;
    vis[a][b]=tot;
    sunxu[a][b]=num;
    int t = ff(a,b);
    int tmp=0;
//    cout<<a<<"()"<<b<<endl;
    for(int i=0; i<4; i++)
    {
        int x = go[i][0]+a;
        int y = go[i][1]+b;
        if(x<0||y<0||x>=n||y>=m)continue;
        int g = f(x,y);
        if(g==t)
        {
            if(vis[x][y]==tot&&
               sunxu[x][y]!=-1&&
               sunxu[x][y]<=sunxu[a][b])
            {
//                cout<<a<<" "<<b<<" "
//                    <<x<<" "<<y<<endl;
                judge=1;
                return;
            }
            dfs(x,y,num+1);
            tmp = max(tmp,Max[x][y]);
        }
    }
    tmp = max(tmp+1,1);
    Max[a][b]=max(Max[a][b],tmp);
    sunxu[a][b]=-1;
}
int main()
{
    int i,j;

    while(scanf("%d%d",&n,&m)!=EOF)
    {
        ans=0;
        tot=0;
        for(i=0; i<n; i++)
        {
            scanf("%s",s[i]);
        }
        memset(vis,-1,sizeof(vis));
        memset(Max,-1,sizeof(Max));
        memset(sunxu,-1,sizeof(sunxu));
        judge=0;
        for(i=0; i<n&&judge==0; i++)
        {
            for(j=0; j<m&&judge==0; j++)
            {
                int t = f(i,j),in=0;
                for(int k=0; k<4; k++)
                {
                    int x = go[k][0]+i;
                    int y = go[k][1]+j;
                    if(x<0||y<0||x>=n||y>=m)continue;
                    int g = ff(x,y);
                    if(t==g)in++;
                }
                if(in==0)
                {
                    //cout<<i<<"*"<<j<<endl;
                    tot++;
                    dfs(i,j,0);
                }
            }
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(vis[i][j]==-1)
                {
                    judge=1;
                }
                run_now(i,j);
                // cout<<Max[i][j]<<" ";
            }
            //cout<<endl;
        }
        if(judge)puts("Poor Inna!");
        else if(ans==0)puts("Poor Dima!");
        else printf("%d\n",ans);
    }
}
