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
#define inf 0x3fffffff
int a[maxn];
int b[maxn], add[maxn];
int ok(int x, int n, int m, int w)
{
    int i,j;
    for(i = 1; i<= n; i++)b[i] = a[i];
    memset(add, 0, sizeof add);
    int sum = 0;
    for(i = 1; i <= n; i++)
    {
        sum += add[i];
        b[i] += sum;
        if(b[i]<x)
        {
            int tmp = x - b[i];
            b[i] += tmp;
            m -= tmp;
            sum += tmp;
            int g = min(maxn-1,i+w);
            add[g] -= tmp;
            if(m<0)return 0;
        }
    }
    for(i = n; i >0; i--)
        if(b[i]<x)return 0;
    return 1;
}
int n, w, m;
int main()
{
    while(scanf("%d %d %d",&n,&m,&w)!=EOF)
    {
        int Min = inf, Max = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&a[i]);
            Min = min(Min, a[i]);
            Max = max(Max, a[i]);
        }
        int ans = Min;
        int l = Min, r = Max + m;
        while(l <= r)
        {
            int mid = (l+r)>>1;
            if(ok(mid, n, m, w))
            {
                ans = max(ans, mid);
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
