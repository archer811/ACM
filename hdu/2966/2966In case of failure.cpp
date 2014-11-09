#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int k = 2;
#define lchd idx << 1
#define rchd idx << 1 | 1
#define ll __int64
const int MAXN =200000;
const ll inf = 0x7777777777777777ll;

inline ll sqr(ll x){ return x * x; }

int n;               //k为维数, n为点数
struct point
{
    ll x[2];
}po[200010],ans[200010];

struct kd_Tree
{
    point p;
    int succeed;    //记录后代数，判断是否叶子。
}tree[MAXN];

struct node
{
    point p;
    ll dis;
    friend bool operator < (node n1, node n2)
    {
        return n1.dis < n2.dis;
    }
};

priority_queue<node> nq;            //维护前m大数的堆。
point le[MAXN], ri[MAXN];           //归并操作用的两个数组

ll cald(point p1, point p2)
{
    ll d = 0;
    for(int i = 0; i < k; i++)
        d += sqr(p1.x[i] - p2.x[i]);
    return d;
}

void merge(point p[], int l, int m, int r, int dim)
{
    for(int i = l; i <= m; i++)
        le[i - l] = p[i];
    for(int i = m + 1; i <= r; i++)
        ri[i - m - 1] = p[i];
    le[m - l + 1].x[dim] = inf;
    ri[r - m].x[dim] = inf;
    int ltop = 0, rtop = 0;
    for(int i = l; i <= r; )
    {
        if(le[ltop].x[dim] < ri[rtop].x[dim])
            p[i++] = le[ltop++];
        else p[i++] = ri[rtop++];
    }
}

void mergesort(point p[], int l, int r, int dim)
{
    int m = (l + r) >> 1;
    if(l < r)
    {
         mergesort(p, l, m, dim);
         mergesort(p, m + 1, r, dim);
         merge(p, l, m, r, dim);
    }
}

//建树，采用wiki上的建树方法。
void build(point po[], int l, int r, int idx, int dep)
{
    if(l > r) return;
    tree[idx].succeed = r - l;
    tree[lchd].succeed = tree[rchd].succeed = -1;
    int dim = dep % k;
    mergesort(po, l, r, dim);           //按某一维进行排序
    int mid = (l + r) >> 1;
    tree[idx].p = po[mid];
    build(po, l, mid - 1, lchd, dep + 1);
    build(po, mid + 1, r, rchd, dep + 1);
}

//询问前m近的点。
//与最近邻相似，先一路搜到叶子，然后如果当前得到的点数<m时，要搜索所有的子树。
//得到m个点之后就维护一个大小为m的堆，当前节点距离<堆顶元素距离时，将当前节点加入，堆顶元素弹出。
//其余与最近邻询问相似。
void query(point p, int idx, int dep, int m)
{
    if(tree[idx].succeed == -1) return;
    node nd; nd.p = tree[idx].p;
    nd.dis = cald(nd.p, p);
    if(tree[idx].succeed == 0)
    {
        if(nq.size() < m) nq.push(nd);
        else
        {
            if(nd.dis < nq.top().dis)
            {
                nq.pop();
                nq.push(nd);
            }
        }
        return;
    }
    int dim = dep % k;
    if(p.x[dim] < tree[idx].p.x[dim])
    {
        query(p, lchd, dep + 1, m);
        if(nq.size() < m)
        {
            nq.push(nd);
            query(p, rchd, dep + 1, m);
        }
        else
        {
            if(nd.dis < nq.top().dis)
            {
                nq.pop();
                nq.push(nd);
            }
            ll mx = nq.top().dis;
            //如果要查询的点与超平面的距离 < 堆顶元素的距离，则要到另一边超平面去查询
            if(sqr(p.x[dim] - tree[idx].p.x[dim]) < mx)
                query(p, rchd, dep + 1, m);
        }
    }
    else
    {
        query(p, rchd, dep + 1, m);
        if(nq.size() < m)
        {
            nq.push(nd);
            query(p, lchd, dep + 1, m);
        }
        else
        {
            if(nd.dis < nq.top().dis)
            {
                nq.pop();
                nq.push(nd);
            }
            ll mx = nq.top().dis;
            if(sqr(p.x[dim] - tree[idx].p.x[dim]) < mx)
                query(p, lchd, dep + 1, m);
        }
    }
}
void print(point p)
{
    for(int j = 0; j < k; j++)
    {
        printf("%d", p.x[j]);
        j == k - 1 ? puts("") : printf(" ");
    }
}
int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            for(j=0;j<2;j++)
              scanf("%I64d",&po[i].x[j]),ans[i].x[j]=po[i].x[j];
        build(po,0,n-1,1,0);
        node nd[10];
        for(i=0;i<n;i++)
        {
            query(ans[i], 1, 0, 2);
            for(int j = 0; !nq.empty(); j++)
                nd[j].p = nq.top().p, nq.pop();
            printf("%I64d\n",cald(nd[0].p,ans[i]));
        }
    }
}
