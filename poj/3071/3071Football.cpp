#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
double p[129][129];
double f[129][129][129];
double sum[129][129];
int main()
{
    int n,i,j,k;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==-1)break;
        int m = 1<<n;
        memset(sum,0,sizeof(sum));
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=m;j++)
                scanf("%lf",&p[i][j]),sum[i][j]=sum[i][j-1]+p[i][j];
        }
        memset(f,0,sizeof(f));
        for(i=1;i<=m;i+=2)
            f[i][i+1][i]=p[i][i+1],f[i][i+1][i+1]=p[i+1][i];
        j = 4;
        while(j<=m)
        {
            for(i=1;i<=m;i+=j)
            {
                for(k=i;k<i+j/2;k++)
                {
                    for(int g=i+j/2;g<i+j;g++)
                    {
//                        cout<<i<<" "<<i+j-1<<" "<<k<<" "<<g<<" "<<f[i+j/2][i+j-1][g]<<
//                        " "<<p[k][g]<<endl;
                        f[i][i+j-1][k]+=f[i][i+j/2-1][k]*f[i+j/2][i+j-1][g]*p[k][g];
                    }
                }
                for(k=i+j/2;k<i+j;k++)
                {
                    for(int g=i;g<i+j/2;g++)
                    {
                        f[i][i+j-1][k]+=f[i+j/2][i+j-1][k]*f[i][i+j/2-1][g]*p[k][g];
                    }
                }
            }
            j *= 2;
        }
        double ans = -1;
        int pp;
        for(i=1;i<=m;i++)
        {
            if(ans<f[1][m][i])
            {
                ans = f[1][m][i];
                pp = i;
            }
        }
        printf("%d\n",pp);
    }
}
