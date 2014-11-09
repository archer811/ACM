#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN = 200010;

int hashmap[MAXN], hcnt;
int tree[MAXN];

int hash(int x)
{
    return lower_bound(hashmap, hashmap + hcnt, x) - hashmap + 1;
}

inline int lowbit(int x)
{
    return x & -x;
}

void modify(int k, int val)
{
    while(k <= hcnt)
    {
        tree[k] += val;
        k += lowbit(k);
    }
}

int get_sum(int k)
{
    int res = 0;
    while(k)
    {
        res += tree[k];
        k -= lowbit(k);
    }
    return res;
}

struct Node
{
    int v, l, r, id;
    Node() {}
    Node(int v, int l, int r, int id): v(v), l(l), r(r), id(id) {}
    bool operator < (const Node &rhs) const
    {
        if(r != rhs.r) return r > rhs.r;
        if(l != rhs.l) return l < rhs.l;
        return (v == 0) < (rhs.v == 0);
    }
};

bool cmp_id(const Node &a, const Node &b)
{
    return a.id < b.id;
}

Node p[MAXN];
int ans[MAXN], tl[MAXN], tr[MAXN];
int n;

void solve(int l, int r)
{
    if(l == r) return ;
    int mid = (l + r) >> 1;
    solve(l, mid);
    solve(mid + 1, r);
    sort(p + l, p + r + 1);
    for(int i = l; i <= r; ++i)
    {
        if(p[i].id <= mid)
        {
            if(p[i].v) modify(p[i].l, p[i].v);
        }
        else
        {
            if(!p[i].v) ans[p[i].id] += get_sum(p[i].l);
        }
    }
    for(int i = l; i <= r; ++i)
    {
        if(p[i].id <= mid && p[i].v) modify(p[i].l, -p[i].v);
    }
    sort(p + l, p + r + 1, cmp_id);
}

int main()
{
    while(scanf("%d", &n) != EOF)
    {
        int tcnt = 0;
        hcnt = 0;
        char c;
        for(int i = 1, t, u; i <= n; ++i)
        {
            scanf(" %c", &c);
            if(c == 'D')
            {
                scanf("%d%d", &t, &u);
                p[i] = Node(1, t, u, i);
                hashmap[hcnt++] = t;
                hashmap[hcnt++] = u;
                tl[++tcnt] = t;
                tr[tcnt] = u;
            }
            if(c == 'C')
            {
                scanf("%d", &t);
                p[i] = Node(-1, tl[t], tr[t], i);
            }
            if(c == 'Q')
            {
                scanf("%d%d", &t, &u);
                p[i] = Node(0, t, u, i);
                hashmap[hcnt++] = t;
                hashmap[hcnt++] = u;
            }
        }
        sort(hashmap, hashmap + hcnt);
//        for(int i=1;i<hcnt;i++)
//        {
//            cout<<i<<" "<<hashmap[i].l<<" "<<
//            hashmap[i].r<<"  "<<hashmap[i].v<<" "
//            <<hashmap[i].id<<endl;
//        }
        hcnt = unique(hashmap, hashmap + hcnt) - hashmap;
        for(int i = 1; i <= n; ++i)
        {
            p[i].l = hash(p[i].l);
            p[i].r = hash(p[i].r);
        }
        memset(ans + 1, 0, n * sizeof(int));
        solve(1, n);
        for(int i = 1; i <= n; ++i)
            if(p[i].v == 0) printf("%d\n", ans[i]);
    }
}
