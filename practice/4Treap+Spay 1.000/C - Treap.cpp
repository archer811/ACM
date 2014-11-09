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
int n,m;
const int maxn = 100011;
int a[maxn];
struct array
{
    int x,y,k,index;
} s[51001];
int ans[51001];
struct node
{
    int l,r,key,fix,size;
};
int M=0;
struct treap
{
public:
    int size,root;
    node p[maxn];
    treap()
    {
        size=-1;
        root=-1;
       // srand(time(0));
    }
    void maintain(int k)
    {
        p[k].size=1;
        if(p[k].l!=-1)
            p[k].size += p[p[k].l].size;
        if(p[k].r!=-1)
            p[k].size += p[p[k].r].size;
    }
    void rot_r(int &k)
    {
        int y = p[k].l;
        p[k].l=p[y].r;
        p[y].r=k;
        p[y].size=p[k].size;
        maintain(k);
        k = y;
    }
    void rot_l(int &k)
    {
        int y = p[k].r;
        p[k].r = p[y].l;
        p[y].l = k;
        p[y].size = p[k].size;
        maintain(k);
        k = y;
    }
    void insert(int &k,int tkey)
    {
        if(k==-1)
        {
            k = ++size;
            p[k].l=p[k].r=-1;
            p[k].size=1;
            p[k].key=tkey;
            p[k].fix = rand();
        }
        else if(p[k].key>tkey)
        {
            p[k].size++;
            insert(p[k].l,tkey);
            if(p[p[k].l].fix>p[k].fix)
                rot_r(k);
        }
        else
        {
            p[k].size++;
            insert(p[k].r,tkey);
            if(p[p[k].r].fix>p[k].fix)
                rot_l(k);
        }
    }
    void remove(int &k,int tkey)
    {
        if(k==-1)return;
        if(p[k].key<tkey)
        {
            p[k].size--;
            remove(p[k].r,tkey);
        }
        else if(p[k].key>tkey)
        {
            p[k].size--;
            remove(p[k].l,tkey);
        }
        else
        {
            if(p[k].l==-1&&p[k].r==-1)
            {
                p[k].size=0;
                k=-1;
            }
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
                    rot_r(k);
                    p[k].size--;
                    remove(p[k].r,tkey);
                }
                else
                {
                    rot_l(k);
                    p[k].size--;
                    remove(p[k].l,tkey);
                }
            }
        }
    }
    int find(int k,int num)
    {
        int tmp = 0;
        if(p[k].l!=-1)
            tmp = p[p[k].l].size;
        if(num==tmp+1)return p[k].key;
        if(num<=tmp)
        {
            return find(p[k].l,num);
        }
        else
        {
            return find(p[k].r,num-tmp-1);
        }
    }
};
int cmp(array a,array b)
{
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
int main()
{
    int i,j;
    //freopen("out.txt","w",stdout);
    scanf("%d%d",&n,&m);

    for(i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(i=0; i<m; i++)
    {
        scanf("%d%d%d",&s[i].x,&s[i].y,&s[i].k);
        if(s[i].x>s[i].y)
            swap(s[i].x,s[i].y);
        s[i].index=i;
    }
    sort(s,s+m,cmp);

    treap T;
    for(i=s[0].x; i<=s[0].y; i++)
    {

        T.insert(T.root,a[i]);

    }
    int l = s[0].x,r = s[0].y;

    ans[s[0].index]=T.find(T.root,s[0].k);


    for(i=1; i<m; i++)
    {
        int x = s[i].x,y = s[i].y;
        for(j=l; j<x; j++)
        {
            T.remove(T.root,a[j]);
        }

        if(r>y)
        {
            for(j=r; j>=y+1; j--)
            {

                T.remove(T.root,a[j]);
            }

        }
        else if(r<y)
        {
            for(j=r+1; j<=y; j++)
            {
cout<<T.root<<"("<<endl;
                T.insert(T.root,a[j]);
                cout<<T.root<<")"<<endl;
            }

        }
        l = x;
        r = y;
        ans[s[i].index]=T.find(T.root,s[i].k);

    }
    for(i=0; i<m; i++)
    {
        //printf("%d\n",ans[i]);
    }
}
