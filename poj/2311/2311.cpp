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
int d[205][205];
int dfs(int x,int y)
{
    if(d[x][y]!=-1)return d[x][y];
    int g[1005]={0};
    for(int i=2;i<x-1;i++)
    {
        g[dfs(i,y)^dfs(x-i,y)]=1;
    }
    for(int i=2;i<y-1;i++)
    {
        g[dfs(x,i)^dfs(x,y-i)]=1;
    }
    for(int i=0;;i++)
    {
        if(g[i]==0)return d[x][y]=i;
    }
}
int main()
{
    int i,j;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    memset(d,-1,sizeof(d));
    //d[2][2]=0;
    for(i=1;i<=200;i++)
    {
        for(j=1;j<=200;j++)
        {
            if(d[i][j]==-1)d[i][j]=dfs(i,j);
        }
    }
//    for(i=1;i<=10;i++)
//    {
//        for(j=1;j<=10;j++)
//            cout<<i<<"  "<<j<< "  "<<d[i][j]<<endl;
//    }
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        if(d[a][b]!=0)puts("WIN");
        else puts("LOSE");
    }
    return 0;
}
