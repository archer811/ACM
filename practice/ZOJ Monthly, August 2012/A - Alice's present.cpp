#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
using namespace std;
#define lson rt<<1
#define rson rt<<1|1
const int maxn = 500004;
struct array
{
    int x,y;
}doll[maxn];
int n;
int cmp(array a,array b)
{
    if(a.x!=b.x)return a.x<b.x;
    return a.y<b.y;
}
int tree[maxn<<2][2],a[maxn],b[maxn];
int pre[maxn];
int anspre[maxn];
void pushup(int a1,int b1,int a2,int b2,int &ansx,int &ansy)
{
    if(a1==n+1&&a2==n+1)
    {
        ansx=n+1;ansy=b2;
    }
    else if(a1==n+1&&a2!=n+1)
    {
        ansx=a2;ansy=b2;
    }
    else if(a1!=n+1&&a2==n+1)
    {
        ansx=a1;ansy=b1;
    }
    else
    {
        if(b2-a2>=b1-a1)
        {
            ansx=a2;ansy=b2;
        }
        else
        {
            ansx=a1;ansy=b1;
        }
    }
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        tree[rt][0]=b[l];
        tree[rt][1]=l;
       // cout<<l<<" "<<r<<" "<<rt<<" "<<tree[rt][0]<<" "<<tree[rt][1]<<endl;
        return;
    }
    int mid = (l+r)>>1;
    build(l,mid,lson);
    build(mid+1,r,rson);
    pushup(tree[lson][0],tree[lson][1],tree[rson][0],tree[rson][1],
           tree[rt][0],tree[rt][1]);
//    cout<<l<<" "<<r<<" "<<rt<<" "<<tree[rt][0]<<" "<<tree[rt][1]<<
//    " "<<anspre[tree[rt][1]]<<endl;
}
void query(int x,int y,int l,int r,int rt,int &ansx,int &ansy)
{

    if(x<=l&&y>=r)
    {
        //cout<<tree[rt][0]<<" "<<tree[rt][1]<<" "<<x<<" "<<y<<" "<<anspre[tree[rt][0]]<<endl;
        if(tree[rt][0]==n+1||tree[rt][0]>(tree[rt][1]-x+1))
        {
            ansx=n+1;ansy=-1;
        }else
        {
            ansx = tree[rt][0];
            ansy = tree[rt][1];
        }
        //cout<<l<<" "<<r<<" "<<rt<<" "<<ansx<<" "<<ansy<<endl;
        return;
    }
    int a1=n+1,a2=n+1,b1=-1,b2=-1;
    int mid = (l+r)>>1;
    if(x<=mid)
    query(x,y,l,mid,lson,a1,b1);
    if(y>mid)
    query(x,y,mid+1,r,rson,a2,b2);
    pushup(a1,b1,a2,b2,ansx,ansy);
}

int main()
{
    int i,j,m;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&doll[i].x);
            doll[i].y=i;
        }
        memset(pre,-1,sizeof(pre));
        sort(doll+1,doll+1+n,cmp);
        int size=1;
        for(i=1;i<=n;i++)
        {
            if(i==1||doll[i-1].x!=doll[i].x)
                a[doll[i].y]=size++;
            else
                a[doll[i].y]=size-1;
            anspre[doll[i].y]=doll[i].x;
        }
        for(i=1;i<=n;i++)
        {
            if(pre[a[i]]==-1)
            {
                pre[a[i]]=i;
                b[i]=n+1;
            }
            else
            {
                b[i]=i-pre[a[i]]+1;
                pre[a[i]]=i;
            }
        }
        build(1,n,1);
        scanf("%d",&m);
        int x,y;
        while(m--)
        {
            scanf("%d%d",&x,&y);
            int ansx=n+1,ansy=-1;
            query(x,y,1,n,1,ansx,ansy);
            if(ansx!=n+1)
                printf("%d\n",anspre[ansy]);
            else
                puts("OK");

            //cout<<ansx<<" * "<<ansy<<endl;
        }puts("");
    }
}
