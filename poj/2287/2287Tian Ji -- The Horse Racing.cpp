#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int n;
int f[1005][1005],g[1005][1005];
int a[1005],b[1005];
int ff(int i,int j)
{
    if(a[i]>b[j])return 1;
    else if(a[i]==b[j])return 0;
    else return -1;
}
int cmp(int x,int y)
{
    return x>y;
}
int main()
{
    int i,j,k;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
        }
        sort(b+1,b+1+n,cmp);
        sort(a+1,a+1+n,cmp);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                g[i][j]=ff(i,j);
            }
        }
        int gg=n;
        for(i=1;i<=n;i++)
            f[i][0]=f[i-1][0]+g[n+1-i][i],f[i][i]=f[i-1][i-1]+g[i][i];
        for(i=2;i<=n;i++)
        {
            for(j=1;j<i;j++)
            {
                  f[i][j]= max(f[i-1][j]+g[n+1-(i-j)][i],f[i-1][j-1]+g[j][i]);
            }
        }
        int M= f[n][0];
        for(i=1;i<=n;i++)
            M = max(M,f[n][i]);
        cout<<M*200<<endl;
    }
}
