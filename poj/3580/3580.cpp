#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

struct node
{
    node *ch[2],*p;
    bool rev;
    int Min,val,add,siz;
    inline int d()
    {
        return p->ch[1]==this;
    }
    inline void addit(int x)
    {
        Min += x;
        val += x;
        add += x;
    }
    inline void revit()
    {
        rev ^= 1;
    }
    inline void sc(node *x, int d)
    {
        ch[d]=x;
        x->p=this;
    }
    inline void update()
    {
        Min = min(val,min(ch[0]->Min,ch[1]->Min));
        siz = 1+ch[0]->siz+ch[1]->siz;
    }
    inline void relax();
}*nil,*root;
void node::relax()
{
    if(add)
    {
        for(int i=0; i<2; i++)
            if(ch[i]!=nil)
                ch[i]->addit(add);
        add = 0;
    }
    if(rev)
    {
        swap(ch[0],ch[1]);
        for(int i=0; i<2; i++)
            if(ch[i]!=nil)
                ch[i]->revit();
        rev=0;
    }
}
node *makenode(int x)
{
    node *p = new node;
    p->ch[0]=p->ch[1]=p->p=nil;
    p->add=0;
    p->rev=0;
    p->Min=p->val=x;
    p->siz=1;
    p->add=0;
    return p;
}

node* rot(node *x)
{
    node* p = x->p;
    p->relax();
    x->relax();
    int d = x->d();
    p->p->sc(x,p->d());
    p->sc(x->ch[d^1],d);
    x->sc(p,d^1);
    p->update();
    x->update();
    if(p==root)root=x;
}


node* splay(node* x,node* target = nil)
{
    x -> relax();
    while(x->p != target)
    {
        if(x->p->p == target)
            rot(x);
        else
        {
            x->d() == x->p->d() ? (rot(x), rot(x)) : (rot(x), rot(x));
        }
    }
    x->update();
}

node *select(int k)
{
    node* res = root;
    for(;;)
    {
        res ->relax();
        int s = res->ch[0]->siz;
        if(s==k)break;
        if(k>s)
        {
            k -= (s+1);
            res = res->ch[1];
        }
        else
            res = res->ch[0];
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
const int inf = 0x3fffffff;
void build(int l,int r)
{
    nil = makenode(inf);
    nil->siz=0;
    root = makenode(inf);
    int j;
    node *p,*q = root;
    for(int i=l; i<=r; i++)
    {
        scanf("%d",&j);
        p = makenode(j);
        q->sc(p,1);
        q=p;
    }
    node *last = makenode(inf);
    q -> sc(last,1);
    splay(last);
}
char str[10];
void revserve(int l,int r)
{
    if(l>=r)return;
    node* x = get(l,r);
    x->revit();
    splay(x);
}
void Revolve(int l, int r, int t)
{
    int len = r - l + 1;
    t = (t % len + len) % len;
    if (t == 0) return;
    revserve(l, r - t);
    revserve(r - t + 1, r);
    revserve(l, r);
}
void insert(int x,int v)
{
    node* y = get(x,x);
    y->relax();
    y->update();
    y->sc(makenode(v),1);
    splay(y);
}
int main()
{
    int i,j;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        build(1,n);
        int m;
        scanf("%d",&m);
        while(m--)
        {
            scanf("%s",str);
            if(str[0]=='A')
            {
                int a,b,v;
                scanf("%d%d%d",&a,&b,&v);
                node* x = get(a,b);
                x->addit(v);
                splay(x);
            }
            else if(str[0]=='R'&&str[3]=='E')
            {
                int a,b;
                scanf("%d%d",&a,&b);
                revserve(a,b);

            }
            else if(str[0]=='R')
            {
                int a,b,t;
                scanf("%d%d%d",&a,&b,&t);
                Revolve(a,b,t);
            }
            else if(str[0]=='I')
            {
                int x,p;
                scanf("%d%d",&x,&p);
                insert(x,p);
            }
            else if(str[0]=='D')
            {
                int x,p;
                scanf("%d%d",&x,&p);
                node* y = get(x,x)->p;
                //y->sc(nil,0);
                y->ch[0]=nil;
                splay(y);
            }
            else
            {
                int a,b;
                scanf("%d%d",&a,&b);
                node* x = get(a,b);
                printf("%d\n",x->Min);
            }
        }
    }
}
