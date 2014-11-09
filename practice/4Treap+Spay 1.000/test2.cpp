#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <string>
#include <time.h>
#include <math.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define INF 0x3f3f3f3f
#define eps 1e-8
#define pi acos(-1.0)
typedef long long ll;
ll ran()
{
    static ll ranx=323232;
    return ranx+=ranx<<2|1;
}
struct Node
{
    Node *l,*r;
    ll delta,sum,size,fix,key;
}*root,*nill,mem[1101000];
ll tot;
void up(Node *o)
{
    if(o==nill)return;
    o->size=o->l->size+o->r->size+1;
    o->sum=o->key;
    if(o->l!=nill)o->sum+=o->l->sum;
    if(o->r!=nill)o->sum+=o->r->sum;
}
void down(Node *o)
{
    if(o->delta)
    {
        o->key+=o->delta;
        if(o->l!=nill)o->l->delta+=o->delta,o->l->sum+=o->l->size*o->delta;
        if(o->r!=nill)o->r->delta+=o->delta,o->r->sum+=o->r->size*o->delta;
        o->delta=0;
    }
}
void newnode(Node *&o,ll val)
{
    o=&mem[tot++];
    o->l=o->r=nill;
    o->size=1;
    o->fix=ran();
    o->sum=o->key=val;
    o->delta=0;
}
void cut(Node *o,Node *&a,Node *&b,int p)
{
    if (o->size <= p) a = o,b = nill;
    else if (p==0) a = nill,b = o;
    else
    {
        down(o);
        if (o->l->size >= p)
        {
            b = o;
            cut(o->l,a,b->l,p);
            up(b);
        }
        else
        {
            a = o;
            cut(o->r,a->r,b,p - o->l->size - 1);
            up(a);
        }
    }
}
void merge(Node *&o,Node *a,Node *b)
{
    if (a==nill) o = b;
    else if (b==nill) o = a;
    else
    {
        if (a->fix> b->fix)
        {
            down(a);
            o = a;
            merge(o->r,a->r,b);
        }
        else
        {
            down(b);
            o = b;
            merge(o->l,a,b->l);
        }
        up(o);
    }
}
void add(ll l,ll r,ll val)
{
    Node *a,*b,*c;
    cut(root,a,b,l-1);
    cut(b,b,c,r-l+1);
    //b->key+=val;
    b->delta+=val;
    b->sum+=val*b->size;
//	up(b);
    merge(a,a,b);
    merge(root,a,c);
}
ll query(ll l,ll r)
{
    Node *a,*b,*c;
    cut(root,a,b,l-1);
    cut(b,b,c,r-l+1);
    ll ans=b->sum;
    merge(b,b,c);
    merge(root,a,b);
    return ans;
}
void del(ll p)
{
    Node *a,*b,*c;
    cut(root,a,b,p-1);
    cut(b,b,c,1);
    merge(root,a,c);
}
Node *Ins(ll x)
{
    if(x==0)return nill;
    if(x==1)
    {
        int d;
        Node *a;
        scanf("%lld",&d);
        newnode(a,d);
        return a;
    }
    Node *a,*b;
    int m=x>>1;
    a=Ins(m);
    b=Ins(x-m);
    merge(a,a,b);
    return a;
}
void ins(ll pos,ll x)
{
    ll d;
    Node *a,*b,*c,*t;
    cut(root,a,b,pos);
    c=Ins(x);
    merge(a,a,c);
    merge(root,a,b);
}
int main()
{
    //freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    ll i,j,k,m,n;
    while(~scanf("%lld%lld",&n,&m))
    {
        Node* g;
        cout<<g->delta<<endl;
        /*
        tot=0;
        newnode(nill,0);
        nill->size=0;
        root=nill;
        ins(0,n);
        while(m--)
        {
            char op[3];
            scanf("%s",op);
            if(op[0]=='Q')
            {
                ll l,r;
                scanf("%lld%lld",&l,&r);
                printf("%lld\n",query(l,r));
            }
            else
            {
                scanf("%lld%lld%lld",&i,&j,&k);
                add(i,j,k);
            }
        }
        /*Node *a,*b,*c;
        cut(root,a,b,0);
        cut(b,b,c,1);
        cout<<a->size<<" "<<b->size<<" "<<c->size<<endl;
        cout<<b->key<<" "<<b->delta<<" "<<b->sum<<endl;
        */
    }
    return 0;
}
