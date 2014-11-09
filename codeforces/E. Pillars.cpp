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
#define ll __int64
ll D;
const int maxn = 100005;
ll h[maxn];
vector<ll>v;
int d[maxn],pre[maxn];
#define ii pair<int,int>
#define lson rt<<1
#define rson rt<<1|1
ii t[maxn<<2];
void build(int l,int r,int rt)
{
    t[rt].first=t[rt].second=-1;
    if(l==r)
    {
        return;
    }
    int mid = (l+r)>>1;
    build(l,mid,lson);
    build(mid+1,r,rson);
}
ii query(int x,int y,int l,int r,int rt)
{
    if(x<=l&&y>=r)return t[rt];
    int mid  = (l+r)>>1;
    ii ans=make_pair(-1,-1);
    if(x<=mid)
    {
        ii ans2 = query(x,y,l,mid,lson);
        if(ans2.first>ans.first)
            ans=ans2;
    }
    if(y>mid)
    {
        ii ans2 = query(x,y,mid+1,r,rson);
        if(ans2.first>ans.first)
            ans=ans2;
    }return ans;
}
void up(int l,int r,int mid,int rt)
{
    ii x = t[lson];
    ii y = t[rson];
    if(x.first>y.first)t[rt]=x;
    t[rt]=y;
}
void update(int x,ii p,int l,int r,int rt)
{
    if(l==r)
    {
        t[rt]=p;
        return;
    }
    int mid = (l+r)>>1;
    if(x<=mid)
        update(x,p,l,mid,lson);
    else
        update(x,p,mid+1,r,rson);
    up(l,r,mid,rt);
}
int main()
{
    int i,j;
    int x,y;
    int n;
    while(scanf("%d%I64d",&n,&D)!=EOF)
    {
        v.clear();
        memset(pre,-1,sizeof(pre));
        for(i=1; i<=n; i++)
        {
            scanf("%I64d",&h[i]);
            v.push_back(h[i]);
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        int nn=n;
        n = v.size();
        build(1,n,1);
        for(i=1;i<=nn;i++)
        {
            int k = lower_bound(v.begin(),v.end(),h[i])-v.begin()+1;
            int x = upper_bound(v.begin(),v.end(),h[i]-D)-v.begin();
            int y = lower_bound(v.begin(),v.end(),h[i]+D)-v.begin()+1;
            cout<<k<<" "<<x<<" "<<y<<endl;
            ii ans = make_pair(-1,-1);
            if(x>=1)
                ans =  query(1,x,1,n,1);
            if(y<=n)
            {
                ii ans2 = query(y,n,1,n,1);
                if(ans2.first>ans.first)
                    ans=ans2;
            }
            int g = ans.first;
            if(g==-1)g=0;
            g++;
            ii tmp = make_pair(g,k);
            update(k,tmp,1,n,1);
            cout<<ans.first<<" "<<ans.second<<endl;
        }
    }
    return 0;
}
