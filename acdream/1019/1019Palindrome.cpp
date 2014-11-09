#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 1000005;
#define ll unsigned long long
ll bit[maxn],c[2][maxn];
char s[maxn];
void init()
{
    int i;
    bit[0]=1;
    for(i=1;i<maxn;i++)
        bit[i]=bit[i-1]*31;
}
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,ll w,int p)
{
    while(x<maxn)
    {
        c[p][x]+=w;
        x+=x&(-x);
    }
}
//void Add(int x,i64 det,int p)
//{
//    while(x<MAX)
//    {
//        s[p][x]+=det;
//        x+=x&(-x);
//    }
//}
ll get(int x,int p)
{
    ll sum=0;
    while(x>0)
    {
        sum += c[p][x];
        x -= lowbit(x);
    }
    return sum;
}
int main()
{
    int i,j,k,m,d;
    char ask[2];
    while(scanf("%s",s+1)!=EOF)
    {
        init();
        int n = strlen(s+1);
        memset(c,0,sizeof(c));
        for(i=1;i<=n;i++)
        {
            add(i,s[i]*bit[i],0);
            add(n+1-i,s[i]*bit[n+1-i],1);
        }

        scanf("%d",&m);
        while(m--)
        {
            scanf("%s",ask);
            if(ask[0]=='C')
            {
                scanf("%d%s",&d,ask);
                add(d,bit[d]*(ask[0]-s[d]),0);
                add(n+1-d,bit[n+1-d]*(ask[0]-s[d]),1);
            }
            else
            {
                scanf("%d%d",&i,&j);
                ll x = get(j,0)-get(i-1,0);
                ll y = get(n+1-i,1)-get(n-j,1);
                x *= bit[maxn-i];
                y *= bit[maxn-(n+1-j)];
                if(x==y)puts("yes");
                else puts("no");
            }
        }
    }
}
