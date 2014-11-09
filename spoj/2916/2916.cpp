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
#define lson rt<<1
#define rson rt<<1|1

const int maxn = 10006;
int tree[maxn<<2],L[maxn<<2],R[maxn<<2];
int M[maxn<<2];
int sum[maxn];
int A[maxn];
void pushup(int l,int r,int mid,int rt)
{
    tree[rt] = tree[lson]+tree[rson];
    L[rt] = max(L[lson],tree[lson]+L[rson]);
    R[rt] = max(R[rson],tree[rson]+R[lson]);
    M[rt] = max(M[lson],M[rson]);
    M[rt] = max(M[rt],R[lson]+L[rson]);
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        tree[rt]=L[rt]=R[rt]=M[rt]=A[l];
        return;
    }
    int mid = (l+r)>>1;
    build(l,mid,lson);
    build(mid+1,r,rson);
    pushup(l,r,mid,rt);
}
int queryl(int x,int y,int l,int r,int rt)
{
    if(x<=l&&y>=r)
    {
        return L[rt];
    }
    int mid = (l+r)>>1;
    if(x<=mid&&y>mid)
    {
        int ans = queryl(x,mid,l,mid,lson);
        ans = max(ans,sum[mid]-sum[x-1]+queryl(mid+1,y,mid+1,r,rson));
        return ans;
    }
    else if(x<=mid)
    {
        return queryl(x,y,l,mid,lson);
    }
    else if(y>mid)
    {
        return queryl(x,y,mid+1,r,rson);
    }
}

int queryr(int x,int y,int l,int r,int rt)
{
    if(x<=l&&y>=r)
    {
        return R[rt];
    }
    int mid = (l+r)>>1;
    if(x<=mid&&y>mid)
    {
        int ans = queryr(mid+1,y,mid+1,r,rson);
        ans = max(ans,sum[y]-sum[mid]+queryr(x,mid,l,mid,lson));
        return ans;
    }
    else if(x<=mid)
    {
        return queryr(x,y,l,mid,lson);
    }
    else if(y>mid)
    {
        return queryr(x,y,mid+1,r,rson);
    }
}

int queryM(int x,int y,int l,int r,int rt)
{
    if(x<=l&&y>=r)return M[rt];
    int mid = (l+r)>>1;
    if(x<=mid&&y>mid)
    {
        int ans = max(queryM(x,mid,l,mid,lson),queryM(mid+1,y,mid+1,r,rson));
        //cout<<l<<" "<<r<<"  "<<ans<<endl;
        ans = max(ans,queryr(x,mid,l,mid,lson)+queryl(mid+1,y,mid+1,r,rson));
        //cout<<ans<<endl;
        return ans;
    }
    else if(x<=mid)
        return queryM(x,y,l,mid,lson);
    else if(y>mid)
        return queryM(x,y,mid+1,r,rson);
}
int querysum(int x,int y,int a,int b,int c)
{
    return sum[y]-sum[x-1];
}
int n;
int cal(int x1,int y1,int x2,int y2)
{
    int a,b,c;
    if(x2>y1)
    {
        a=queryr(x1,y1,1,n,1);
        b=queryl(x2,y2,1,n,1);
        return a+b+sum[x2-1]-sum[y1];
    }
    int ans;
    a=queryr(x1,x2,1,n,1);
    b=queryl(x2,y2,1,n,1);
    ans=a+b-A[x2];


    a=queryM(x2,y1,1,n,1);
    ans=max(ans,a);


    a=queryr(x1,y1,1,n,1);
    b=queryl(y1,y2,1,n,1);
    ans=max(ans,a+b-A[y1]);


    return ans;
}
int main()
{
    int i,j,m,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        sum[0]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&A[i]);
            sum[i] = sum[i-1]+A[i];
        }
        build(1,n,1);
        int a,b;
        scanf("%d",&m);
        while(m--)
        {
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            int sum=0;

            if(b<c)
            {
                sum=0;
                if(b+1<=c-1)
                    sum = querysum(b+1,c-1,1,n,1);
                sum += queryr(a,b,1,n,1);
                sum += queryl(c,d,1,n,1);
            }
            else if(b==c)
            {
                int sum2=queryr(a,c,1,n,1)+queryl(c,d,1,n,1)-A[b];
                sum = sum2;
            }
            else if(b>c)
            {
                sum = 0;
                if(c+1<=b-1)
                    sum = querysum(c+1,b-1,1,n,1);
                sum += max(0,queryr(a,c,1,n,1));
                sum += max(0,queryl(b,d,1,n,1));
                //cout<<sum<<"()"<<queryr(a,c,1,n,1)<<"*"<<queryl(b,d,1,n,1)<<endl;

                int sum2 = queryM(c,b,1,n,1);
                sum = max(sum,sum2);
                //cout<<sum2<<endl;


                int sum3 = queryr(a,c,1,n,1)+queryl(c,b,1,n,1)-A[c];
                sum = max(sum,sum3);
                //cout<<sum3<<" "<<A[c]<<"  "<<endl;

                int sum4 = queryl(b,d,1,n,1)+queryr(c,b,1,n,1)-A[b];
                sum = max(sum,sum4);
                //cout<<sum4<<"----"<<A[b]<<endl;
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}
