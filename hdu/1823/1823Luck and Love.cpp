#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define MAXN 110
#define MAXM 1010
struct node
{
    int big[MAXM<<2];
};
node tree[MAXN<<2];
inline int MAX(int x,int y)
{
    return x>y?x:y;
}
void SubBuild(int t,int L,int R,int rt)
{
    tree[t].big[rt]=-1;
    if(L!=R)
    {
        int mid=(L+R)>>1;
        SubBuild(t,L,mid,rt<<1);
        SubBuild(t,mid+1,R,rt<<1|1);
    }
}
void Build(int h1,int h2,int rt)
{
    SubBuild(rt,0,1000,1);
    if(h1!=h2)
    {
        int mid=(h1+h2)>>1;
        Build(h1,mid,rt<<1);
        Build(mid+1,h2,rt<<1|1);
    }
}
void SubUpdate(int t,int x,int val,int L,int R,int rt)
{
    if(L==R)
        tree[t].big[rt]=MAX(tree[t].big[rt],val);
    else
    {
        int mid=(L+R)>>1;
        if(x<=mid)
            SubUpdate(t,x,val,L,mid,rt<<1);
        else
            SubUpdate(t,x,val,mid+1,R,rt<<1|1);
        tree[t].big[rt]=MAX(tree[t].big[rt<<1],tree[t].big[rt<<1|1]);
    }
}
void Update(int x,int y,int val,int L,int R,int rt)
{
    SubUpdate(rt,y,val,0,1000,1);
    if(L!=R)
    {
        int mid=(L+R)>>1;
        if(x<=mid)
            Update(x,y,val,L,mid,rt<<1);
        else
            Update(x,y,val,mid+1,R,rt<<1|1);
    }
}
int SubQuery(int t,int x,int y,int L,int R,int rt)
{
    if(x<=L&&R<=y)
        return tree[t].big[rt];
    int mid=(L+R)>>1,ans=-1;
    if(x<=mid)
        ans=MAX(ans,SubQuery(t,x,y,L,mid,rt<<1));
    if(y>mid)
        ans=MAX(ans,SubQuery(t,x,y,mid+1,R,rt<<1|1));
    return ans;
}
int Query(int h1,int h2,int a1,int a2,int L,int R,int rt)
{
    if(h1<=L&&R<=h2)
        return SubQuery(rt,a1,a2,0,1000,1);
    int mid=(L+R)>>1,ans=-1;
    if(h1<=mid)
        ans=MAX(ans,Query(h1,h2,a1,a2,L,mid,rt<<1));
    if(h2>mid)
        ans=MAX(ans,Query(h1,h2,a1,a2,mid+1,R,rt<<1|1));
    return ans;
}
int main()
{
    char ch;
    int q,h1,h2,ans;
    double a1,a2,val;
    while(scanf("%d",&q),q)
    {
        Build(100,200,1);
        while(q--)
        {
            scanf(" %c",&ch);
            if(ch=='I')
            {
                scanf("%d%lf%lf",&h1,&a1,&val);
                Update(h1,int(a1*10),int(val*10),100,200,1);
            }
            else
            {
                scanf("%d%d%lf%lf",&h1,&h2,&a1,&a2);
                if(h1>h2)
                    swap(h1,h2);
                if(a1>a2)
                    swap(a1,a2);
                ans=Query(h1,h2,(int)(a1*10),(int)(a2*10),100,200,1);
                if(ans<0)
                    puts("-1");
                else
                    printf("%.1lf\n",ans/10.0);
            }
        }
    }
    return 0;
}
