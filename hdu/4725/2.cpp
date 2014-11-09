#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 3e5 + 7;
const int INF = 1e9 + 7;
struct heapnode
{
    int d;
    int  u;
    bool operator < (const heapnode &rhs) const
    {
        return d > rhs.d;
    }
};
struct Edge
{
    int from, to, cost;
};

vector<int> G[MAX_N];
vector<Edge> edges;
int N,M,C;
int d[MAX_N];
bool done[MAX_N];
//vector <int> lay[MAX_N];

void add_edge(int from, int to, int cost)
{
    edges.push_back((Edge)
    {
        from, to, cost
    });
    int m = edges.size();
    G[from].push_back(m - 1);
}

void dij(int s)
{
    memset(done,0,sizeof(done));
    for(int i = 1; i <= 3 * N; ++i)
    {
        d[i] = INF;
    }
    d[s] = 0;
    priority_queue <heapnode> q;
    q.push((heapnode)
    {
        d[s], s
    });

    while(!q.empty())
    {
        heapnode x = q.top();
        q.pop();
        int u = x.u;
        if(done[u]) continue;
        done[u] = 1;
        if(u == N) return;

        for(int i = 0; i < G[u].size(); ++i)
        {
            Edge &e = edges[ G[u][i] ];
            if(d[e.to] > d[u] + e.cost)
            {
                d[e.to] = d[u] + e.cost;
                q.push((heapnode)
                {
                    d[e.to], e.to
                });
            }
        }
    }
}
int main()
{

    // freopen("sw.in","r",stdin);
    int t;
    scanf("%d",&t);
    int ca = 1;
    while(t--)
    {
        scanf("%d%d%d",&N,&M,&C);
        for(int i = 1; i <= 3 * N; ++i) G[i].clear();
        edges.clear();

        for(int i = 1; i <= N; ++i)
        {
            int ch;
            scanf("%d",&ch);
            add_edge(i, ch + N, 0);
            add_edge(ch + 2 * N, i, 0);

        }




        for(int i = N + 1; i <= 2 * N - 1; ++i)
        {
            add_edge(i, i + 1 + N, C);
            add_edge(i + 1, i + N, C);
        }

        for(int i = 1; i <= M; ++i)
        {
            int u, v, w;
            scanf("%d%d%d",&u, &v, &w);
            add_edge(u, v, w);
            add_edge(v, u, w);
        }

        dij(1);
        printf("Case #%d: %d\n",ca++, (d[N] == INF) ? -1 : d[N]);
    }

    return 0;
}
