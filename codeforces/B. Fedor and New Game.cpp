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
//
int a[maxn];
int main()
{
    int i,j,n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        for(i=1;i<=m+1;i++)
            scanf("%d",&a[i]);
        int s=0;
        for(i=1;i<=m;i++)
        {
            int g=0;
            for(j=0;j<n;j++)
            {
                int a2 = (1<<j)&a[i];
                int b = (1<<j)&a[m+1];
                if(a2!=b)g++;
            }
            if(g<=k)s++;
        }
        printf("%d\n",s);
    }
    return 0;
}
