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
#define ll long long
const int maxn = 10005;
ll a[maxn];
int b[maxn];
ll c[maxn];
const int num = 333;
struct array
{
    int l,r,id;
} g[100005];
int cmp(array x,array y)
{
    int a = x.l/num;
    int b = y.l/num;
    if(a==b)return x.r<y.r;
    return a<b;
}
int vis[maxn];
ll sum1,sum2;
void add(int x)
{
    int id = b[x];
    ll v = a[x];
    if(vis[id]==0)
    {
        sum1+=v;
        sum2+=1;
        //cout<<id<<"*"<<v<<" "<<sum1<<" "<<sum2<<endl;
    }
    vis[id]++;
}
void sub(int x)
{
    int id = b[x];
    ll v = a[x];
    if(vis[id]==1)
    {
        sum1-=v;
        sum2-=1;
        //cout<<id<<"()"<<v<<" "<<sum1<<" "<<sum2<<endl;
    }
    vis[id]--;
}
double ans[maxn];
int main()
{
    int i,j,t,n;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%lld",&a[i]);
            c[i]=a[i];
        }
        sort(c,c+n);
        int m = unique(c,c+n)-c;
        memset(vis,0,sizeof(vis));
        for(i=0; i<n; i++)
        {
            b[i]=lower_bound(c,c+m,a[i])-c;
        }
        int q;
        scanf("%d",&q);
        for(i=0; i<q; i++)
        {
            scanf("%d%d",&g[i].l,&g[i].r);
            g[i].l--;
            g[i].r--;
            g[i].id=i;
        }
        sort(g,g+q,cmp);
        sum1=0;
        sum2=0;
        int tl=0,tr=-1;
        for(i=0; i<q; i++)
        {
            int l = g[i].l;
            int r = g[i].r;
            while (tr<r) add(++tr);
            while (l<tl) add(--tl);
            while (r<tr) sub(tr--);
            while (tl<l) sub(tl++);
            ans[g[i].id] = sum2==0?0:(double)sum1*1.0/sum2;
            //cout<<g[i].id<<" "<<sum1<<" "<<sum2<<endl;
        }
        printf("Case %d:\n",++cas);
        for(i=0;i<q;i++)
        {
            printf("%.6f\n",ans[i]);
        }
    }
    return 0;
}
