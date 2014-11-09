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
int b[606],num[606];
int d[maxn];
int f[maxn],o[maxn],flag[maxn];
int main()
{
    int i,j,n,k,p;
    while(scanf("%d%d%d",&n,&k,&p)!=EOF)
    {
        for(i=1;i<=k;i++)
            scanf("%d",&b[i]);
        memset(num,0,sizeof(num));
        memset(flag,0,sizeof(flag));
        int a,c;
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&c);
            b[c]+=a;
            num[c]++;
        }
        memset(d,-1,sizeof(d));
        for(i=1;i<=k;i++)
        {
            cout<<i<<" "<<b[i]<<" "<<num[i]<<endl;
        }
        d[0]=0;
        int g=0;
        f[g++]=0;
        for(i=1;i<=k;i++)
        {
            int s=0;
            for(j=0;j<g;j++)
            {
                int tmp = f[j];
                if(tmp+b[i]<=p)
                {
                    d[tmp+b[i]]=max(d[tmp+b[i]],d[tmp]+num[i]);
                    o[s++]=tmp+b[i];
                    flag[tmp+b[i]]=1;
                }
            }
            g =0;
            for(j=0;j<s;j++)
            {
                if(flag[o[j]])
                    f[g++]=o[j];
                flag[o[j]]=0;
            }
        }
        int M = 0;
        for(i=0;i<=p;i++)
            M=max(M,d[i]);
        printf("%d\n",M);
    }
    return 0;
}
