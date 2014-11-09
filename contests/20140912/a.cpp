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
const int maxn = 1000006;
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int extgcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    int d=extgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-a/b*y;
    return d;
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int g = gcd(a,b);

        if(c%g)
        {
            puts("0");
        }
        else
        {
            //cout<<c<<"*"<<g<<endl;
            int a2,b2,c2;
            a2 = a/g;
            b2 = b/g;
            c2 = c/g;
            int x,y;
            extgcd(a2,b2,x,y);
            int sum=0;
            int g1,g2;
            //cout<<x<<" "<<y<<endl;
            for(i=-c2*x/b2;;i++)
            {
                g1 = c2*x+b2*i;
                g2 = (c-g1*a)/b;
                //cout<<g1<<" "<<g2<<endl;
                if(g1>0&&g2>0)sum++;
                else if(g2<0)break;
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}
