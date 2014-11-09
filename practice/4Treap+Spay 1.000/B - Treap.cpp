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
#define ll int
const int maxn = 30000+10;
struct node
{
    int l,r,fix,size;
    ll key;
};
struct treap
{
public:
    int size,root;
    node p[maxn];
    treap()
    {
        size=-1;
        root=-1;
        srand(time(0));
    }
    void maintain(int k)
    {
        if(k==-1)return;
        p[k].size=1;
        if(p[k].l!=-1)
            p[k].size += p[p[k].l].size;
        if(p[k].r!=-1)
            p[k].size += p[p[k].r].size;
    }
    void rot_l(int &k)
    {
        int y = p[k].r;
        p[k].r = p[y].l;
        p[y].l=k;
        p[y].size = p[k].size;
        maintain(k);
        k=y;
    }
    void rot_r(int &k)
    {
        int y = p[k].l;
        p[k].l = p[y].r;
        p[y].r = k;
        p[y].size = p[k].size;
        maintain(k);
        k = y;
    }
    void insert(int &k,ll tkey)
    {
        if(k==-1)
        {
            k= ++size;
            p[k].l=p[k].r=-1;
            p[k].size=1;
            p[k].key=tkey;
            p[k].fix=rand();
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
    int find(int k,int num)
    {
        int tmp=0;
        if(k==-1)return 0;
        if(p[k].l!=-1)
            tmp = p[p[k].l].size;
        if(num==tmp+1)return p[k].key;
        if(tmp>=num)
        {
            return find(p[k].l,num);
        }
        else
        {
            return find(p[k].r,num-tmp-1);
        }
    }
};
ll a[30005];
int u[30005];
int main()
{
    int i,j;
    int m,n;
    //freopen("TST_B9.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d",&m,&n);

    for(i=1; i<=m; i++)
        scanf("%d",&a[i]);
    treap T;
    j = 1;
    for(i=1; i<=n; i++)
    {
        scanf("%d",&u[i]);
        for(; j<=u[i]; j++)
        {
            T.insert(T.root,a[j]);
            // T.output(T.root);
            //cout<<endl;

        }
        //cout<<g<<"()"<<endl;
        printf("%d\n",T.find(T.root,i));
    }
}
