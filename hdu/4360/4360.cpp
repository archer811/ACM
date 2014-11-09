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
#ifdef __int64
typedef __int64 ll;
#else
typedef long long ll;
#endif

const int maxn = 1314+100;
int head[maxn],tot;
const int maxm =13520*2+1000;
struct Edge
{
    int to,next,l,kind;
}edge[maxm];
void add(int u,int v,int l,int kind)
{
    edge[tot].to=v;
    edge[tot].l=l;
    edge[tot].kind=kind;
    edge[tot].next=head[u];
    head[u]=tot++;
}
char s[2];
int d[maxn][16],d2[maxn],num[maxn][16];
void bfs()
{
    queue<int>q;
    q.push(1);
    while(!q.empty())
    {
        int u = q.front();q.pop();
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].to;
            int flag=0;
            if(edge[i].kind==0)
            {
                if(d[v][1]==-1||d[v][1]>d2[u]+edge[i].l)
                {
                    d[v][1]=d2[u]+edge[i].l;
                    flag=1;
                    num[v][1]=num
                }
                else
                    d[v][1]=min(d[v][1],d2[u]+edge[i].l);
            }
            else if(edge[i].kind==1)
            {
                if(d[v][3]==-1||d[v][3]>d[u][1]+edge[i].l)
                {
                    d[v][3]=d[u][1]+edge[i].l;
                    flag=1;
                    num[v][3]=num[u][1];
                }
                else
                    d[v][3]=min(d[v][3],d[u][1]+edge[i].l);
            }
            else if(edge[i].kind==2)
            {
                if(d[v][7]==-1||d[v][7]>d[u][3]+edge[i].l)
                {
                    d[v][7]=d[u][3]+edge[i].l;
                    flag=1;
                    num[v][7]=num[u][3];
                }
                else
                    d[v][7]=min(d[v][7],d[u][3]+edge[i].l);
            }
            else if(edge[i].kind==3)
            {
                if(d[v][15]==-1||d[v][15]>d[u][7]+edge[i].l)
                {
                    d[v][15]=d[u][7]+edge[i].l;
                    flag=1;
                    num[v][15]=num[u][7]+1;
                }
                else
                    d[v][15]=min(d[v][15],d[u][7]+edge[i].l);
            }

            if(flag)
                q.push(v);
        }
    }
}
const int inf = 0x3fffffff;
int main()
{
    int i,j,t,n,m;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(head,-1,sizeof(head));
        tot=0;
        for(i=0;i<m;i++)
        {
            int u,v,l,kind;
            scanf("%d%d%d%s",&u,&v,&l,s);
            if(s[0]=='L')kind=0;
            else if(s[0]=='O')kind=1;
            else if(s[0]=='V')kind=2;
            else kind=3;
            add(u,v,l,kind);
            add(v,u,l,kind);
        }
        memset(d,0x3f,sizeof(d));
        //memset(d2,0x3f,sizeof(d2));
        d[1][0]=0;
        num[1][0]=0;
        d2[1]=0;
        bfs();
        printf("Case %d: ",++cas);
        int ans=d[n][15];
        if(ans<m)printf("Cute Sangsang, Binbin will come with a donkey after travelling %d meters and finding 1 LOVE strings at last.",ans);
        else
        puts("Binbin you disappoint Sangsang again, damn it!");
    }
    return 0;
}
