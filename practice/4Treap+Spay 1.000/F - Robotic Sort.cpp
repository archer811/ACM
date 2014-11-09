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
    Node* ch[2];
    int v;
    int s;
    int flip;
    int Min;
    Node(int _v)
    {
        v=_v;
        Min=_v;
        s=1;
        flip=0;
        ch[0]=ch[1]=NULL;
    }
    void maintain()
    {
        s=1;
        Min=v;
        if(ch[0]!=NULL)
        {
            s+=ch[0]->s;
            if(ch[0]->Min<Min)
            {
                Min = ch[0]->Min;
                //minindex=ch[0]->minindex;
            }
        }
        if(ch[1]!=NULL)
        {
            s+=ch[1]->s;
            if(ch[1]->Min<Min)
            {
                Min = ch[1]->Min;
                //minindex=ch[1]->minindex;
            }
        }
    }
    void pushdown()
    {
        if(flip)
        {
            flip=0;
            swap(ch[0],ch[1]);
            if(ch[0]!=NULL)
                ch[0]->flip=!ch[0]->flip;
            if(ch[1]!=NULL)
                ch[1]->flip=!ch[1]->flip;
        }
    }
}*root;
void rotate(Node* &k,int d)
{
    Node* y = k->ch[d^1];
    k->ch[d^1] = y->ch[d];
    y->ch[d]=k;
    k->maintain();
    y->maintain();
    k=y;
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
    left=o;
    right = o->ch[1];
    o->ch[1]=NULL;
    left->maintain();
}
const int maxn = 100005;
struct array
{
    int x,y;
} a[maxn];
int b[maxn];
int cmp(array a,array b)
{
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
int ans[maxn];
void find(Node* &k,int num)
{
    if(k==NULL)return;
    int d=-1;
    k->pushdown();
    if(k->ch[0]!=NULL)
    {
        if(num==k->ch[0]->Min)d=0;
    }
    if(k->ch[1]!=NULL)
    {
        if(num==k->ch[1]->Min)d=1;
    }
    if(d!=-1)
    {
        Node* p = k->ch[d];
        int d2=-1;
        p->pushdown();
        if(p->ch[0]!=NULL&&num==p->ch[0]->Min)
            d2=0;
        if(p->ch[1]!=NULL&&num==p->ch[1]->Min)
            d2=1;
        if(d2!=-1)
        {
            find(p->ch[d2],num);
            if(d2==d)
                rotate(k,d^1);
            else
                rotate(k->ch[d],d);
        }
        rotate(k,d^1);
    }
}
void output(Node* k)
{
    k->pushdown();
    cout<<"L=:";
    if(k->ch[0]!=NULL)
        cout<<k->ch[0]->v<<endl;
    else cout<<endl;
    cout<<"woshi:";
    cout<<k->v<<endl;
    cout<<"R=:";
    if(k->ch[1]!=NULL)
        cout<<k->ch[1]->v<<endl;
    else cout<<endl;
    if(k->ch[0]!=NULL)
    {
        output(k->ch[0]);
    }
    if(k->ch[1]!=NULL)
    {
        output(k->ch[1]);
    }
}
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        for(i=1; i<=n; i++)
        {
            a[i].y=i;
            scanf("%d",&a[i].x);
        }
        sort(a+1,a+1+n,cmp);
        for(i=1; i<=n; i++)
            b[a[i].y]=i;
        for(i=1; i<=n; i++)
        {
            j = b[i];
            if(i==1)
            {
                root = new Node(j);
            }
            else
            {
                Node *x = new Node(j);
                root = merge(root,x);
            }
        }
        //output(root);
        for(i=1; i<=n; i++)
        {
            find(root,i);
            int tmp=0;
            if(root->ch[0]!=NULL)
                tmp=root->ch[0]->s;
            ans[i]=tmp+i;
            //cout<<tmp+1+i<<"*"<<endl;
            int k = tmp+1;
            //cout<<k<<endl;
            Node *left,*right;
            //cout<<root->s<<"***"<<k<<endl;
            split(root,k,left,right);

            left->flip^=1;
            root = merge(left,right);
            split(root,1,left,right);
            root = right;
            //output(root);
        }
        for(i=1;i<=n;i++)
        {
            if(i==1)printf("%d",ans[i]);
            else printf(" %d",ans[i]);
        }
        printf("\n");
    }
}
