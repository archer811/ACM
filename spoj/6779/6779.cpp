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
const int N=200005;

struct node
{
    int val,sum,Max,LMax,RMax,Size;
    int isChanged;
    node *c[2],*f;

    void change(int x)
    {
        isChanged=1;
        val=x;
        sum=Size*x;
        Max=LMax=RMax=x>0?sum:0;
    }
};

node a[N],*nullNode=a;
int n;

void up(node *p)
{
    p->Size=p->c[0]->Size+p->c[1]->Size+1;
    p->sum=p->c[0]->sum+p->c[1]->sum+p->val;
    p->Max=max(max(p->c[0]->Max,p->c[1]->Max),p->c[0]->RMax+p->val+p->c[1]->LMax);
    p->LMax=max(p->c[0]->LMax,p->c[0]->sum+p->val+p->c[1]->LMax);
    p->RMax=max(p->c[1]->RMax,p->c[1]->sum+p->val+p->c[0]->RMax);
}

void pushDown(node *p)
{
    if(p->isChanged)
    {
        if(p->c[0]!=nullNode) p->c[0]->change(p->val);
        if(p->c[1]!=nullNode) p->c[1]->change(p->val);
        p->isChanged=0;
    }
}

void rotate(node *p,int k)
{
    node *q=p->f;
    pushDown(q);
    pushDown(p);
    q->c[k]=p->c[!k];
    if(p->c[!k]!=nullNode) p->c[!k]->f=q;
    p->c[!k]=q;
    p->f=q->f;
    if(q->f!=nullNode)
    {
        if(p->f->c[0]==q) p->f->c[0]=p;
        if(p->f->c[1]==q) p->f->c[1]=p;
    }
    q->f=p;
    up(q);
}

int isRoot(node *p)
{
    return p->f==nullNode||p->f->c[0]!=p&&p->f->c[1]!=p;
}


void splay(node *p)
 {
     pushDown(p);
     while (!isRoot(p))
     {
         if(isRoot(p->f))
         {
             if(p==p->f->c[0]) rotate(p,0);
             else rotate(p,1);
         }
         else
         {
             if(p->f->f->c[0]==p->f)
             {
                 if(p->f->c[0]==p) rotate(p->f,0);
                 else rotate(p,1);
                 rotate(p,0);
             }
             else
             {
                 if(p->f->c[1]==p) rotate(p->f,1);
                 else rotate(p,0);
                 rotate(p,1);
             }
         }
     }
     up(p);
}

node* access(node *p)
{
    node *q=nullNode;
    while(p!=nullNode)
    {
        splay(p);
        p->c[1]=q;
        up(p);
        q=p;
        p=p->f;
    }
    return q;
}


void change(int x,int y,int val)
{
    access(a+x);
    node *p=a+y,*q=nullNode;
    while(p!=nullNode)
    {
        splay(p);
        if(p->f==nullNode)
        {
            p->c[1]->change(val);
            if(q!=nullNode)
                q->change(val);
            p->val=val;
        }
        p->c[1]=q;
        up(p);
        q=p;
        p=p->f;
     }
}

int query(int x,int y)
{
    access(a+x);
    node *p=a+y,*q=nullNode;
    int ans;
    while(p!=nullNode)
    {
        splay(p);
        if(p->f==nullNode)
        {
            ans=max(p->c[1]->Max,q->Max);
            ans=max(ans,p->c[1]->LMax+q->LMax+p->val);
            return ans;
        }
        p->c[1]=q;
        up(p);
        q=p;
        p=p->f;
     }
}

struct Node
{
    int v,next;
};

Node edges[N];
int head[N],e;


void Add(int u,int v)
{
    edges[e].v=v;
    edges[e].next=head[u];
    head[u]=e++;

    edges[e].v=u;
    edges[e].next=head[v];
    head[v]=e++;
}

void build()
{
    queue<int> Q;
    Q.push(1);
    int i,u,v;
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();

        for(i=head[u];i!=-1;i=edges[i].next)
        {
            v=edges[i].v;
            if(a+v==a[u].f) continue;
            a[v].f=a+u;
            Q.push(v);
        }
    }

}


void init()
{
  //  nullNode=new node();
    nullNode->Size=0;
    nullNode->isChanged=0;
    nullNode->c[0]=nullNode->c[1]=nullNode->f=nullNode;
    nullNode->Max=nullNode->LMax=nullNode->RMax=nullNode->val=0;
    scanf("%d",&n);
    int i,u,v,dis;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&dis);
        a[i].c[0]=a[i].c[1]=a[i].f=nullNode;
        a[i].Size=1;
        a[i].isChanged=0;
        a[i].sum=a[i].Max=a[i].LMax=a[i].RMax=a[i].val=dis;
    }
    memset(head,-1,sizeof(head));
    e=0;
    for(i=1;i<=n-1;i++) scanf("%d%d",&u,&v),Add(u,v);
    build();
}

int main()
{
    init();
    int a,b,c,op,m;
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d",&op);
        if(op==1) scanf("%d%d",&a,&b),printf("%d\n",query(a,b));
        else
        {
            scanf("%d%d%d",&a,&b,&c);
            change(a,b,c);
        }
    }
    return 0;
}

