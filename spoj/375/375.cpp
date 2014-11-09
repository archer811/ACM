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
const int maxn = 40005;
int head[10005],tot;
int dy[10005];
const int inf = 0x3fffffff;
struct Edge
{
    int to,next,w,id;
} edge[maxn];
void add(int u,int v,int w,int id)
{
    edge[tot].to=v;
    edge[tot].w=w;
    edge[tot].id = id;
    edge[tot].next=head[u];
    head[u]=tot++;
}
struct node
{
    int val,M,isRoot;
    node *c[2],*f;

};
node a[10005],*null = a;
void dfs(int u,int fa)
{
    int i,j;
    for(i=head[u]; i!=-1; i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa)continue;
        a[v].f=a+u;
        dy[edge[i].id]=v;
        a[v].val=a[v].M=edge[i].w;
        dfs(v,u);
    }
}
void init()
{
    null->val=null->M=-inf;
    null->f=null->c[0]=null->c[1]=null;
}
void up(node* p)
{
    p->M= max(max(p->c[0]->M,p->c[1]->M),p->val);
}
void rotate(node *p,int k)
{
    node *q = p->f;
    q->c[k]=p->c[!k];
    if(p->c[!k]!=null) p->c[!k]->f=q;
    p->c[!k]=q;
    p->f=q->f;
    if(q->f!=null)
    {
        if(p->f->c[0]==q) p->f->c[0]=p;
        if(p->f->c[1]==q) p->f->c[1]=p;
    }
    q->f=p;
    up(q);
    p->isRoot=q->isRoot;
    q->isRoot=0;
}


void splay(node *p)
{
    while (!p->isRoot)
    {
        if(p->f->isRoot)
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
    node *q=null;
    while(p!=null)
    {
        splay(p);
        p->c[1]->isRoot=1;
        p->c[1]=q;
        q->isRoot=0;
        //cout<<p->val<<"!!!"<<p->c[0]->val<<" "<<p->c[1]->val<<endl;
        up(p);
        q=p;
        p=p->f;
        //cout<<p->val<<"ooo"<<endl;
    }
    return q;
}
/*
int query(int x,int y)
{
    access(a+x);
    node *p=a+y,*q=null;
    int ans;
    while(p!=null)
    {
        splay(p);
        //cout<<p->val<<endl;
        if(p->f==null)
        {
            //cout<<p->val<<"*"<<q->M<<endl;
            ans=max(p->val,q->M);
            ans = max(ans,p->c[1]->M);
            return ans;
        }
        p->c[1]=q;
        up(p);
        q=p;
        p=p->f;
    }
}

*/
void query(int x,int y)
{
    access(a+x);
    node *lca=access(a+y);
    splay(a+x);
    int ans=lca->c[1]->M;
    if(lca!=a+x) ans=max(ans,a[x].M);
    printf("%d\n",ans);
}

char s[15];
int get()
{
    int x=0,flag=1;
    char c=getchar();
    while(!isdigit(c)) c=getchar();
    if(c=='-')
    {
        flag=-1,c=getchar();
        while(!isdigit(c)) c=getchar();
    }
    while(isdigit(c))
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*flag;
}
struct array
{
    int x,y;
} g[10005];
void change(int x,int y)
{
    node *p = a+x;
    access(p);
    p->val=y;
    up(p);
}
int main()
{
    int i,j,t,n;
    t = get();
    init();
    while(t--)
    {
        n = get();
        for(i=1; i<=n; i++)
            a[i].f=a[i].c[0]=a[i].c[1]=null,a[i].isRoot=1;
        memset(head,-1,sizeof(head));
        tot=0;

        for(i=1; i<n; i++)
        {
            int a,b,c;
            a = get();
            b = get();
            c = get();
            g[i].x=a;
            g[i].y=b;
            add(a,b,c,i);
            add(b,a,c,i);
        }
        a[1].val=a[1].M=-inf;
        dfs(1,-1);
        int x,y;
        while(scanf("%s",s)!=EOF)
        {
            if(s[0]=='D')break;
            x = get();
            y = get();
            if(s[0]=='C')
            {
                change(dy[x],y);
            }
            else if(s[0]=='Q')
            {
                //printf("%d\n",query(x,y));
                query(x,y);
            }
        }
    }
    return 0;
}

