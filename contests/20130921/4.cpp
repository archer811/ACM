#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
class match
{
//  #pragma comment(linker,"/STACK:100000000,100000000")扩栈语句啊！！
public://top标记重边的头，w标记与其父节点相连的边在树中的位置，也为代表点的
    int n,m,len,topw;
    int fa[N],size[N],son[N],w[N],top[N],dep[N];
    int pre[N],lit[N];//表示字节点在线段树中的后区间的
    struct node
    {
        int y,pre;
    };
    node a[N];
    struct no
    {
        int l,r,sign;
        bool flag;
    };
    no aa[N*4];
    void init()
    {
        len=0;
        topw=1;
        memset(pre,-1,sizeof(pre));
        memset(son,-1,sizeof(son));
    }
    void addpage(int x,int y)
    {
        a[len].pre=pre[x];
        a[len].y=y;
        pre[x]=len++;
    }
    void dfs(int s,int faa,int h)//根节点，父节点和深度的
    {
        dep[s]=h;
        size[s]=1;
        int Max=0,sign;
        for(int i=pre[s]; i!=-1; i=a[i].pre)
        {
            int y=a[i].y;
            if(y==faa) continue;
            fa[y]=s;
            dfs(y,s,h+1);
            if(size[y]>Max)
                Max=size[y],sign=y;
            size[s]+=size[y];
        }
        if(Max!=0) son[s]=sign;
    }
    void dfs2(int s,int faa,int tp)//搜索top值，和w值得
    {
        w[s]=topw++;
        top[s]=tp;
        if(son[s]!=-1) dfs2(son[s],s,tp);
        for(int i=pre[s]; i!=-1; i=a[i].pre)
        {
            int y=a[i].y;
            if(y==faa || y==son[s]) continue;
            dfs2(y,s,y);
        }
        lit[s]=topw-1;//记录字节点在线段树的最后的位置的
    }
    void bulidtree(int s,int l,int r)//建立线段树
    {
        aa[s].sign=0;
        aa[s].l=l;
        aa[s].r=r;
        aa[s].flag=false;
        if(l==r) return ;
        int mid=(l+r)/2;
        bulidtree(2*s,l,mid);
        bulidtree(2*s+1,mid+1,r);
    }
    void pushdown(int s)//进行更新的
    {
        aa[2*s].sign=aa[2*s+1].sign=aa[s].sign;
        aa[2*s].flag=aa[2*s+1].flag=true;
        aa[s].sign=0;
        aa[s].flag=false;
    }
    int search(int s,int x)//查找线段树中x节点的值x=w[?]'
    {
        if(aa[s].l==aa[s].r && aa[s].l==x)
            return aa[s].sign;
        if(aa[s].flag==true)
            pushdown(s);
        int mid=(aa[s].l+aa[s].r)/2;
        if(x<=mid)
            return search(2*s,x);
        else return search(2*s+1,x);
    }
    void deal(int s,int x,int y,int z)//处理x和y之间的路径什么的
    {
        //top[x],top[y]代表的是重链的最头部的
        int fx=top[x],fy=top[y];
        while(fx!=fy)
        {
            if(dep[fx]>dep[fy])
                swap(fx,fy),
                     swap(x,y);
            refresh(1,w[fy],w[y],z);//更新的
            y=fa[fy],fy=top[y];
        }
        if(dep[x]>dep[y])
            swap(x,y);
        refresh(1,w[x],w[y],z);
    }
    void refresh(int s,int l,int r,int x)//对l和r之间进行更新的
    {
        if(aa[s].l>=l && aa[s].r<=r)
        {
            aa[s].flag=true;
            aa[s].sign=x;
            return ;
        }
        if(aa[s].flag==true)
            pushdown(s);
        int mid=(aa[s].l+aa[s].r)/2;
        if(r<=mid)
            refresh(2*s,l,r,x);
        else if(l>mid)
            refresh(2*s+1,l,r,x);
        else
            refresh(2*s,l,r,x),
                    refresh(2*s+1,l,r,x);
    }

};
match sa;
int main()
{
    int x,y;
    while(scanf("%d",&sa.n)!=EOF)
    {
        sa.init();
        rep(i,sa.n-1)
        scanf("%d%d",&x,&y),
              sa.addpage(x,y),
              sa.addpage(y,x);
        sa.dfs(1,-1,1);
        sa.dfs2(1,-1,1);
        sa.bulidtree(1,1,sa.n);
        /*用于给节点附初值的,没有的话忽略的
        repf(i,1,sa.n)
            refresh(1,sa.w[i],sa.w[i],sa.sum[N]);*/
        int q;
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d%d",&x,&y);
            if(x==1)
                sa.refresh(1,sa.w[y],sa.lit[y],1);
            else if(x==2)
                sa.deal(1,1,y,0);
            else
                printf("%d\n",sa.search(1,sa.w[y]));

        }
    }
    return 0;
}
