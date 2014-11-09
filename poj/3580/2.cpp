#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 10, inf = 1<<29;

struct node
{
    node *ch[2], *p;
    bool rev;
    int add, val, min, size;
    inline bool d()
    {
        return p->ch[1] == this;
    }
    inline void addIt(int x)
    {
        add += x, val += x, min += x;
    }
    inline void revIt()
    {
        rev ^= 1;
    }
    inline void sc(node *y, int d)
    {
        ch[d] = y;
        y->p = this;
    }
    inline void update()
    {
        this->min = std::min(val, std::min(ch[0]->min, ch[1]->min));
        size = ch[0]->size + ch[1]->size + 1;
    }
    inline void relax();
} *nil, *root;

void node::relax()
{
    if (add)
    {
        for (int i = 0; i < 2; ++i)
            if (ch[i] != nil)
                ch[i]->addIt(add);
        add = 0;
    }
    if (rev)
    {
        swap(ch[0], ch[1]);
        for(int i=0; i<2; i++)
            if(ch[i]!=nil)
                ch[i]->revIt();
        rev = false;
    }
}

node* makenode(int x)
{
    node *cur = new node;
    cur->ch[0] = cur->ch[1] = cur->p = nil;
    cur->val = cur->min = x;
    cur->size = 1;
    cur->add = cur->rev = 0;
    return cur;
}

node* rot(node *x)
{
    node *p = x->p;
    p->relax(), x->relax();
    int d = x->d();
    p->p->sc(x, p->d());
    p->sc(x->ch[d^1], d);
    x->sc(p, d^1);
    p->update(), x->update();
    if (p == root) root = x;
}

void splay(node *x, node *target = nil)
{
    x->relax();
    while (x->p != target)
    {
        if (x->p->p == target)
            rot(x);
        else
            x->d() == x->p->d() ? (rot(x), rot(x)) : (rot(x), rot(x));
    }
    x->update();
}

node* select(int k)
{
    node* res = root;
    for (;;)
    {
        res->relax();
        int s = res->ch[0]->size;
        if (s == k) break;
        if (s < k)
        {
            k -= (s + 1);
            res = res->ch[1];
        }
        else res = res->ch[0];
    }
    splay(res);
    return res;
}

node*& get(int l, int r)
{
    node *x = select(l - 1), *y = select(r + 1);
    splay(x);
    splay(y, x);
    return y->ch[0];
}

void build(int l, int r)
{
    nil = makenode(inf);
    //nil->ch[0] = nil->ch[1] = nil->p = nil;
    nil->size = 0;
    root = makenode(inf);
    node *p, *q = root;
    int x;
    for (int i = l; i <= r; ++i)
    {
        scanf("%d", &x);
        p = makenode(x);
        q->sc(p, 1);
        q = p;
    }
    node *last = makenode(inf);
    q->sc(last, 1);
    splay(last);
}

void Reverse(int l, int r)
{
    if (l >= r) return;
    node *p = get(l, r);
    p->revIt();
    splay(p);
}

void Revolve(int l, int r, int t)
{
    int len = r - l + 1;
    t = (t % len + len) % len;
    if (t == 0) return;
    Reverse(l, r - t);
    Reverse(r - t + 1, r);
    Reverse(l, r);
}

void Insert(int pos, int val)
{
    node *p = get(pos, pos);
    p->relax(), p->update();
    p->sc(makenode(val), 1);
    splay(p);
}

void Delete(int pos)
{
    node *p = get(pos, pos)->p;
    p->sc(nil, 0);
    splay(p);
}

int main()
{
    int n, m;
    scanf("%d", &n);
    build(1, n);
    scanf("%d", &m);
    char op[10];
    int x, y, val;
    node *p, *q, *tmp;
    while (m--)
    {
        scanf(" %s", op);
        switch (op[0])
        {
        case 'A':
            scanf("%d%d%d", &x, &y, &val);
            p = get(x, y);
            p->addIt(val);
            splay(p);
            break;
        case 'R':
            scanf("%d%d", &x, &y);
            op[3] == 'E' ? Reverse(x, y) : (scanf("%d", &val), Revolve(x, y, val));
            break;
        case 'I':
            scanf("%d%d", &x, &y);
            Insert(x, y);
            break;
        case 'D':
            scanf("%d", &x);
            Delete(x);
            break;
        case 'M':
            scanf("%d%d", &x, &y);
            p = get(x, y);
            printf("%d\n", p->min);
            break;
        }
    }
    return 0;
}
