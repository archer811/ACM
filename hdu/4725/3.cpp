#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAXN 200010
using namespace std;
bool in[MAXN];
int N, M, C;
int dist[MAXN];
vector <pair<int, int> > G[MAXN];
queue <int> Q;
int layer[MAXN];
bool has[MAXN];

void SPFA()
{
    memset(dist, -1, sizeof(dist));
    dist[1] = 0;
    dist[N + layer[1]] = 0;
    memset(in, 0, sizeof(in));
    while (!Q.empty()) Q.pop();
    Q.push(1);
    Q.push(N + layer[1]);
    while (!Q.empty())
    {
        int v= Q.front();
        Q.pop();
        if (v > N && !has[v - N]) continue;
        for (int i = 0; i < G[v].size(); ++i)
        {
            int w = G[v][i].first;
            int c = G[v][i].second;
            if (dist[w] == -1 || dist[w] > dist[v] + c)
            {
                dist[w] = dist[v] + c;
                if (!in[w])
                {
                    in[w] = 1;
                    Q.push(w);
                }
            }
            if (w <= N)
                if (dist[N + layer[w]] == -1 || dist[N + layer[w]] > dist[v] + c)
                {
                    dist[N + layer[w]] = dist[v] + c;
                    if (!in[N + layer[w]])
                    {
                        in[N + layer[w]] = 1;
                        Q.push(N +layer[w]);
                    }
                }
        }
        in[v] = 0;
    }
}

void add(int x, int y, int z)
{
    pair<int, int> tmp;
    tmp.first = y;
    tmp.second = z;
    G[x].push_back(tmp);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int _;
    scanf("%d", &_);
    for (int __ = 1; __ <= _; ++__)
    {
        memset(has, 0, sizeof(has));
        printf("Case #%d: ", __);
        scanf("%d%d%d", &N, &M, &C);
        for (int i = 0; i <= N * 2; ++i)
            G[i].clear();
        for (int i = 1; i <= N; ++i)
        {
            scanf("%d", &layer[i]);
            has[layer[i]] = 1;
            if (layer[i] > 1)
            {
                add(N + layer[i] - 1, i, C);
                add(i, N + layer[i] - 1, C);
            }
            if (layer[i] < N)
            {
                add(N + layer[i] + 1, i, C);
                add(i, N + layer[i] + 1, C);
            }
        }
        int o, p, q;
        for (int i = 1; i <= M; ++i)
        {
            scanf("%d%d%d", &p, &q, &o);
            add(p, q, o);
            add(q, p, o);
        }
        SPFA();
        cout << dist[N] << endl;
    }
    return 0;
}
