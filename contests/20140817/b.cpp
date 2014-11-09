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
int a[20];
void getAns(int n,int m)
{
    a[0]=0;
    a[1]=(m-1)%n;
    a[2]=(2*m-2)%n;
    for(int i=0;i<=n;i++)
        a[i]=i;
    int j=0;
    for (int i=2; i<=n; i++)
    {
        //ans=(ans+m)%i;
       // a[0]=(a[0]+m)%i;
       // //a[1]=(a[1]+m)%i;
       // a[2]=(a[2]+m)%i;
    for(int j=0;j<=n;j++)
    {
        a[j]=(a[j]+m)%i;
    }
    }
    a[0]=a[0]+1;
}
int main()
{
    int i,j;
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        getAns(n,m);
        for(i=0;i<=n;i++)
            cout<<i<<"  "<<a[i]<<endl;
        //cout<<a[0]<<" "<<a[1]<<"  "<<a[2]<<endl;
        //printf("%d %d %d\n",anso[0],anso[1],anso[2]);
    }
    return 0;
}
