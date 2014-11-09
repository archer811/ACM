#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
using namespace std;
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif
const int maxn = 400006;
struct array
{
    int u,v,w;
} g[maxn];
int cmp(array x,array y)
{
    return x.w<y.w;
}
int Min[maxn],d[maxn];
const int inf = 0x3fffffff;
void up(int &a,int b)
{
    if(a<b)a=b;
}
int f[maxn];
int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(d,0,sizeof(d));
        for(i=1; i<=n; i++)
            Min[i]=inf;
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d",&g[i].u,&g[i].v,&g[i].w);
        }
        sort(g,g+m,cmp);
        for(i=0; i<m; i++)
        {
            for(j=i;j<m;j++)
            {
                if(j+1<m&&g[j+1].w!=g[i].w)break;
            }
            for(int k=i;k<=j;k++)
            {
                f[k]=d[g[k].u]+1;
            }
            for(int k=i;k<=j;k++)
            {
                up(d[g[k].v],f[k]);
               // cout<<g[k].v<<" "<<d[g[k].v]<<endl;
            }
            i=j;
        }
        int M=0;
        for(i=1; i<=n; i++)
            if(d[i]>M)M=d[i];
        printf("%d\n",M);
    }
    return 0;
}
