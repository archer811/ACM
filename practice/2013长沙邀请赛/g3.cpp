#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, T, S, E, S2, E2;
int ct[105];
int sa[105];
int mp[105][105];
int f[105][305];
const int INF = 0x3f3f3f3f;

void floyd()
{
    for (int k = 0; k < N; ++k)
    {
        for (int i = 0; i < N; ++i)
        {
            if (mp[i][k] == INF || i == k) continue;
            for (int j = 0; j < N; ++j)
            {
                if (mp[k][j] == INF || k == j) continue;
                if (mp[i][j] > mp[i][k] + mp[k][j])
                {
                    mp[i][j] = mp[i][k] + mp[k][j];
                }
            }
        }
    }
}

char vis[105][305];

struct Node
{
    int x, t;
} info;

int spfa()
{
    memset(f, 0, sizeof (f));
    memset(vis, 0, sizeof (vis));
    f[S2][0] = 0;
    vis[S2][0] = 1;
    info.x = S2, info.t = 0;
    queue<Node>q;
    q.push(info);
    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();
        vis[cur.x][cur.t] = 0;
        int u = cur.x, v;
        for (int v = 0; v < N; ++v)
        {
            if (mp[u][v] == INF || v == u) continue;
            int tt = cur.t + ct[v] + mp[u][v];
            if (tt <= T && (sa[u] < sa[v] || v == E2))
            {
                if (f[v][tt] < f[u][cur.t] + sa[v])
                {
                    f[v][tt] = f[u][cur.t] + sa[v];
                    if (!vis[v][tt])
                    {
                        vis[v][tt] = 1;
                        info.x = v, info.t = tt;
                        q.push(info);
                    }
                }
            }
        }
    }
    int ret = 0;
    for (int i = 0; i <= T; ++i)
    {
        ret = max(ret, max(f[E][i], f[E2][i]));
    }
    return ret;
}

int main()
{
    int W;
    scanf("%d", &W);
    for (int ca = 1; ca <= W; ++ca)
    {
        scanf("%d%d%d%d%d", &N, &M, &T, &S, &E);
        memset(mp, 0x3f, sizeof (mp));
        for (int i = 0; i < N; ++i)
        {
            scanf("%d", &ct[i]);
        }
        for (int i = 0; i < N; ++i)
        {
            scanf("%d", &sa[i]);
        }
        S2 = N, sa[S2] = -1;
        E2 = N+1, sa[E2] = 0, ct[E2] = 0;
        int a, b, c;
        for (int i = 0; i < M; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            mp[a][b] = mp[b][a] = min(c, mp[a][b]);
        }
        floyd();
        for (int i = 0; i < N; ++i)
        {
            mp[S2][i] = mp[S][i];
            mp[i][E2] = mp[i][E];
        }
        mp[S2][S] = 0;
        mp[E][E2] = 0;
        N += 2;
        printf("Case #%d:\n%d\n", ca, spfa());
    }
    return 0;
}
