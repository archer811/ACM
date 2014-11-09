#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;
#ifdef __int64
typedef __int64 ll;
#else
typedef long long ll;
#endif
/*
const int maxn = 400005;
int head[maxn],tot;
struct Edge
{
    int to,next;
}edge[maxn];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}*/
const int maxn = 1000006;
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
struct node
{
    node *ch[2],*p;
    bool rev;
    inline bool d(){return ch[1]==this;}
    void sc(node *y,int d){ch[d]=y;y->p = this;}
}*nill,*root;
node* makenode(int x)
{
    node *cur = new node;
    cur->ch[0]=cur->ch[1]=cur->p=nill;
    cur->rev=0;
    return cur;
}
node* rot(node *x)
{
    node *p = x->p;
    int d = x->d();
    p->p->sc(x,p->d());
    p->sc(x->ch[d^1],d);
    x->sc(p,d^1);
    if(p==root)root=x;
}
void splay(node *x,node *target = nill)
{

}
int main()
{
    int i,j;
    return 0;
}
