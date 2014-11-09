#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
char s[1001][1001];
int mark[1001][1001];
int n,m;
int sz,sx,sy;
int go[][2]={-1,0,1,0,0,1,0,-1};
void dfs(int x,int y)
{
    int i,j;
    mark[x][y]=sz;
    for(i=0;i<4;i++)
    {
        int a = go[i][0]+x;
        int b = go[i][1]+y;
        if(a>=0&&b>=0&&a<n&&b<m)
        {
            if(s[a][b]!='#'&&mark[a][b]==0)
            {
                dfs(a,b);
            }
        }
    }
}
int vis[1000001];
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%s",s[i]);
            for(j=0;j<m;j++)
            {
                if(s[i][j]=='S'){sx=i;sy=j;}
                mark[i][j]=0;
            }
        }
//        cout<<sx<<" "<<sy<<endl;
        sz = 1;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(s[i][j]!='#')
                {
                    if(mark[i][j]==0)
                    {
                        dfs(i,j);sz++;
                    }

                }
            }
        }
//        for(i=0;i<n;i++)
//        {
//            for(j=0;j<m;j++)
//                cout<<mark[i][j]<<" ";
//            cout<<endl;
//        }

        memset(vis,0,sizeof(vis));
        int tmp1 = mark[sx][sy],tmp;
        vis[tmp1]=1;
        for(i=0;i<n;i++)
        {
            tmp = mark[i][0];
            if(tmp)
            {
                if(tmp==tmp1)
                {
                    int tmp2 = mark[i][m-1];
                    vis[tmp2]=1;
                }
            }
            tmp = mark[i][m-1];
            if(tmp)
            {
                if(tmp==tmp1)
                {
                    int tmp2 = mark[i][0];
                    vis[tmp2]=1;
                }
            }
        }

        for(i=0;i<m;i++)
        {
            tmp = mark[0][i];
            if(tmp)
            {
                if(tmp==tmp1)
                {
                    int tmp2 = mark[n-1][i];
                    vis[tmp2]=1;
                }
            }
            tmp = mark[n-1][i];
            if(tmp)
            {
                if(tmp==tmp1)
                {
                    int tmp2 = mark[0][i];
                    vis[tmp2]=1;
                }
            }
        }

        int judge = 0;
        for(i=0;i<n&&judge==0;i++)
        {
            for(j=0;j<n&&judge==0;j++)
            {
                if(mark[i][0]&&mark[j][m-1])
                {
                    if(vis[mark[i][0]]&&vis[mark[j][m-1]])
                        judge=1;
                }
            }
        }


        for(i=0;i<m&&judge==0;i++)
        {
            for(j=0;j<m&&judge==0;j++)
            {
                if(mark[0][i]&&mark[n-1][j])
                {
                    if(vis[mark[0][i]]&&vis[mark[n-1][j]])
                        judge=1;
                }
            }
        }

        if(judge)puts("YES");
        else puts("NO");
    }
}
