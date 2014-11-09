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
const int N = 20005;
const int M = 60005;
int n,m;
struct edge
{
    int u,v;
}e[M];
int w[N];
struct query
{
    int ask,a,b;
}s[500005];
int vis[M];
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
    else if(k->key>tkey)
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
                //cout<<k->key<<"GGG"<<endl;
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
int fa[N];
int find(int x)
{
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
Node* root[N];
void dfs(Node* &a,Node* &b)
{
    if(a==NULL)return;
    if(a->l!=NULL)
        dfs(a->l,b);
    if(a->r!=NULL)
        dfs(a->r,b);
    //cout<<b->key<<"!!!"<<a->key<<"  "<<b->size<<"  "<<a->size<<endl;
    insert(b,a->key);
    delete a;
    a = NULL;
}
void add(int u,int v)
{
    int x = find(u),y = find(v);
    if(x!=y)
    {
        if(root[x]->size>root[y]->size)
        {
            dfs(root[y],root[x]);
            fa[y]=x;
        }
        else
        {
            dfs(root[x],root[y]);
            fa[x]=y;
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
long long getans(Node* &k,int num)
{
    int tmp=0;
    if(k==NULL||num>k->size||num<=0)return 0;
    if(k->r!=NULL)
        tmp = k->r->size;
    if(num==tmp+1)
    {
        //cout<<k->key<<"   "<<k->size<<endl;
        return (long long)k->key;
    }
    if(num<=tmp)
        return getans(k->r,num);
    else if(num-1-tmp>=0)
        return getans(k->l,num-1-tmp);
}
int main()
{
    int i,j;
    srand(time(0));
    char t[2];
    int cas=0;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)break;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&w[i]);
            fa[i]=i;
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&e[i].u,&e[i].v);
            vis[i]=0;
        }
        int g=0;
        long long ans=0;
        int num=0;
        while(scanf("%s",t)!=EOF)
        {
            if(t[0]=='E')break;
            if(t[0]=='Q')
            {
                s[g].ask=1;
                scanf("%d%d",&s[g].a,&s[g].b);
            }
            else if(t[0]=='C')
            {
                s[g].ask=0;
                scanf("%d%d",&s[g].a,&s[g].b);
                swap(s[g].b,w[s[g].a]);
                //cout<<s[g].b<<"!"<<endl;
            }
            else if(t[0]=='D')
            {
                s[g].ask=-1;
                scanf("%d",&s[g].a);
                vis[s[g].a]=1;
            }
            g++;
        }
//        for(i=1;i<=n;i++)
//        {
//            cout<<i<<"*"<<w[i]<<endl;
//        }
        for(i=1;i<=n;i++)
        {
            if(root[i]!=NULL)
                de(root[i]);
            //insert(root[i],w[i]);
            root[i]= new Node(w[i]);
        }

        for(i=1;i<=m;i++)
        {
            if(vis[i])continue;
            add(e[i].u,e[i].v);
            //cout<<e[i].u<<"   *******   "<<e[i].v<<endl;
        }
        for(i=g-1;i>=0;i--)
        {
            //cout<<i<<"nimei"<<endl;
            if(s[i].ask==-1)
            {
                //cout<<e[s[i].a].u<<"  *******  "<<e[s[i].a].v<<endl;
                add(e[s[i].a].u,e[s[i].a].v);
            }
            else if(s[i].ask==0)
            {
                int ok = find(s[i].a);
                //Node * tmp = root[ok];

                remove(root[ok],w[s[i].a]);
               // cout<<"hahahahah   "<<s[i].b<<endl;
                insert(root[ok],s[i].b);
                w[s[i].a]=s[i].b;
               // cout<<tmp->key<<endl;
            }
            else
            {
                int ok = find(s[i].a);
                ans += (long long)getans(root[ok],s[i].b);
                num++;
                //cout<<ans<<" "<<num<<endl;
            }
        }
        //cout<<ans<<" "<<num<<endl;
        printf("Case %d: %.6f\n",++cas,ans/(double)num);
    }
}
