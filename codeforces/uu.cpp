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
    int size,fix,key;
    Node(int v)
    {
        size=1;
        fix=rand();
        ch[0] = NULL;
        ch[1] = NULL;
        key = v;
    }
    void maintain()
    {
        size=1;
        if(ch[0]!=NULL)
            size += ch[0]->size;
        if(ch[1]!=NULL)
            size += ch[1]->size;
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
void insert(Node* &k,int tkey)
{
    if(k==NULL)
    {
        k = new Node(tkey);
    }
    else if(k->key>=tkey)
    {
        k->size ++;
        insert(k->ch[0],tkey);
        if(k->ch[0]->fix>k->fix)
        {
            rotate(k,1);
        }
    }
    else
    {
        k->size++;
        insert(k->ch[1],tkey);
        if(k->ch[1]->fix>k->fix)
        {
            rotate(k,0);
        }
    }
}
void remove(Node * &k,int tkey)
{
    if(k==NULL)return;
    if(k->key>tkey)
    {
        k->size--;
        remove(k->ch[0],tkey);
    }
    else if(k->key<tkey)
    {
        k->size--;
        remove(k->ch[1],tkey);
    }
    else
    {
        Node * u = k;
        if(k->ch[0]!=NULL&&k->ch[1]!=NULL)
        {
            if(k->ch[0]->fix>k->ch[1]->fix)
            {
                rotate(k,1);
                k->size--;
                remove(k->ch[1],tkey);
            }
            else
            {
                rotate(k,0);
                k->size--;
                remove(k->ch[0],tkey);
            }
        }
        else
        {
            if(k->ch[0] == NULL) k = k->ch[1];
            else k = k->ch[0];
            delete u;
        }
    }
}
void de(Node * &k)
{
    if(k==NULL)return;
    if(k->ch[0]!=NULL)de(k->ch[0]);
    if(k->ch[1]!=NULL)de(k->ch[1]);
    delete k;
    k = NULL;
}
int find2(Node* k,int num)//DI JI GE SHI JI
{
    int tmp=0;
    if(k==NULL||num>k->size||num<0)return -1;
    if(k->ch[0]!=NULL)
        tmp = k->ch[0]->size;
    if(num==tmp+1)
    {
        return k->key;
    }
    if(num<=tmp)
        return find2(k->ch[0],num);
    else if(num-1-tmp>=0)
        return find2(k->ch[1],num-1-tmp);
}
int find(Node* t,int x)//cha zhao shi fou cun zai
{
    if(t==NULL)return 0;
    if(t->key == x)return 1;
    if(t->key>x)return find(t->ch[0],x);
    return find(t->ch[1],x);
}
int Rank(Node* t,int x)// JI SHI DI JI GE
{
    int r;
    if(t==NULL)return 0;
    if(t->ch[0]==NULL) r=0;
    else  r=t->ch[0]->size;
    if(x==t->key)
    {
        if(t->ch[1]!=NULL)
        {
            if(t->ch[1]->key==x)
                return r+1+Rank(t->ch[1],x);
        }
        else return r+1;
    }
    if(x<t->key)
        return Rank(t->ch[0],x);
    return r+1+Rank(t->ch[1],x);
}
Node* root;
int main ()
{
    int i,z,x,c,v,b,n,j,k,l;
    int a[9];
    printf("依次输入三点坐标:");
    for(i=0; i<9; i++)
        scanf("%d",&a[i]);
    z=a[3]-a[0];
    x=a[4]-a[1];
    c=a[5]-a[2];
    v=a[6]-a[0];
    b=a[7]-a[1];
    n=a[8]-a[2];
    j=n*x-b*c;
    k=z*n-v*c;
    l=z*b-v*x;
    printf("%d %d %d",j,k,l);
}
