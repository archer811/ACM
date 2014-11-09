#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
struct node
{
    node *ch[2], *p;
    int val;
    bool rev;
    inline bool dir()
    {
        return this == p->ch[1];
    }
    inline bool isroot()
    {
        return !(this == p->ch[0] || this == p->ch[1]);
    }
    inline bool revit()
    {
        rev ^= 1;
    }
    inline void relax();
    inline void update();
} *root[10005],*nil;
void node::update()
{

}
void node::relax()
{
    if(rev)
    {
        swap(ch[0],ch[1]);
        for(int i=0;i<=2;i++)
            if(ch[i]!=nil)
                ch[i]->revit();
        rev=0;
    }
}
node* makenode(int x)
{
    node *cur = new node;
    cur->ch[0] = cur->ch[1] = cur->p = nil;
    cur->val=x;
    cur->rev=0;
    return cur;
}
void rotate(node *u)
{
    node *p = u->p;
    p->relax(), u->relax();
    bool d = u->dir();
    u->p = p->p;
    if (!p->isroot()) p->p->ch[p->dir()] = u;
    if (u->ch[d^1] != nil) u->ch[d^1]->p = p;
    p->p = u, p->ch[d] = u->ch[d^1], u->ch[d^1] = p;
    p->update(), u->update();
}
void splay(node *u)
{

    u->relax();
    while (!u->isroot())
    {
        if (u->p->isroot())
            rotate(u);
        else
            u->dir() == u->p->dir() ? (rotate(u->p), rotate(u)) : (rotate(u), rotate(u));
    }
    u->update();
}
node* expose(node *u)
{
    node *v = nil;
    //if(u!=NULL)cout<<"!"<<u->val<<endl;
    for (v = nil; u != nil; u = u->p)
    {
        //if(u==NULL)cout<<"nooo"<<endl;
        splay(u);
        //cout<<"ooo"<<endl;
        u->ch[1] = v;      //断开u与u下面（Splay中右边）的点的连接
        //这里可以看到把p和fa一起存的好处：我们不用u->ch[1]->fa = u这样写了
        (v = u)->update(); //递归处理
    }
    return v;              //返回最后一个访问的点
}
bool sametree(node *u, node *v)
{
    while (u->p != nil) u = u->p;
    while (v->p != nil) v = v->p;
    return u == v;
}
void evert(node *u)
{
    expose(u)->rev ^= 1;  //提取到根的路径并反转（这样原来在u下面的点便到了u上面，ie u变成了根）
    splay(u);             //清标记
}
void link(node *u, node *v)
{
    if (sametree(u, v))
    {
        //puts("-1");
        return;
    }
    evert(u);
    u->p = v;
    expose(u);
}
void cut(node *u, node *v)
{
    if (u == v || !sametree(u, v))
    {
        // puts("-1");
        return;
    }
    evert(u);
    expose(v);
    splay(v);
    v->ch[0]->p = nil; //双向断开
    v->ch[0] = nil;
    v->update();
}
char s[15];
const int inf = 0x3fffffff;
int main()
{
    int i,j,n,q;
    scanf("%d%d",&n,&q);
    {
        nil = makenode(inf);
        nil->ch[0] = nil->ch[1] = nil->p = nil;
        for(i=1; i<=n; i++)
            root[i]=makenode(i);
        while(q--)
        {
            int a,b;
            scanf("%s%d%d",s,&a,&b);
            if(s[0]=='Q')
            {
                if(sametree(root[a],root[b]))printf("Yes\n");
                else printf("No\n");
            }
            else if(s[0]=='C')
            {
                link(root[a],root[b]);
            }
            else
            {
                cut(root[a],root[b]);
            }
        }
    }
    return 0;
}
