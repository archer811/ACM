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
int a[500005];
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for(i=1;i<=3;i++)
        {
            a[i]=(k-1)%i;
            for(j=i+1;j<=n;j++)
            {
                a[j]=(a[j-1]+k)%j;
            }
            a[i]=a[n]+1;
        }
        printf("%d %d %d\n",a[3],a[2],a[1]);
    }
    return 0;
}
