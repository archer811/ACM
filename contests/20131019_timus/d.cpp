#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int c[105][105];
const int inf = 0x3fffffff;
int a[105];
int prim(int n,int sta)//n表示有n个顶点，sta表从sta这个顶点出发生成最小生成树
{
    int mark[105],dis[105];
    int i,sum = 0,j;     //sum是总的最小生成树边权值
    for (i = 1; i <= n; i ++) //初始化dis[i] 表从顶点sta到点i的权值
    {
        dis[i] = c[sta][i];
        mark[i] = 0;
    }
    mark[sta] = 1;           //sta 这个顶点加入最小生成树中
    for (i = 1; i < n; i ++) //循环n-1次，每次找出一条最小权值的边 n个点的图
    {
        //只有n-1条边
        int min = inf,flag;       //inf 表无穷大
        for (j = 1; j <= n; j ++) //找出当前未在最小生成树中边权最小的顶点
            if (!mark[j] && dis[j] < min)
                min = dis[j],flag = j;
        mark[flag] = 1;         //把该顶点加入最小生成树中
        sum += dis[flag];       //sum加上其边权值
        for (j = 1; j <= n; j ++) //以falg为起点更新到各点是最小权值
            if (dis[j] > c[flag][j])
                dis[j] = c[flag][j];
    }
    return sum;       //返回边权总和
}

int main()
{
    int i,j,k,n;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(i=1; i<=n+1; i++)
        {
            c[i][i]=0;
            for(j=i+1; j<=n+1; j++)
            {
                c[i][j]=c[j][i]=inf;
            }
        }
        for(i=1; i<=k; i++)
        {
            scanf("%d",&a[i]);
            c[a[i]][n+1]=c[n+1][a[i]]=0;
        }

        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
                scanf("%d",&c[i][j]);
        }
        n ++;
//        for(i=1;i<=n;i++)
//        {
//            for(j=1;j<=n;j++)
//                cout<<c[i][j]<<" ";
//            cout<<endl;
//        }
        int ans = prim(n,n);
        printf("%d\n",ans);
    }
}
