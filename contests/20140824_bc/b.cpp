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
int f(int sum,int k,int f2)
{
    int s=0;
    int j=1,i;
    for(i=1;i<=k;i++)
    {
        if(j==f2)j++;
        s += j;
        j++;
    }
    if(sum<s)return 0;
    s =0;
    j = 1;
    for(i=1;i<=k-1;i++)
    {
        if(j==f2)j++;
        s += j;
        j++;
    }
    int tmp = sum-s;
    if(tmp!=f2 && tmp >= j)return 1;
    s = 0;
    j = 1;
    for(i=1;i<=k-2;i++)
    {
        if(j==f2)j++;
        s += j;
        j++;
    }
    tmp = sum-s;
    for(i=j;i<=tmp/2;i++)
    {
        int x = i;
        int y = tmp-i;
        if(x>=j&&y>=j&&x!=y&&x!=f2&&y!=f2)return 1;
    }
    return 0;
}
int main()
{
    int i,j,n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        int flag=0;
        for(i=1;i*i<n;i++)
        {
            if(f(i*i,k-1,n-i*i))
            {
                flag=1;
                //cout<<i<<endl;
                break;
            }
        }
        if(flag)puts("YES");
        else puts("NO");
    }
    return 0;
}
