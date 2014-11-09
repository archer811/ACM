
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<functional>
#include<bitset>
#include<ctime>
#include<cstdio>

using namespace std;

#pragma comment(linker, "/STACK:1024000000,1024000000")
#define PB push_back
#define MP make_pair

const double pi=acos(-1.0),eps=1e-8;
const int maxn=1100,maxm=1100000;
#define ll long long
//const ll linf=1122334455667788990;
struct array
{
    double x,y;
}g[1005];
int num;
const double inf = 0x3fffffff;
double dis[1005];
int vis[10005];
double d[1005][1005];
double gt(int i,int j)
{
    return sqrt((g[i].x-g[j].x)*(g[i].x-g[j].x)+(g[i].y-g[j].y)*(g[i].y-g[j].y));
}
void spfa()
{
    int i,j;
    for(i=0;i<num;i++)
    {
        vis[i]=0;dis[i]=inf;
    }
    vis[0]=1;
    dis[0]=0;
    queue<int>q;
    q.push(0);
    while(!q.empty())
    {
        int u = q.front();
        vis[u]=0;q.pop();
        //cout<<u<<endl;
        for(i=0;i<num;i++)
        {
            if(dis[i]>dis[u]+d[u][i])
            {
                dis[i]=dis[u]+d[u][i];
                if(vis[i]==0)
                {
                    vis[i]=1;
                    q.push(i);
                }
            }
        }
    }
}
int main()
{

    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        double l;
        scanf("%d%lf",&n,&l);
        num=0;
        scanf("%lf%lf",&g[num].x,&g[num].y);
        num++;
        scanf("%lf%lf",&g[num].x,&g[num].y);
        num++;
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf",&g[num].x,&g[num].y);
            num++;
        }

        for(i=0;i<num;i++)
        {
            for(j=0;j<num;j++)
            {
                d[i][j]=gt(i,j);//cout<<i<<" "<<j<<"  "<<d[i][j]<<endl;
                if(d[i][j]<l+eps);
                else d[i][j]=inf;

            }
        }
        spfa();
        if(dis[1]>=inf)puts("impossible");
        else printf("%.2f\n",dis[1]);
    }
    return 0;
}
