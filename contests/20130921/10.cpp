#include <set>
#include <map>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define debug puts("here")
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define foreach(i,vec) for(unsigned i=0;i<vec.size();i++)
#define pb push_back
#define RD(n) scanf("%d",&n)
#define RD2(x,y) scanf("%d%d",&x,&y)
#define RD3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define RD4(x,y,z,w) scanf("%d%d%d%d",&x,&y,&z,&w)
#define All(vec) vec.begin(),vec.end()
#define MP make_pair
#define PII pair<int,int>
#define PQ priority_queue
#define cmax(x,y) x = max(x,y)
#define cmin(x,y) x = min(x,y)
#define Clear(x) memset(x,0,sizeof(x))
/*

#pragma comment(linker, "/STACK:1024000000,1024000000")

int size = 256 << 20; // 256MB
char *p = (char*)malloc(size) + size;
__asm__("movl %0, %%esp\n" :: "r"(p) );

*/

/******** program ********************/

const int MAXN = 100005;

int val[MAXN];
int po[MAXN],tol;
bool use[MAXN];
int n;

struct node
{
    int y,c,next;
} edge[MAXN];

inline void add(int x,int y,int c)
{
    edge[++tol].y = y;
    edge[tol].c = c;
    edge[tol].next = po[x];
    po[x] = tol;
}

struct tc  // tree chain subdivision
{
    int sz;     // x子树大小
    int dep;    // 节点x的深度
    int top;    // 节点x所在链的顶端节点
    int fa;     // 节点x的父亲
    int son;    // 重儿子
    int tid;    // 在线段树中的位置
} p[MAXN];

void dfsFind(int x,int fa,int dep)
{
    use[x] = true;
    p[x].dep = dep;
    p[x].sz = 1;
    p[x].son = 0;
    p[x].fa = fa;

    int mx = 0;
    for(int i=po[x]; i; i=edge[i].next)
    {
        int y = edge[i].y;
        if(use[y])continue;
        dfsFind(y,x,dep+1);
        p[x].sz += p[y].sz;
        if(p[y].sz>mx)
        {
            p[x].son = y;
            mx = p[y].sz;
        }
    }
}

int tid;
void dfsCon(int x,int fa)
{
    use[x] = true;
    p[x].tid = ++ tid;
    p[x].top = fa;
    if(p[x].son)
        dfsCon(p[x].son,fa);
    for(int i=po[x]; i; i=edge[i].next)
    {
        int y = edge[i].y;
        if(use[y])continue;
        dfsCon(y,y);
    }
}

struct Tree
{
    int l,r,mx;
    inline int mid()
    {
        return (l+r)>>1;
    }
} tree[MAXN<<2];

inline void update(int rt)
{
    tree[rt].mx = max(tree[rt<<1].mx,tree[rt<<1|1].mx);
}

void build(int l,int r,int rt)
{
    tree[rt].l = l;
    tree[rt].r = r;
    if(l==r)
    {
        tree[rt].mx = val[l];
        return;
    }
    int mid = tree[rt].mid();
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);

    update(rt);
}

void modify(int pos,int c,int rt)
{
    if(tree[rt].l==tree[rt].r)
    {
        tree[rt].mx = c;
        return;
    }
    int mid = tree[rt].mid();
    if(pos<=mid)
        modify(pos,c,rt<<1);
    else
        modify(pos,c,rt<<1|1);

    update(rt);
}

int ask(int l,int r,int rt)
{
    if(tree[rt].l==l&&tree[rt].r==r)
        return tree[rt].mx;
    int mid = tree[rt].mid();
    if(r<=mid)
        return ask(l,r,rt<<1);
    else if(l>mid)
        return ask(l,r,rt<<1|1);
    else
        return max( ask(l,mid,rt<<1),ask(mid+1,r,rt<<1|1) );
}

int main()
{

    int x,y,z,ncase;
    RD(ncase);
    while(ncase--)
    {
        RD(n);
        Clear(po);
        tol = 1;

        REP(i,2,n)
        {
            RD3(x,y,z);
            add(x,y,z);
            add(y,x,z);
        }

        Clear(use);
        dfsFind(1,1,1);

        tid = 0;
        Clear(use);
        dfsCon(1,1);

        for(int i=2; i<tol; i+=2)
        {
            int x = edge[i^1].y; // 对应于第x条边的节点 (x,y)
            int y = edge[i].y;

            if(p[x].dep>p[y].dep)
                val[ p[x].tid ] = edge[i].c;
            else
                val[ p[y].tid ] = edge[i].c;
        }

        build(2,n,1);

        char op[10];
        while(scanf("%s",op),op[0]!='D')
        {

            if(op[0]=='C')
            {
                RD2(x,z);
                y = edge[x<<1].y;
                x = edge[x<<1|1].y;

                if( p[x].dep>p[y].dep )
                    modify( p[x].tid,z,1 );
                else
                    modify( p[y].tid,z,1 );
            }
            else
            {
                RD2(x,y);
                int ans = -(1<<30);
                while( p[x].top != p[y].top )
                {
                    if( p[ p[x].top ].dep < p[ p[y].top ].dep )
                        swap(x,y);
                    ans = max(ans,ask(p[ p[x].top ].tid,p[x].tid,1));
                    x = p[ p[x].top ].fa;
                }
                if(p[x].dep>p[y].dep)
                    swap(x,y);
                if(x!=y)
                    ans = max(ans,ask(p[x].tid+1,p[y].tid,1));
                printf("%d\n",ans);
            }
        }
    }

    return 0;
}
