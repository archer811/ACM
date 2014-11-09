#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 11000;
double eps = 1e-10;
vector<int>g[maxn];
double A[maxn],B[maxn],C[maxn];
double sha[maxn],tao[maxn];
void dfs(int u,int fa)
{
    int i,j,k;
    double suma =0,sumb =0,sumc =0;
    int m=g[u].size();
    for(i=0;i<m;i++)
    {
        int v = g[u][i];
        if(v==fa)continue;
        dfs(v,u);
        suma += A[v];
        sumb += B[v];
        sumc += C[v];
    }
    A[u] = (sha[u]+(1-sha[u]-tao[u])*1.0/m*suma)*1.0
           /(1-(1-sha[u]-tao[u])*1.0/m*sumb);
    B[u] = (1-sha[u]-tao[u])*1.0/m
           /(1-(1-sha[u]-tao[u])*1.0/m*sumb);
    C[u] = ((1-sha[u]-tao[u])*1.0/m*sumc+1-sha[u]-tao[u])
           /(1-(1-sha[u]-tao[u])*1.0/m*sumb);
}
int main()
{
    int T,i,j,k,n,a,b;
    scanf("%d",&T);
    int cas=0;
    while(T--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            g[i].clear();
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        for(i=1;i<=n;i++)
            scanf("%lf%lf",&sha[i],&tao[i]),sha[i]/=100,tao[i]/=100;
        dfs(1,-1);
        printf("Case %d: ",++cas);
        if(fabs(A[1]-1.0)<eps)
           puts("impossible");
        else
           printf("%.6f\n",C[1]/(1-A[1]));
    }
}
