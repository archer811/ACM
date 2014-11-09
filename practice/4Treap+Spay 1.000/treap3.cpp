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
    int l,r,key,fix;
};
class treap
{
public:
    node p[maxn];
    int root,size;
    treap()
    {
        srand(time(0));
        root=-1;
        size=-1;
    }
    void tot_r(int &k)
    {
        int y = p[k].l;
        p[k].l = p[y].r;
        p[y].r = k;
        k = y;
    }
    void tot_l(int &k)
    {
        int y = p[k].r;
        p[k].r = p[y].l;
        p[y].l=k;
        k=y;
    }
    void insert(int &k,int tkey)
    {
        if(k==-1)
        {
            k = ++size;
            p[k].l=p[k].r=-1;
            p[k].key=tkey;
            p[k].fix=rand();
        }
        else if(p[k].key<tkey)
        {
            insert(p[k].r,tkey);
            if(p[p[k].r].fix>p[k].fix)
            {
                tot_l(k);
            }
        }
        else if(p[k].key>tkey)
        {
            insert(p[k].l,tkey);
            if(p[p[k].l].fix>p[k].fix)
                tot_r(k);
        }
    }
    void remove(int &k,int tkey)
    {
        if(k==-1)return;
        if(p[k].key>tkey)
        {
            remove(p[k].l,tkey);
        }
        else if(p[k].key<tkey)
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
                if(p[p[k].l].fix>p[p[k].r].fix)
                {
                    tot_r(k);
                    remove(p[k].r,tkey);
                }
                else if(p[p[k].l].fix<p[p[k].r].fix)
                {
                    tot_l(k);
                    remove(p[k].l,tkey);
                }
            }
        }
    }
};
int main()
{
    int i,j;
}
