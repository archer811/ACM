#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
struct array
{
    int x,y,v;
}g[100006];
#define ll __int64
const int maxn = 1000005;
struct HashMap
{
    int head[maxn],next[maxn],size;
    int f[maxn];
    ll state[maxn];
    void init()
    {
        size=0;
        memset(head,-1,sizeof(head));
    }
    void push(ll st,int ans)
    {
        int i,h=(st%maxn+maxn)%maxn;
        for(i=head[h];i!=-1;i=next[i])
        {
            if(st==state[i])
            {
                f[i]=ans;return;
            }
        }
        f[size]=ans;
        state[size]=st;
        next[size]=head[h];
        head[h]=size++;
    }
    int find(ll st)
    {
        int i,h=(st%maxn+maxn)%maxn;
        for(i=head[h];i!=-1;i=next[i])
        {
            if(st==state[i])
            {
                return f[i];
            }
        }
        return 0;
    }
}myhash;
const ll G = (ll)1000000007;
int max(int a,int b)
{
    if(a>b)return a;
    return b;
}
inline int readint()
{
    char c = getchar();
    while(!isdigit(c))c=getchar();
    int x=0;
    while(isdigit(c))
    {
        x = x*10+c-'0';
        c = getchar();
    }
    return x;
}
int buf[10];
inline void writeint(int i)
{
    int p=0;
    if(i==0)p++;
    else while(i)
    {
        buf[p++]=i%10;
        i/=10;
    }
    for(int j=p-1;j>=0;j--)
        putchar('0'+buf[j]);
}
int main()
{
    int i,j,n;
    n=readint();
    {
        myhash.init();
        for(i=0;i<n;i++)
        {
            //scanf("%d%d%d",&g[i].x,&g[i].y,&g[i].v);
            g[i].x=readint();
            g[i].y=readint();
            g[i].v=readint();
            ll x = (ll)g[i].x*G+(ll)g[i].y;
            myhash.push(x,g[i].v);
        }
        int ans=0;
        for(i=0;i<n;i++)
        {
            ll a,b,c,d,e,f,g2,h,i2;
            a = myhash.find((ll)(g[i].x*G+g[i].y));
            b = myhash.find(g[i].x*G+g[i].y-1);
            c = myhash.find((g[i].x+1)*G+g[i].y);
            d = myhash.find(g[i].x*G+g[i].y+1);
            e = myhash.find((g[i].x-1)*G+g[i].y);

            f = myhash.find((g[i].x-1)*G+g[i].y-1);
            //v[make_pair(g[i].x-1,g[i].y-1)];
            g2 = myhash.find((g[i].x+1)*G+g[i].y-1);
            //v[make_pair(g[i].x+1,g[i].y-1)];
            h = myhash.find((g[i].x+1)*G+g[i].y+1);
            //v[make_pair(g[i].x+1,g[i].y+1)];
            i2 = myhash.find((g[i].x-1)*G+g[i].y+1);
            //v[make_pair(g[i].x-1,g[i].y+1)];
            ans = max(ans,a+b+e+f);

            ans = max(ans,a+b+g2+c);

            ans = max(ans,a+d+c+h);
            ans = max(ans,a+d+e+i2);
        }
       // writeint(ans);
        printf("%d / 1\n",ans);
//        putchar(' ');
//        putchar('/');
//        putchar(' ');
//        putchar('1');
//        putchar('\n');
    }
    return 0;
}
