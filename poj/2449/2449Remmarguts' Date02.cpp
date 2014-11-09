#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 1005;
const int maxm = 500005;
const int inf = 1000000000;
struct node
{
    int v,w,next;
}edge[maxm],revedge[maxm];
struct A
{
    int f,g,v;
    bool operator < (A a)const
    {
        if(a.f==f)return a.g<g;
        return a.f<f;
    }
};
int n,m,k,s,t,e;
int q[maxn*5];
int d[maxn],vis[maxn];
int head[maxn],revhead[maxn];
void init()
{
    e=0;
    memset(head,-1,sizeof(head));
    memset(revhead,-1,sizeof(revhead));
}
void insert(int x,int y,int w)
{
    edge[e].v = y;edge[e].w = w;
    edge[e].next=head[x];
    head[x]=e;
    revedge[e].v = x;revedge[e].w = w;
    revedge[e].next=revhead[y];
    revhead[y]=e++;
}
/*
void insert(int x,int y,int w)
{
    edge[e].v=y;edge[e].w=w;
    edge[e].next=head[x];
    head[x]=e;
    revedge[e].v = x;revedge[e].w = w;
    revedge[e].next=revhead[y];
    revhead[y]=e++;
}*/
void spfa(int src)
{
    int i,j,k=0;
    q[k++]=src;
    for(i=1;i<=n;i++)
        d[i]=inf,vis[i]=0;
    vis[src]=1;d[src]=0;
    for(j = 0;j<k;j++)
    {
        int v = q[j];
        vis[v]=0;
        for(i=revhead[v];i!=-1;i=revedge[i].next)
        {

            int vv = revedge[i].v; //cout<<vv<<"()())()"<<endl;
            if(d[vv]>d[v]+revedge[i].w)
            {
                d[vv]=d[v]+revedge[i].w;
                if(vis[vv]==0)
                {
                    vis[vv]=1;
                    q[k++]=vv;
                }
            }
        }
    }
    //cout<<"&"<<endl;
}


int astar()
{
    priority_queue<A>p;
    A t1,tt;
    if(d[t]>=inf)return -1;
    if(s==t)k++;
    t1.g=0;t1.v=s;t1.f=t1.g+d[s];
    p.push(t1);
    int tot=0;
//    for(int i=1;i<=n;i++)
//        cout<<i<<"f"<<d[i]<<endl;
//    cout<<endl;
    while(!p.empty())
    {
        tt = p.top();p.pop();
//        cout<<tt.f<<" "<<tt.g<<" "<<tt.v<<endl;
        if(tt.v==t)
        {
            tot ++;
            if(tot==k)return tt.g;
        }
        for(int i=head[tt.v];i!=-1;i=edge[i].next)
        {
            int v = edge[i].v;
            t1.g = tt.g+edge[i].w;
            t1.v = v;
            t1.f = t1.g + d[v];
            p.push(t1);
        }
    }
    return -1;
}
int main()
{
    int i,j,a,b,c;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            insert(a,b,c);
        }
        scanf("%d%d%d",&s,&t,&k);
        spfa(t);//cout<<"f"<<endl;

        printf("%d\n",astar());
    }
}
