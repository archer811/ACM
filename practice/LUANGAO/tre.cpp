#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n,m,a1,a2,b1,b2;
const int maxn = 10005;
struct array
{
    int x,y;
} s[1005];
int pre[10005],vis[maxn],dis[maxn];
int Max=0;
const int inf = 0x3fffffff;
vector<int>g[maxn];
int _map[105][105];
int change(int a,int b)
{
    return (a-1)*100+b;
}
queue<int>q;
int change2(int d)
{
    int t = d%100;
    if(t==0)t=100;
    return t;
}
int change1(int d)
{
    int x = change2(d);
    return (d-x)/100+1;
}
void spfa()
{
    int i,j;
    for(i=0; i<maxn; i++)
        vis[i]=0,dis[i]=inf;
    vis[change(a1,b1)]=1;
    dis[change(a1,b1)]=0;
    while(!q.empty())q.pop();
    q.push(change(a1,b1));
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        vis[t]=0;
        int x = change1(t);
        int y = change2(t);
        //cout<<x<<"*"<<y<<endl;
        for(i=0; i<g[x].size(); i++)
        {
            int v = g[x][i];
            if(v==x||v==y)continue;
            if(_map[v][y]==0)continue;
            int tmp = change(v,y);
            if(dis[tmp]>dis[t]+1)
            {
                dis[tmp]=dis[t]+1;
                pre[tmp]=t;
                if(vis[tmp]==0)
                {
                    vis[tmp]=1;
                    q.push(tmp);
                }
            }
            for(j=0; j<g[y].size(); j++)
            {
                int t1 = g[x][i],t2 = g[y][j];
                int tmp = change(t1,t2);
                if(g[t1][t2]==1&&t1!=t2&&t1!=x&&t2!=y)
                {
                    //cout<<"*"<<endl;
                    if(dis[tmp]>dis[t]+2)
                    {
                        dis[tmp]=dis[t]+2;
                        pre[tmp]=t;
                        if(vis[tmp]==0)
                        {
                            vis[tmp]=1;
                            q.push(tmp);
                        }
                    }
                }
            }
        }
        for(i=0; i<g[y].size(); i++)
        {
            int v = g[y][i];
            if(v==x||v==y)continue;
            if(_map[x][v]==0)continue;
            int tmp = change(x,v);
            if(dis[tmp]>dis[t]+1)
            {
                dis[tmp]=dis[t]+1;
                pre[tmp]=t;
                if(vis[tmp]==0)
                {
                    vis[tmp]=1;
                    q.push(tmp);
                }
            }
        }
    }
}
struct xx
{
    int x,y;
};
xx ans[maxn];
int main()
{
    int i,j;
    int a,b;
    while(scanf("%d%d%d%d%d%d",&n,&m,&a1,&b1,&a2,&b2)!=EOF)
    {
        memset(pre,-1,sizeof(pre));
        for(i=1; i<=n; i++)
            g[i].clear();
        memset(_map,0,sizeof(_map));
        for(i=0; i<m; i++)
        {
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
            _map[a][b]=_map[b][a]=1;
        }
        spfa();
        int t = change(a2,b2);
        int sum=0;

        while(t!=-1)
        {
            xx g;
            g.x = change1(t);
            g.y = change2(t);
            ans[sum++]=g;
            t=pre[t];
        }
        t = change(a2,b2);
        cout<<dis[t]<<" "<<sum<<endl;
        for(i=sum-1; i>=0; i--)
        {
            cout<<ans[i].x<<" "<<ans[i].y<<endl;
        }
    }
}
