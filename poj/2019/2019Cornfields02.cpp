#include<cstdio>
#define MAXN 300
struct node
{
    int big[MAXN<<2],small[MAXN<<2];
};
node tree[MAXN<<2];
int n,b;
inline int MAX(int x,int y)
{
    return x>y?x:y;
}
inline int MIN(int x,int y)
{
    return x>y?y:x;
}
void SubBuild(int t,int L,int R,int rt)
{
    tree[t].big[rt]=0;
    tree[t].small[rt]=MAXN;
    if(L!=R)
    {
        int mid=(L+R)>>1;
        SubBuild(t,L,mid,rt<<1);
        SubBuild(t,mid+1,R,rt<<1|1);
    }
}
void Build(int L,int R,int rt)
{
    SubBuild(rt,1,n,1);
    if(L!=R)
    {
        int mid=(L+R)>>1;
        Build(L,mid,rt<<1);
        Build(mid+1,R,rt<<1|1);
    }
}
void SubUpdate(int t,int x,int val,int L,int R,int rt)
{
    if(L==R)
    {
        tree[t].big[rt]=MAX(tree[t].big[rt],val);
        tree[t].small[rt]=MIN(tree[t].small[rt],val);
    }
    else
    {
        int mid=(L+R)>>1;
        if(x<=mid)
            SubUpdate(t,x,val,L,mid,rt<<1);
        else
            SubUpdate(t,x,val,mid+1,R,rt<<1|1);
        tree[t].big[rt]=MAX(tree[t].big[rt<<1],tree[t].big[rt<<1|1]);
        tree[t].small[rt]=MIN(tree[t].small[rt<<1],tree[t].small[rt<<1|1]);
    }
}
void Update(int x,int y,int val,int L,int R,int rt)
{
    SubUpdate(rt,y,val,1,n,1);
    if(L!=R)
    {
        int mid=(L+R)>>1;
        if(x<=mid)
            Update(x,y,val,L,mid,rt<<1);
        else
            Update(x,y,val,mid+1,R,rt<<1|1);
    }
}
int SubQueryB(int t,int x,int y,int L,int R,int rt)
{
    if(x<=L&&R<=y)
        return tree[t].big[rt];
    int mid=(L+R)>>1,ans=0;
    if(x<=mid)
        ans=MAX(ans,SubQueryB(t,x,y,L,mid,rt<<1));
    if(y>mid)
        ans=MAX(ans,SubQueryB(t,x,y,mid+1,R,rt<<1|1));
    return ans;
}
int QueryB(int x1,int x2,int y1,int y2,int L,int R,int rt)
{
    if(x1<=L&&R<=x2)
        return SubQueryB(rt,y1,y2,1,n,1);
    int mid=(L+R)>>1,ans=0;
    if(x1<=mid)
        ans=MAX(ans,QueryB(x1,x2,y1,y2,L,mid,rt<<1));
    if(x2>mid)
        ans=MAX(ans,QueryB(x1,x2,y1,y2,mid+1,R,rt<<1|1));
    return ans;
}
int SubQueryS(int t,int x,int y,int L,int R,int rt)
{
    if(x<=L&&R<=y)
        return tree[t].small[rt];
    int mid=(L+R)>>1,ans=MAXN;
    if(x<=mid)
        ans=MIN(ans,SubQueryS(t,x,y,L,mid,rt<<1));
    if(y>mid)
        ans=MIN(ans,SubQueryS(t,x,y,mid+1,R,rt<<1|1));
    return ans;
}
int QueryS(int x1,int x2,int y1,int y2,int L,int R,int rt)
{
    if(x1<=L&&R<=x2)
        return SubQueryS(rt,y1,y2,1,n,1);
    int mid=(L+R)>>1,ans=MAXN;
    if(x1<=mid)
        ans=MIN(ans,QueryS(x1,x2,y1,y2,L,mid,rt<<1));
    if(x2>mid)
        ans=MIN(ans,QueryS(x1,x2,y1,y2,mid+1,R,rt<<1|1));
    return ans;
}
int main()
{
    int q,x,i,j,big,small;
    while(~scanf("%d%d%d",&n,&b,&q))
    {
        Build(1,n,1);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&x);
                Update(i,j,x,1,n,1);
            }
        }
        while(q--)
        {
            scanf("%d%d",&i,&j);
            big=QueryB(i,i+b-1,j,j+b-1,1,n,1);
            small=QueryS(i,i+b-1,j,j+b-1,1,n,1);
            printf("%d\n",big-small);
        }
    }
    return 0;
}
