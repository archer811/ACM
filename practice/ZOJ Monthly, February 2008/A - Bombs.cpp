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
int mark[1005][1005];
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        memset(mark,0,sizeof(mark));
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
                if(a[i][j]==0)
                {
                    if(i+1<n&&vis[i+1][j]==2)
                        vis[i][j]=2;
                    if(j+1<m&&j+1-mark[i][j+1]<=i)
                    {
                        vis[i][j]=2;
                        mark[i][j]=max(mark[i][j],mark[i][j+1]-1);
                    }
                }
            }
        }
        printf("%d\n",sum);
    }
}
