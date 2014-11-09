#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
using namespace std;
int n,m;
int a[1005][1005];
int vis[1005][1005];
void ac(int x,int y)
{
    int tmp = a[x][y];
    for(int i=x-1;i>=0;i--)
    {
        if(a[i][y]&&vis[i][y]==0)
        {
            vis[i][y]=1;
            ac(i,y);
        }
        vis[i][y]=1;
    }
    for(int i=y-1;i>=y-tmp&&i>=0;i--)
    {
        if(a[x][i])
        {
            if(vis[x][i]==0)
            {
               vis[x][i]=1; ac(x,i);
            }
        }
        vis[x][i]=1;
    }
}
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        memset(a,0,sizeof(a));
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        }
        int sum=0;
        for(i=n-1;i>=0;i--)
        {
            for(j=m-1;j>=0;j--)
            {
                if(vis[i][j]==0)
                {
                    if(a[i][j])
                    {
                        vis[i][j]=1;
                        sum++;
                        ac(i,j);
                    }
                    vis[i][j]=1;
                }
            }
        }
        printf("%d\n",sum);
    }
}
