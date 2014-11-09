#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define pb push_back
#define mp make_pair
const int MAXN = 100010;
struct Node
{
    int l, r;
    int cnt;
    int ls, rs;
} p[MAXN * 20];
int n, m, tot, a[MAXN], id[MAXN], s[MAXN], u[MAXN], v[MAXN], k[MAXN], size, root[MAXN];
int lca[MAXN], f[MAXN];
bool flag[MAXN];
vector<int> e[MAXN];
vector<pair<int,int> > query[MAXN];
inline bool cmp(int x, int y)
{
    return a[x] < a[y];
}
void init()
{
    int i;
    scanf("%d%d", &n, &m);
    for(i = 1;i <= n; ++i)
        scanf("%d", &a[i]), id[i] = i;
    sort(id + 1, id + n + 1, cmp);
    for (s[1] = a[id[1]], a[id[1]] = tot = 1, i = 2; i <= n ; ++i)
        a[id[i]] = s[tot] == a[id[i]] ? tot : (s[tot + 1] = a[id[i]], ++tot);
    for(int i = 1, x, y; i < n; ++i)
    {
        scanf("%d%d", &x, &y);
        e[x].pb(y), e[y].pb(x);
    }
    for(int i = 1;i <= m; ++i)
    {
        scanf("%d%d%d", &u[i], &v[i], &k[i]);
        query[u[i]].pb(mp(v[i], i)), query[v[i]].pb(mp(u[i], i));
    }
}
int build(int l, int r)
{
    int now = size++;
    p[now].l = l, p[now].r = r, p[now].cnt = 0;
    if(l == r) return now;
    int mid = (l + r) >> 1;
    p[now].ls = build(l, mid);
    p[now].rs = build(mid + 1, r);
    return now;
}
int insert(int c, int ps)
{
    int now = size++;
    p[now] = p[c], p[now].cnt++;
    if(p[now].l == p[now].r) return now;
    int mid = (p[now].l + p[now].r) >> 1;
    if(ps <= mid) p[now].ls = insert(p[c].ls, ps);
    else p[now].rs = insert(p[c].rs, ps);
    return now;
}
int find(int c1, int c2, int c3, int tp, int k)
{
    if(p[c2].l == p[c2].r) return p[c2].l;
    int mid = (p[c1].l + p[c1].r) >> 1;
    int ano = (tp >= p[c1].l && tp <= mid);
    if(k <= p[p[c1].ls].cnt + p[p[c2].ls].cnt - 2 * p[p[c3].ls].cnt + ano) return find(p[c1].ls, p[c2].ls, p[c3].ls, tp, k);
    else return find(p[c1].rs, p[c2].rs, p[c3].rs, tp, k - (p[p[c1].ls].cnt + p[p[c2].ls].cnt - 2 * p[p[c3].ls].cnt + ano));
}
int findSet(int x)
{
    if(f[x] != x) f[x] = findSet(f[x]);
    return f[x];
}
void LCA(int x, int father)
{
    f[x] = x;
    root[x] = insert(root[father], a[x]);
    for(int i = 0; i < (int)e[x].size(); ++i)
    {
        int to = e[x][i];
        if(to == father) continue;
        LCA(to, x);
        f[to] = x;
    }
    flag[x] = true;
    for(int i = 0; i < (int)query[x].size(); ++i)
    {
        int to = query[x][i].first, idx = query[x][i].second;
        if(flag[to]) lca[idx] = findSet(to);
    }
}
void solve()
{
    memset(flag, false, sizeof(flag));
    root[1] = build(1, tot);
    LCA(1, -1);
    for(int i = 1;i <= m; ++i)
        printf("%d\n", s[find(root[u[i]], root[v[i]], root[lca[i]], a[lca[i]], k[i])]);
}
int main()
{
//    freopen("in.txt", "r", stdin);
    init();
    for(int i=1;i<n;i++)
    {
        cout<<i<<" "<<a[i]<< " "<<s[i]<<endl;
    }

    solve();
    return 0;
}
