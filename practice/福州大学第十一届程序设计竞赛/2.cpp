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
#define ll long long
struct matrix
{
    ll m[55][55];
};
const ll inf = 1000000+1;
int n;
ll d[55][55];
ll _min(ll a,ll b)
{
    if(a>b)return b;
    return a;
}
matrix mul(matrix a,matrix b)
{
    matrix c;
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            c.m[i][j]=inf;
    }
    for(int k=1; k<=n; k++)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(a.m[i][k]==inf||b.m[k][j]==inf)continue;
                if(c.m[i][j]==inf||c.m[i][j]>a.m[i][k]+b.m[k][j])
                    c.m[i][j]=a.m[i][k]+b.m[k][j];
            }
        }
    }
    return c;
}
matrix pow(int k)
{
    matrix a,b;
    int i,j;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            a.m[i][j]=d[i][j];
            //if(i==j)b.m[i][j]=0;
            //else b.m[i][j]=inf;
            b.m[i][j]=d[i][j];
        }
    }
    k--;
    while(k)
    {
        if(k&1)b=mul(b,a);
        a=mul(a,a);
        k>>=1;
    }
    return b;
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    int h,k;
    int u,v;
    ll ds;
    while(t--)
    {
        scanf("%d%d%d",&n,&h,&k);
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
                d[i][j]=inf;
        }
        for(i=0; i<h; i++)
        {
            scanf("%d%d%lld",&u,&v,&ds);
            if(d[u][v]==inf||d[u][v]>ds)
            d[u][v]=ds;
        }
        matrix ans = pow(k);
        ll ant = ans.m[1][n];
        if(ant==inf)ant=-1;
        printf("%lld\n",ant);
    }
    return 0;
}
