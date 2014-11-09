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
int a[100],b[100];
int f(int a,int b)
{
    if(a-b<0)return b-a;
    return a-b;
}
int main()
{
    int i,j,t;
    int n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(i=1;i<=1001;i++)
        {
            int flag=0;
            for(j=1;j<n;j++)
            {
                b[j]=f(a[j],a[j+1]);
                if(b[j])flag=1;
            }
            b[n]=f(a[n],a[1]);
            if(b[n])flag=1;
            for(j=1;j<=n;j++)
                a[j]=b[j];
            if(flag==0)break;
        }
        if(i>=1001)puts("LOOP");
        else puts("ZERO");
    }
    return 0;
}
