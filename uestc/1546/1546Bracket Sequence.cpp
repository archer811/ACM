#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int se[maxn<<2],re[maxn<<2],Min[maxn<<2],Max[maxn<<2],sum[maxn<<2];
int n,m;
#define lson rt<<1
#define rson rt<<1|1
char s[maxn];
void up(int rt)
{
    Min[rt] = min(Min[lson],sum[lson]+Min[rson]);
    Max[rt] = max(Max[lson],sum[lson]+Max[rson]);
    sum[rt] = sum[lson]+sum[rson];
}
void build(int l,int r,int rt)
{
    se[rt]=0;re[rt]=0;
    if(l==r)
    {
        //cout<<l<<"&&&&&&&&&&&&"<<s[l]<<endl;
        if(s[l]=='(')Min[rt]=-1,Max[rt]=-1,sum[rt]=-1;
        else Min[rt]=Max[rt]=sum[rt]=1;
        return;
    }
    int mid = (l+r)>>1;
    build(l,mid,lson);
    build(mid+1,r,rson);
    up(rt);
}
int mx,_sum;
void OR(int l,int r,int mid,int rt)
{
    if(se[rt])
    {
        if(se[rt]==1)
        {
            se[rt]=-1;Max[rt]=-1;
            Min[rt]=-(mid-l+1);
            sum[rt]=Min[rt];
        }
        else
        {
            se[rt]=1;Max[rt]=r-mid;
            Min[rt]=1;
            sum[rt]=Max[rt];
        }
        re[rt]=0;
    }
    else
    {
        re[rt]=1;
        swap(Min[rt],Max[rt]);
        sum[rt]=-sum[rt];
    }
}
void down(int l,int r,int mid,int rt)
{
    if(se[rt])
    {
        se[lson]=se[rson]=se[rt];
        re[lson]=re[rson]=0;
        sum[lson]=(mid-l+1)*se[rt];
        sum[rson]=(r-mid)*se[rt];
        if(se[rt]==1)
            Max[lson]=mid-l+1,Max[rson]=r-mid,Min[lson]=Min[rson]=1;
        else
            Max[lson]=Max[rson]=-1,Min[lson]=-mid+l-1,Min[rson]=-r+mid;
        se[rt]=0;
    }
    if(re[rt])
    {
        OR(l,mid,(l+mid)/2,lson);
        OR(mid+1,r,(mid+1+r)/2,rson);
        re[rt]=0;
    }
}
void query(int x,int y,int l,int r,int rt)
{
    if(x<=l&&y>=r)
    {
        mx = Max[rt];_sum=  sum[rt];
        return;
    }
    int mid = (l+r)>>1;
    down(l,r,mid,rt);
    if(x<=mid)query(x,y,l,mid,lson);
    if(y>mid)query(x,y,mid+1,r,rson);
    up(rt);
}
void update(int x,int y,int tmp,int l,int r,int rt)
{
    if(x<=l&&y>=r)
    {
        se[rt]=tmp;re[rt]=0;
        sum[rt]=(r-l+1)*se[rt];
        if(tmp==1)
            Max[rt]=r-l+1,Min[rt]=1;
        else
            Max[rt]=-1,Min[rt]=-(r-l+1);
        re[rt]=0;
        return;
    }
    int mid = (l+r)>>1;
    down(l,r,mid,rt);
    if(x<=mid)update(x,y,tmp,l,mid,lson);
    if(y>mid)update(x,y,tmp,mid+1,r,rson);
    up(rt);
}
void Update(int x,int y,int l,int r,int rt)
{
    if(x<=l&&y>=r)
    {
        OR(l,r,(l+r)/2,rt);
        return;
    }
    int mid = (l+r)>>1;
    down(l,r,mid,rt);
    if(x<=mid)Update(x,y,l,mid,lson);
    if(y>mid)Update(x,y,mid+1,r,rson);
    up(rt);
}
int main()
{
    int i,j,k,T,a,b;
    char op[8],gg[2];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%s",s);
        build(0,n-1,1);
       // cout<<Max[1]<<"fdsafds"<<endl;=
//       for(i=1;i<=14;i++)
//        cout<<i<<" "<<Max[i]<<" "<<sum[i]<<endl;
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%s%d%d",op,&a,&b);
            if(op[0]=='q')
            {
                query(a,b,0,n-1,1);
                cout<<mx<<" "<<_sum<<endl;
                if(mx<=0&&_sum==0)puts("YES");
                else puts("NO");
            }
            else if(op[0]=='s')
            {
                scanf("%s",gg);
                int tmp;
                if(gg[0]=='(')tmp = -1;
                else tmp = 1;
                update(a,b,tmp,0,n-1,1);
            }
            else
            {
                Update(a,b,0,n-1,1);
            }
        }
    }
}
