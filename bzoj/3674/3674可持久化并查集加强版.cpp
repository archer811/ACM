#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;
const int maxn = 100010;
struct tree
{
    int l,r;
    int ls,rs;
    int sum;
}t[maxn*20];
int tot,root[maxn];
int build(int l,int r)
{
    int k =  ++tot;
    t[k].l=l;
    t[k].r=r;
    t[k].sum=0;
    if(l==r)return k;
    int mid = (l+r)>>1;
    t[k].ls=build(l,mid);
    t[k].rs=build(mid+1,r);
    return k;
}
int change(int o,int x,int v)
{
    int k= ++tot;
    t[k] = t[o];
    t[k].sum += v;
    if(t[o].l==x&&t[o].r==x)
        return k;
    int mid = (t[o].l+t[o].r)>>1;
    if(x<=mid)
        t[k].ls = change(t[o].ls,x,v);
    else
        t[k].rs = change(t[o].rs,x,v);
    return k;
}
int query(int n,int o,int k)
{
    if(t[n].l==t[n].r)return t[n].l;
    int res = t[t[n].ls].sum-t[t[o].ls].sum;
    if(res<=k)
        return query(t[n].ls,t[o].ls,k);
    else
        return query(t[n].rs,t[o].rs,k-res);
}
int b[maxn],sortb[maxn];
int q;
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
            sortb[i]=b[i];
        }
        sort(b+1,b+1+n);
        for(q=1,i=2;i<=n;i++)
            if(sortb[q]!=sortb[i])
                sortb[++q]=sortb[i];
        root[0]=build(1,q);
        for(i=1;i<=n;i++)
        {
            int p = lower_bound(sortb+1,sortb+1+q,b[i])-sortb;
            root[i] = change(root[i-1],p,1);
        }
        for(i=0;i<m;i++)
        {
            int a,b,k;
            scanf("%d%d%d",&a,&b,&k);
            printf("%d\n",sortb[query(root[b],root[a-1],k)]);
        }
    }
}
