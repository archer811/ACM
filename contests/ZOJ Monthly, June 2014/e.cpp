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
const int maxn = 600006;
int f[maxn];
int s[maxn];
int r[maxn];
char tp[2];
int mark[maxn];
int find(int x)
{
    if(x==f[x])return x;
    int t=find(f[x]);
    if(r[x]==r[f[x]])r[x]=0;
    else r[x]=1;
    return f[x]=t;
}
void add(int a,int b,int u,int v)
{
    f[v]=u;
    s[u]+=s[v];
    if(a!=b)r[v]=r[u];
    else
    {
        r[v]=1-r[u];
    }

}
int main()
{
    int i,j,n,m;
    int a,b;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int tot=n+1;
        for(i=1;i<=n+m;i++)
        {
            f[i]=i;s[i]=1;
            r[i]=0;mark[i]=i;
        }
        while(m--)
        {
            scanf("%s",tp);
            if(tp[0]=='L')
            {
                scanf("%d%d",&a,&b);
                a=mark[a];b=mark[b];
                int x = find(a),y=find(b);
                if(x==y)continue;
                //x=mark[x];y=mark[y];
                add(r[a],r[b],x,y);
            }
            else if(tp[0]=='D')
            {
                scanf("%d",&a);
                b=mark[a];
                int x=find(b);
                //x=mark[x];
                s[x]--;
                mark[a]=tot++;
            }
            else if(tp[0]=='Q')
            {
                scanf("%d%d",&a,&b);
                a=mark[a];b=mark[b];
                int x=find(a),y=find(b);
                //x=mark[x];y=mark[y];
                if(x!=y)puts("Unknown");
                else if(r[a]==r[b])puts("Same");
                else puts("Different");
            }
            else
            {
                scanf("%d",&a);
                a=mark[a];
                int x=find(a);
                printf("%d\n",s[x]);
            }
        }
    }
    return 0;
}
