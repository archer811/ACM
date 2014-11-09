#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define MID(x,y) ((x+y)>>1)
using namespace std;
const int maxn = 100100;
struct tree
{
    int l,r;
    int ls,rs;
    int sum;
}t[maxn*20];
int tot,root[maxn],b[maxn],sortb[maxn];
int build(int l,int r)
{
    int k = ++tot;
    t[k].l = l;
    t[k].r = r;
    t[k].sum=0;
    if(l==r)return k;
    int mid = (l+r)/2;
    t[k].ls = build(l,mid);
    t[k].rs = build(mid+1,r);
    return k;
}
int change(int o,int x,int v)
{
    int k = ++tot;
    t[k]=t[o];
    t[k].sum += v;
    if(t[o].l==x&&t[o].r==x)return k;
    int mid = (t[o].l+t[o].r)/2;
    if(x<=mid)t[k].ls = change(t[o].ls,x,v);
    else t[k].rs = change(t[o].rs,x,v);
    return k;
}/*
int query(int a,int b,int k)
{
    if(t[a].l==t[b].r)return t[a].l;
    int res = t[t[b].ls].sum-t[t[a].ls].sum;
    if(k<=res)
      return query(t[a].ls,t[b].ls,k);
    else return query(t[a].rs,t[b].rs,k-res);
}*/
int query(int n,int o,int k)  //询问区间[t1,t2]第k小
{
    if (t[n].l == t[n].r) return t[n].l;
    int res = t[t[n].ls].sum-t[t[o].ls].sum;
    if (k <= res)
        return query(t[n].ls,t[o].ls,k);
    else return query(t[n].rs,t[o].rs,k-res);
}

int main()
{
    int i,j,k,n,m,a,bb,c;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;i++)
           scanf("%d",&b[i]),sortb[i]=b[i];
        sort(sortb+1,sortb+1+n);
        int q;
        for (q = 1, i = 2; i <= n; ++ i)
            if (sortb[q] != sortb[i])
                sortb[++q] = sortb[i];
        root[0] = build(1,q);
        for (int i = 1; i <= n; i ++)
        {
            int p = lower_bound(sortb+1, sortb+n+1, b[i])-sortb;
            root[i] = change(root[i-1], p, 1);
        }
        while(m--)



        {
            scanf("%d%d%d",&a,&bb,&c);
            printf("%d\n",sortb[query(root[bb],root[a-1],c)]);
        }
    }
}
