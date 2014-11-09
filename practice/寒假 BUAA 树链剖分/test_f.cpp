#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
using namespace std;
struct Node
{
    Node *ch[2];
    int v;
    int s;
    int flip;
    Node(int _v)
    {
        v = _v;
        s=1;
        flip=0;
        ch[0]=ch[1]=NULL;
    }
    void maintain()
    {
        s=1;
        if(ch[0]!=NULL)
            s+=ch[0]->s;
        if(ch[1]!=NULL)
            s+=ch[1]->s;
    }
    void pushdown()
    {
        if(flip)
        {
            flip=0;
            swap(ch[0],ch[1]);
            if(ch[0]!=NULL)
                ch[0]->flip = !ch[0]->flip;
            if(ch[1]!=NULL)
                ch[1]->flip = !ch[1]->flip;
        }
    }
};

void rotate(Node* &k,int d)
{
    Node* p = k->ch[d^1];
    k->ch[d^1]=p->ch[d];
    p->ch[d]=k;
    k->maintain();
    p->maintain();
    k = p;
}
void output(Node* k)
{
    k->pushdown();
    if(k->ch[0]!=NULL)
    {
        output(k->ch[0]);
    }
    if(k->v>0)
        printf("%d\n",k->v);
    if(k->ch[1]!=NULL)
    {
        output(k->ch[1]);
    }
}
void splay(Node* &k,int num)
{
    int d;
    k->pushdown();
    int tmp=0;
    if(k->ch[0]!=NULL)tmp=k->ch[0]->s;
    if(num>tmp+1)
        num -= tmp+1,d=1;
    else if(num<=tmp)
        d=0;
    else d=-1;
    if(d!=-1)
    {
        Node* p = k->ch[d];
        p->pushdown();
        int k2=num,d2;
        int t2=0;
        if(p->ch[0]!=NULL)t2=p->ch[0]->s;
        if(num>t2+1)k2=num-t2-1,d2=1;
        else if(num<=t2)k2=num,d2=0;
        else
        {
            k2=num;
            d2=-1;
        }
        if(d2!=-1)
        {
            splay(p->ch[d2],k2);
            if(d==d2)
            {
                rotate(k,d^1);
            }
            else
            {
                rotate(k->ch[d],d);
            }
        }
        rotate(k,d^1);

    }
}

Node* merge(Node* left,Node* right)
{
    splay(left,left->s);
    left->ch[1]=right;
    left->maintain();
    return left;
}
void split(Node* o,int k,Node* &left,Node* &right)
{
    splay(o,k);
    left = o;
    right = o->ch[1];
    o->ch[1]=NULL;
    left->maintain();
}
int main()
{
    int i,j,n,m,a,b;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        Node *root = new Node(0);
        for(i=1; i<=n; i++)
        {
            Node *now = new Node(i);
            root = merge(root,now);
        }
        while(m--)
        {
            scanf("%d%d",&a,&b);
            Node *left,*right,*mid,*o;
            split(root,a,left,o);
            split(o,b-a+1,mid,right);
            mid->flip^=1;
            root=merge(merge(left,right),mid);
        }
        output(root);
    }
}
