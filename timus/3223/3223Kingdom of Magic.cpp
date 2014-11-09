#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<queue>
#include<string>
#include<map>
#include<set>
#define REP(i, n) for(int i=0; i<(n); i++)
#define CLR(a, b) memset(a, b, sizeof(a))
#define PII pair<int, int>
#define xx first
#define yy second
#define LL long long
using namespace std;

const int maxn = 111;
int n, m, g[maxn][maxn], d[maxn][maxn], p[maxn][maxn];
int sx, sy, tx, ty;
bool inq[maxn][maxn];
queue<PII> q;
vector<int> G[maxn];

void relax(int x1,int y1,int x2,int y2,int w)
{
    if(d[x1][y1]>d[x2][y2]+w)
    {
        d[x1][y1]=d[x2][y2]+w;
        int tmp = x2*1000+y2;
        p[x1][y1]=tmp;
        if(inq[x1][y1]==0)
        {
            inq[x1][y1]=1;
            q.push(make_pair(x1,y1));
        }
    }
}

void spfa()
{
    q.push(make_pair(sx, sy));
    d[sx][sy] = 0; p[sx][sy] = -1;
    CLR(inq, false);
    inq[sx][sy]=true;
    while(!q.empty())
    {
        int ux = q.front().xx, uy = q.front().yy;
        q.pop();
        inq[ux][uy] = false;

        REP(i, G[ux].size())
        {
            int vx = G[ux][i];
            if(g[vx][uy]) relax(vx, uy,ux, uy,  1);
            REP(j, G[uy].size())
            {
                int vy = G[uy][j];
                if(ux == vy && uy == vx) continue;
                if(g[vx][vy]) relax(vx, vy,ux, uy,  2);
            }
        }

        REP(i, G[uy].size())
        {
            int vy = G[uy][i];
            if(g[ux][vy]) relax(ux, vy,ux, uy,  1);
        }
    }
}

int main()
{
    bool flag = 0;
    while(~scanf("%d%d%d%d%d%d", &n, &m, &sx, &sy, &tx, &ty))
    {
        REP(i, n+1)
        {
            G[i].clear();
            REP(j, n+1)
                g[i][j] = 0, d[i][j] = 1000000000;
        }
        while(m--)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
            g[u][v] = g[v][u] = 1;
        }

        spfa();

        int c = d[tx][ty];
        vector<PII> path;
        while(p[tx][ty] != -1)
        {
            path.push_back(make_pair(tx, ty));
            int tmp = p[tx][ty];
            tx = tmp / 1000, ty = tmp % 1000;
        }
        path.push_back(make_pair(sx, sy));
        reverse(path.begin(), path.end());

        int nc = path.size();
        printf("%d %d\n", c, nc);
        REP(i, nc) printf("%d %d\n", path[i].xx, path[i].yy);
    }
    return 0;
}
