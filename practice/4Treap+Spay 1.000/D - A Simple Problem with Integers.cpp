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
#define ll __int64
struct Node
{
    Node* ch[2];
    ll sum,v;
    int s;
    ll add;
    Node(ll _v)
    {
        v=sum=_v;
        s=1;
        add=0;
        ch[0]=ch[1]=NULL;
    }
    void maintain()
    {
        s = 1;sum = v;
        if(ch[0]!=NULL)
            s += ch[0]->s,sum += ch[0]->sum;
        if(ch[1]!=NULL)
            s += ch[1]->s,sum += ch[1]->sum;
    }
    int cmp(int num)
    {
        int tmp = 0;
        if(ch[0]!=NULL)
            tmp = ch[0]->s;
        if(num>tmp+1)return 1;
        else if(num==tmp+1)return -1;
        return 0;
    }
    void pushdown()
    {
        if(add)
        {
            v += add;
            if(ch[0]!=NULL)
                ch[0]->add+=add,ch[0]->sum += (ll)(ch[0]->s)*add;
            if(ch[1]!=NULL)
                ch[1]->add+=add,ch[1]->sum += (ll)(ch[1]->s)*add;
            add=0;
        }
    }
}*root;
void rotate(Node* &k,int d)
{
    Node* p = k->ch[d^1];
    k->ch[d^1]=p->ch[d];
    p->ch[d]=k;
    k->maintain();
    p->maintain();
    k = p;
}
void splay(Node* &k,int num)
{
    k->pushdown();
    int tmp = 0;
    if(k->ch[0]!=NULL)
        tmp = k->ch[0]->s;
    int d = -1;
    if(num>tmp+1)d=1;
    else if(num<=tmp)d=0;
    if(d==1)
        num -= (tmp)+1;
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
void output(Node* k)
{
    k->pushdown();
    cout<<"L=:";
    if(k->ch[0]!=NULL)
        cout<<k->ch[0]->v<<endl;
    else cout<<endl;
    cout<<"woshi:";
    cout<<k->v<<"              "<<k->sum<<endl;
    cout<<"R=:";
    if(k->ch[1]!=NULL)
        cout<<k->ch[1]->v<<endl;
    else cout<<endl;
    cout<<endl;
    if(k->ch[0]!=NULL)
    {
        output(k->ch[0]);
    }
    if(k->ch[1]!=NULL)
    {
        output(k->ch[1]);
    }
}
void split(Node* o,int k,Node* &left,Node* &right)
{
    splay(o,k);
    left=o;
    right = o->ch[1];
    o->ch[1]=NULL;
    left->maintain();
}
Node* merge(Node* left,Node* right)
{
    splay(left,left->s);
    left->ch[1]=right;
    left->maintain();
    return left;
}
int main()
{
    int i,j,n,q;
    //freopen("tout.txt","w",stdout);
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        ll d;
        int a,b;
        ll c;
        char s[2];
        root = new Node(0);
        for(i=1;i<=n;i++)
        {
            scanf("%I64d",&d);
            Node *a = new Node(d);
            root = merge(root,a);
        }
//        output(root);
        while(q--)
        {
            scanf("%s",s);
            if(s[0]=='C')
            {
                scanf("%d%d%I64d",&a,&b,&c);
                Node *left,*mid,*right,*xx;
                split(root,a,left,mid);
                split(mid,b-a+1,xx,right);
                xx->add+=c;
                xx->sum += c*(xx->s);
                root = merge(merge(left,xx),right);
            }
            else
            {
                scanf("%d%d",&a,&b);
                Node *left,*mid,*right,*xx;
                split(root,a,left,mid);
                split(mid,b-a+1,xx,right);
                xx->pushdown();
                printf("%I64d\n",xx->sum);
                root = merge(merge(left,xx),right);
            }
        }
    }
}
