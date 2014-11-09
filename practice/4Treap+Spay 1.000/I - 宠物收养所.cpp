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
const int mod = 1000000;
struct Node
{
    Node* ch[2];
    int r;
    int v;
    int s;
    Node(int _v)
    {
        ch[0]=ch[1]=NULL;
        v = _v;
        r = rand();
        s = 1;
    }
    int cmp(int num)
    {
        if(v==num)return -1;
        return num<v?0:1;
    }
    void maintain()
    {
        s=1;
        if(ch[0]!=NULL)
            s+=ch[0]->s;
        if(ch[1]!=NULL)
            s+=ch[1]->s;
    }
};
void rotate(Node* &k,int d)
{
    Node* y = k->ch[d^1];
    k->ch[d^1]=y->ch[d];
    y->ch[d]=k;
    k->maintain();
    y->maintain();
    k=y;
}
void insert(Node* &k,int num)
{
    if(k==NULL)
    {
        k= new Node(num);
        return;
    }
    if(k->v>num)
    {
        k->s++;
        insert(k->ch[0],num);
        if(k->ch[0]->r>k->r)
        {
            rotate(k,1);
        }
    }
    else
    {
        k->s++;
        insert(k->ch[1],num);
        if(k->ch[1]->r>k->r)
        {
            rotate(k,0);
        }
    }
}
void remove(Node* &k,int num)
{
    if(k->v==num)
    {
        Node * u = k;
        if(k->ch[0]!=NULL&&k->ch[1]!=NULL)
        {
            if(k->ch[0]->r>k->ch[1]->r)
            {
                rotate(k,1);
                //cout<<k->key<<"GGG"<<endl;
                k->s--;
                remove(k->ch[1],num);
            }
            else
            {
                rotate(k,0);
                k->s--;
                remove(k->ch[0],num);
            }
        }
        else
        {
            if(k->ch[0] == NULL) k = k->ch[1];
            else k = k->ch[0];
            delete u;
        }
    }
    else if(k->v>num)
    {
        k->s--;
        remove(k->ch[0],num);
    }
    else
    {
        k->s--;
        remove(k->ch[1],num);
    }
}
Node* root;
Node* root2;
void splay(Node* &k,int num)
{
    if(k==NULL)return;
    int d = k->cmp(num);
    if(d!=-1)
    {
        Node* p = k->ch[d];
        int d2 = p->cmp(num);
        if(d2!=-1)
        {
            splay(p->ch[d2],num);
            if(d==d2)
                rotate(k,d^1);
            else
                rotate(k->ch[d],d);
        }
        rotate(k,d^1);
    }
}
void find(Node* k,int d,int &ans)
{
    if(k==NULL)return;
    ans = k->v;
    find(k->ch[d],d,ans);
}
void output(Node* k)
{
   cout<<"L=";
   if(k->ch[0]!=NULL)
    cout<<k->ch[0]->v<<endl;
   else cout<<endl;
   cout<<"woshi"<<k->v<<endl;
   cout<<"R=";
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
    int a,b;
    scanf("%d",&n);
    {
        int sum=0;
        int _0=0,_1=0;
        while(n--)
        {
            scanf("%d%d",&a,&b);
            //cout<<_0<<" "<<_1<<endl;
            if(a==0)
            {
                if(_1>_0)
                {
                    int Max=-1,Min=-1;
                    insert(root2,b);
                    splay(root2,b);
                    find(root2->ch[0],1,Max);
                    find(root2->ch[1],0,Min);
                    remove(root2,b);
                    int tmp=-1,f=-1;
                    if(Max!=-1)
                    {
                        tmp=b-Max;f=Max;
                    }
                    if(Min!=-1&&(tmp==-1||tmp>Min-b))
                    {
                        tmp=Min-b;
                        f=Min;
                    }
                    sum += tmp;
                    sum %= mod;
                    remove(root2,f);
                    _1--;
                }
                else
                {
                    _0++;
                    insert(root,b);
                }
            }
            else
            {
                if(_0>_1)
                {
                    int Max=-1,Min=-1;
                    insert(root,b);
                    splay(root,b);
                    //output(root);

                    find(root->ch[0],1,Max);
                    find(root->ch[1],0,Min);
                    remove(root,b);
                    //cout<<Max<<"   "<<Min<<endl;

                    int tmp=-1,f=-1;
                    if(Max!=-1)
                    {
                        tmp=b-Max;f=Max;
                    }
                    if(Min!=-1&&(tmp==-1||tmp>Min-b))
                    {
                        tmp=Min-b;
                        f=Min;
                    }
//                    cout<<ans->v<<endl;
                    //if(tmp<0)tmp=-tmp;
                    sum += tmp;
                    sum %= mod;
                    remove(root,f);
                    _0--;
                }
                else
                {
                    _1++;
                    insert(root2,b);
                }
            }
//            cout<<sum<<endl;
        }
        printf("%d\n",sum);
    }
}
