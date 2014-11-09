#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;
struct Node
{
    Node *l,*r;
    int size,fix,key;
    Node(int v)
    {
        size=1;
        fix=rand();
        l = NULL;
        r = NULL;
        key = v;
    }
    void maintain()
    {
        size=1;
        if(l!=NULL)
            size += l->size;
        if(r!=NULL)
            size += r->size;
    }
};
void rot_r(Node* &k)
{
    Node* y = k->l;
    k->l = y->r;
    y->r = k;
    y->size = k->size;
    k->maintain();
    k = y;
}
void rot_l(Node* &k)
{
    Node* y= k->r;
    k->r = y->l;
    y->l = k;
    y->size = k->size;
    k->maintain();
    k = y;
}
void insert(Node* &k,int tkey)
{
    if(k==NULL)
    {
        k = new Node(tkey);
    }
    else if(k->key>=tkey)
    {
        k->size ++;
        insert(k->l,tkey);
        if(k->l->fix>k->fix)
        {
            rot_r(k);
        }
    }
    else
    {
        k->size++;
        insert(k->r,tkey);
        if(k->r->fix>k->fix)
        {
            rot_l(k);
        }
    }
}
void remove(Node * &k,int tkey)
{
    if(k==NULL)return;
    if(k->key>tkey)
    {
        k->size--;
        remove(k->l,tkey);
    }
    else if(k->key<tkey)
    {
        k->size--;
        remove(k->r,tkey);
    }
    else
    {
        Node * u = k;
        if(k->l!=NULL&&k->r!=NULL)
        {
            if(k->l->fix>k->r->fix)
            {
                rot_r(k);
                k->size--;
                remove(k->r,tkey);
            }
            else
            {
                rot_l(k);
                k->size--;
                remove(k->l,tkey);
            }
        }
        else
        {
            if(k->l == NULL) k = k->r;
            else k = k->l;
            delete u;
        }
    }
}
void de(Node * &k)
{
    if(k==NULL)return;
    if(k->l!=NULL)de(k->l);
    if(k->r!=NULL)de(k->r);
    delete k;
    k = NULL;
}
int find2(Node* k,int num)//DI JI GE SHI JI
{
    int tmp=0;
    if(k==NULL||num>k->size||num<0)return -1;
    if(k->l!=NULL)
        tmp = k->l->size;
    if(num==tmp+1)
    {
        return k->key;
    }
    if(num<=tmp)
        return find2(k->l,num);
    else if(num-1-tmp>=0)
        return find2(k->r,num-1-tmp);
}
int find(Node* t,int x)
{
    if(t==NULL)return 0;
    if(t->key == x)return 1;
    if(t->key>x)return find(t->l,x);
    return find(t->r,x);
}
int Rank(Node* t,int x)// JI SHI DI JI GE
{
    int r;
    if(t==NULL)return 0;
    if(t->l==NULL) r=0;
    else  r=t->l->size;
    if(x==t->key)
    {
        if(t->r!=NULL)
        {
            if(t->r->key==x)
                return r+1+Rank(t->r,x);
        }
        else return r+1;
    }
    if(x<t->key)
        return Rank(t->l,x);
    return r+1+Rank(t->r,x);
}
Node* root;
int main()
{
    int i,j,t;
    int d,a,b;
    while(scanf("%d",&t)!=EOF)
    {
        de(root);
        while(t--)
        {
            scanf("%d",&d);
            if(d==0)
            {
                scanf("%d",&a);
                insert(root,a);
                //cout<<root->size<<endl;
            }
            else if(d==1)
            {
                scanf("%d",&a);
                if(find(root,a)==0)puts("No Elment!");
                else remove(root,a);
            }
            else
            {
                scanf("%d%d",&a,&b);
                int o ;
                int ll =0;
                if(find(root,a)==0)
                {
                    ll ++;
                    //cout<<"("<<endl;
                    insert(root,a);
                    o = Rank(root,a);
                    remove(root,a);
                }
                else o =  Rank(root,a);
                //cout<<o<<endl;
                o += b-ll;
                int w = find2(root,o);
                //cout<<w<<"&"<<"  "<<root->size<< "  "<<find(root,2)<<endl;
                if(w==-1)puts("Not Find!");
                else printf("%d\n",w);

            }
        }
    }
}
