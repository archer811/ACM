#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;
#ifdef __int64
typedef __int64 ll;
#else
typedef long long ll;
#endif
/*
const int maxn = 400005;
int head[maxn],tot;
struct Edge
{
    int to,next;
}edge[maxn];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}*/
const int maxn = 1000006;
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
int a[][3]= {  {0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}
};
double v[10][4];
int ans[9];
struct array
{
    double x,y,z;
} g[11];
int flag=0;
double dis[10][10];
double get(array a,array b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);
}
double d[10];
int judge()
{
    for(int i=0; i<8; i++)
    {
        dis[i][i]=0;
        for(int j=i+1; j<8; j++)
        {
            dis[i][j]=dis[j][i]=get(g[i],g[j]);
        }
    }
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
            d[j]=dis[i][j];
        sort(d,d+8);
//        if(ans[0]==0&&ans[1]==0&&ans[2]==0&&ans[3]==0
//                &&ans[4]==0&&ans[5]==0&&ans[6]==0&&ans[7]==0)
//        {
//            cout<<i<<endl;
//            for(int j=0; j<8; j++)
//                cout<<d[j]<<" ";
//            cout<<endl;
//        }
        if(d[1]>0&&d[1]==d[2]&&d[2]==d[3]&&d[4]==d[5]&&d[5]==d[6]&&d[6]==2*d[1]&&d[7]==3*d[1])
            ;
        else return 0;
    }
    return 1;
}
int sum=0;
void dfs(int x)
{
    if(flag)return;
    if(x==8)
    {
        for(int i=0; i<8; i++)
        {
            g[i].x = v[i][a[ans[i]][0]];

            g[i].y = v[i][a[ans[i]][1]];

            g[i].z = v[i][a[ans[i]][2]];
        }


        //cout<<x<<endl;
        sum++;
        if(judge())flag=1;
        if(flag)
        {
            puts("YES");
            for(int i=0; i<8; i++)
            {
                printf("%.0lf %.0lf %.0lf\n",g[i].x,g[i].y,g[i].z);
            }
        }
        return;
    }
    else
    {
        for(int i=0; i<6; i++)
        {
            ans[x] = i;
            dfs(x+1);
        }
    }
}
int main()
{
    int i,j;
    while(scanf("%lf%lf%lf",&v[0][0],&v[0][1],&v[0][2])!=EOF)
    {
        for(i=1; i<8; i++)
            scanf("%lf%lf%lf",&v[i][0],&v[i][1],&v[i][2]);
        flag = 0;
        dfs(0);
        if(flag==0)puts("NO");
    }
    return 0;
}
