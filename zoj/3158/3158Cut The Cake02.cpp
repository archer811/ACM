#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int N=10;
int m,n,c[N][N],ans;
void dfs(int x,int y)
{
        if(x<=n)
        {
               for(int i=1;i<=m-1;i++)
                       dfs(x+1,y+c[x][i]);
        }
        else
        {
               if(abs(y)<ans) ans=abs(y);
               return ;
        }
}
int main()
{
        int i,j,x;
        while(scanf("%d %d",&n,&m)!=-1)
        {
               for(i=1;i<=n;i++)
               {
                       c[i][0]=0;
                       for(j=1;j<=m;j++)
                       {
                               scanf("%d",&c[i][j]);
                               c[i][j]+=c[i][j-1];
                       }
               }
               scanf("%d",&x);
               for(i=1;i<=n;i++)
                       for(j=1;j<=m-1;j++)
                               c[i][j]=c[i][m]-c[i][j]-c[i][j];
//               for(i=0;i<n;i++)
//               {
//                   for(j=0;j<m;j++)
//                    cout<<c[i][j] << " ";
//                   cout<<endl;
//               }
               ans=0xffffff;
               dfs(1,0);
               printf(ans>x ? "You'd better buy another one!\n" : "%d\n",ans);
        }
}
