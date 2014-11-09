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
    Node(int _v)
    {
        ch[0]=ch[1]=NULL;
        v=_v;
        s=1;
        flip=0;
    }
    int cmp2(int num)
    {
        int tmp = 0;
        if(ch[0]!=NULL)
            tmp = ch[0]->s;
        if(num>tmp+1)return 1;
        if(num<=tmp)return 0;
        return -1;
    }
    void maintain()
    {
        s=1;
        if(ch[0]!=NULL)
            s += ch[0]->s;
        if(ch[1]!=NULL)
            s += ch[1]->s;
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

void splay_k(Node* &k,int num)
{
    if(k==NULL)return;
    k->pushdown();
    int d = k->cmp2(num);
    if(d==1)
    {
        if(k->ch[0]!=NULL)num-=(k->ch[0]->s);
        num-=1;
    }
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
            splay_k(p->ch[d2],k2);
            if(d==d2)
            {
                rotate(k,d^1);
            }
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
Node* merge(Node* left,Node* right)
{
    splay_k(left,left->s);
    left->ch[1]=right;
    left->maintain();
    return left;
}
void split(Node* o,int k,Node* &left,Node* &right)
{
    splay_k(o,k);
    left = o;
    right = o->ch[1];
    o->ch[1]=NULL;
    left->maintain();
}
char s[25];
const int maxn = 2*1024*1024+10;
char str[maxn];
Node* root;

void find(Node* k,int &ans)
{
    if(k==NULL)return;
    k->pushdown();
    k->maintain();
    ans=k->v;
    find(k->ch[0],ans);
}
void de(Node * &k)
{
    if(k==NULL)return;
    if(k->ch[0]!=NULL)de(k->ch[0]);
    if(k->ch[1]!=NULL)de(k->ch[1]);
    delete k;
    k = NULL;
}
int main()
{
    int i,j,n,d,num;
//    freopen("editor8.in","r",stdin);
//    freopen("1.txt","w",stdout);
    while(scanf("%d",&n)==1)
    {
        de(root);
        root = new Node(0);
        int k;
        int g=0;
        while(n--)
        {
           // cout<<g<<endl;
            g++;
            scanf("%s",s);
            if(s[0]=='N')
            {
                int tmp=0;
                if(root->ch[0]!=NULL)
                    tmp = root->ch[0]->s;
                tmp += 2;
                splay_k(root,tmp);
                continue;
            }
            if(s[0]=='I')
            {
                scanf("%d%*c",&num);
                gets(str);
//                cout<<strlen(str)<<"SSSSSSSSSSSSS"<<endl;
                Node *left,*mid,*right;
                int tmp=0;
                if(root->ch[0]!=NULL)
                    tmp = root->ch[0]->s;
                split(root,tmp+1,left,right);
                for(i=0; i<num; i++)
                {
                    j = (int)(str[i]);
                    Node* a = new Node(j);
                    left = merge(left,a);
                }
                root = merge(left,right);
                splay_k(root,tmp+1);
                continue;
            }
            if(s[0]=='M')
            {
                scanf("%d",&num);
                splay_k(root,num+1);
                continue;
            }
            if(s[0]=='D')
            {
                scanf("%d",&num);
                int tmp=0;
                if(root->ch[0]!=NULL)
                    tmp = root->ch[0]->s;
                Node *left,*right,*laji,*mid;
                split(root,tmp+1,left,right);
                split(right,num,laji,mid);
                root = merge(left,mid);
                splay_k(root,tmp+1);
                continue;
            }
            if(s[0]=='R')
            {
                scanf("%d",&num);
                Node *left,*right,*mid,*laji;
                int tmp=0;
                if(root->ch[0]!=NULL)
                    tmp = root->ch[0]->s;
                split(root,tmp+1,left,mid);

                split(mid,num,laji,right);
                laji->flip^=1;
                //output(laji);
                root = merge(merge(left,laji),right);
                splay_k(root,tmp+1);
                continue;
            }
            if(s[0]=='G')
            {
                int ans=-1;
                find(root->ch[1],ans);
                // cout<<ans<<"  "<<root->ch[1]->v<<endl;
                if(ans==-1)
                    printf(" \n");
                else
                    printf("%c\n",(char)ans);
                continue;
            }
            if(s[0]=='P')
            {
                int tmp=0;
                if(root->ch[0]!=NULL)
                    tmp = root->ch[0]->s;
                splay_k(root,tmp);
                continue;
            }

        }

    }
}
