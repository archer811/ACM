#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n,m ,sx, sy, tx, ty;
const int maxn = 20005;
int p[105][105],vis[105][105],d[105][105];
const int inf = 1000000000;
vector<int>G[maxn];
int g[105][105];
queue<pair<int,int> >q;

void relax(int x1, int y1, int x2, int y2, int w)
{
    if(d[x1][y1] > d[x2][y2] + w)
    {
        d[x1][y1] = d[x2][y2] + w;
        p[x1][y1] = x2*1000 + y2;
        if(!vis[x1][y1])
        {
            vis[x1][y1]=1;
            q.push(make_pair(x1, y1));
        }

    }
}
void spfa()
{
    int i,j;
    vis[sx][sy]=1;
    d[sx][sy]=0;
    while(!q.empty())q.pop();
    q.push(make_pair(sx,sy));
    while(!q.empty())
    {
        int ux = q.front().first;
        int uy = q.front().second;
        q.pop();
        vis[ux][uy]=0;
        for(i=0; i<G[ux].size(); i++)
        {
            int vx = G[ux][i];
            if(g[vx][uy])
               relax(vx, uy,ux, uy,  1);
            for(j=0; j<G[uy].size(); j++)
            {
                int vy = G[uy][j];
                if(ux == vy && uy == vx) continue;
                if(g[vx][vy]) relax(vx, vy,ux, uy,  2);
            }
        }
        for(i=0; i<G[uy].size(); i++)
        {
            int vy = G[uy][i];
            if(g[ux][vy]) relax(ux, vy,ux, uy,  1);
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
    while(scanf("%d%d%d%d%d%d",&n,&m,&sx,&sy,&tx,&ty)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            G[i].clear();
            for(j=1;j<=n;j++)
            {
                g[i][j] = 0, d[i][j] = 1000000000;
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                d[i][j]=inf,vis[i][j]=0,p[i][j]=-1;
        }
        memset(g,0,sizeof(g));
        for(i=0; i<m; i++)
        {
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
            g[a][b]=g[b][a]=1;
        }
        spfa();
        int c = d[tx][ty];
        vector<pair<int,int> >path;
        while(p[tx][ty] != -1)
        {
            path.push_back(make_pair(tx, ty));
            int tmp = p[tx][ty];
            tx = tmp / 1000, ty = tmp % 1000;
        }
        path.push_back(make_pair(sx, sy));
        reverse(path.begin(), path.end());
        cout<<c<<" "<<path.size()<<endl;
        for(i=0;i<path.size();i++)
        {
            cout<<path[i].first<<" "<<path[i].second<<endl;
        }
    }
}