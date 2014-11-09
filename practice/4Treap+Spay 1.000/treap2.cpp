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
const int maxn = 101;
struct node
{
    int l,r,key,fix,size;
};
class treap
{
public :
    node p[maxn];
    int size,root;
    treap()
    {
        srand(time(0));
        size = -1;
        root = -1;
    }
    void maintain(int k)
    {
        p[k].size =1;
        if(p[k].l!=-1)
            p[k].size += p[ p[k].l ].size;
        if(p[k].r!=-1)
            p[k].size += p[ p[k].r ].size;
    }
    void rot_r(int &k)
    {
        int y = p[k].l;
        p[k].l = p[y].r;
        p[y].r=k;
        maintain(k);
        maintain(y);
        k = y;
    }
    void rot_l(int &k)
    {
        int y = p[k].r;
        p[k].r = p[y].l;
        p[y].l = k;
        maintain(k);
        maintain(y);
        k = y;
    }
    void insert(int &k,int tkey)
    {
        if(k==-1)
        {
            k = ++size;
            p[k].l=p[k].r=-1;
            p[k].key = tkey;
            p[k].fix = rand();
        }
        else if(tkey<p[k].key)
        {
            insert(p[k].l,tkey);
            if(p[ p[k].l ].fix>p[k].fix)
                rot_r(k);
        }
        else if(tkey>p[k].key)
        {
            insert(p[k].r,tkey);
            if(p[ p[k].r ].fix>p[k].fix)
                rot_l(k);
        }
    }
    void remove(int &k,int tkey)
    {
        if(k==-1)return;
        if(tkey<p[k].key)
        {
            remove(p[k].l,tkey);
        }
        else if(tkey>p[k].key)
        {
            remove(p[k].r,tkey);
        }
        else
        {
            if(p[k].l==-1&&p[k].r==-1)
                k = -1;
            else if(p[k].l==-1)
            {
                k = p[k].r;
            }
            else if(p[k].r==-1)
            {
                k = p[k].l;
            }
            else
            {
                if(p[ p[k].l ].fix>p[ p[k].r].fix)
                {
                    rot_r(k);
                    remove(p[k].r,tkey);
                }
                else
                {
                    rot_l(k);
                    remove(p[k].l,tkey);
                }
            }
        }
    }
    void output(int x)
    {
        if(x==-1)return;
        printf("%d:%d %d %d %d\n",x,p[x].l,p[x].r,p[x].key,p[x].fix);
        output(p[x].l);
        output(p[x].r);
    }
};
int main()
{
    int i,j;
    treap T;
    for(i=1;i<=3;i++)
    {
        T.insert(T.root,i);
        T.output(T.root);
        cout<<endl;
    }
}
