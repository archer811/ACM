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
const int maxn = 50005;
ll t[maxn<<3];
ll lazy[maxn<<3];
ll Max[maxn<<3];
#define lson rt<<1
#define rson rt<<1|1
inline ll max(ll a,ll b)
{
    if(a>b)return a;
    return b;
}
void up(int l,int r,int mid,int rt)
{
    t[rt]=t[lson]+t[rson];
    Max[rt]=max(Max[lson],Max[rson]);
}
void down(int l,int r,int mid,int rt)
{
    if(lazy[rt]>1)
    {
        lazy[lson] *= lazy[rt];
        lazy[rson] *= lazy[rt];
        t[lson] = t[lson]*lazy[rt];
        t[rson] = t[rson]*lazy[rt];
        Max[lson] = Max[lson]*lazy[rt];
        Max[rson] = Max[rson]*lazy[rt];
        lazy[rt]=1;
    }
}
void build(int l,int r,int rt)
{
    t[rt]=1;
    lazy[rt]=1;
    Max[rt]=1;
    if(l==r)return;
    int mid = (l+r)>>1;
    build(l,mid,lson);
    build(mid+1,r,rson);
    up(l,r,mid,rt);
}
ll query(int x,int y,int l,int r,int rt)
{
    if(x<=l&&y>=r)return t[rt];
    int mid = (l+r)>>1;
    down(l,r,mid,rt);
    ll sum=0;
    if(x<=mid)sum += query(x,y,l,mid,lson);
    if(y>mid)sum += query(x,y,mid+1,r,rson);
    return sum;
}
void update(int x,int l,int r,int rt,ll v)
{
    if(l==r)
    {
        t[rt]=v;
        lazy[rt]=1;
        Max[rt]=v;
        return;
    }
    int mid = (l+r)>>1;
    down(l,r,mid,rt);
    if(x<=mid)update(x,l,mid,lson,v);
    else update(x,mid+1,r,rson,v);
    up(l,r,mid,rt);
}
char s[2];
int n,m;
int f(ll x)
{
    int l = 1,r = n;
    while(l<r)
    {
        int mid = (l+r)>>1;
        ll tmp = query(1,mid,1,n,1);
        if(tmp<x)l=mid+1;
        else r=mid;
    }
    return l;
}
void update2(int x,int y,int l,int r,int rt)
{
    if(x<=l&&y>=r)
    {
        t[rt] *= 2;
        lazy[rt] *= 2;
        Max[rt] *= 2;
        return;
    }
    int mid = (l+r)>>1;
    down(l,r,mid,rt);
    if(x<=mid)
        update2(x,y,l,mid,lson);
    if(y>mid)
        update2(x,y,mid+1,r,rson);
    up(l,r,mid,rt);
}
ll ask(int x,int y,int l,int r,int rt)
{
    if(x<=l&&y>=r)
    {
        return Max[rt];
    }
    int mid = (l+r)>>1;
    down(l,r,mid,rt);
    ll ans=0;
    if(x<=mid)
        ans = max(ans,ask(x,y,l,mid,lson));
    if(y>mid)
        ans = max(ans,ask(x,y,mid+1,r,rson));
    return ans;
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        build(1,n,1);
        printf("Case #%d:\n",++cas);
//        for(i=1;i<=n;i++)
//                    cout<<i<<"ooo"<<query(1,i,1,n,1)<<endl;
        while(m--)
        {
            int l,r;
            scanf("%s%d%d",s,&l,&r);
            int x = f(l);
            int y = f(r);
//            cout<<x<<"*"<<y<<endl;
            if(s[0]=='D')
            {


                int l_l = 0;
                if(x-1>=1)
                    l_l = query(1,x-1,1,n,1);
                int l_r = query(1,x,1,n,1);
                int g = r;
                if(g>l_r)g = l_r;//l g
                int tmp1 = g-l+1;

                int r_l = 0;
                if(y-1>=1)
                    r_l = query(1,y-1,1,n,1);
                int r_r = query(1,y,1,n,1);

                //cout<<r_r<<"*"<<endl;
                int g2 = l;
                if(g2<r_l+1)g2=r_l+1;// g2 r
                int tmp2 = r-g2+1;


//cout<<l_r<<" "<<l_l<<" * "<<tmp1<<endl;
                update(x,1,n,1,l_r-l_l+tmp1);
                //cout<<r-r<<" "<<r-l<<" "<<tmp2<<endl;
                update(y,1,n,1,r_r-r_l+tmp2);

                if(y-1>=x+1)
                    update2(x+1,y-1,1,n,1);
//                for(i=1; i<=n; i++)
//                        cout<<i<<" "<<query(i,i,1,n,1)<<endl;
//                    cout<<endl;


            }
            else
            {
                ll ans = 0;
                if(y-1>=x+1)
                    ans = ask(x+1,y-1,1,n,1);

                ll tp = 0;
                tp = query(1,x,1,n,1);
                if(tp>r)tp=r;
                ans = max(ans,tp-l+1);

                tp = 1;
                if(y-1>=1)
                    tp = query(1,y-1,1,n,1)+1;
                if(tp<l)tp=l;
                ans = max(ans,r-tp+1);
                printf("%I64d\n",ans);
            }
        }
    }
    return 0;
}
