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
int a[1005];
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        int sum=0;
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]),sum += a[i];

        sort(a+1,a+1+n);

        int g = (1+n)/2;
        int ans = a[g];
        if(ans*n<=sum)puts("NO");
        else puts("YES");
    }
    return 0;
}
