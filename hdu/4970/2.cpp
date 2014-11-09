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
struct Node *nill;
struct Node
{
    int sz;
    bool rev;
    Node *ch[2],*fa;
    void up()
    {
        if (this==nill) return ;
        sz = ch[0]->sz + ch[1]->sz + 1;
    }
    void down()
    {
        if (this==nill) return ;
        if (!rev) return ;
        rev = false;
        ch[0]->revc();
        ch[1]->revc();
    }
    bool d()
    {
        return fa->ch[1]==this;
    }
    void revc()
    {
        rev ^= 1;
        swap(ch[0],ch[1]);
    }
    void setc(Node *o,int c)
    {
        ch[c] = o;
        o->fa = this;
        up();
    }
    void rot()
    {
        int c = d(),cc = fa->d();
        Node *z = fa->fa;
        Node *tmp = fa;
        fa->setc(ch[c^1],c);
        setc(tmp,c^1);
        z->setc(this,cc);
    }
    void D()
    {
        if (this==nill) return ;
        fa->D();
        down();
    }
    void splay(Node *aim = nill)
    {
        D();
        while (fa!=aim)
        {
            if (fa->fa!=aim)
            {
                d()==fa->d() ? fa->rot() : rot();
            }
            rot();
        }
    }
};
int main()
{
    int i,j;
    return 0;
}
