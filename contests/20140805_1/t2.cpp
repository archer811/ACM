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
struct Edge
{
    int m,w,l;
    Edge *next;
};
int const INF=0x3fffffff;
int const N=100,M=9,Q=10000;
int const S=2000000;
int p3[M+1];
Edge edges[Q];
Edge *adj[N];
int e[M],f[M];
int ii[S],jj[S];
int d[S];
bool b[S];
int n,m,q;
int cnt,num;
inline void initialize()
{
    int k;
    p3[0]=1;
    for(k=1; k<=M; ++k)
        p3[k]=p3[k-1]*3;
}
inline Edge* makeEdge(int m,int w,int l,Edge *next)
{
    edges[cnt].m=m;
    edges[cnt].w=w;
    edges[cnt].l=l;
    edges[cnt].next=next;
    return &edges[cnt];
}
bool readin()
{
    int x,y,z,d,k;
    if(scanf("%d%d%d",&n,&m,&q)==EOF)
        return false;
    for(k=0; k<m; ++k)
        scanf("%d",&e[k]);
    for(k=0; k<m; ++k)
        scanf("%d",&f[k]);
    for(k=0; k<n; ++k)
        adj[k]=NULL;
    for(cnt=0; cnt<q; ++cnt)
    {
        scanf("%d%d%d%d",&x,&y,&z,&d);
        adj[x]=makeEdge(z,y,d,adj[x]);
    }
    return true;
}
inline int D(int index)
{
    return d[index];
}
void remove()
{
    int x,y,z,r=1,pr,left,right;
    z=ii[num];
    ii[1]=z;
    jj[z]=1;
    --num;
    while((r<<1)<=num)
    {
        left=r<<1;
        right=(r<<1)+1;
        if(right<=num)
            pr=D(ii[left])<D(ii[right])?left:right;
        else
            pr=left;
        if(D(ii[r])<=D(ii[pr]))
            break;
        x=ii[r];
        y=ii[pr];
        ii[r]=y;
        jj[y]=r;
        ii[pr]=x;
        jj[x]=pr;
        r=pr;
    }
}
void adjust(int pr)
{
    int x,y,r;
    while((pr>>1)>=1)
    {
        r=pr>>1;
        if(D(ii[r])<=D(ii[pr]))
            break;
        x=ii[r];
        y=ii[pr];
        ii[r]=y;
        jj[y]=r;
        ii[pr]=x;
        jj[x]=pr;
        pr=r;
    }
}
void solve()
{
    int status,pstatus,nstatus,v,w,mid,t,l,k;
    Edge *pE;
    cnt=p3[m]*n;
    for(k=0; k<cnt; ++k)
    {
        d[k]=INF;
        ii[k+1]=k;
        jj[k]=k+1;
    }
    memset(b,false,sizeof(b));
    num=cnt;
    d[0]=0;
    while(true)
    {
        if(num==0)
        {
            printf("-1\n");
            return;
        }
        pstatus=ii[1];
        if(d[pstatus]==INF)
        {
            printf("-1\n");
            return;
        }
        b[pstatus]=true;
        v=pstatus/p3[m];
        status=pstatus%p3[m];
        if(v==n-1)
        {
            printf("%d\n",d[pstatus]);
            return;
        }
        pE=adj[v];
        remove();
        while(pE!=NULL)
        {
            mid=pE->m;
            t=(status%p3[mid+1])/p3[mid];
            w=pE->w;
            l=pE->l;
            if(t==0)
            {
                nstatus=status+p3[mid];
            }
            else if(t==1)
            {
                l+=e[mid];
                nstatus=status+p3[mid];
            }
            else if(t==2)
            {
                l+=f[mid];
                nstatus=status;
            }
            nstatus+=w*p3[m];
            if(!b[nstatus]&&d[pstatus]+l<d[nstatus])
            {
                d[nstatus]=d[pstatus]+l;
                adjust(jj[nstatus]);
            }
            pE=pE->next;
        }
    }
}
int main()
{
    initialize();
    while(readin())
        solve();
    return 0;
}
