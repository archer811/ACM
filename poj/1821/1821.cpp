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
/*
const int maxn = 400005;
int head[maxn],tot;
struct Edge
{
    int to,next;
}edge[maxn];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}*/
const int maxn = 16006;
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
struct array
{
    int l,p,s;
}g[105];
int cmp(array a,array b)
{
    return a.s<b.s;
}
struct oo
{
    int whichman,ind;
    ll val;
}now,next;
int mark[maxn];
int main()
{
    int i,j,n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        memset(mark,0,sizeof(mark));
        for(i=1;i<=k;i++)
        {
            scanf("%d%d%d",&g[i].l,&g[i].p,&g[i].s);
            mark[g[i].s]=1;
        }
        sort(g+1,g+1+k,cmp);
        queue<oo>q;
        for(i=0;i<g[1].s;i++)
        {
            now.whichman = 0;
            now.ind = i;
            now.val=0;
            q.push(now);
        }
        int _now=1;
        ll ans=0;
        for(;i<=n;i++)
        {
            if(mark[i])_now++;
            int M = -1;
            while(!q.empty())
            {
                now = q.front();
                if(now.whichman<_now)
                {
                    //if(i-g[_now].s+1<=g[_now].l)
                    {
                        int t1 = i-now.ind;
                        if(t1>g[_now].l)
                        {
                            ll tmp = now.val + (ll)g[_now].l*(ll)g[_now].p;
                            if(M<tmp)M=tmp;
                        }
                        else
                        {
                            ll tmp = now.val + (ll)g[_now].p*(ll)t1;
                            if(M<tmp)M=tmp;
                        }
                    }
                    q.pop();
                }
                else break;
            }
            if(M>-1)
            {
                next.whichman = _now;
                next.val = M;
                next.ind=i;
                q.push(next);
                if(ans<M)ans=M;
                cout<<i<<" "<<_now<<"()"<<M<<endl;
            }
        }
        while(!q.empty())
        {
            now = q.front();q.pop();
            if(now.val>ans)ans=now.val;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
