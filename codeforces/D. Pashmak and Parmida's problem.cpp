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
const int maxn = 1000006;
int a[maxn];
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
int b[maxn],c[maxn];
map<int,int>M,N;
int bs[maxn],cs[maxn];
#define ll __int64
int lowbit(int x)
{
    return x&(-x);
}
int gs(int x)
{
    int s=0;
    while(x>0)
    {
        s+=bs[x];
        x-=lowbit(x);
    }
    return s;
}
void add(int x,int v)
{
    while(x<maxn)
    {
        bs[x]+=v;
        x+=lowbit(x);
    }
}
int main()
{
    int i,j;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        memset(bs,0,sizeof(bs));
        M.clear();
        int tot=1;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(M[a[i]]==0)M[a[i]]=tot++;
        }
        N.clear();
        for(i=1;i<=n;i++)
        {
            int t = M[a[i]];
            N[t]++;
            b[i]=N[t];
        }

        N.clear();
        for(i=n;i>=1;i--)
        {
            int t = M[a[i]];
            N[t]++;
            c[i]=N[t];
        }
        ll ans=0;
        for(i=n;i>=1;i--)
        {
//            cout<<i<<"  "<<b[i]-1<<" "<<gs(b[i]-1)<<endl;
            ans += gs(b[i]-1);
            add(c[i],1);
        }
        cout<<ans<<endl;
    }
    return 0;
}
