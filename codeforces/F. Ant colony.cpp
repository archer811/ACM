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
const int maxn = 100005;
int t[maxn<<2];
#define lson rt<<1
#define rson rt<<1|1
int g[maxn];
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
void up(int l,int r,int mid,int rt)
{
    t[rt]=gcd(t[lson],t[rson]);
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        t[rt]=g[l];
        return;
    }
    int mid = (l+r)>>1;
    build(l,mid,lson);
    build(mid+1,r,rson);
    up(l,r,mid,rt);
}
vector<int>v[maxn];
map<int,int>M;
int num[maxn];
int query(int x,int y,int l,int r,int rt)
{
    if(x<=l&&y>=r)return t[rt];
    int mid = (l+r)>>1;
    int a,b;
    if(x<=mid)
        a = query(x,y,l,mid,lson);
    if(y>mid)
        b = query(x,y,mid+1,r,rson);
    if(y<=mid)return a;
    if(x>mid)return b;
    return gcd(a,b);
}
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        M.clear();
        int tot=1;
        for(i=1; i<=n; i++)
            v[i].clear(),num[i]=0;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&g[i]);
            if(M[g[i]]==0)M[g[i]]=tot++;
            v[M[g[i]]].push_back(i);
            num[M[g[i]]]++;
        }
        for(i=1; i<=n; i++)
            v[i].push_back(1e9+7);
        build(1,n,1);
        int m;
        scanf("%d",&m);
        while(m--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            int a=query(x,y,1,n,1);
            int w = M[a];
            int l = lower_bound(v[w].begin(),v[w].end(),x)-v[w].begin();
            int r = upper_bound(v[w].begin(),v[w].end(),y)-v[w].begin()-1;
            printf("%d\n",y-x+1-(r-l+1));
        }
    }
    return 0;
}
